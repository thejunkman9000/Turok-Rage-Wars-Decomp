#!/usr/bin/env python3
"""Link log -> absorb functions that another object already defines (combined multi-function files).
usage: python tools/absorb_dups.py <build log>   (then rebuild, run tools/fix_short_objs.py on the map / sizes)"""
import re, sys, os
t = open(sys.argv[1], encoding='utf-8', errors='replace').read()
pairs = set()
for m in re.finditer(r"multiple definition of `(func_[0-9A-F]{8})'; (?:\S*\n)?\s*build/src/(?:game|ovl_a)/(\w+)\.o", t):
    pairs.add((m.group(1), m.group(2)))
dup = {d for d, p in pairs if d != p}
print(len(dup), 'duplicate member functions:', sorted(dup)[:20])
for manifest, sub in (('funcs.txt', 'game'), ('funcs_a.txt', 'ovl_a')):
    L = open(manifest).read().split('\n')
    out = [l for l in L if not (l.split() and l.split()[0] in dup)]
    open(manifest, 'w', newline='\n').write('\n'.join(out))
for d in sorted(dup):
    for sub in ('game', 'ovl_a'):
        p = f'src/{sub}/{d}.c'
        if os.path.exists(p): os.remove(p)
    open('wip/absorbed.txt', 'a').write(d + '\n')
