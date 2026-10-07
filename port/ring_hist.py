#!/usr/bin/env python3
"""histogram of the function entries in the last 'trace (oldest first)' ring dump of port_log.txt"""
import sys, collections
exec(open('port/where.py').read().split('seen = set()')[0])
tr = [l for l in open('port_log.txt', errors='replace') if l.strip().startswith('trace (oldest first):')]
c = collections.Counter(); per = collections.defaultdict(collections.Counter)
for it in tr[-1].split(':', 1)[1].split():
    t, r = it.split(':'); nm = where(int(r, 16)).split('+')[0].lstrip('_'); c[nm] += 1; per[t][nm] += 1
for t, cc in per.items(): print('thread', t, sum(cc.values()), ' '.join(f'{n}:{k}' for n, k in cc.most_common(int(sys.argv[1]) if len(sys.argv) > 1 else 25)))
