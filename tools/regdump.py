#!/usr/bin/env python3
"""regdump.py <dumpdir> <pseudo> [<pseudo> ...] : what GCC 2.8.1's allocators did with pseudos, from the .lreg/.greg dumps made by tools/dumpl.sh.
For every pseudo: the usage line of the local-alloc dump, its position in the global-alloc order (the 'regs to allocate' list is sorted by priority),
the hard register it got, and its conflict list split into pseudos and hard registers (a pseudo takes the lowest-numbered register that none of its
hard-register conflicts and none of the already allocated conflicting pseudos occupy)."""
import glob, re, sys
d = sys.argv[1]
def rd(ext):
    f = glob.glob(d + '/*.' + ext)
    return open(f[0], errors='replace').read() if f else ''
lreg, greg = rd('lreg'), rd('greg')
order = []
m = re.search(r';; \d+ regs to allocate: ([\d ]+)', greg)
if m: order = [int(x) for x in m.group(1).split()]
disp = {}
for m in re.finditer(r'(\d+) in (\d+)', greg[greg.find(';; Register dispositions'):][:60000]):
    disp.setdefault(int(m.group(1)), int(m.group(2)))
conf = {}
for m in re.finditer(r'^;; (\d+) conflicts: ([\d ]+)', greg, re.M):
    conf[int(m.group(1))] = [int(x) for x in m.group(2).split()]
for a in sys.argv[2:]:
    r = int(a)
    u = re.search(r'^Register %d used[^\n]*' % r, lreg, re.M)
    print('pseudo %d: %s' % (r, u.group(0) if u else '(no lreg line)'))
    print('   global order #%s of %d   hard reg: %s' % (order.index(r) + 1 if r in order else '-', len(order), disp.get(r, 'none')))
    c = conf.get(r)
    if c is None: print('   (no conflict line)'); continue
    ps = [x for x in c if x >= 80]; hs = [x for x in c if x < 80]
    print('   conflicts with hard regs %s' % hs)
    print('   conflicting pseudos (reg): ' + ' '.join('%d(%s)' % (x, disp.get(x, '?')) for x in ps))
