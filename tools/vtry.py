#!/usr/bin/env python3
"""Try source variants of one function against the ROM and rank them.

usage: python tools/vtry.py <template.c> <function> <rom_hex> <variants.json> [--max N] [--keep]

The template contains placeholders `@@name@@`; variants.json maps each name to a list of alternative snippets
(strings). All combinations (capped by --max, default 150, sampled evenly) are written to wip/_v_<i>.c, checked
with tools/chk.ps1 (WSL) and printed best first as  <differing words>  <combination>.  `--keep` keeps the best file.
"""
import itertools, json, os, random, re, subprocess, sys

args = sys.argv[1:]
cap = 150
keep = False
if '--max' in args:
    i = args.index('--max'); cap = int(args[i + 1]); del args[i:i + 2]
if '--keep' in args:
    keep = True; args.remove('--keep')
template, func, rom, vfile = args[:4]
variants = json.load(open(vfile))
names = list(variants)
text = open(template, encoding='utf-8').read()
combos = list(itertools.product(*[range(len(variants[n])) for n in names]))
if len(combos) > cap:
    random.seed(1)
    combos = random.sample(combos, cap)
os.makedirs('wip', exist_ok=True)
lines = []
for k, combo in enumerate(combos):
    t = text
    for n, ci in zip(names, combo):
        t = t.replace(f'@@{n}@@', variants[n][ci])
    fn = f'wip/_v_{k}.c'
    open(fn, 'w', encoding='utf-8', newline='\n').write(t)
    lines.append(f'{fn} {func} {rom}')
open('wip_list.txt', 'w', newline='\n').write('\n'.join(lines) + '\n')
r = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/chk.ps1', 'wip_list.txt'], capture_output=True, text=True)
res = []
cur = None
for l in r.stdout.split('\n'):
    if l.startswith(func + ' ') or l.startswith(func.ljust(28)):
        m = re.search(r'(\d+) words differ', l)
        cur = [0 if 'EXACT' in l else (int(m.group(1)) if m else 10**6), 10**6 if 'EXACT' in l else -1, l.strip()]
        res.append(cur)
    elif cur is not None and cur[1] == -1:
        m = re.match(r'\s+\[(\d+)\]', l)
        if m:
            cur[1] = int(m.group(1))
if len(res) != len(combos):
    print(r.stdout[-2000:])
    sys.exit(f'result count {len(res)} != {len(combos)}')
order = sorted(range(len(combos)), key=lambda i: (-res[i][1], res[i][0]))
for i in order[:8]:
    print('first diff', res[i][1], 'words', res[i][0], [variants[n][ci][:40] for n, ci in zip(names, combos[i])])
best = order[0]
print('best file: wip/_v_%d.c  (%s)' % (best, res[best][2]))
if not keep:
    for k in range(len(combos)):
        if k != best:
            os.remove(f'wip/_v_{k}.c')
