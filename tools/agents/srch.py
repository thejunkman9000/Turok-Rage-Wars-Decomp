#!/usr/bin/env python
"""srch.py (Windows python): statement-move search driver on top of tools/vb.py (WSL).
usage: srch.py <file.c> <first_line> <last_line> [-m i,j,..] [--swap] [--jobs N] [--top N] [--rom 0x366D0] [--fn func_00235AD0] [--flags "@SN"]
Each line in [first,last] is one statement.  Variants: move statement i to every other position (or swap pairs with --swap).
Best variant -> wip/vb_best.c (copy it yourself)."""
import sys, os, re, subprocess, shutil
a = sys.argv[1:]
def opt(name, default=None, flag=False):
    if name in a:
        k = a.index(name)
        if flag:
            a.pop(k); return True
        v = a[k+1]; del a[k:k+2]; return v
    return default
rom = opt('--rom', '0x366D0'); fn = opt('--fn', 'func_00235AD0'); flags = opt('--flags', '@SN')
jobs = opt('--jobs', '4'); top = opt('--top', '15'); movers = opt('-m'); swap = opt('--swap', None, True)
src, lo, hi = a[0], int(a[1]), int(a[2])
lines = open(src, encoding='utf-8').read().split('\n')
blk = lines[lo-1:hi]; n = len(blk)
mv = None
if movers: mv = [int(x) for x in movers.split(',')]
vars_ = []; seen = set()
def add(nb, desc):
    key = '\n'.join(nb)
    if key in seen: return
    seen.add(key); vars_.append((desc, lines[:lo-1] + nb + lines[hi:]))
for i in range(n):
    if mv and (i + lo) not in mv: continue
    for j in range(n):
        if i == j: continue
        if swap:
            if j < i: continue
            nb = blk[:]; nb[i], nb[j] = nb[j], nb[i]; add(nb, f'swap {i+lo}<->{j+lo}')
        else:
            nb = blk[:]; x = nb.pop(i); nb.insert(j, x); add(nb, f'move {i+lo}->{j+lo}')
d = 'wip/sr'
if os.path.isdir(d): shutil.rmtree(d)
os.makedirs(d)
for k, (desc, L) in enumerate(vars_):
    open(f'{d}/v{k:04d}.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(L))
env = dict(os.environ, MSYS_NO_PATHCONV='1')
cmd = f'cd /mnt/d/Projects/ws/s905 && python3 tools/vb.py {fn} {rom} --flags "{flags}" --jobs {jobs} --top {top} --dir {d} 2>&1 | grep -v Warning'
r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=env)
out = r.stdout
for l in out.splitlines():
    m = re.match(r'(\S*/v(\d+)\.c): (.*)', l)
    if m: print(f'{l}   [{vars_[int(m.group(2))][0]}]')
    else: print(l)
print('variants:', len(vars_))
