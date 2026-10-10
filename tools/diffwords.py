#!/usr/bin/env python3
"""run in WSL: python3 tools/diffwords.py [limit]  -> first differing words between ~/trw/build/turok_ragewars.z64 and the base ROM"""
import os, sys
a = open(os.path.expanduser('~/trw/build/turok_ragewars.z64'), 'rb').read()
b = open('/mnt/d/Projects/TurokRageWars/baserom.us.v11.z64', 'rb').read()
lim = int(sys.argv[1]) if len(sys.argv) > 1 else 20
d = [i for i in range(0, min(len(a), len(b)), 4) if a[i:i + 4] != b[i:i + 4]]
print(len(a), len(b), 'differing words', len(d))
prev = None
for i in d[:lim]:
    print(hex(i), 'ours', a[i:i + 4].hex(), 'rom', b[i:i + 4].hex())
