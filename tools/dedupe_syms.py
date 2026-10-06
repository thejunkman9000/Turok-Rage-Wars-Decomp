#!/usr/bin/env python3
"""Drop duplicate names / duplicate addresses from symbol_addrs.txt (splat refuses to read such a file) and make sure
the file ends with a newline.  usage: python tools/dedupe_syms.py"""
import re

lines = open('symbol_addrs.txt', encoding='utf-8').read().split('\n')
names, addrs, out = set(), set(), []
for l in lines:
    m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;', l)
    if m:
        n, a = m.group(1), int(m.group(2), 16)
        if n in names or a in addrs:
            print('dropped', l)
            continue
        names.add(n)
        addrs.add(a)
    if l.strip() or out:
        out.append(l)
while out and not out[-1].strip():
    out.pop()
open('symbol_addrs.txt', 'w', encoding='utf-8', newline='\n').write('\n'.join(out) + '\n')
