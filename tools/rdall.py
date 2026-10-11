#!/usr/bin/env python3
"""Run chk (code + pool check) and the rodata doctor over every entry of wip/rd/list.txt (or the named functions) and print a compact table.
usage: python tools/rdall.py [func ...]
Columns: chk verdict, ro= piece chk derived, doctor verdict (IDENTICAL / n differing words / size)."""
import os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
want = set(sys.argv[1:])
lines = [l for l in open('wip/rd/list.txt') if l.strip() and (not want or l.split()[1] in want)]
open('wip/rd/sel.txt', 'w', newline='\n').write(''.join(lines))
r = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/fchk.ps1', 'wip/rd/sel.txt'], capture_output=True, text=True)
chk = {}
for l in (r.stdout + r.stderr).split('\n'):
    m = re.match(r'(func_[0-9A-Fa-f]{8})\s+(.*)', l)
    if m: chk[m.group(1)] = m.group(2)
cmds = ['cp /mnt/d/Projects/TurokRageWars/tools/rodoc.py ~/trw/tools/rodoc.py', 'cd ~/trw', 'rsync -a /mnt/d/Projects/TurokRageWars/wip/rd/ wip/rd/', 'rsync -a /mnt/d/Projects/TurokRageWars/include/ include/']
for l in lines:
    f = l.split(); fn = f[1]; flags = f[3:]
    mode = 'sn272' if '@SN272' in flags else 'sn' + ('+nb' if '-fno-builtin' in flags else '')
    m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', chk.get(fn, ''))
    a = [f[0], mode] + ([m.group(1), m.group(2)] if m else ['0x0', '0'])
    cmds.append(f'echo "== {fn}"; python3 tools/rodoc.py ' + ' '.join(a) + ' 2>&1 | grep -v "^  object\\|^  ro piece" | head -12')
env = dict(os.environ, MSYS_NO_PATHCONV='1')
d = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', '; '.join(cmds)], capture_output=True, text=True, env=env).stdout
doc = {}; cur = None
for l in d.split('\n'):
    if l.startswith('== '): cur = l[3:].strip(); doc[cur] = []
    elif cur and l.strip(): doc[cur].append(l.strip())
for l in lines:
    fn = l.split()[1]
    c = chk.get(fn, '?')
    dd = doc.get(fn, [])
    verdict = 'IDENTICAL' if any('IDENTICAL' in x for x in dd) else ('no ro' if not dd else '; '.join(dd)[:150])
    print(f'{fn}  chk: {c[:100]}')
    print(f'      doctor: {verdict}')
