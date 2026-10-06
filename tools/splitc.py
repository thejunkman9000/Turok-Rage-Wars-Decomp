#!/usr/bin/env python3
"""Split a multi-function C file into one file per function (preamble + function): python tools/splitc.py <file.c> <outdir>"""
import re, sys, os
src = open(sys.argv[1], encoding='utf-8').read().split('\n')
out = sys.argv[2]
os.makedirs(out, exist_ok=True)
pre, chunks, cur, infn = [], [], [], False
for l in src:
    if not infn and re.match(r'^[A-Za-z_][^;]*\(.*\)\s*\{\s*$', l):
        infn = True; cur = [l]; continue
    if infn:
        cur.append(l)
        if l == '}':
            chunks.append(cur); infn = False; cur = []
        continue
    pre.append(l)
for c in chunks:
    m = re.search(r'(\w+)\s*\(', c[0])
    name = m.group(1)
    open(os.path.join(out, name + '.c'), 'w', newline='\n').write('\n'.join(pre).rstrip('\n') + '\n\n' + '\n'.join(c) + '\n')
    print(name)
