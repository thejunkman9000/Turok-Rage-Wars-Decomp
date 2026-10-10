#!/usr/bin/env python3
"""exp13.py <base.c> <first_stmt_regex> <last_stmt_regex> <outdir> : do-while(0) barrier placements.
For each statement line i: (a) wrap it in do { } while (0);  (b) insert an empty do { } while (0); before it."""
import sys, re, os
base, r1, r2, outdir = sys.argv[1:5]
L = open(base, encoding='utf-8').read().split('\n')
i1 = next(i for i, l in enumerate(L) if re.search(r1, l))
i2 = next(i for i, l in enumerate(L) if i >= i1 and re.search(r2, l))
os.makedirs(outdir, exist_ok=True)
for f in os.listdir(outdir):
    if f.endswith('.c'): os.remove(os.path.join(outdir, f))
n = 0
for i in range(i1, i2 + 2):
    # (b) empty barrier before line i
    T = L[:i] + ['    do { } while (0);'] + L[i:]
    open(os.path.join(outdir, 'b%03d_empty_before_%d.c' % (n, i - i1)), 'w', newline='\n').write('\n'.join(T)); n += 1
    if i <= i2:
        s = L[i].strip()
        T = L[:i] + ['    do { ' + s + ' } while (0);'] + L[i + 1:]
        open(os.path.join(outdir, 'b%03d_wrap_%d.c' % (n, i - i1)), 'w', newline='\n').write('\n'.join(T)); n += 1
print('variants', n)
