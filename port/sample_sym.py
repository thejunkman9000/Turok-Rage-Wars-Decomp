#!/usr/bin/env python3
"""symbolize the last 'sample:' line of port_log.txt (TUROK_SAMPLE=1): per thread, the module return addresses found on its stack"""
import re, sys
exec(open('port/where.py').read().split('seen = set()')[0])
L = [l for l in open('port_log.txt', errors='replace') if l.startswith('sample:')]
for grp in re.findall(r'\[([^\]]*)\]', L[int(sys.argv[1]) if len(sys.argv) > 1 else -1]):
    f = grp.split()
    names = []
    for r in f[1:]:
        n = where(int(r, 16)).split('+')[0].lstrip('_')
        if not names or names[-1] != n: names.append(n)
    if names: print(f[0], ' < '.join(names))
