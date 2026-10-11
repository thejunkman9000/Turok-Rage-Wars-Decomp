#!/usr/bin/env python3
"""prio2.py <dumpdir> [n] : global-alloc order table from tools/dump.sh output (a.i.lreg + a.i.greg).
columns: order, pseudo, weighted refs, live length, calls crossed, priority, mode(FP/GR), final hard reg (name)"""
import re, sys, os, math
d = sys.argv[1]
lim = int(sys.argv[2]) if len(sys.argv) > 2 else 100000
lreg = open(d + '/a.i.lreg').read()
greg = open(d + '/a.i.greg').read()
st = {}
for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(.*)$', lreg, re.M):
    r, n, l, blk, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4), m.group(5)
    c = re.search(r'crosses (\d+) call', rest)
    st[r] = (n, l, int(c.group(1)) if c else 0, 'FP' if 'FP_REGS' in rest else 'GR', blk)
order = []
for m in re.finditer(r';; (\d+) regs to allocate: ([\d ]+)', greg):
    order = [int(x) for x in m.group(2).split()]
    break
disp = {}
if 'Register dispositions' in greg:
    seg = greg[greg.index('Register dispositions'):]
    seg = seg[:seg.index('Hard regs used')] if 'Hard regs used' in seg else seg
    for m in re.finditer(r'(\d+) in (\d+)', seg):
        disp[int(m.group(1))] = int(m.group(2))
names = ['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
def hn(h):
    if h is None: return '-'
    if h < 32: return names[h]
    if h >= 32 and h < 64: return '$f%d' % (h - 32)
    return str(h)
print('ord pseudo refs  len calls   prio  mode  reg')
for i, r in enumerate(order[:lim]):
    n, l, c, md, blk = st.get(r, (0, 1, 0, '??', None))
    lg = int(math.log2(n)) if n > 0 else 0
    pr = lg * n / max(l, 1) * 10000
    print('%3d %5d %4d %4d %3d %7.0f  %s  %s' % (i, r, n, l, c, pr, md, hn(disp.get(r))))
