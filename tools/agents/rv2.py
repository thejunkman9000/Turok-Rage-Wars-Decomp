#!/usr/bin/env python3
"""rv2.py <spec.py> : like rv.py but ranks variants by ALIGNED diff (structural*3+operand). Run in WSL from the workspace root."""
import sys, os, subprocess, shutil
sys.path.insert(0, '/mnt/d/Projects/ws/s702/tools')
spec = {}
exec(open(sys.argv[1]).read(), spec)
import adlib
base = open(spec['BASE']).read()
os.makedirs('wip/_rv', exist_ok=True)
files = []
for i, v in enumerate(spec['VARS']):
    if isinstance(v, dict): t = open(v['full']).read()
    else:
        t = base; ok = True
        for o, n in v:
            if o not in t: print('variant', i, 'missing', repr(o[:50])); ok = False; break
            t = t.replace(o, n, 1)
        if not ok: continue
    p = f'wip/_rv/w{i}.c'; open(p, 'w').write(t); files.append((i, p))
open('wip/_rv/list2.txt', 'w').write(''.join(f"{p} {spec['FN']} {spec['ROM']} {spec['FLAGS']}\n" for i, p in files))
subprocess.run(['bash', 'tools/fk.sh', 'wip/_rv/list2.txt'], capture_output=True)
flags = spec['FLAGS'].split()
res = []
for i, p in files:
    ns, no, out = adlib.adiff(p, spec['FN'], int(spec['ROM'], 16), flags)
    res.append((ns*3+no if ns is not None else 10**6, i, ns, no, out))
res.sort()
for sc, i, ns, no, out in res[:int(os.environ.get('TOP', 12))]:
    print(f'v{i}: structural={ns} operand={no}')
if os.environ.get('SHOW') and res:
    print('\n'.join(res[0][4]))
