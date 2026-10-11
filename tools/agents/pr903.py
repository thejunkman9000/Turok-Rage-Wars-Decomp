#!/usr/bin/env python3
"""pr903.py <dumpdir> [n]: global-alloc order table from a.i.lreg (stats) and a.i.greg (order + dispositions).
columns: order pseudo refs len calls priority(=floor_log2(refs)*refs/len*10000) final-reg"""
import re, sys, math, os
d = sys.argv[1]
lreg = open(d + '/a.i.lreg').read()
greg = open(d + '/a.i.greg').read()
st = {}
for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(.*)$', lreg, re.M):
    r, n, l, blk, rest = int(m.group(1)), int(m.group(2)), int(m.group(3)), m.group(4), m.group(5)
    c = re.search(r'crosses (\d+) call', rest)
    st[r] = (n, l, int(c.group(1)) if c else 0, 'ptr' if 'pointer' in rest else '', 'dies2' if 'dies in' in rest else '')
order = [int(x) for x in re.search(r'regs to allocate: ([\d ]+)', greg).group(1).split()]
disp = {}
sec = greg[greg.index('Register dispositions'):]
for m in re.finditer(r'(\d+) in (\d+)', sec[:sec.index('Hard regs used')] if 'Hard regs used' in sec else sec):
    disp[int(m.group(1))] = int(m.group(2))
names = ['zero','at','v0','v1','a0','a1','a2','a3','t0','t1','t2','t3','t4','t5','t6','t7','s0','s1','s2','s3','s4','s5','s6','s7','t8','t9','k0','k1','gp','sp','fp','ra']
fnames = ['f%d' % i for i in range(32)]
def nm(h):
    if h is None: return '-'
    if h < 32: return names[h]
    if 32 <= h < 64: return 'f%d' % (h - 32)
    return str(h)
print('ord pseudo refs  len calls   prio  reg')
lim = int(sys.argv[2]) if len(sys.argv) > 2 else 999
for i, r in enumerate(order[:lim]):
    n, l, c, p, x = st.get(r, (0, 1, 0, '', ''))
    lg = int(math.log2(n)) if n > 0 else 0
    pr = lg * n / max(l, 1) * 10000
    print('%3d %5d %4d %4d %3d %7.0f  %s %s' % (i, r, n, l, c, pr, nm(disp.get(r)), p))
