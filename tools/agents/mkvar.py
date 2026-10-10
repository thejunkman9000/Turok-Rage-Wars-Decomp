#!/usr/bin/env python3
"""mkvar.py <base.c> <out.c> 'old=>new' ['old2=>new2' ...] : text-replace.
Each pattern must match exactly once unless prefixed with '*'.  The token @NL@ in a pattern means a newline."""
import sys
src = open(sys.argv[1], encoding='utf-8').read()
for spec in sys.argv[3:]:
    allr = spec.startswith('*')
    if allr:
        spec = spec[1:]
    old, new = spec.split('=>', 1)
    old = old.replace('@NL@', '\n')
    new = new.replace('@NL@', '\n')
    n = src.count(old)
    if n == 0 or (n > 1 and not allr):
        print('MATCH COUNT', n, 'for', repr(old))
        sys.exit(1)
    src = src.replace(old, new)
open(sys.argv[2], 'w', encoding='utf-8', newline='\n').write(src)
