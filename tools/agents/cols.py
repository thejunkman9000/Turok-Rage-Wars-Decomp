#!/usr/bin/env python3
"""cols.py <ours_lo> <ours_hi> <rom_lo> <rom_hi> : print /tmp/ours.lst lines and /tmp/rom.lst lines side by side (WSL)"""
import sys
a = [int(x) for x in sys.argv[1:5]]
o = open('/tmp/ours.lst').read().splitlines()
r = open('/tmp/rom.lst').read().splitlines()
O = o[a[0]:a[1] + 1]; R = r[a[2]:a[3] + 1]
for i in range(max(len(O), len(R))):
    x = O[i] if i < len(O) else ''
    y = R[i] if i < len(R) else ''
    print('%-38s | %s' % (x, y))
