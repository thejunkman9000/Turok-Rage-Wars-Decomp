#!/usr/bin/env python3
"""asmins.py - insert an empty asm after statements (WSL, workspace root).
usage: asmins.py <file.c> <fn> <rom hex> <first_line> <last_line> [--flags "@SN"] [--jobs N] [--top N] [--kinds plus,use,vol,do,dowrap]
For every line in [first,last] that is a simple assignment `x = ...;` (or `x op= ...;`), generate variants:
  plus : `__asm__("" : "+r"(x));`     after the line     (x must be a scalar variable name)
  use  : `__asm__("" : : "r"(x));`    after the line
  vol  : `__asm__ volatile("");`      after the line
  do   : wrap the single line in do { } while (0);
Evaluated with vb.evaluate (parallel); best -> wip/asm_best.c; variants in wip/ai/."""
import sys, os, re, shutil, multiprocessing as mp
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import vb

def main():
    a = sys.argv[1:]
    src, fn, rom_hex, lo, hi = a[0], a[1], int(a[2], 16), int(a[3]), int(a[4])
    flags = ['@SN']; jobs = 3; top = 15; kinds = ['plus', 'use', 'vol', 'do']
    i = 5
    while i < len(a):
        if a[i] == '--flags': flags = a[i + 1].split(); i += 2
        elif a[i] == '--jobs': jobs = int(a[i + 1]); i += 2
        elif a[i] == '--top': top = int(a[i + 1]); i += 2
        elif a[i] == '--kinds': kinds = a[i + 1].split(','); i += 2
        else: i += 1
    os.chdir(vb.ROOT)
    lines = open(src, encoding='utf-8').read().split('\n')
    asg = re.compile(r'^(\s*)([A-Za-z_]\w*)\s*(?:[-+*/|&^]|<<|>>)?=[^=].*;\s*$')
    variants = []
    for k in range(lo - 1, hi):
        m = asg.match(lines[k])
        if not m: continue
        ind, x = m.group(1), m.group(2)
        for kind in kinds:
            nl = list(lines)
            if kind == 'plus': nl.insert(k + 1, f'{ind}__asm__("" : "+r"({x}));')
            elif kind == 'use': nl.insert(k + 1, f'{ind}__asm__("" : : "r"({x}));')
            elif kind == 'vol': nl.insert(k + 1, f'{ind}__asm__ volatile("");')
            elif kind == 'do': nl[k] = f'{ind}do {{ {lines[k].strip()} }} while (0);'
            else: continue
            variants.append((k + 1, kind, x, nl))
    os.makedirs('wip/ai', exist_ok=True)
    for f in os.listdir('wip/ai'): os.remove('wip/ai/' + f)
    jl = []
    for n, (k, kind, x, nl) in enumerate(variants):
        p = f'wip/ai/v{n:04d}.c'
        open(p, 'w', encoding='utf-8', newline='\n').write('\n'.join(nl))
        dst = os.path.join(vb.HOME_WS, p)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy(p, dst)
        jl.append((dst, fn, rom_hex, flags))
    shutil.copytree(vb.ROOT + '/include', vb.HOME_WS + '/include', dirs_exist_ok=True)
    print('variants:', len(variants), flush=True)
    with mp.Pool(jobs) as pool:
        res = pool.map(vb.evaluate, jl, chunksize=1)
    out = sorted(((not r[3], r[1] * 3 + r[2], n, r) for n, r in enumerate(res)))
    for ex, sc, n, r in out[:top]:
        k, kind, x, nl = variants[n]
        print(f'v{n:04d}: line {k} {kind} {x}: structural={r[1]} operand={r[2]} exact={r[3]} {r[4]}')
    if out:
        shutil.copy(f'wip/ai/v{out[0][2]:04d}.c', 'wip/asm_best.c')

if __name__ == '__main__':
    main()
