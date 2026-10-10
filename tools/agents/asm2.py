#!/usr/bin/env python3
"""asm2.py <fn> ... : print asm of function (glabel or alabel), until next glabel/alabel/endlabel; shows ROM/VRAM address columns"""
import re, sys, glob
want = set(sys.argv[1:])
for p in sorted(glob.glob('asm/*.s')):
    out = False
    for l in open(p, encoding='utf-8'):
        m = re.match(r'\s*[ga]label (\S+)', l)
        if m:
            out = m.group(1) in want
            if out: print('===', m.group(1))
            continue
        if l.startswith('endlabel'):
            out = False; continue
        if out and re.match(r'\s*(/\*|\.L|\w)', l) and not l.startswith('.'):
            print(re.sub(r'/\*\s*([0-9A-F]+)\s+([0-9A-F]{8})\s+[0-9A-F]{8}\s*\*/\s*', r'\2 ', l.rstrip()))
