#!/usr/bin/env python3
"""Move the repaired sources of wip/rd/ into the tree: src/<sub>/<fn>.c + manifest lines (funcs.txt / funcs_a.txt).

usage: python tools/rdintegrate.py [--dry] [--insns name=N ...] [func ...]
Needs wip/rd/list.txt (tools/rdprep.py).  Runs tools/chk.py first (through fchk.ps1) and only takes functions it reports as plain `EXACT`; the ro= piece
(offset:size) comes from chk, the mode from the list flags (@SN -> sn, -fno-builtin -> +nb, @SN272 -> sn272).  --insns overrides the instruction count of a
span file (e.g. func_0023C914=143: the file holds three consecutive functions).  Afterwards run tools/dropfix.py (or tools/cycle.ps1) to verify the real build."""
import os, re, shutil, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
dry = '--dry' in sys.argv
args = [a for a in sys.argv[1:] if a != '--dry']
over = {}
names = []
i = 0
while i < len(args):
    if args[i] == '--insns': k, v = args[i + 1].split('='); over[k] = int(v); i += 2
    else: names.append(args[i]); i += 1
lines = [l for l in open('wip/rd/list.txt') if l.strip() and (not names or l.split()[1] in names)]
open('wip/rd/sel.txt', 'w', newline='\n').write(''.join(lines))
r = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/fchk.ps1', 'wip/rd/sel.txt'], capture_output=True, text=True)
chk = {}
for l in (r.stdout + r.stderr).split('\n'):
    m = re.match(r'(func_[0-9A-Fa-f]{8})\s+(\d+) insns\s+(.*)', l)
    if m: chk[m.group(1)] = (int(m.group(2)), m.group(3))
have = set()
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if f: have.add(f[0])
add = {'funcs.txt': [], 'funcs_a.txt': []}
for l in lines:
    f = l.split(); src, fn, rom, flags = f[0], f[1], int(f[2], 16), f[3:]
    if fn in have: print(fn, 'already in a manifest'); continue
    n, verdict = chk.get(fn, (0, '?'))
    if not verdict.startswith('EXACT'): print(fn, 'NOT integrated:', verdict[:100]); continue
    n = over.get(fn, n)
    mode = 'sn272' if '@SN272' in flags else 'sn'
    if '-fno-builtin' in flags: mode += '+nb'
    if '-msplit-addresses' in flags: mode += '+sa'
    if '-mcpu=r4000' in flags: mode += '+r4k'
    m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', verdict)
    ovl = rom >= 0x16E000
    sub = 'ovl_a' if ovl else 'game'
    mf = 'funcs_a.txt' if ovl else 'funcs.txt'
    line = f'{fn} 0x{rom:X} {n} {sub} mode={mode}' + (f' ro={m.group(1)}:{m.group(2)}' if m else '')
    add[mf].append(line)
    print(line)
    if not dry:
        shutil.copy(src, f'src/{sub}/{fn}.c')
if not dry:
    for mf, ls in add.items():
        if ls:
            t = open(mf).read()
            open(mf, 'w', newline='\n').write(t.rstrip('\n') + '\n' + '\n'.join(ls) + '\n')
print('added', sum(len(v) for v in add.values()))
