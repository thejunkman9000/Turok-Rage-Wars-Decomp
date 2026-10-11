#!/usr/bin/env python3
"""Pull melalawi/ragewars-decomp (D:/Projects/ext/ragewars-decomp) and list what it matches for US v1.1 (us-rev1) that our manifests do not cover yet.

usage: python tools/upstream_check.py [--no-fetch] [--all]
  fetches origin and fast-forwards the local copy (unless --no-fetch), reads versions/us-rev1/report.json (per-function fuzzy match %) and
  symbol_addrs.txt (their name -> us-rev1 address), and prints every function matched at 100% whose ROM range holds game functions
  (docs/game_funcs.txt) that no entry of funcs.txt / funcs_a.txt covers (3/4 of the bytes rule of tools/remaining.py).
  A line says whether the function's C source exists in their src/ (a 100% line without a source is a match they have not published).
  New names since the last run are marked `NEW` (state in wip/upstream_seen.txt); --all also lists the covered ones' count.
Meant for the hourly check-in and as the first step of every integration."""
import json, os, re, subprocess, sys
REPO = 'D:/Projects/ext/ragewars-decomp'
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

def git(*a):
    r = subprocess.run(['git', '-C', REPO] + list(a), capture_output=True, text=True)
    return (r.stdout + r.stderr).strip()

if '--no-fetch' not in sys.argv:
    print('fetch:', git('fetch', 'origin').split('\n')[-1][:120] or 'up to date')
    behind = git('rev-list', 'HEAD..origin/main', '--count')
    if behind.isdigit() and int(behind) > 0:
        print('upstream commits since our copy:', behind)
        print('merge:', git('merge', '--ff-only', 'origin/main').split('\n')[-1][:120])
print('their HEAD:', git('log', '-1', '--format=%h %ci %s')[:110])

cover = []
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 3:      # padding entries (pad_*) count: a function's size in docs/game_funcs.txt includes its trailing alignment words
            try: s = int(f[1], 16); cover.append((s, s + 4 * int(f[2])))
            except ValueError: pass
cover.sort()
def covered(a, b):
    return sum(max(0, min(b, e) - max(a, s)) for s, e in cover if s < b and e > a) * 4 >= (b - a) * 3

uni = []                                         # (va, rom, insns, name)
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) >= 3 and f[1].startswith('func_'): uni.append((int(f[1][5:], 16) | 0x80000000, int(f[0], 16), int(f[2]), f[1]))
uni.sort()

addr = {}
for l in open(REPO + '/versions/us-rev1/symbol_addrs.txt'):
    m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
    if m: addr[m.group(1)] = int(m.group(2), 16)
report = json.load(open(REPO + '/versions/us-rev1/report.json'))
seen_path = 'wip/upstream_seen.txt'
seen = set(open(seen_path).read().split()) if os.path.exists(seen_path) else set()
rows = []; nmatch = 0
for u in report['units']:
    for f in u.get('functions', []):
        if float(f.get('fuzzy_match_percent') or 0) < 99.99 or f['name'] not in addr: continue
        a = addr[f['name']]; size = int(f.get('size') or 0)
        if size <= 0: continue
        nmatch += 1
        inside = [x for x in uni if a <= x[0] < a + size]
        open_ = [x for x in inside if not covered(x[1], x[1] + 4 * x[2])]
        if not open_: continue
        src = os.path.exists('%s/src/%s.c' % (REPO, f['name']))
        rows.append((f['name'], a, size // 4, sum(x[2] for x in open_), [x[3] for x in open_][:4], src))
rows.sort(key=lambda r: r[1])
print('functions matched at 100%% for us-rev1 in their report: %d' % nmatch)
print('...of which not (fully) covered by our manifests: %d functions, %d insns open' % (len(rows), sum(r[3] for r in rows)))
for n, a, ins, openi, names, src in rows:
    print('  %-4s %-20s 0x%08X  %4d insns (%d open: %s%s)  source %s' % ('NEW' if n not in seen else '', n, a, ins, openi, ' '.join(names), ' ...' if openi > 0 and len(names) == 4 else '', 'yes' if src else 'NOT PUBLISHED'))
open(seen_path, 'w').write('\n'.join(sorted(seen | {r[0] for r in rows})) + '\n')
