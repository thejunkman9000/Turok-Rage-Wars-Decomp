#!/usr/bin/env python3
"""Port a melalawi/ragewars-decomp source to our names (WSL, cwd = the workspace root, e.g. /mnt/d/Projects/TurokRageWars).

usage: port_names.py <their file stem> [<their file stem> ...] --out <dir>      (stem = src/<stem>.c of their repo, e.g. func_8044952C_de)
  reads ragewars-decomp/src/<stem>.c, renames every symbol token that versions/us-rev1/symbol_addrs.txt maps to a US v1.1 address
  (func_XXXXXXXX_de -> func_00<us addr>, D_XXXXXXXX[_de] -> D_<us addr>, library names of our symbol_addrs.txt such as memset) and adds `extern` lines for
  renamed symbols that were declared by their headers (taken from the preprocessed includes of the original and renamed); writes <dir>/<stem>.c with
  `/* their2 */` in the first line.  The map is printed so it can be reviewed.  Check the result with tools/chk (list line `<out>/<stem>.c <our name> <rom hex> @SN`).
  Notes: our symbol table names 0x002A101C `memset` (their func_802A001C_de): it is renamed to memset, fix its prototype by hand (void *memset(void *, int, u32)).
  A header-declared function that their source calls WITHOUT any declaration stays implicit (as in the original)."""
import os, re, subprocess, sys

REPO = os.environ.get('THEIR_REPO', '/mnt/d/Projects/ext/ragewars-decomp')
addr = {}
for l in open(REPO + '/versions/us-rev1/symbol_addrs.txt'):
    m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
    if m: addr[m.group(1)] = int(m.group(2), 16)
ours_func = {}      # US address (24 bit) -> our function name when it is not func_XXXXXXXX (memset ...)
for l in open('symbol_addrs.txt'):
    m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+);.*type:func', l)
    if m and not re.match(r'(func|D|jtbl)_[0-9A-Fa-f]{8}$', m.group(1)): ours_func.setdefault(int(m.group(2), 16) & 0xFFFFFF, m.group(1))
theirsyms = {}
for l in open('their_syms.ld', errors='replace'):
    m = re.match(r'\s*PROVIDE\((\S+)\s*=\s*(0x[0-9A-Fa-f]+)\)', l)
    if m: theirsyms[m.group(1)] = int(m.group(2), 16)

TOK = re.compile(r'\b(?:func|D|jtbl)_[0-9A-Fa-f]{8}(?:_\w+)?\b')

def newname(t):
    a = addr.get(t)
    if a is None: return None
    if t.startswith('func_'):
        return ours_func.get(a & 0xFFFFFF) or 'func_%08X' % (a & 0xFFFFFF)
    return 'D_%08X' % a if not t.startswith('jtbl_') else 'jtbl_%08X' % a

def strip_comments(s):
    return re.sub(r'/\*.*?\*/', lambda m: re.sub(r'[^\n]', ' ', m.group(0)), s, flags=re.S)

def cpp_text(text, tag):
    tmp = 'wip/c/_conv_%s.c' % tag
    open(tmp, 'w', newline='\n').write(text)
    r = subprocess.run(['cpp', '-P', '-undef', '-nostdinc', '-D_LANGUAGE_C', '-DF3DEX_GBI_2', '-D__GNUC__=2', '-D__UNBAKE_STDARG_GCC', '-DVERSION_US_REV1',
                        '-I', 'include', '-I', 'include/their2', tmp], capture_output=True, text=True)
    os.remove(tmp)
    return r.stdout

def toplevel(text):
    """split C text into top-level statements: [(head, full)] ; head = text before a function body / the whole statement"""
    out = []; i = 0; n = len(text)
    buf = []; depth = 0; par = 0; head = None
    while i < n:
        c = text[i]
        if c == '(': par += 1
        elif c == ')': par -= 1
        if c == '{':
            if depth == 0 and head is None:
                h = ''.join(buf).rstrip()
                if h.endswith(')'): head = h          # function definition body starts
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0 and head is not None:
                buf.append(c); out.append((head, ''.join(buf))); buf = []; head = None; i += 1; continue
        elif c == ';' and depth == 0 and par <= 0:
            buf.append(c); s = ''.join(buf); out.append((s, s)); buf = []; head = None; i += 1; continue
        buf.append(c); i += 1
    rest = ''.join(buf).strip()
    if rest: out.append((rest, rest))
    return [(re.sub(r'\s+', ' ', h).strip(), re.sub(r'\s+', ' ', f).strip()) for h, f in out]

def declares(head, t):
    """does a top-level statement head declare symbol t (prototype, extern, definition, array)?"""
    if head.startswith('typedef') : return False
    if re.search(r'\b%s\s*\(' % re.escape(t), head) and not re.search(r'\b%s\s*\([^)]*\)\s*\(' % re.escape(t), head): return True
    if re.search(r'\b%s\s*(\[[^\]]*\])*\s*(;|=)' % re.escape(t), head): return True
    return False

def main():
    args = sys.argv[1:]
    out = args[args.index('--out') + 1]; stems = [a for a in args if not a.startswith('--') and a != out]
    os.makedirs(out, exist_ok=True)
    for stem in stems:
        src = open(REPO + '/src/%s.c' % stem, errors='replace').read().replace('\r\n', '\n')
        code = strip_comments(src)
        used = sorted(set(TOK.findall(code)))
        ren = {}                                   # renamed: every token of the text (comments included)
        for t in sorted(set(TOK.findall(src))):
            n = newname(t)
            if n is None or n == t: continue
            ren[t] = n
        used = set(used)                           # declarations are only needed for tokens used by code
        for t, n in ren.items():           # a new name must not already mean something else in their symbol table
            if n in theirsyms and theirsyms[n] != (addr[t] & 0xFFFFFF if t.startswith('func_') else addr[t]):
                print('!! name clash', stem, t, '->', n, 'their_syms has it at 0x%X' % theirsyms[n])
        own = toplevel(code)
        incl = '\n'.join(l for l in src.split('\n') if l.startswith('#include')) + '\n'
        hdr = toplevel(cpp_text('/* their2 */\n' + incl, 'inc'))
        decls = []
        for t in sorted(ren):
            if t not in used: continue
            if any(declares(h, t) for h, f in own): continue          # declared (or defined) by the source itself
            c = [h for h, f in hdr if declares(h, t)]
            if not c:
                print('?? no header declaration found for', t, 'in', stem); continue
            if len(set(c)) > 1: print('   (several header declarations of %s, using the last: %s)' % (t, c[-1]))
            decls.append((t, c[-1]))
        def sub(m): return ren.get(m.group(0), m.group(0))
        body = TOK.sub(sub, src)
        lines = body.split('\n')
        last_inc = max([i for i, l in enumerate(lines) if l.startswith('#include')] or [-1])
        block = []
        for t, d in decls:
            nd = TOK.sub(sub, d)
            if not nd.startswith('extern') and not nd.startswith('static'): nd = 'extern ' + nd
            block.append(nd)
        res = ['/* their2 */'] + lines[:last_inc + 1] + (['/* symbols declared by the headers under their names, here under ours */'] + block if block else []) + lines[last_inc + 1:]
        open(os.path.join(out, stem + '.c'), 'w', newline='\n').write('\n'.join(res))
        print('== %s: %d renamed, %d declarations added' % (stem, len(ren), len(decls)))
        for t, n in sorted(ren.items()): print('   %-26s -> %s' % (t, n))
        for t, d in decls: print('   decl: ' + d)

main()
