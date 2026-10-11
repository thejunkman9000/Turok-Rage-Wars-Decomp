#!/usr/bin/env python3
"""Prepare the rodata-doctor loop for functions that a worker matched (EXACT) but that the real ROM build rejected.

usage: python tools/rdprep.py <func> [<func> ...] | --blocked
For every function: copy the worker's source of the newest EXACT results line to wip/rd/<func>.c, copy the worker's missing `_types.h` headers to include/,
and write wip/rd/list.txt (a tools/chk.py list: `wip/rd/<func>.c <func> <rom> @SN ...`).  Then
    powershell -NoProfile -File tools/fchk.ps1 wip/rd/list.txt        (code compare + the pool order/value check of chk.py)
    wsl -d Ubuntu-24.04 -- bash tools/rdcheck.sh                       (rodata doctor over the same files: layout, sizes, differing words)"""
import glob, os, re, shutil, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
os.makedirs('wip/rd', exist_ok=True)
names = sys.argv[1:]
if names == ['--blocked']: names = open('wip/blocked_exact.txt').read().split()

def newest(fn):
    best = None
    for p in sorted(glob.glob('D:/Projects/ws/*/wip/out/results.txt')):
        ws = os.path.dirname(os.path.dirname(os.path.dirname(p)))
        for l in open(p, errors='replace'):
            f = l.split('#')[0].split()
            if len(f) >= 4 and f[0] == fn and f[3] == 'EXACT': best = (ws, l)
    return best

lines = []; ro_lines = []
for fn in names:
    b = newest(fn)
    if not b: print(fn, 'no EXACT result'); continue
    ws, l = b
    body = l.split('#')[0].split(); rest = body[4:]
    note = l.split('#', 1)[1] if '#' in l else ''
    mm = re.search(r'flags:\s*((?:[@-]\S+[ \t]*)+)', note)
    if mm: rest += [t.rstrip('.,;') for t in mm.group(1).split()]
    rest = [t.strip('[]') for t in rest]
    rest = [u for t in rest for u in ((t, t.split('=', 1)[1]) if t.startswith('flags=') else (t,))]
    flags = [t for t in rest if t.startswith('@') or t.startswith('-f') or t.startswith('-m')]
    src = f'{ws}/wip/out/{fn}.c'
    dst = f'wip/rd/{fn}.c'
    if not os.path.exists(dst): shutil.copy(src, dst)
    txt = open(dst, errors='replace').read()
    for h in os.listdir(f'{ws}/include'):
        if h.endswith('_types.h') and h in txt and not os.path.exists(f'include/{h}'): shutil.copy(f'{ws}/include/{h}', f'include/{h}'); print('  header', h)
    lines.append(f'{dst} {fn} {body[1]} ' + ' '.join(flags))
    ro_lines.append((fn, ws))
    print(fn, ws, ' '.join(flags))
open('wip/rd/list.txt', 'w', newline='\n').write('\n'.join(lines) + '\n')
