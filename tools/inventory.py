"""Inventory of functions in a ROM range: done-in-C, named asm, or unnamed, with the best libreultra structural match.
usage: python tools/inventory.py <lo> <hi> [min_ratio]     (needs ud_json/ from tools/lu_json_all.sh)
Prints: ROM  size  status  name  | best libreultra candidate (ratio) | hint (cop0/cache/fp use)
"""
import sys, re, glob, json, struct, difflib, os
sys.path.insert(0, 'tools')
from loclib import norm_word, rom_window, our_norm, rom

lo, hi = int(sys.argv[1], 0), int(sys.argv[2], 0)
min_r = float(sys.argv[3]) if len(sys.argv) > 3 else 0.6

# functions from splat's asm: (rom, name, size_in_words)
funcs = {}
for p in glob.glob('asm/*.s') + glob.glob('asm/nonmatchings/**/*.s', recursive=True):
    t = open(p, encoding='utf-8').read()
    for m in re.finditer(r'nonmatching (\S+), 0x([0-9A-Fa-f]+)\n\nglabel (\S+)\n\s+/\* ([0-9A-F]+) ', t):
        funcs[int(m.group(4), 16)] = (m.group(3), int(m.group(2), 16) // 4)
# C functions from funcs.txt
done = {}
for l in open('funcs.txt'):
    f = l.split('#')[0].split()
    if len(f) >= 4: done[int(f[1], 16)] = (f[0], int(f[2]))

# libreultra candidates
cands = []
for jp in glob.glob('ud_json/*.json'):
    for f in json.load(open(jp)):
        if len(f['words']) >= 4:
            cands.append((f['name'], our_norm(f['words'], f['mask'])))

def hint(off, n):
    ops = set()
    for i in range(n):
        w = struct.unpack_from('>I', rom, off + 4 * i)[0]
        op = w >> 26
        if op == 0x10: ops.add('cop0')
        elif op == 0x2F: ops.add('cache')
        elif op == 0x11: ops.add('fp')
        elif op == 0 and (w & 0x3F) == 0x0C: ops.add('syscall')
    return ','.join(sorted(ops))

rows = sorted(set(funcs) | set(done))
for off in rows:
    if not (lo <= off < hi): continue
    if off in done:
        print(f'{off:06X} {done[off][1]:4d}  C    {done[off][0]}'); continue
    name, n = funcs[off]
    n = max(n, 1)
    best = (0, '')
    if n >= 4 and n <= 400:
        w = rom_window(off, n)
        for cname, cn in cands:
            if abs(len(cn) - n) > max(4, n // 3): continue
            r = difflib.SequenceMatcher(None, cn, w, autojunk=False).ratio()
            if r > best[0]: best = (r, cname)
    cand = f'{best[1]} ({best[0]:.2f})' if best[0] >= min_r else ''
    print(f'{off:06X} {n:4d}  asm  {name:24s} | {cand:34s} | {hint(off, n)}')
