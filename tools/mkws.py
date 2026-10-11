#!/usr/bin/env python3
"""Create an isolated matching workspace for a parallel worker (agent).

usage: python tools/mkws.py <name> [--update] [--asm] [--src <workspace dir> [--as-v11]]
Copies the project to D:/Projects/ws/<name> (without .git/build/asm) and rewrites the hard-coded paths in tools/ so that
chk.ps1, try.ps1, vtry.py, vq.py ... use the copy and its own WSL build dir ~/trw_<name>.  Results are brought back by
copying the finished src/libultra/<fn>.c files into the main tree (then tools/to_c.py + tools/cycle.ps1 there).

  --src <dir>   copy another WORKSPACE (e.g. D:/Projects/ws/v10, a release build made by tools/mkver.py) instead of the main tree: the worker then sees
                that release's manifests, symbols, asm and ROM.
  --as-v11      (with --src) store the release's ROM under the name baserom.us.v11.z64 and drop the other ROMs: every tool that hard-codes that name
                (chk, rodoc, sdiff, apply_results, ...) then works on the release without changes.  The workspace says so in wip/README_VERSION.txt."""
import os, shutil, sys, re
args = sys.argv[1:]
name = args[0]
update = '--update' in args
src = r'D:\Projects\TurokRageWars'
if '--src' in args: src = args[args.index('--src') + 1].replace('/', '\\')
dst = rf'D:\Projects\ws\{name}'
if update:
    for d in ('tools', 'docs'):
        shutil.copytree(os.path.join(src, d), os.path.join(dst, d), dirs_exist_ok=True, ignore=shutil.ignore_patterns('gcc', '__pycache__', '.git'))      # .git packs are read-only: a second copy over them fails
    for h in os.listdir(os.path.join(src, 'include')):
        if h.endswith('_types.h') or h in ('common.h', 'libaudio.h'):
            shutil.copy(os.path.join(src, 'include', h), os.path.join(dst, 'include', h))
elif os.path.exists(dst):
    shutil.rmtree(dst, ignore_errors=True)
if not update: shutil.copytree(src, dst, ignore=shutil.ignore_patterns('.git', 'build', *([] if '--asm' in args else ['asm']), 'ud_json', '__pycache__', 'wip', 'm2c_jt_tmp.s', 'assets', 'mapdump', 'port', 'nul', 'port_*', 'port_ram*'))
os.makedirs(os.path.join(dst, 'wip'), exist_ok=True)
subs = [
    (r'D:\Projects\TurokRageWars', rf'D:\Projects\ws\{name}'),
    ('D:/Projects/TurokRageWars', f'D:/Projects/ws/{name}'),
    ('/mnt/d/Projects/TurokRageWars', f'/mnt/d/Projects/ws/{name}'),
    ('/home/johns/trw', f'/home/johns/trw_{name}'),
    ('$HOME/trw', f'$HOME/trw_{name}'),
    ('~/trw', f'~/trw_{name}'),
]
sname = os.path.basename(src.rstrip('\\/')) if '--src' in args else None
if sname:                                           # a workspace made from another workspace: its own names are rewritten too (before the generic ones, which would match their prefix)
    subs = [(rf'D:\Projects\ws\{sname}', rf'D:\Projects\ws\{name}'), (f'D:/Projects/ws/{sname}', f'D:/Projects/ws/{name}'), (f'/mnt/d/Projects/ws/{sname}', f'/mnt/d/Projects/ws/{name}'),
            (f'/home/johns/trw_{sname}', f'/home/johns/trw_{name}'), (f'$HOME/trw_{sname}', f'$HOME/trw_{name}'), (f'~/trw_{sname}', f'~/trw_{name}')]      # (only these: the generic ~/trw pairs would match the prefix of the new names)
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
if '--as-v11' in args and not update:
    mk = open(os.path.join(dst, 'Makefile'), newline='').read()
    rom = re.search(r'BASEROM\s*:=\s*(\S+)', mk).group(1)
    if rom != 'baserom.us.v11.z64':
        shutil.copyfile(os.path.join(dst, rom), os.path.join(dst, 'baserom.us.v11.z64'))
        for f in os.listdir(dst):
            if f.startswith('baserom.') and f != 'baserom.us.v11.z64': os.remove(os.path.join(dst, f))
        open(os.path.join(dst, 'Makefile'), 'w', newline='').write(re.sub(r'(BASEROM\s*:=\s*)\S+', r'\1baserom.us.v11.z64', mk))
        yp = os.path.join(dst, 'turok_ragewars.yaml')
        y = open(yp, newline='').read()
        open(yp, 'w', newline='').write(re.sub(r'(target_path:\s*)\S+', r'\1baserom.us.v11.z64', y))
        open(os.path.join(dst, 'wip', 'README_VERSION.txt'), 'w', newline='\n').write(
            f'This workspace builds ANOTHER RELEASE ({rom} of the project root it was copied from): the file baserom.us.v11.z64 here is that release\'s ROM,\n'
            'so that every tool that hard-codes the name compares against it.  The sources under src/ are the US v1.1 C that reproduces this release (manifest units whose\n'
            'code is identical up to relocations); the functions that really differ are your targets (wip/targets.txt).\n')
        print(f'  ROM: {rom} stored as baserom.us.v11.z64')
