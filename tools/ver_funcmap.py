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
    # the libultra / libaudio units of funcs.txt (named by their SDK names, they are not in docs/game_funcs.txt) are looked up the same way: the SDK code is the same in
    # every release, so the units that our 1.1 C reproduces can be reused (a unit that overlaps a listed function is skipped)
    spans = sorted((r, r + 4 * n) for r, _, n in funcs)
    starts = [s for s, _ in spans]
    extra = []
    for l in open('funcs.txt'):
        f = l.split('#')[0].split()
        if len(f) < 4 or f[3] != 'libultra' or f[0].startswith('pad_'): continue
        r, n = int(f[1], 16), int(f[2])
        i = bisect.bisect_right(starts, r) - 1
        if (i >= 0 and spans[i][1] > r) or (i + 1 < len(spans) and spans[i + 1][0] < r + 4 * n): continue
        extra.append((r, f[0], n))
    funcs += extra; funcs.sort()
    print('libultra units added to the function list:', len(extra))
    base = open(ROMS['us-rev1'], 'rb').read(); other = open(ROMS[ver], 'rb').read()
    lo, hi = 0x1000, min(len(other), 0x1D0000) // 4 * 4
    ow = struct.unpack('>%dI' % ((hi - lo) // 4), other[lo:hi])
    onorm = norm(ow)
    K = 6
    index = collections.defaultdict(list)
    for i in range(len(onorm) - K): index[tuple(onorm[i:i + K])].append(i)
    # 1. every position at which a function's normalised body occurs
    short = {}
    def short_index(n):
        if n not in short:
            d = collections.defaultdict(list)
            for i in range(len(onorm) - n): d[tuple(onorm[i:i + n])].append(i)
            short[n] = d
        return short[n]
    cands = []
    for rom, name, n in funcs:
        w = struct.unpack('>%dI' % n, base[rom:rom + 4 * n]); nw = norm(w)
        if n >= K: cs = [i for i in index.get(tuple(nw[:K]), ()) if onorm[i:i + n] == nw]
        else: cs = list(short_index(n).get(tuple(nw), ()))
        cands.append(cs)
    # a release can hold the same code twice (another overlay carries copies of library functions): a function of 1.1's overlay A can only be in the release's overlay A, a main image
    # function in its main image (layouts: tools/mkver.py LAYOUT)
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    from mkver import LAYOUT
    lay = LAYOUT[ver]
    filt = []
    for (rom, name, n), cs in zip(funcs, cands):
        lo_, hi_ = (lay['OVL_START'], lay['OVL_END']) if rom >= 0x16E000 else (0x1000, lay['MAIN_CODE_END'])
        filt.append([i for i in cs if lo_ <= lo + 4 * i and lo + 4 * (i + n) <= hi_])
    cands = filt
    # 2. anchors: functions with exactly one occurrence, reduced to the longest run that keeps the ROM order (the layout of a release is the 1.1 layout with insertions and deletions)
    anchors = [(i, cs[0]) for i, cs in enumerate(cands) if len(cs) == 1]
    tails = []; prev = [None] * len(anchors); idxs = []
    for k, (i, pos) in enumerate(anchors):
        j = bisect.bisect_left([anchors[t][1] for t in tails], pos)
        if j > 0: prev[k] = tails[j - 1]
        if j == len(tails): tails.append(k)
        else: tails[j] = k
    lis = []; k = tails[-1] if tails else None
    while k is not None: lis.append(k); k = prev[k]
    anchor_at = {anchors[k][0]: anchors[k][1] for k in lis}
    anchor_idx = sorted(anchor_at)
    # 3. assign in 1.1 order: an occurrence must lie after the previous assignment and before the next anchor; the first one after the previous end wins
    res = []; prev_end = 0
    for fi, (rom, name, n) in enumerate(funcs):
        cs = cands[fi]; pick = None
        if fi in anchor_at: pick = anchor_at[fi]
        elif cs:
            ni = bisect.bisect_right(anchor_idx, fi)
            limit = anchor_at[anchor_idx[ni]] - n if ni < len(anchor_idx) else len(onorm)
            ok = [c for c in cs if prev_end <= c <= limit]
            if ok: pick = min(ok)
        if pick is not None:
            st = 'same' if pick == prev_end else 'shift'
            res.append((name, rom, n, st, lo + 4 * pick, len(cs)))
            prev_end = pick + n
        else:
            res.append((name, rom, n, 'none', 0, len(cs)))
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
