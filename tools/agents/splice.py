#!/usr/bin/env python3
"""splice.py <work.c> <perm output source.c> <fn> <out.c>: replace fn's definition in work.c by the one in the permuter output"""
import sys,re
def grab(src,fn):
    m=None
    for m in re.finditer(r'(?m)^[A-Za-z_][^;{}\n]*\b'+fn+r'\s*\([^;{]*\)\s*\{',src): pass
    if not m: raise SystemExit('fn not found')
    i=src.index('{',m.start()+len(m.group(0))-1)
    d=0;j=i
    while True:
        if src[j]=='{': d+=1
        elif src[j]=='}':
            d-=1
            if d==0: break
        j+=1
    return m.start(),j+1
w=open(sys.argv[1]).read(); p=open(sys.argv[2]).read(); fn=sys.argv[3]
a,b=grab(w,fn); c,d=grab(p,fn)
open(sys.argv[4],'w').write(w[:a]+p[c:d]+w[b:])
