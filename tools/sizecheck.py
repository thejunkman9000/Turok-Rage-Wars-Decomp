#!/usr/bin/env python3
"""run in WSL: compare the .text size of every mode=sn object with 4*insns of its manifest entry (ported files that define extra helper functions are bigger)"""
import os, re, subprocess
root = '/mnt/d/Projects/TurokRageWars'
bad = []
for m in ('funcs.txt', 'funcs_a.txt'):
    for l in open(f'{root}/{m}'):
        f = l.split('#')[0].split()
        if len(f) >= 4 and 'mode=sn' in l:
            o = os.path.expanduser(f'~/trw/build/src/{f[3]}/{f[0]}.o')
            if not os.path.exists(o): continue
            t = subprocess.run(['mips-linux-gnu-readelf', '-SW', o], capture_output=True, text=True).stdout
            sz = max([int(x, 16) for x in re.findall(r'\.text\s+PROGBITS\s+[0-9a-f]+\s+[0-9a-f]+\s+([0-9a-f]+)', t)] or [-1])
            if sz != 4 * int(f[2]): bad.append((f[0], 4 * int(f[2]), sz))
for b in bad: print(*b)
print(len(bad), 'objects differ in size')
