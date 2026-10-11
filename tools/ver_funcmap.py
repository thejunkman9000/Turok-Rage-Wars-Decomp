#!/usr/bin/env python3
"""Function-level map US v1.1 -> another release by CODE CONTENT (analysis only, no build): which of our functions exist unchanged in the other release,
where, and which ones really differ (the work list of a version build).

usage: python tools/ver_funcmap.py [us|eu|de] [--out wip/funcmap_<ver>.txt]
Every function of docs/game_funcs.txt is looked up in the other ROM: instruction words are normalised (j/jal targets ignored, lui/addiu/ori/load/store immediates
ignored unless the base register is $zero or $sp), the first 6 normalised words index the other ROM, candidates are verified over the whole body and the one nearest
to the expected position (previous match + its length) wins.  Status: `same` (normalised body found), `shift` (found, but the previous function's match was not
adjacent: the layout moved), `none` (not found: changed or missing code).  Output line: `<name> <rom 1.1> <insns> <status> <rom other>`."""
import os, re, struct, sys, collections, bisect
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
ROMS = {'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64', 'us-rev1': 'baserom.us.v11.z64'}
LOADSTORE = (0x23, 0x2B, 0x21, 0x25, 0x20, 0x24, 0x29, 0x28, 0x31, 0x39, 0x35, 0x3D, 0x0D, 0x09, 0x0C, 0x08, 0x37, 0x3F, 0x30, 0x38, 0x22, 0x26, 0x2A, 0x2E)

def norm(words):
    out = []
    for w in words:
        op = w >> 26
        if op in (2, 3): out.append(op)
        elif op == 0x0F: out.append(w >> 16)
        elif op in LOADSTORE:
            rs = (w >> 21) & 31
            out.append(w if rs in (0, 29) else w >> 16)
        else: out.append(w)
    return out

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    ver = args[0] if args else 'us'
    outp = sys.argv[sys.argv.index('--out') + 1] if '--out' in sys.argv else f'wip/funcmap_{ver}.txt'
    funcs = []
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#') or not l.strip(): continue
        f = l.split()
        funcs.append((int(f[0], 16), f[1], int(f[2])))
    base = open(ROMS['us-rev1'], 'rb').read(); other = open(ROMS[ver], 'rb').read()
    lo, hi = 0x1000, min(len(other), 0x1D0000) // 4 * 4
    ow = struct.unpack('>%dI' % ((hi - lo) // 4), other[lo:hi])
    onorm = norm(ow)
    K = 6
    index = collections.defaultdict(list)
    for i in range(len(onorm) - K): index[tuple(onorm[i:i + K])].append(i)
    res = []; expect = None
    for rom, name, n in funcs:
        w = struct.unpack('>%dI' % n, base[rom:rom + 4 * n]); nw = norm(w)
        cands = []
        key = tuple(nw[:K]) if n >= K else None
        if key is not None:
            for i in index.get(key, ()):
                if onorm[i:i + n] == nw: cands.append(i)
        else:
            # tiny functions: scan near the expected position only
            if expect is not None:
                for i in range(max(0, expect - 64), min(len(onorm) - n, expect + 64)):
                    if onorm[i:i + n] == nw: cands.append(i)
        if cands:
            pick = min(cands, key=lambda i: abs(i - expect)) if expect is not None else cands[0]
            st = 'same' if expect is not None and abs(pick - expect) <= 1 else ('shift' if expect is not None else 'same')
            res.append((name, rom, n, st, lo + 4 * pick, len(cands)))
            expect = pick + n
        else:
            res.append((name, rom, n, 'none', 0, 0))
            if expect is not None: expect += n
    os.makedirs(os.path.dirname(outp) or '.', exist_ok=True)
    with open(outp, 'w') as f:
        for r in res: f.write('%s 0x%06X %d %s 0x%06X %d\n' % r)
    c = collections.Counter(); ci = collections.Counter()
    for name, rom, n, st, o, nc in res: c[st] += 1; ci[st] += n
    print(ver, dict(c), 'insns', dict(ci))
    amb = sum(1 for r in res if r[5] > 1)
    print('functions with more than one candidate:', amb)
    none = sorted((r for r in res if r[3] == 'none'), key=lambda r: -r[2])
    print('largest functions without a normalised counterpart:')
    for r in none[:15]: print('  %s 0x%06X %d insns' % (r[0], r[1], r[2]))
    print('total none insns', sum(r[2] for r in none), 'in', len(none), 'functions')

if __name__ == '__main__': main()
