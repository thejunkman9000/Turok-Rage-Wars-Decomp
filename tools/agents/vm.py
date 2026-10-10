#!/usr/bin/env python3
"""usage: python tools/vm.py <variants.txt> <fn> <rom> [flags...]   variants separated by lines starting with //====
writes wip/vx_N.c, runs the aligned-diff metric (sbsm) once for all, prints sorted (structural*10+operand).
env TARGET_N passes through; env WIN=lo,hi restricts the ranking to ROM insn window [lo,hi] (window structural*10+window operand first).
Best -> wip/vm_best.c"""
import sys, subprocess, re, os
vf, fn, rom = sys.argv[1:4]
flags = sys.argv[4:] or ['@SN']
txt = open(vf, encoding='utf-8').read()
parts = re.split(r'^//====.*\n', txt, flags=re.M)
parts = [p for p in parts if p.strip()]
for f in os.listdir('wip'):
    if f.startswith('vx_') and f.endswith('.c'):
        os.remove('wip/' + f)
lines = []
for i, p in enumerate(parts):
    open(f'wip/vx_{i}.c', 'w', encoding='utf-8', newline='\n').write(p)
    lines.append(f'wip/vx_{i}.c {fn} {rom} ' + ' '.join(flags))
open('wip/_vlist.txt', 'w').write('\n'.join(lines) + '\n')
env = dict(os.environ, MSYS_NO_PATHCONV='1')
pre = ''
for k in ('TARGET_N', 'WIN'):
    if os.environ.get(k):
        pre += f'{k}={os.environ[k]} '
cmd = ['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', pre + 'bash /mnt/d/Projects/ws/s706/go2.sh sbsm wip/_vlist.txt']
r = subprocess.run(cmd, capture_output=True, text=True, env=env)
res = []
i = 0
PAT = re.compile(r'structural=(\d+) operand=(\d+) ours=\d+ rom=\d+ firststruct=(\d+) firstop=(\d+) winstruct=(\d+) winop=(\d+)')
for l in r.stdout.splitlines():
    m = PAT.search(l)
    if m:
        res.append((i,) + tuple(int(x) for x in m.groups()))
        i += 1
    elif 'FAIL' in l or 'NOTFOUND' in l:
        res.append((i, 9999, 9999, 0, 0, 9999, 9999))
        i += 1
if os.environ.get('WIN'):
    res.sort(key=lambda x: (x[5] * 10 + x[6], x[1] * 10 + x[2]))
else:
    res.sort(key=lambda x: x[1] * 10 + x[2])
for x in res[:25]:
    print(f'v{x[0]}: structural={x[1]} operand={x[2]} first={min(x[3], x[4])} win=({x[5]},{x[6]})')
if res and res[0][1] < 9999:
    open('wip/vm_best.c', 'w', encoding='utf-8', newline='\n').write(open(f'wip/vx_{res[0][0]}.c', encoding='utf-8').read())
print('variants:', len(parts))
