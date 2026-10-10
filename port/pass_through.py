#!/usr/bin/env python3
"""Matched C sources whose calls rely on MIPS argument registers that the C does not pass.

The matching C is written to reproduce the ROM's bytes, not its semantics: `func_00288E78();` (declared without parameters) is a call
whose callee reads $a0/$a1 as they happen to be at that point, and the original compiler's register allocation made them equal to
the caller's own arguments (or to leftovers).  On x86 a C call pushes only what is written, so the callee reads stack garbage.
build_clang.py patches the easy cases (zero-argument calls get the caller's entry arguments) but that is a heuristic; the exact
semantics exist in the statically recompiled twin of the caller.

usage: python port/pass_through.py          print the stems of the C sources that contain such a call (to feed port/bisect_c.py set ...)
       python port/pass_through.py --why    also list the call sites
A call counts when the callee is defined (C source, port/build/rc_argc.txt) with more non-float parameters than the call passes."""
import glob, os, re, sys
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

DEF = re.compile(r'^[\w][\w\s\*]*?\b(func_[0-9A-Fa-f]{8}(?:_\w+)?)\s*\(([^)]*)\)\s*\{', re.M)
CALL = re.compile(r'(?<![\w.>])(func_(?:00)?[0-9A-Fa-f]{6})(?![\w])\s*\(')       # overlay functions are also spelled func_44ACCC (build_clang.py normalises them to func_0044ACCC)
TYPES = re.compile(r'\b(void|int|char|short|long|float|double|unsigned|signed|struct|union|enum|const|extern|static|[su]\d+|f32|f64|u8|u16|u32|s8|s16|s32|[A-Z]\w+)\s*\**\s*$')

def split_args(t):
    t = t.strip()
    if not t or t == 'void': return []
    out, depth, cur = [], 0, ''
    for ch in t:
        if ch in '([': depth += 1
        elif ch in ')]': depth -= 1
        if ch == ',' and depth == 0: out.append(cur); cur = ''
        else: cur += ch
    out.append(cur)
    return out

def call_args(text, i):
    """arguments of the call whose '(' is at text[i-1]; returns the list or None"""
    depth, cur, args = 1, '', []
    while i < len(text) and depth:
        c = text[i]
        if c in '([': depth += 1
        elif c in ')]': depth -= 1
        if depth == 0: break
        if c == ',' and depth == 1: args.append(cur); cur = ''
        else: cur += c
        i += 1
    if cur.strip(): args.append(cur)
    return args if depth == 0 else None

def main():
    their = {}
    try:
        for m in re.finditer(r'^PROVIDE\((func_[0-9A-F]{8}_\w+) = 0x(00[0-9A-Fa-f]{6})\);', open('their_syms.ld').read(), re.M): their[m.group(1)] = 'func_' + m.group(2).upper()
    except OSError: pass
    nparams = {}
    srcs = sorted(glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c'))
    texts = {p: open(p, errors='replace').read() for p in srcs}
    for t in texts.values():
        for m in DEF.finditer(t):
            ps = split_args(m.group(2))
            if '...' in m.group(2): continue
            if any(re.search(r'\b(f32|f64|float|double)\b', a) and '*' not in a for a in ps): continue       # float parameters travel in FPU registers: not this problem
            name = their.get(m.group(1), m.group(1))
            nparams[name] = max(nparams.get(name, 0), len(ps))
    if os.path.exists('port/build/rc_argc.txt'):
        for l in open('port/build/rc_argc.txt'):
            f = l.split()
            if len(f) == 2: nparams.setdefault(f[0], int(f[1]))
    sys.path.insert(0, 'port'); import fpsig
    fsig = fpsig.load()                                                  # functions with floating point parameters / results: their arguments are not the integer registers
    overridden = {os.path.basename(p)[:-2] for p in glob.glob('port/overrides/*.c')}      # hand-written / generated port versions already exist
    bad = {}
    for p, t in texts.items():
        stem = os.path.basename(p)[:-2]
        if stem in overridden: continue
        for m in CALL.finditer(t):
            callee = m.group(1) if len(m.group(1)) == 13 else 'func_00' + m.group(1)[5:]
            n = nparams.get(callee, 0)
            if not n or callee in fsig: continue
            line_start = t.rfind('\n', 0, m.start()) + 1
            if TYPES.search(t[line_start:m.start()]): continue                       # a declaration (void func_X();)
            args = call_args(t, m.end())
            if args is None or len(args) >= n: continue
            if callee == stem: continue
            bad.setdefault(stem, []).append((callee, len(args), n, t.count('\n', 0, m.start()) + 1))
    for stem in sorted(bad):
        print(stem)
        if '--why' in sys.argv:
            for c, a, n, ln in bad[stem][:6]: print(f'    line {ln}: {c} called with {a} of {n} arguments', file=sys.stderr)
    print(len(bad), 'sources with pass-through calls', file=sys.stderr)

if __name__ == '__main__':
    main()
