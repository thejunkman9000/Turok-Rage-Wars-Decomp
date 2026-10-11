#!/usr/bin/env python3
"""vp.py <spec.py> [--jobs N] [--top N]   (WSL, workspace root).  spec.py defines BASE (file), FN, ROM, FLAGS and
VARS = list of variants; a variant is a list of (old, new) text replacements applied (once each) to BASE, or a str (full text),
or {'full': path}.  Writes wip/vp/vNNN.c, ranks them with tools/vb.py (aligned structural/operand metric)."""
import sys, os, subprocess
args = sys.argv[1:]
spec = {}
exec(open(args[0]).read(), spec)
jobs = '3'; top = '15'
if '--jobs' in args: jobs = args[args.index('--jobs') + 1]
if '--top' in args: top = args[args.index('--top') + 1]
base = open(spec['BASE'], encoding='utf-8').read()
d = 'wip/vp'
os.makedirs(d, exist_ok=True)
for f in os.listdir(d):
    os.remove(os.path.join(d, f))
n = 0
for i, v in enumerate(spec['VARS']):
    if isinstance(v, str):
        t = v
    elif isinstance(v, dict):
        t = open(v['full'], encoding='utf-8').read()
    else:
        t = base
        ok = True
        for o, nw in v:
            if o not in t:
                print('variant', i, 'missing', repr(o[:70]))
                ok = False
                break
            t = t.replace(o, nw, 1)
        if not ok:
            continue
    open(f'{d}/v{i:03d}.c', 'w', encoding='utf-8', newline='\n').write(t)
    n += 1
print('generated', n, 'variants')
sys.stdout.flush()
subprocess.run(['python3', 'tools/vb.py', spec['FN'], spec['ROM'], '--flags', spec['FLAGS'], '--jobs', jobs, '--top', top, '--dir', d])
