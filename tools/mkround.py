#!/usr/bin/env python3
"""Build round-N worker workspaces for every game function that has no matching C yet.

usage: python tools/mkround.py <round> <group size> [--dry]
 - remaining = docs/game_funcs.txt functions not in funcs.txt / funcs_a.txt (dropped ones included)
 - groups are consecutive in address order (so each worker sees neighbouring code), named s<round>01..; targets go to
   D:/Projects/ws/<name>/wip/targets.txt (`name rom insns`), the prompt to docs/BATCH_PROMPT.txt (from wip/ROUND_PROMPT.txt)
"""
import os, re, subprocess, sys
rnd, size = sys.argv[1], int(sys.argv[2])
dry = '--dry' in sys.argv
done = set()
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4 and not f[0].startswith('pad_'): done.add(f[0])
rem = []
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) >= 3 and f[1].startswith('func_') and f[1] not in done:
        va = int(f[1][5:], 16)
        rom = va - 0x400000 + 0x16E000 if 0x400000 <= va < 0x500000 else va - 0x1FF400
        rem.append((va, f[1], rom, int(f[2])))
# functions another worker still has (workspaces named in EXCLUDE_WS env, comma separated) are left out
for w in filter(None, os.environ.get('EXCLUDE_WS', '').split(',')):
    t = f'D:/Projects/ws/{w}/wip/targets.txt'
    if os.path.exists(t):
        ex = {l.split()[0] for l in open(t) if l.strip()}
        rem = [r for r in rem if r[1] not in ex]
if os.path.exists('wip/skip_funcs.txt'):                      # padding words / hand-written asm that no C can match
    sk = set(open('wip/skip_funcs.txt').read().split())
    rem = [r for r in rem if r[1] not in sk]
rem.sort()
groups = [rem[i:i + size] for i in range(0, len(rem), size)]
print(len(rem), 'functions,', sum(r[3] for r in rem), 'insns ->', len(groups), 'groups')
if dry: sys.exit()
prompt = open('wip/ROUND_PROMPT.txt').read().replace('round 3', f'round {rnd}')
names = []
for gi, g in enumerate(groups, 1):
    name = f's{rnd}{gi:02d}'; names.append(name)
    subprocess.run([sys.executable, 'tools/mkws.py', name], check=True, capture_output=True)
    ws = f'D:/Projects/ws/{name}'
    os.makedirs(f'{ws}/wip', exist_ok=True)
    open(f'{ws}/wip/targets.txt', 'w').write('\n'.join(f'{n} 0x{rom:X} {i}' for _, n, rom, i in g) + '\n')
    open(f'{ws}/docs/BATCH_PROMPT.txt', 'w').write(prompt.replace('@@N@@', name))
print(' '.join(names))
