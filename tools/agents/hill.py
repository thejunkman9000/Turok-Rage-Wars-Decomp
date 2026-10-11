#!/usr/bin/env python
"""hill.py (Windows python): generic greedy hill climber over source mutations, scored by tools/vb.py (aligned metric) in WSL.
usage: hill.py <file.c> [--lo N --hi M] [--muts move,declswap,commute,types,dowhile] [--rounds N] [--jobs N] [--out FILE] [--rom 0x366D0] [--fn func_00235AD0]
 move     : move one statement line (lines lo..hi, one statement per line) to another position
 declswap : swap two adjacent local declaration lines (lines of the form 'T a, b;' / 'T a;' between 'func(...) {' and first statement)
 commute  : swap operands of a+b / a*b where both are simple operands (identifier, o->x, number)
 types    : toggle s16 <-> s32 on one local declaration
 dowhile  : wrap one statement line (inside lo..hi) in do { } while (0);
Score = (not exact, structural*3+operand)."""
import sys, os, re, subprocess, shutil
a = sys.argv[1:]
def opt(name, default=None):
    if name in a:
        k = a.index(name); v = a[k+1]; del a[k:k+2]; return v
    return default
rom = opt('--rom', '0x366D0'); fn = opt('--fn', 'func_00235AD0'); flags = opt('--flags', '@SN')
jobs = opt('--jobs', '4'); rounds = int(opt('--rounds', '30')); out = opt('--out', 'wip/c/hill_best.c')
lo = int(opt('--lo', '0')); hi = int(opt('--hi', '0')); muts = opt('--muts', 'move').split(',')
movers = opt('-m'); mv = [int(x) for x in movers.split(',')] if movers else None
src = a[0]
cur = open(src, encoding='utf-8').read().split('\n')
env = dict(os.environ, MSYS_NO_PATHCONV='1')
def evaluate():
    cmd = f'cd /mnt/d/Projects/ws/s905 && python3 tools/vb.py {fn} {rom} --flags "{flags}" --jobs {jobs} --top 100000 --dir wip/cl 2>&1 | grep -v Warning'
    r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=env)
    res = {}
    for l in r.stdout.splitlines():
        m = re.match(r'.*/(v\d+)\.c: structural=(\d+) operand=(\d+) exact=(\d)', l)
        if m: res[m.group(1)] = (int(m.group(2)), int(m.group(3)), int(m.group(4)))
    return res
def score(t): return (0 if t[2] else 1, t[0]*3 + t[1])
def gen(cur):
    vs = []
    seen = {'\n'.join(cur)}
    def add(desc, L):
        k = '\n'.join(L)
        if k in seen: return
        seen.add(k); vs.append((desc, L))
    if 'move' in muts and hi:
        blk = cur[lo-1:hi]; n = len(blk)
        for i in range(n):
            if mv and (i + lo) not in mv: continue
            for j in range(n):
                if i == j: continue
                nb = blk[:]; x = nb.pop(i); nb.insert(j, x)
                add(f'move {i+lo}->{j+lo}', cur[:lo-1] + nb + cur[hi:])
    if 'dowhile' in muts and hi:
        for i in range(lo-1, hi):
            l = cur[i]
            if l.strip().endswith(';') and not l.strip().startswith(('if', 'else', 'for', 'while', 'return', '}', 'do')) and 'do {' not in l:
                ind = re.match(r'\s*', l).group(0)
                L = cur[:]; L[i] = f'{ind}do {{ {l.strip()} }} while (0);'
                add(f'dowhile {i+1}', L)
    # find declaration lines: between first '{' line of function and first statement
    if 'declswap' in muts:
        decl = [i for i, l in enumerate(cur) if re.match(r'\s+(s16|s32|u32|u8|f32|S9View|struct)\b.*;\s*$', l) and i < (hi or 60)]
        # adjacent declaration lines
        for i, j in zip(decl, decl[1:]):
            if j == i + 1:
                L = cur[:]; L[i], L[j] = L[j], L[i]; add(f'declswap {i+1}', L)
        # swap names inside a comma declaration
        for i in decl:
            m = re.match(r'(\s+)(s16|s32|u32|f32)\s+([^;]*,[^;]*);\s*$', cur[i])
            if m:
                names = [x.strip() for x in m.group(3).split(',')]
                for k in range(len(names)-1):
                    nn = names[:]; nn[k], nn[k+1] = nn[k+1], nn[k]
                    L = cur[:]; L[i] = f'{m.group(1)}{m.group(2)} ' + ', '.join(nn) + ';'
                    add(f'namesswap {i+1}:{k}', L)
    if 'types' in muts:
        for i, l in enumerate(cur):
            if i >= (hi or 60): break
            m = re.match(r'(\s+)(s16|s32)\s+([^;]*);\s*$', l)
            if m and ',' in m.group(3) and 'func' not in l:
                # split off one variable toggled type
                names = [x.strip() for x in m.group(3).split(',')]
                for k, nm in enumerate(names):
                    other = 's32' if m.group(2) == 's16' else 's16'
                    rest = [x for q, x in enumerate(names) if q != k]
                    L = cur[:]
                    L[i] = f'{m.group(1)}{m.group(2)} ' + ', '.join(rest) + f';\n{m.group(1)}{other} {nm};'
                    add(f'type {nm}->{other}', L)
    if 'commute' in muts and hi:
        pat = re.compile(r'\b((?:o->)?[A-Za-z_]\w*|\d+\.\d+f)\s*([+*])\s*((?:o->)?[A-Za-z_]\w*|\d+\.\d+f)\b')
        for i in range(lo-1, hi):
            l = cur[i]
            for m in pat.finditer(l):
                if '(' in l[:m.start()] and l[:m.start()].rstrip().endswith('('): pass
                s = l[:m.start()] + m.group(3) + ' ' + m.group(2) + ' ' + m.group(1) + l[m.end():]
                L = cur[:]; L[i] = s; add(f'commute {i+1}@{m.start()}', L)
    return vs
best_desc = []
for rd in range(rounds):
    vs = gen(cur)
    if os.path.isdir('wip/cl'): shutil.rmtree('wip/cl')
    os.makedirs('wip/cl')
    open('wip/cl/v0000.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(cur))
    for k, (d, L) in enumerate(vs, 1):
        open(f'wip/cl/v{k:04d}.c', 'w', encoding='utf-8', newline='\n').write('\n'.join(L))
    res = evaluate()
    if 'v0000' not in res: print('base failed'); break
    b = res['v0000']
    bestk = min(res.items(), key=lambda kv: score(kv[1]))
    print(f'round {rd}: base s={b[0]} o={b[1]} ; best {bestk[0]} s={bestk[1][0]} o={bestk[1][1]} exact={bestk[1][2]} ({len(vs)} variants)', flush=True)
    if score(bestk[1]) >= score(b):
        print('no improvement'); break
    k = int(bestk[0][1:]); cur = vs[k-1][1]
    print('  adopted', vs[k-1][0], flush=True)
    open(out, 'w', encoding='utf-8', newline='\n').write('\n'.join(cur))
    if bestk[1][2]: print('EXACT'); break
print('final in', out)
