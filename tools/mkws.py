#!/usr/bin/env python3
"""Create an isolated matching workspace for a parallel worker (agent).

usage: python tools/mkws.py <name>
Copies the project to D:/Projects/ws/<name> (without .git/build/asm) and rewrites the hard-coded paths in tools/ so that
chk.ps1, try.ps1, vtry.py, vq.py ... use the copy and its own WSL build dir ~/trw_<name>.  Results are brought back by
copying the finished src/libultra/<fn>.c files into the main tree (then tools/to_c.py + tools/cycle.ps1 there)."""
import os, shutil, sys, re
name = sys.argv[1]
update = '--update' in sys.argv
src = r'D:\Projects\TurokRageWars'
dst = rf'D:\Projects\ws\{name}'
if update:
    for d in ('tools', 'docs'):
        shutil.copytree(os.path.join(src, d), os.path.join(dst, d), dirs_exist_ok=True, ignore=shutil.ignore_patterns('gcc', '__pycache__'))
    for h in os.listdir(os.path.join(src, 'include')):
        if h.endswith('_types.h') or h in ('common.h', 'libaudio.h'):
            shutil.copy(os.path.join(src, 'include', h), os.path.join(dst, 'include', h))
elif os.path.exists(dst):
    shutil.rmtree(dst, ignore_errors=True)
if not update: shutil.copytree(src, dst, ignore=shutil.ignore_patterns('.git', 'build', *([] if '--asm' in sys.argv else ['asm']), 'ud_json', '__pycache__', 'wip', 'm2c_jt_tmp.s'))
os.makedirs(os.path.join(dst, 'wip'), exist_ok=True)
subs = [
    (r'D:\Projects\TurokRageWars', rf'D:\Projects\ws\{name}'),
    ('D:/Projects/TurokRageWars', f'D:/Projects/ws/{name}'),
    ('/mnt/d/Projects/TurokRageWars', f'/mnt/d/Projects/ws/{name}'),
    ('/home/johns/trw', f'/home/johns/trw_{name}'),
    ('$HOME/trw', f'$HOME/trw_{name}'),
    ('~/trw', f'~/trw_{name}'),
]
n = 0
for root, _, files in os.walk(os.path.join(dst, 'tools')):
    if 'gcc' in root.split(os.sep):
        continue
    for f in files:
        if not f.endswith(('.py', '.sh', '.ps1', '.txt', '.json')):
            continue
        p = os.path.join(root, f)
        try:
            t = open(p, encoding='utf-8').read()
        except Exception:
            continue
        t2 = t
        for a, b in subs:
            t2 = t2.replace(a, b)
        if t2 != t:
            open(p, 'w', encoding='utf-8', newline='\n').write(t2)
            n += 1
print(f'workspace {dst}: {n} tool files rewritten; WSL dir ~/trw_{name}')
