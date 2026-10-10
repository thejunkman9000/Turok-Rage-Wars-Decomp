#!/usr/bin/env python3
"""rf.py <file.c> <fn> <rom> [extra tokens e.g. -fno-builtin] : try single cc1 flags (and some pairs) from a menu in ONE chk call, rank by S/R."""
import sys, os, re, subprocess, difflib
f, fn, rom = sys.argv[1:4]; extra = sys.argv[4:]
menu = ['-fno-thread-jumps','-fno-rerun-cse-after-loop','-fno-strength-reduce','-fno-cse-follow-jumps','-fno-cse-skip-blocks','-fno-schedule-insns','-fno-schedule-insns2',
        '-fno-expensive-optimizations','-fno-delayed-branch','-fno-peephole','-fno-force-mem','-fno-defer-pop','-fno-caller-saves','-fno-inline','-fno-function-cse','-fno-gcse',
        '-fno-rerun-loop-opt','-fno-loop-optimize','-fno-crossjumping','-fno-optimize-sibling-calls','-fno-guess-branch-probability','-fno-if-conversion','-fno-regmove','-fno-omit-frame-pointer','-fno-reorder-blocks',
        '-fno-unroll-loops','-fno-peephole2','-fno-merge-constants','-fno-move-all-movables','-fno-reduce-all-givs','-fno-cprop-registers','-fno-branch-count-reg','-fno-trapping-math','-fno-keep-static-consts','-fno-argument-alias','-fno-strict-aliasing','-fstrict-aliasing','-fno-common','-fsched-spec-load','-fno-optimize-register-move','-fno-bounded-pointers']
combos = [('-fno-thread-jumps','-fno-rerun-cse-after-loop'),('-fno-thread-jumps','-fno-cse-follow-jumps'),('-fno-schedule-insns','-fno-schedule-insns2'),('-fno-cse-follow-jumps','-fno-cse-skip-blocks')]
cands = [[m] for m in menu] + [list(c) for c in combos] + [[]]
try:
    import rabbitizer
except ImportError:
    rabbitizer = None
lst = []
for k, c in enumerate(cands):
    lst.append(f'{f} {fn} {rom} @SN ' + ' '.join(extra + c))
open('wip/vx/rf_list.txt', 'w').write('\n'.join(lst) + '\n')
out = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '/mnt/d/Projects/ws/s703/tools/fchk.sh', 'wip/vx/rf_list.txt'], capture_output=True, text=True).stdout
lines = [l for l in out.splitlines() if l.startswith(fn + ' ') or 'COMPILE FAIL' in l or 'not found' in l]
res = []
for c, l in zip(cands, lines):
    m = re.search(r'(\d+) words differ(?:\s+score=(\d+))?', l)
    if 'EXACT' in l: key = (0, 0)
    elif m: key = (int(m.group(1)), int(m.group(2) or 0))
    else: key = (99999, 0)
    res.append((key, ' '.join(c) or '(none)', l.strip()[:70]))
res.sort()
for key, c, l in res[:int(os.environ.get('RV_TOP', 14))]:
    print(f'{c:50s} {l}')
