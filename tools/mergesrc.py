#!/usr/bin/env python3
"""Concatenate worker C sources into one translation unit (functions of one original object, in ROM order).

usage: python tools/mergesrc.py <out.c> <a.c> <b.c> ...
`#include` lines that repeat are kept once; everything else is copied as is (a duplicate typedef / extern with a different type is a compile error to fix by hand).
A source starting with the `/* their2` marker keeps it in the first line of the output (the build then uses include/their2)."""
import sys
out, srcs = sys.argv[1], sys.argv[2:]
seen = set(); lines = []
their2 = False
for s in srcs:
    t = open(s, errors='replace', newline='').read().replace('\r\n', '\n')
    if 'their2' in '\n'.join(t.split('\n')[:3]): their2 = True
    lines.append('/* ---- merged from %s ---- */' % s.replace('\\', '/').split('/')[-1])
    for l in t.split('\n'):
        if l.startswith('#include'):
            if l in seen: continue
            seen.add(l)
        if l.startswith('/* their2'): continue
        lines.append(l)
body = '\n'.join(lines)
if their2: body = '/* their2: merged span */\n' + body
open(out, 'w', newline='\n').write(body + '\n')
print('wrote', out, len(body.split('\n')), 'lines')
