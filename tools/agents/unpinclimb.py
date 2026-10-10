#!/usr/bin/env python3
"""unpinclimb.py <src.c> <fn> <rom> <flags...> : greedily remove register-asm pins while the aligned diff score (3*struct+oper) does not get worse; writes <src>.unpinned.c"""
import sys, os, re, subprocess
sys.path.insert(0, '/mnt/d/Projects/ws/s702/tools')
import adlib
src, fn, rom = sys.argv[1], sys.argv[2], sys.argv[3]
flags = sys.argv[4:] or ['@SN']
def score(text, tag):
    p = f'wip/_rv/uc_{tag}.c'; open(p, 'w').write(text)
    return p
def evalset(texts):
    files = []
    for i, t in enumerate(texts):
        p = f'wip/_rv/uc_{i}.c'; open(p, 'w').write(t); files.append(p)
    open('wip/_rv/uc_list.txt', 'w').write(''.join(f'{p} {fn} {rom} {" ".join(flags)}\n' for p in files))
    subprocess.run(['bash', 'tools/fk.sh', 'wip/_rv/uc_list.txt'], capture_output=True)
    out = []
    for p in files:
        ns, no, _ = adlib.adiff(p, fn, int(rom, 16), flags)
        out.append(3*ns + no if ns is not None else 10**6)
    return out
cur = open(src).read()
pat = re.compile(r'register\s+([^;=]*?)\s*(?:__asm__|asm)\s*\(\s*"[^"]*"\s*\)')
base = evalset([cur])[0]
print('base', base)
improved = True
while improved:
    improved = False
    ms = list(pat.finditer(cur))
    if not ms: break
    cands = [cur[:m.start()] + m.group(1) + cur[m.end():] for m in ms]
    sc = evalset(cands)
    best = min(range(len(sc)), key=lambda i: sc[i])
    if sc[best] <= base:
        print('remove pin', ms[best].group(0), '->', sc[best])
        cur = cands[best]; base = sc[best]; improved = True
open(src.replace('.c', '.unpinned.c'), 'w').write(cur)
print('final', base)
