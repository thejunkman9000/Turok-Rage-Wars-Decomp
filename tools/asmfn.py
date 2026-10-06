#!/usr/bin/env python3
"""Print the asm of game functions: python tools/asmfn.py func_00245840 [...]   (reads asm/entry.s and asm/16E000.s)"""
import re, sys
want = set(sys.argv[1:])
for p in ['asm/entry.s', 'asm/16E000.s']:
    out = None
    for l in open(p, encoding='utf-8'):
        m = re.match(r'glabel (\S+)', l)
        if m:
            out = m.group(1) in want
            if out: print('===', m.group(1))
            continue
        if out and re.match(r'\s*(/\*|\.L|\w)', l) and not l.startswith(('endlabel', 'nonmatching', '.')):
            print(re.sub(r'/\*\s*[0-9A-F]+\s+[0-9A-F]+\s+[0-9A-F]{8}\s*\*/\s*', '', l.rstrip()))
