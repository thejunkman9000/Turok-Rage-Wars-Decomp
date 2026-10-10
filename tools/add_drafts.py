#!/usr/bin/env python3
"""Append `draft=<path>` (up to 3, newest first) to every line of the given workspaces' wip/targets.txt: earlier workers' near-miss sources.
usage: python tools/add_drafts.py s801 s802 ...
Looks in D:/Projects/ws/*/wip/{hard,out,c}/ for <fn>.c, <fn>.*.c and <fn>_*.c (a function's drafts keep its name as the stem start)."""
import glob, os, re, sys
WS = 'D:/Projects/ws'
index = {}
for pat in ('wip/hard/*.c', 'wip/out/*.c', 'wip/c/*.c', 'wip/*/*.c'):
    for p in glob.glob(f'{WS}/*/{pat}'):
        m = re.match(r'(func_[0-9A-Fa-f]{8})', os.path.basename(p))
        if m: index.setdefault(m.group(1), set()).add(p.replace('\\', '/'))
for ws in sys.argv[1:]:
    t = f'{WS}/{ws}/wip/targets.txt'
    out = []
    for l in open(t):
        f = l.split()
        if not f: continue
        base = [x for x in f if not x.startswith('draft=')]
        own = f'{WS}/{ws}/'
        cand = sorted((p for p in index.get(f[0], ()) if not p.startswith(own)), key=os.path.getmtime, reverse=True)[:3]
        out.append(' '.join(base + [f'draft={p}' for p in cand]))
    open(t, 'w', newline='\n').write('\n'.join(out) + '\n')
    print(ws, sum(1 for l in out if 'draft=' in l), 'of', len(out), 'targets have drafts')
