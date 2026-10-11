#!/usr/bin/env python3
"""tokdiff.py a.c b.c : token-level diff of the function bodies (whitespace-insensitive); prints changed regions with context"""
import sys, re, difflib
def toks(path):
    s = open(path, encoding='utf-8', errors='replace').read()
    i = s.find('func_00235AD0(S9View')
    j = s.rfind('void func_00235AD0')
    k = j if j >= 0 else i
    s = s[k:]
    return re.findall(r'[A-Za-z_]\w*|0[xX][0-9a-fA-F]+[uUlL]*|\d+\.\d*[fF]?|\d+[uUlL]*|->|<<|>>|[<>=!&|+\-*/]=|&&|\|\||\+\+|--|\S', s)
a, b = toks(sys.argv[1]), toks(sys.argv[2])
sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal': continue
    ctx = ' '.join(a[max(0, i1-6):i1])
    print(f'--- {tag}: ... {ctx} [[ {" ".join(a[i1:i2])} ]] -> [[ {" ".join(b[j1:j2])} ]]')
