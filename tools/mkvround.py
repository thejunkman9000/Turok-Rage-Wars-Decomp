#!/usr/bin/env python3
"""Build agent workspaces for the version-specific work of one release (the targets of tools/mkvtargets.py).

usage: python tools/mkvround.py <us|eu|de> <release workspace name (veu ...)> <name prefix> [--targets wip/vtargets_<ver>.txt] [--limit diff=1200,lib=1200,new=900] [--dry] [--only a01,b02]
 - groups: targets of one class, in release-ROM order (neighbouring code stays together), up to <limit> insns per group (and at most 30 targets)
 - workspace <prefix><class letter><nn> (d = diff, l = lib, n = new): tools/mkws.py <name> --asm --src D:/Projects/ws/<release workspace> --as-v11,
   wip/targets.txt, docs/BATCH_PROMPT.txt from docs/VERSION_MATCH_PROMPT.txt
Prints the workspace names, one line per group."""
import os, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
args = sys.argv[1:]
def opt(k, d=None): return args[args.index(k) + 1] if k in args else d
ver, relws, prefix = args[0], args[1], args[2]
targets = opt('--targets', f'wip/vtargets_{ver}.txt')
limits = {'diff': 1200, 'lib': 1200, 'new': 900}
for kv in opt('--limit', '').split(','):
    if '=' in kv: k, v = kv.split('='); limits[k] = int(v)
only = set(opt('--only', '').split(',')) - {''}
RELEASE = {'us': 'US v1.0', 'eu': 'Europe (PAL)', 'de': 'Germany (PAL)'}[ver]
letter = {'diff': 'd', 'lib': 'l', 'new': 'n'}
rows = {'diff': [], 'lib': [], 'new': []}
for l in open(targets):
    f = l.split()
    if len(f) >= 4 and f[3] in rows: rows[f[3]].append((int(f[1], 16), int(f[2]), l.strip()))
prompt = open('docs/VERSION_MATCH_PROMPT.txt').read()
made = []
for cls, lst in rows.items():
    lst.sort()
    groups = []; cur = []; n = 0
    for r in lst:
        if cur and (n + r[1] > limits[cls] or len(cur) >= 30): groups.append(cur); cur = []; n = 0
        cur.append(r); n += r[1]
    if cur: groups.append(cur)
    for gi, g in enumerate(groups, 1):
        name = f'{prefix}{letter[cls]}{gi:02d}'
        if only and name not in only and name[len(prefix):] not in only: continue
        print(name, cls, len(g), 'targets', sum(r[1] for r in g), 'insns')
        if '--dry' in args: continue
        if os.path.exists(rf'D:\Projects\ws\{name}'): print('  workspace exists, skipped'); continue
        r = subprocess.run([sys.executable, 'tools/mkws.py', name, '--asm', '--src', f'D:/Projects/ws/{relws}', '--as-v11'], capture_output=True, text=True)
        if r.returncode: print(r.stdout[-300:], r.stderr[-300:]); continue
        ws = rf'D:\Projects\ws\{name}'
        os.makedirs(rf'{ws}\wip', exist_ok=True); os.makedirs(rf'{ws}\docs', exist_ok=True)
        open(rf'{ws}\wip\targets.txt', 'w', newline='\n').write('\n'.join(r_[2] for r_ in g) + '\n')
        open(rf'{ws}\docs\BATCH_PROMPT.txt', 'w', newline='\n').write(prompt.replace('@@RELEASE@@', RELEASE).replace('@@W@@', name))
        made.append(name)
print(' '.join(made))
