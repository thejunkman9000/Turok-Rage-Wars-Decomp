#!/usr/bin/env python3
"""Draft a port of the other decompilation's (melalawi/ragewars-decomp) matched sources with OUR names (WSL python3, cwd = workspace root).

usage: python3 tools/port_names.py [--out DIR] <their function/source name> [...]         e.g. func_8044A790_de func_8044BE04_de
writes DIR/p_<our name of the unit's first function>.c  (default DIR = wip/c) and prints a report:
  * the source gets the `/* their2 */` marker (compiled against include/their2, the headers of their current tree)
  * every `func_XXXXXXXX_de`, `D_XXXXXXXX[_de]` symbol is renamed with versions/us-rev1/symbol_addrs.txt: functions -> func_00<US address & 0xFFFFFF>,
    data -> D_<US address>.  Their D_ names carry the DE-version address (their D_8010ACC0 is our D_8010ECC0): copying them unchanged links to the wrong object.
  * declarations of renamed symbols that exist only in their headers (extern lines of the preprocessed source) are copied, renamed, after the last #include
  * D_XXXXXXXXXX names whose US address is a function start of ours (callbacks passed as D_00285160) are renamed to the function and REPORTED: fix the
    declaration (`extern void func_00285130();`) and the use (`(void *) func_00285130`) by hand
After drafting: list the units with tools/chk.ps1 (`<file> <our fn> <rom hex> @SN`, ROM = (addr & 0xFFFFFF) - 0x400000 + 0x16E000 for overlay A), then
  decide by hand what is a TU pool constant (literal) and what is shared data (extern): see FINDINGS s1004 (tools/xrange.py lists the code that forms an address
  in a range; pool words follow the link order of the code), and finish with tools/unitchk.py (end-to-end through tools/cc.sh)."""
import re, subprocess, sys, tempfile, os
REPO = '/mnt/d/Projects/ext/ragewars-decomp'
args = sys.argv[1:]
out_dir = 'wip/c'
if '--out' in args:
    i = args.index('--out'); out_dir = args[i + 1]; del args[i:i + 2]
if not args: print(__doc__); sys.exit(1)
addr = {}
for l in open(REPO + '/versions/us-rev1/symbol_addrs.txt'):
    m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
    if m: addr[m.group(1)] = int(m.group(2), 16)
func_starts = set()
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) >= 3 and f[1].startswith('func_'): func_starts.add(int(f[1][5:], 16) & 0xFFFFFF)
pat = re.compile(r'\b((?:func|D|jtbl)_[0-9A-Fa-f]{8}(?:_[A-Za-z0-9_]+)?)\b')

def split_stmts(txt):
    """top-level statements of preprocessed C (function bodies and struct bodies end a statement at depth 0)"""
    stmts = []; depth = 0; cur = []
    for c in txt:
        cur.append(c)
        if c == '{': depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                s = ''.join(cur)
                if not re.match(r'\s*(typedef\s+)?(struct|union|enum)\b[^({]*\{', s) and not re.search(r'=\s*\{', s):
                    stmts.append(s.strip()); cur = []
        elif c == ';' and depth == 0:
            stmts.append(''.join(cur).strip()); cur = []
    return stmts

def decls_for(stmts, nm):
    p = re.compile(r'\b%s\b' % re.escape(nm))
    return [re.sub(r'\s+', ' ', s) for s in stmts if p.search(s) and not s.rstrip().endswith('}')]

def ours(n):
    a = addr[n]
    if n.startswith('func_'): return 'func_%08X' % (a & 0xFFFFFF)
    if (a & 0xFFFFFF) in func_starts and a < 0x01000000:      # a KUSEG-spelled address of a function of ours: a callback
        print('  NOTE %s is the function pointer func_%08X: fix the declaration and the use by hand' % (n, a & 0xFFFFFF))
        return 'func_%08X' % (a & 0xFFFFFF)
    return 'D_%08X' % a

for th in args:
    th = th[:-2] if th.endswith('.c') else th
    raw = open('%s/src/%s.c' % (REPO, th), errors='replace').read().replace('\r\n', '\n')
    raw = '/* their2 */\n' + raw
    tmp = tempfile.mkdtemp()
    open(tmp + '/a.c', 'w').write(raw)
    inc = os.path.abspath('include')
    subprocess.run('cd %s && cpp -P -undef -nostdinc -D_LANGUAGE_C -DF3DEX_GBI_2 -D__GNUC__=2 -D__UNBAKE_STDARG_GCC -DVERSION_US_REV1 -I%s -I%s/their2 -I%s a.c > a.i' % (tmp, inc, inc, inc), shell=True, check=True)
    pre = split_stmts(open(tmp + '/a.i', errors='replace').read())
    rawst = split_stmts(raw)
    names = sorted(set(n for n in pat.findall(raw) if n in addr))
    extra = []
    for n in names:
        ins = [s for s in decls_for(rawst, n) if s.rstrip().endswith(';') and not re.search(r'\bfor\b|\bif\b|=[^=]|return|\bwhile\b', s)]
        hdr = [d for d in decls_for(pre, n) if d not in ins and d.startswith('extern') and re.search(r'\b%s\b\s*(\(|\[|;|,)' % re.escape(n), d)]
        if hdr and not any(re.match(r'(extern\s+)?[\w\s\*]+\b%s\b\s*\(' % re.escape(n), s) for s in ins):
            extra.append(hdr[-1])
    def rep(m):
        n = m.group(1)
        return ours(n) if n in addr else n
    body = pat.sub(rep, raw)
    extra = [pat.sub(rep, e) for e in extra]
    lines = body.split('\n')
    last = max(i for i, l in enumerate(lines) if l.startswith('#include'))
    lines[last + 1:last + 1] = [''] + extra
    first = 'func_%08X' % (addr[th] & 0xFFFFFF)
    os.makedirs(out_dir, exist_ok=True)
    open('%s/p_%s.c' % (out_dir, first), 'w', newline='\n').write('\n'.join(lines))
    defs = re.findall(r'^(?:static\s+)?(?:inline\s+)?[A-Za-z_][\w \*]*?\b(func_[0-9A-Fa-f]{8}_\w+)\s*\([^;{]*\)\s*\{', raw, flags=re.M)
    print('%s -> %s/p_%s.c  (+%d declarations copied from headers); functions:' % (th, out_dir, first, len(extra)))
    for d in defs:
        a = addr[d]; print('   %s  our func_%08X  rom 0x%X' % (d, a & 0xFFFFFF, (a & 0xFFFFFF) - 0x400000 + 0x16E000 if 0x400000 <= (a & 0xFFFFFF) < 0x500000 else (a & 0xFFFFFF) - 0x1FF400))
