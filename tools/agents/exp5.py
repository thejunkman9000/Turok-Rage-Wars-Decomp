#!/usr/bin/env python3
"""exp5.py: statement-move search around a base file (non-volatile world).
usage: exp5.py <base.c> <first_stmt_line_regex> <last_stmt_line_regex> <outdir> [mode]
Splits the function body lines between the first and last matching lines (inclusive) into statements (one per line) and
writes variants: every single-statement move to every other position (mode=move) or every adjacent/any swap (mode=swap)."""
import sys, re, os
base, r1, r2, outdir = sys.argv[1:5]
mode = sys.argv[5] if len(sys.argv) > 5 else 'move'
L = open(base, encoding='utf-8').read().split('\n')
i1 = next(i for i, l in enumerate(L) if re.search(r1, l))
i2 = next(i for i, l in enumerate(L) if i >= i1 and re.search(r2, l))
S = L[i1:i2 + 1]
os.makedirs(outdir, exist_ok=True)
for f in os.listdir(outdir):
    if f.endswith('.c'): os.remove(os.path.join(outdir, f))
n = 0
seen = set()
def emit(T, tag):
    global n
    key = '\n'.join(T)
    if key in seen: return
    seen.add(key)
    txt = '\n'.join(L[:i1] + T + L[i2 + 1:])
    open(os.path.join(outdir, 'm%04d_%s.c' % (n, tag)), 'w', encoding='utf-8', newline='\n').write(txt)
    n += 1
seen.add('\n'.join(S))
for i in range(len(S)):
    for j in range(len(S)):
        if i == j: continue
        if mode == 'move':
            T = S[:i] + S[i + 1:]
            T.insert(j, S[i])
            emit(T, '%d_to_%d' % (i, j))
        else:
            T = list(S); T[i], T[j] = T[j], T[i]
            if i < j: emit(T, 'sw_%d_%d' % (i, j))
print('statements', len(S), 'variants', n)
