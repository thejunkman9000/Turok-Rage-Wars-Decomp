#!/usr/bin/env python3
"""Collect behaviour-level C for every function that has no matching C in src/: parked group objects (wip/groups) and the
workers' best PARTIAL/NONE drafts (D:/Projects/ws/*/wip/hard).  Copies them to port/nonmatching/ (one file per source).
For the port they only need to be functionally right, not byte-identical.   usage: python port/collect_nonmatching.py"""
import glob, os, re, shutil
man = set()
for m in ('funcs.txt', 'funcs_a.txt'):
    for l in open(m):
        f = l.split('#')[0].split()
        if len(f) >= 4 and not f[0].startswith('pad_'): man.add(f[0])
absorbed = set(open('wip/absorbed.txt').read().split())
fs = [l.split() for l in open('docs/game_funcs.txt') if not l.startswith('#')]
missing = [f[1] for f in fs if f[1] not in man and f[1] not in absorbed]
# parked group objects count as "missing" too (their per-function entries were removed from the manifest)
missing = sorted(set(missing))
cands = {}
order = {'b': 0, 'p': 0, 'm': 1, 'o': 1, 'q': 2, 'r': 3}
def rank(path):
    ws = re.search(r'/ws/(\w+)/', path.replace(chr(92), '/'))
    w = ws.group(1)[0] if ws else 'x'
    return (order.get(w, 0), 0 if '.prev' not in path else -1, os.path.getmtime(path))
files = glob.glob('D:/Projects/ws/*/wip/hard/func_*.c') + glob.glob('wip/groups/func_*.c')
defs = {}
for p in files:
    txt = open(p, errors='replace').read()
    for n in re.findall(r'^[A-Za-z_][^;{}()=]*[ *](func_[0-9A-F]{8})\s*\([^;{}]*\)\s*\{', txt, re.M):
        defs.setdefault(n, []).append(p)
chosen = {}
for n in missing:
    ps = defs.get(n, [])
    if not ps: continue
    # prefer parked group files (EXACT per function), then the newest draft
    g = [p for p in ps if p.replace(chr(92), '/').startswith('wip/groups/')]
    chosen[n] = g[0] if g else max(ps, key=rank)
os.makedirs('port/nonmatching', exist_ok=True)
for f in glob.glob('port/nonmatching/*.c'): os.remove(f)
used = {}
for n, p in chosen.items():
    used.setdefault(p, []).append(n)
for i, (p, ns) in enumerate(sorted(used.items(), key=lambda kv: kv[1][0])):
    shutil.copy(p, f'port/nonmatching/{ns[0]}__{i}.c')
print('missing functions:', len(missing), ' with a draft:', len(chosen), ' source files:', len(used))
