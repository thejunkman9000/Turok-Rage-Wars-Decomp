#!/usr/bin/env python3
"""Symbolize every 'trace (oldest first):' line of a run log (default port/build/run.log) using port/build/turok.map.
usage: python port/where_trace.py [run.log] [--all]    (prints the last trace line only unless --all; consecutive repeats of a function are collapsed)"""
import re, sys, bisect
syms = []; base = None
for l in open('port/build/turok.map', errors='replace'):
    m = re.match(r'\s*Preferred load address is ([0-9a-f]+)', l)
    if m: base = int(m.group(1), 16)
    m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
    if m and base is not None and int(m.group(2), 16) >= base: syms.append((int(m.group(2), 16) - base, m.group(1)))
syms.sort(); keys = [s[0] for s in syms]
def where(rva):
    i = bisect.bisect_right(keys, rva) - 1
    return (syms[i][1].lstrip('_'), rva - syms[i][0]) if i >= 0 else ('?', 0)
args = [a for a in sys.argv[1:] if not a.startswith('--')]
lines = [l for l in open(args[0] if args else 'port/build/run.log', errors='replace') if l.strip().startswith('trace (oldest first):')]
for l in (lines if '--all' in sys.argv else lines[-1:]):
    out = []
    for it in l.split(':', 1)[1].split():
        t, r = it.split(':'); nm, off = where(int(r, 16) - 1)
        if out and out[-1][0] == nm: out[-1][1] += 1
        else: out.append([nm, 1])
    print('TRACE:', ' > '.join(nm + ('' if n == 1 else f'(x{n})') for nm, n in out))
