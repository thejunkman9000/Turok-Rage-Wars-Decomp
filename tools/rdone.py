#!/usr/bin/env python3
"""One iteration of the rodata-doctor loop for one function: chk (code + pool check) and the rodata doctor on wip/rd/<func>.c.
usage: python tools/rdone.py <func> [--nodoc]       (tools/rdprep.py must have prepared wip/rd/list.txt and the source)
The doctor gets the ro= piece (offset:size) that chk derives from the ROM code and our object, so it checks the whole piece, padding included."""
import os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
fn = sys.argv[1]
line = next((l for l in open('wip/rd/list.txt') if l.split()[1:2] == [fn]), None)
if not line: sys.exit('not in wip/rd/list.txt: ' + fn)
open('wip/rd/one.txt', 'w', newline='\n').write(line)
r = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/fchk.ps1', 'wip/rd/one.txt'], capture_output=True, text=True)
out = '\n'.join(l for l in (r.stdout + r.stderr).split('\n') if l.strip() and not l.startswith('lu_match'))
print(out)
flags = line.split()[3:]
mode = 'sn272' if '@SN272' in flags else 'sn' + ('+nb' if '-fno-builtin' in flags else '')
m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', out)
if '--nodoc' not in sys.argv:
    src = line.split()[0]
    args = [src, mode] + ([m.group(1), m.group(2)] if m else ['0x0', '0'])
    env = dict(os.environ, MSYS_NO_PATHCONV='1')
    cmd = 'cp /mnt/d/Projects/TurokRageWars/tools/rodoc.py ~/trw/tools/rodoc.py; cd ~/trw && rsync -a /mnt/d/Projects/TurokRageWars/wip/rd/ wip/rd/ && rsync -a /mnt/d/Projects/TurokRageWars/include/ include/ && python3 tools/rodoc.py ' + ' '.join(args)
    r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=env)
    print(r.stdout + r.stderr)
