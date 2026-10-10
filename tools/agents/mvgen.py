#!/usr/bin/env python3
"""Line-move variant search.  usage: mvgen.py <file.c> <fn> <rom> <first_line> <last_line> [-m i,j,...] [-- flags]
Lines are 1-based, inclusive, each line must be one complete statement.  Variants: move statement i (default all) to every other position.
Runs ONE chk call (via go.sh), prints the best variants (score).  Best is written to wip/mv_best.c."""
import sys, re, os, subprocess
args = sys.argv[1:]
flags = ['@SN']
if '--' in args:
    k = args.index('--'); flags = args[k+1:]; args = args[:k]
src, fn, rom, a, b = args[:5]; a = int(a); b = int(b)
movers = None
if '-m' in args: movers = [int(x) for x in args[args.index('-m')+1].split(',')]
lines = open(src, encoding='utf-8').read().split('\n')
blk = lines[a-1:b]
n = len(blk)
vars_ = []
seen = set()
for i in range(n):
    if movers and (i + a) not in movers: continue
    for j in range(n):
        if i == j: continue
        nb = blk[:]
        x = nb.pop(i); nb.insert(j, x)
        key = '\n'.join(nb)
        if key in seen: continue
        seen.add(key)
        vars_.append((i + a, j + a, lines[:a-1] + nb + lines[b:]))
os.makedirs('wip/mv', exist_ok=True)
for f in os.listdir('wip/mv'): os.remove('wip/mv/' + f)
lst = []
for k, (i, j, L) in enumerate(vars_):
    open(f'wip/mv/v{k}.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(L))
    lst.append(f'wip/mv/v{k}.c {fn} {rom} ' + ' '.join(flags))
open('wip/_mvlist.txt', 'w').write('\n'.join(lst) + '\n')
env = dict(os.environ, MSYS_NO_PATHCONV='1')
r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', ((f'TARGET_N={os.environ["TARGET_N"]} ') if 'TARGET_N' in os.environ else '') + 'bash /mnt/d/Projects/ws/s706/go2.sh sbsm wip/_mvlist.txt'], capture_output=True, text=True, env=env)
res = []
idx = 0
for l in r.stdout.splitlines():
    m = re.search(r'structural=(\d+) operand=(\d+)', l)
    if m:
        res.append((idx, int(m.group(1)) * 10 + int(m.group(2)), f'structural={m.group(1)} operand={m.group(2)}')); idx += 1
    elif 'FAIL' in l or 'NOTFOUND' in l:
        res.append((idx, 99999, 'COMPILE FAIL')); idx += 1
res.sort(key=lambda x: x[1])
for k, sc, txt in res[:12]:
    print(f'v{k}: move line {vars_[k][0]} -> {vars_[k][1]}: {txt}')
if res:
    open('wip/mv_best.c', 'w', encoding='utf-8').write(open(f'wip/mv/v{res[0][0]}.c', encoding='utf-8').read())
print('variants:', len(vars_))
