#!/usr/bin/env python3
"""their_extra.json (in %TEMP%): functions that melalawi's us-rev1 report matches at 100% and that are not in our manifests (by address)."""
import json, re, os
base = 'D:/Projects/ext/ragewars-decomp'
r = json.load(open(base + '/versions/us-rev1/report.json'))
addr = {}
for l in open(base + '/versions/us-rev1/symbol_addrs.txt'):
    m = re.match(r'(\w+) = (0x[0-9A-Fa-f]+);', l)
    if m: addr[m.group(1)] = int(m.group(2), 16)
theirs = {}
for u in r['units']:
    for f in u.get('functions', []):
        n = f['name']
        if n in addr: theirs[addr[n]] = (n, f.get('fuzzy_match_percent', 0), int(f.get('size') or 0))
ours = set()
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4 and f[0].startswith('func_'): ours.add(int(f[0][5:], 16) | 0x80000000)
allf = set()
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) >= 3 and f[1].startswith('func_'): allf.add(int(f[1][5:], 16) | 0x80000000)
only = {hex(a): v for a, v in theirs.items() if v[1] >= 99.99 and a in allf and a not in ours}
json.dump(only, open(os.environ['TEMP'] + '/their_extra.json', 'w'))
print(len(only), 'functions,', sum(v[2] // 4 for v in only.values()), 'insns they match that we do not')
