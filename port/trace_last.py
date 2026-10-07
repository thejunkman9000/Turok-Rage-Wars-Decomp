#!/usr/bin/env python3
"""symbolize the call trace printed after 'game thread exception' in port_log.txt (last 14 distinct functions)"""
import sys
exec(open('port/where.py').read().split('seen = set()')[0])
L = open('port_log.txt', errors='replace').read().split('\n')
for i, l in enumerate(L):
    if 'game thread exception' in l and i + 1 < len(L):
        out = []
        for it in L[i + 1].split(':', 1)[1].split():
            t, r = it.split(':'); nm = where(int(r, 16)).split('+')[0].lstrip('_')
            if not out or out[-1] != nm: out.append(nm)
        print(' > '.join(out[-int(sys.argv[1] if len(sys.argv)>1 else 14):])); break
