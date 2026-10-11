#!/usr/bin/env python3
"""List the functions of the other decompilation (melalawi/ragewars-decomp) in a US v1.1 address window, with size and match %, and whether we cover them.
usage (WSL, any cwd):  python3 tools/their_range.py 0x8044A000 0x8044F000
Why: tools/upstream_check.py only sees ranges that docs/game_funcs.txt knows (it ends at ROM 0x1B47D8); this one reads their report.json directly.
Env THEIR_REPO overrides the checkout path (default /mnt/d/Projects/ext/ragewars-decomp)."""
import json, os, re, sys
REPO = os.environ.get('THEIR_REPO', '/mnt/d/Projects/ext/ragewars-decomp')
lo, hi = int(sys.argv[1], 0), int(sys.argv[2], 0)
addr = {}
for l in open(REPO + '/versions/us-rev1/symbol_addrs.txt'):
    m = re.match(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+);', l)
    if m: addr[m.group(1)] = int(m.group(2), 16)
cover = []
for fn in ('funcs.txt', 'funcs_a.txt'):
    if os.path.exists(fn):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) >= 3:
                try: s = int(f[1], 16); cover.append((s, s + 4 * int(f[2]), f[0]))
                except ValueError: pass
rows = []
for u in json.load(open(REPO + '/versions/us-rev1/report.json'))['units']:
    for f in u.get('functions', []):
        a = addr.get(f['name'])
        if a is None or not lo <= a < hi: continue
        va = a & 0xFFFFFF
        rom = va - 0x400000 + 0x16E000 if 0x400000 <= va < 0x500000 else va - 0x1FF400
        size = int(f.get('size') or 0)
        ours = [c[2] for c in cover if c[0] < rom + size and rom < c[1]]
        src = os.path.exists('%s/src/%s.c' % (REPO, f['name']))
        rows.append((a, f['name'], size, f.get('fuzzy_match_percent'), rom, ours, src))
for a, n, s, p, rom, ours, src in sorted(rows):
    print('0x%08X rom 0x%X %-26s %5d bytes %4d insns match=%-6s source=%-3s our entries: %s' % (a, rom, n, s, s // 4, p, 'yes' if src else 'no', ' '.join(ours) or '-'))
