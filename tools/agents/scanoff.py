#!/usr/bin/env python3
"""scanoff.py <listfile>: for each line, compile once and print aligned-diff metric for rom offsets -24..+24 bytes"""
import sys, os, struct, difflib
LIST = sys.argv[1]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
g = {}
exec(compile(code, 'lu_match', 'exec'), g)
rom = g['rom']
def mn(w):
    op = w >> 26
    if op == 0: return ('s', w & 0x3F)
    if op == 1: return ('r', (w >> 16) & 0x1F)
    if op == 0x11:
        rs = (w >> 21) & 0x1F
        return ('c', rs, w & 0x3F) if rs in (16, 17) else ('c', rs, (w >> 16) & 3)
    return op
for line in open(LIST):
    f = line.split()
    if not f: continue
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    g['extra'][:] = f[3:]
    res, err = g['compile_funcs'](os.path.expanduser('~/trw_s706/') + path)
    if res is None: print(func, 'FAIL', err); continue
    text, syms, relocs, relnames = res
    name, off, size = [s for s in syms if s[0] == func][0]
    n = size // 4
    fw = struct.unpack('>%dI' % n, text[off:off+size])
    am = [mn(w) for w in fw]
    best = []
    for d in range(-24, 28, 4):
        ro = rom_hex + d
        rw = struct.unpack('>%dI' % n, rom[ro:ro+size])
        bm = [mn(w) for w in rw]
        sm = difflib.SequenceMatcher(None, am, bm, autojunk=False)
        st = sum(max(i2-i1, j2-j1) for t, i1, i2, j1, j2 in sm.get_opcodes() if t != 'equal')
        best.append((st, d))
    best.sort()
    print(func, 'orig_off_structural=', [b for b in best if b[1] == 0][0][0], 'best', best[:3], flush=True)
