#!/usr/bin/env python3
"""WSL-side batch scorer.  usage: hcw.py <listfile>   (chk list lines) -> prints 'idx structural operand ours rom' per line, aligned-diff metric"""
import sys, os, struct, subprocess, difflib, re
from concurrent.futures import ProcessPoolExecutor
LIST = sys.argv[1]
JOBS = int(os.environ.get('HCJOBS', '6'))
def score_line(args):
    idx, line = args
    sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
    code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
    g = {}
    exec(compile(code, 'lu_match', 'exec'), g)
    f = line.split()
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    g['extra'][:] = f[3:]
    ROOTD = os.path.expanduser('~/trw_s706')
    try:
        res, err = g['compile_funcs'](f'{ROOTD}/{path}')
    except Exception as e:
        return idx, 9999, 9999, 0, 0
    if res is None: return idx, 9999, 9999, 0, 0
    text, syms, relocs, relnames = res
    c = [s for s in syms if s[0] == func]
    if not c: return idx, 9999, 9999, 0, 0
    name, off, size = c[0]
    n = size // 4
    fw = struct.unpack('>%dI' % n, text[off:off+size])
    rom = g['rom']
    rw = struct.unpack('>%dI' % (n+64), rom[rom_hex:rom_hex+size+256])
    def mn(w):
        op = w >> 26
        if op == 0: return ('s', w & 0x3F)
        if op == 1: return ('r', (w >> 16) & 0x1F)
        if op == 0x11:
            rs = (w >> 21) & 0x1F
            return ('c', rs, w & 0x3F) if rs in (16, 17) else ('c', rs, (w >> 16) & 3)
        return op
    am = [mn(w) for w in fw]; bm = [mn(w) for w in rw[:n]]
    sm = difflib.SequenceMatcher(None, am, bm, autojunk=False)
    st = 0; opd = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i2 - i1):
                m = 0xFFFFFFFF ^ relocs.get(off + 4*(i1+k), 0)
                kind = am[i1+k]
                if kind in (2, 3): m &= 0xFC000000
                elif kind in (4,5,6,7,20,21,22,23) or (isinstance(kind, tuple) and kind[0]=='r' and kind[1]<4): m &= 0xFFFF0000
                if (fw[i1+k] & m) != (rw[j1+k] & m): opd += 1
        else:
            st += max(i2-i1, j2-j1)
    return idx, st, opd, n, n
if __name__ == '__main__':
    lines = [l.strip() for l in open(LIST) if l.strip()]
    with ProcessPoolExecutor(JOBS) as ex:
        for r in ex.map(score_line, list(enumerate(lines))):
            print(*r)
