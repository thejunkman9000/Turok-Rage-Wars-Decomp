#!/usr/bin/env python3
"""Split the functions that no manifest entry covers yet into
  - blocked: a worker already delivered an EXACT version (wip/out/results.txt of some workspace under D:/Projects/ws) but the integration into the real ROM
    build failed (rodata layout, size, symbol clash ...): the matching work is done, the integration is not;
  - open: nobody matched them yet (PARTIAL / NONE / never tried).
usage: python tools/blocked.py        writes wip/blocked_exact.txt (names) and prints both lists with instruction counts"""
import glob, os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
out = subprocess.run([sys.executable, 'tools/remaining.py', '--sizes'], capture_output=True, text=True).stdout.split('\n')
remd = {}
for x in out[1].split():
    if ':' in x: remd[x.split(':')[0]] = int(x.split(':')[1])
exact = {}
for p in glob.glob('D:/Projects/ws/*/wip/out/results.txt'):
    ws = os.path.basename(os.path.dirname(os.path.dirname(os.path.dirname(p))))
    for l in open(p, errors='replace'):
        m = re.match(r'(func_[0-9A-F]{8})\s+\S+\s+(\d+)\s+(EXACT|PARTIAL|NONE)', l)
        if m and m.group(3) == 'EXACT' and m.group(1) in remd: exact.setdefault(m.group(1), set()).add(ws)
blocked = sorted(n for n in remd if n in exact)
rest = sorted(n for n in remd if n not in exact)
print('not covered:', len(remd), 'functions,', sum(remd.values()), 'insns')
print('blocked (EXACT delivered, integration failed): %d functions, %d insns' % (len(blocked), sum(remd[n] for n in blocked)))
print('  ' + ' '.join('%s:%d' % (n, remd[n]) for n in blocked))
print('open (not matched yet): %d functions, %d insns' % (len(rest), sum(remd[n] for n in rest)))
print('  ' + ' '.join('%s:%d' % (n, remd[n]) for n in rest))
open('wip/blocked_exact.txt', 'w').write('\n'.join(blocked) + '\n')
