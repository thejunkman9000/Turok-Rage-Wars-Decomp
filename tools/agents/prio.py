#!/usr/bin/env python3
"""prio.py [dir]: table of global-alloc order for the RTL dumps in ~/dmp703 (t.c.flow + t.c.greg): pseudo, refs, live length, calls crossed, priority, final hard reg."""
import re, sys, os, math
d = sys.argv[1] if len(sys.argv) > 1 else os.path.expanduser('~/dmp703')
flow = open(d + '/t.c.flow').read()
greg = open(d + '/t.c.greg').read()
st = {}
for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns(?: in block \d+)?(.*)$', flow, re.M):
    r, n, l, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4)
    c = re.search(r'crosses (\d+) call', rest)
    st[r] = (n, l, int(c.group(1)) if c else 0, 'pointer' in rest)
order = [int(x) for x in re.search(r'regs to allocate: ([\d ]+)', greg).group(1).split()]
disp = {}
for m in re.finditer(r'(\d+) in (\d+)', greg[greg.index('Register dispositions'):greg.index('Hard regs used')]):
    disp[int(m.group(1))] = int(m.group(2))
names = ['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
print('order pseudo refs live calls  prio   reg')
for i, r in enumerate(order):
    n, l, c, p = st.get(r, (0, 1, 0, False))
    lg = int(math.log2(n)) if n > 0 else 0
    pr = lg * n / max(l, 1) * 10000
    h = disp.get(r)
    print('%3d %5d %4d %4d %3d %7.0f  %s%s' % (i, r, n, l, c, pr, names[h] if h is not None and h < 32 else h, ' ptr' if p else ''))
