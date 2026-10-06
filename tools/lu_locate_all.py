"""Run the structural locator over every JSON in ud_json/ and print the best ROM candidate per function.
usage: python tools/lu_locate_all.py [min_insns] [min_ratio]"""
import sys, json, glob, os, difflib
sys.path.insert(0, 'tools')
from loclib import function_starts, rom_window, our_norm

min_n = int(sys.argv[1]) if len(sys.argv) > 1 else 8
min_r = float(sys.argv[2]) if len(sys.argv) > 2 else 0.8
starts = function_starts()
cache = {}
def win(s, n):
    k = (s, n)
    if k not in cache: cache[k] = rom_window(s, n)
    return cache[k]
rows = []
for jp in sorted(glob.glob('ud_json/*.json')):
    src = os.path.basename(jp)[:-5]
    for f in json.load(open(jp)):
        n = len(f['words'])
        if n < min_n: continue
        ours = our_norm(f['words'], f['mask'])
        best = (0, None)
        for s in starts:
            r = difflib.SequenceMatcher(None, ours, win(s, n), autojunk=False).ratio()
            if r > best[0]: best = (r, s)
        if best[0] >= min_r: rows.append((best[1], f['name'], n, best[0], src))
rows.sort()
for s, name, n, r, src in rows:
    print(f'0x{s:06X}  {name:28s} {n:4d} insns  {r:.2f}  ({src})')
