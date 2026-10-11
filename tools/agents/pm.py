#!/usr/bin/env python3
"""pm.py <dumpdir> : allocation table from a dump.sh dir (a.i.lreg stats + a.i.greg order/dispositions):
order pseudo refs live calls   prio(refs*floor_log2(refs)/live*1e4)   reg."""
import re, sys, os, math
d = sys.argv[1]
lreg = open(d + '/a.i.lreg').read()
greg = open(d + '/a.i.greg').read()
st = {}
for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(.*)$', lreg, re.M):
    r, n, l, blk, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4), m.group(5)
    c = re.search(r'crosses (\d+) call', rest)
    st[r] = (n, l, int(c.group(1)) if c else 0, blk, 'pointer' in rest, '8 bytes' in rest)
mo = re.search(r'regs to allocate: ([^\n]+)', greg)
order = []
if mo:
    txt = re.sub(r'\(\d+\)', ' ', mo.group(1))
    order = [int(x) for x in txt.split()]
disp = {}
i0 = greg.index('Register dispositions')
i1 = greg.index('Hard regs used') if 'Hard regs used' in greg else len(greg)
for m in re.finditer(r'(\d+) in (\d+)', greg[i0:i1]):
    disp[int(m.group(1))] = int(m.group(2))
names = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
         's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 't8', 't9', 'k0', 'k1', 'gp', 'sp', 'fp', 'ra']
names += ['f%d' % i for i in range(32)]
print('order pseudo refs live calls   prio   reg')
for i, r in enumerate(order):
    n, l, c, blk, p, dbl = st.get(r, (0, 1, 0, None, False, False))
    lg = int(math.log2(n)) if n > 0 else 0
    pr = lg * n / max(l, 1) * 10000
    h = disp.get(r)
    print('%3d %5d %4d %4d %3d %7.0f  %s%s%s' % (i, r, n, l, c, pr, names[h] if h is not None and h < 64 else h, ' ptr' if p else '', ' fp' if dbl else ''))
