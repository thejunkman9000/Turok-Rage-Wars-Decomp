#!/usr/bin/env python3
"""adall.py <listfile> : aligned diff (structural, operand) for every line of a chk list"""
import sys, os
sys.path.insert(0, '/mnt/d/Projects/ws/s702/tools')
import adlib
for l in open(sys.argv[1]):
    f = l.split('#')[0].split()
    if len(f) < 3: continue
    p, fn, rom = f[0], f[1], int(f[2], 16)
    fl = f[3:] or ['@SN']
    if fn in ('func_0024E2E4',): continue
    try:
        ns, no, out = adlib.adiff(p, fn, rom, fl)
    except Exception as e:
        ns = no = None; out = [str(e)[:60]]
    print(f'{p:60s} {fn} struct={ns} oper={no}')
