#!/usr/bin/env python3
"""done.py <fn> <file.c> "<flags e.g. @SN -fno-builtin>" "<note>" [name=xxx] [--partial] : verify with chk; EXACT -> copy to wip/out/<fn>.c + results line.
--partial: record PARTIAL (copy file to wip/hard/<fn>.c).  Run in WSL from the workspace root."""
import sys, subprocess, re, shutil, os
a = [x for x in sys.argv[1:] if not x.startswith('--')]
partial = '--partial' in sys.argv
fn, f, flags, note = a[0], a[1], a[2], a[3]
name = next((x for x in a[4:] if x.startswith('name=')), '')
rom = None
for l in open('wip/targets.txt'):
    p = l.split()
    if p[0] == fn: rom = p[1]
if rom is None:
    rom = next(x for x in a[4:] if x.startswith('rom=')).split('=')[1]
open('wip/_done_l.txt', 'w').write(f'{f} {fn} {rom} {flags}\n')
out = subprocess.run(['bash', 'tools/fk.sh', 'wip/_done_l.txt'], capture_output=True, text=True).stdout
print(out.strip())
m = re.search(r'^' + fn + r'\s+(\d+) insns\s+(EXACT|\d+ words differ)(?:\s+score=\d+)?(?:\s+ro=(\S+))?', out, re.M)
if not m:
    print('NO RESULT'); sys.exit(1)
n, st, ro = m.group(1), m.group(2), m.group(3)
ftxt = f' [flags: {flags}]' if flags.strip() else ''
if st == 'EXACT' and not partial:
    os.makedirs('wip/out', exist_ok=True)
    shutil.copy(f, f'wip/out/{fn}.c')
    line = f'{fn} {rom} {n} EXACT' + (f' ro={ro}' if ro else '') + ftxt + (f' {name}' if name else '') + f' # {note}'
elif st == 'EXACT':
    line = None
else:
    os.makedirs('wip/hard', exist_ok=True)
    shutil.copy(f, f'wip/hard/{fn}.c')
    line = f'{fn} {rom} {n} PARTIAL' + (f' ro={ro}' if ro else '') + ftxt + (f' {name}' if name else '') + f' # {st}; {note}'
if line:
    rf = 'wip/out/results.txt'
    lines = open(rf).read().splitlines() if os.path.exists(rf) else []
    lines = [l for l in lines if not l.startswith(fn + ' ')]
    lines.append(line)
    open(rf, 'w').write('\n'.join(lines) + '\n')
    print('RECORDED:', line)
