#!/usr/bin/env python
"""sub.py in.c out.c 'old=>new' ['old2=>new2' ...]   (use @NL@ for newline in args; each old must occur)"""
import sys
src = open(sys.argv[1], encoding='utf-8').read()
for rep in sys.argv[3:]:
    o, n = rep.split('=>', 1)
    o = o.replace('@NL@', '\n'); n = n.replace('@NL@', '\n')
    if o not in src:
        print('MISSING:', repr(o[:60])); sys.exit(1)
    src = src.replace(o, n, 1)
open(sys.argv[2], 'w', encoding='utf-8', newline='\n').write(src)
