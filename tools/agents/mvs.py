#!/usr/bin/env python3
"""mvs.py - statement-move search with the parallel aligned metric of vb.py (WSL, run from the workspace root).

usage: mvs.py <file.c> <fn> <rom hex> <first_line> <last_line> [--flags "@SN -fno-builtin"] [--jobs N] [--top N] [-m i,j,..] [--swap] [--dup]
Lines first..last (1-based, inclusive) are treated as one statement per line.  Variants:
  default: move statement i (all, or only those in -m) to every other position in the range
  --swap : swap statement i with statement j instead of moving
Each variant is evaluated with vb.evaluate (structural/operand metric + chk-level exact flag).  Best -> wip/mv_best.c, all variants in wip/mv/."""
import sys, os, re, shutil, multiprocessing as mp
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import vb

def main():
    a = sys.argv[1:]
    src, fn, rom_hex, lo, hi = a[0], a[1], int(a[2], 16), int(a[3]), int(a[4])
    flags = ['@SN']; jobs = 3; top = 12; movers = None; swap = False
    i = 5
    while i < len(a):
        if a[i] == '--flags': flags = a[i + 1].split(); i += 2
        elif a[i] == '--jobs': jobs = int(a[i + 1]); i += 2
        elif a[i] == '--top': top = int(a[i + 1]); i += 2
        elif a[i] == '-m': movers = [int(x) for x in a[i + 1].split(',')]; i += 2
        elif a[i] == '--swap': swap = True; i += 1
        else: i += 1
    os.chdir(vb.ROOT)
    lines = open(src, encoding='utf-8').read().split('\n')
    blk = lines[lo - 1:hi]
    n = len(blk)
    variants = []
    seen = set()
    for i in range(n):
        if movers and (i + lo) not in movers: continue
        if not blk[i].strip(): continue
        for j in range(n):
            if i == j or not blk[j].strip(): continue
            nb = blk[:]
            if swap:
                if j < i: continue
                nb[i], nb[j] = nb[j], nb[i]
            else:
                x = nb.pop(i); nb.insert(j, x)
            key = '\n'.join(nb)
            if key in seen: continue
            seen.add(key)
            variants.append((i + lo, j + lo, lines[:lo - 1] + nb + lines[hi:]))
    os.makedirs('wip/mv', exist_ok=True)
    for f in os.listdir('wip/mv'): os.remove('wip/mv/' + f)
    jl = []
    for k, (i, j, L) in enumerate(variants):
        p = f'wip/mv/v{k:04d}.c'
        open(p, 'w', encoding='utf-8', newline='\n').write('\n'.join(L))
        dst = os.path.join(vb.HOME_WS, p)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy(p, dst)
        jl.append((dst, fn, rom_hex, flags))
    shutil.copytree(vb.ROOT + '/include', vb.HOME_WS + '/include', dirs_exist_ok=True)
    print('variants:', len(variants), flush=True)
    with mp.Pool(jobs) as pool:
        res = pool.map(vb.evaluate, jl, chunksize=1)
    out = []
    for k, r in enumerate(res):
        out.append((not r[3], r[1] * 3 + r[2], k, r))
    out.sort()
    for ex, sc, k, r in out[:top]:
        print(f'v{k:04d}: line {variants[k][0]} -> {variants[k][1]}: structural={r[1]} operand={r[2]} exact={r[3]} {r[4]}')
    if out:
        shutil.copy(f'wip/mv/v{out[0][2]:04d}.c', 'wip/mv_best.c')

if __name__ == '__main__':
    main()
