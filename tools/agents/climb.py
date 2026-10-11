#!/usr/bin/env python
"""climb.py (Windows python): greedy hill climbing over statement order, driven by tools/vb.py in WSL.
usage: climb.py <file.c> <first_line> <last_line> [--rounds N] [--jobs N] [--rom 0x366D0] [--fn func_00235AD0] [--flags "@SN"] [--out wip/c/climb_best.c]
Moves: move one statement to another position (one statement per line).  Metric: structural*3+operand (vb.py), exact wins."""
import sys, os, re, subprocess, shutil
a = sys.argv[1:]
def opt(name, default=None):
    if name in a:
        k = a.index(name); v = a[k+1]; del a[k:k+2]; return v
    return default
rom = opt('--rom', '0x366D0'); fn = opt('--fn', 'func_00235AD0'); flags = opt('--flags', '@SN')
jobs = opt('--jobs', '4'); movers = opt('-m'); rounds = int(opt('--rounds', '20')); out = opt('--out', 'wip/c/climb_best.c')
src, lo, hi = a[0], int(a[1]), int(a[2])
lines = open(src, encoding='utf-8').read().split('\n')
mv = [int(x) for x in movers.split(',')] if movers else None
env = dict(os.environ, MSYS_NO_PATHCONV='1')
def evaluate(files):
    cmd = f'cd /mnt/d/Projects/ws/s905 && python3 tools/vb.py {fn} {rom} --flags "{flags}" --jobs {jobs} --top 100000 --dir wip/cl 2>&1 | grep -v Warning'
    r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=env)
    res = {}
    for l in r.stdout.splitlines():
        m = re.match(r'.*/(v\d+)\.c: structural=(\d+) operand=(\d+) exact=(\d)', l)
        if m: res[m.group(1)] = (int(m.group(2)), int(m.group(3)), int(m.group(4)))
    return res
def score(t): return (0 if t[2] else 1, t[0]*3 + t[1])
cur = lines
base = None
for rd in range(rounds):
    blk = cur[lo-1:hi]; n = len(blk)
    vs = []; seen = {'\n'.join(cur)}
    for i in range(n):
        if mv and (i + lo) not in mv: continue
        for j in range(n):
            if i == j: continue
            nb = blk[:]; x = nb.pop(i); nb.insert(j, x)
            L = cur[:lo-1] + nb + cur[hi:]
            key = '\n'.join(L)
            if key in seen: continue
            seen.add(key); vs.append((f'move {i+lo}->{j+lo}', L))
    if os.path.isdir('wip/cl'): shutil.rmtree('wip/cl')
    os.makedirs('wip/cl')
    # include current as v0
    open('wip/cl/v0000.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(cur))
    for k, (d, L) in enumerate(vs, 1):
        open(f'wip/cl/v{k:04d}.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(L))
    res = evaluate(None)
    if 'v0000' not in res: print('base failed'); break
    b = res['v0000']
    best = min(res.items(), key=lambda kv: score(kv[1]))
    print(f'round {rd}: base s={b[0]} o={b[1]} ; best {best[0]} s={best[1][0]} o={best[1][1]} exact={best[1][2]} ({len(vs)} variants)', flush=True)
    if score(best[1]) >= score(b):
        print('no improvement'); break
    k = int(best[0][1:])
    cur = vs[k-1][1]
    print('  adopted', vs[k-1][0], flush=True)
    open(out, 'w', encoding='utf-8', newline='\n').write('\n'.join(cur))
    if best[1][2]: print('EXACT'); break
print('final written to', out)
