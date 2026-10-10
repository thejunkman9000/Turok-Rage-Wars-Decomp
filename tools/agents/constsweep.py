#!/usr/bin/env python3
"""constsweep.py <file.c> <fn> <rom hex> [--flags "@SN"] [--jobs N] [--top N]   (run inside WSL at the workspace root)

Lesson from func_00444024 (round 8): an `extern f32 D_xxx;` that the original code read as a pool constant must be declared `extern const`: the load is then
RTX_UNCHANGING_P and gets NO alias dependence with the stores (non-const = "may alias" every store through a pointer: it pins the stores before/after it).
This tool writes one variant per non-function `extern` declaration (that declaration made const) plus an all-const variant, ranks them with tools/vb.py
(aligned diff metric) and prints the result next to the unchanged base (variant 'base').  Variants are in wip/vcs/."""
import sys, re, os, subprocess
a = sys.argv[1:]
src, fn, rom = a[0], a[1], a[2]
rest = a[3:]
root = '/mnt/d/Projects/ws/s806'
os.chdir(root)
lines = open(src, encoding='utf-8').read().split('\n')
pat = re.compile(r'^(\s*)extern\s+(?!const\b)([^;()]*?)\b(\w+)(\s*\[[^\]]*\])?(\s*__asm__\s*\([^)]*\))?\s*;')
idx = [i for i, l in enumerate(lines) if pat.match(l)]
os.makedirs('wip/vcs', exist_ok=True)
for f in os.listdir('wip/vcs'):
    if f.endswith('.c'): os.remove('wip/vcs/' + f)
def constify(l):
    return re.sub(r'^(\s*)extern\s+', r'\1extern const ', l, count=1)
def write(name, ls):
    open('wip/vcs/' + name, 'w', encoding='utf-8', newline='\n').write('\n'.join(ls))
write('v000_base.c', lines)
for k, i in enumerate(idx):
    m = pat.match(lines[i])
    L = list(lines); L[i] = constify(lines[i])
    write('v%03d_%s.c' % (k + 1, m.group(3)), L)
if len(idx) > 1:
    L = list(lines)
    for i in idx: L[i] = constify(lines[i])
    write('v%03d_ALL.c' % (len(idx) + 1), L)
print('externs:', len(idx))
subprocess.call(['python3', 'tools/vb.py', fn, rom, '--dir', 'wip/vcs'] + rest)
