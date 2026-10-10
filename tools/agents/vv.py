#!/usr/bin/env python3
"""usage: python tools/vv.py <variants.txt> <fn> <rom> [flags...]   variants separated by lines starting with //====
writes wip/vx_N.c, runs chk (sn if flags empty->@SN), prints sorted results"""
import sys, subprocess, re, os
vf, fn, rom = sys.argv[1:4]
flags = sys.argv[4:] or ['@SN']
txt = open(vf, encoding='utf-8').read()
parts = re.split(r'^//====.*\n', txt, flags=re.M)
parts = [p for p in parts if p.strip()]
lines = []
for i, p in enumerate(parts):
    open(f'wip/vx_{i}.c', 'w', encoding='utf-8', newline='\n').write(p)
    lines.append(f'wip/vx_{i}.c {fn} {rom} ' + ' '.join(flags))
open('wip/_vlist.txt', 'w').write('\n'.join(lines) + '\n')
env = dict(os.environ, MSYS_NO_PATHCONV='1')
r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '/mnt/d/Projects/ws/s706/go.sh', 'chk', 'wip/_vlist.txt'], capture_output=True, text=True, env=env)
out = r.stdout.splitlines()
res = []
i = 0
for l in out:
    m = re.match(r'(\S+)\s+(\d+) insns\s+(.*)', l)
    if m:
        res.append((i, m.group(3), m.group(2))); i += 1
    elif 'FAIL' in l or 'not found' in l:
        res.append((i, l.strip()[:150], '0')); i += 1
def key(x):
    m = re.search(r'score=(\d+)', x[1])
    if x[1].startswith('EXACT'): return -1
    return int(m.group(1)) if m else 9999
for x in sorted(res, key=key):
    print(x[0], x[1])
print('(variants: %d)' % len(parts))
