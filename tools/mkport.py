#!/usr/bin/env python3
"""Workspaces that port matched functions from the cloned melalawi/ragewars-decomp (CC0) into our build.

usage: python tools/mkport.py <group size> [prefix=x]
 targets = functions their us-rev1 report matches at 100% that are not in our manifests (see their_extra.json made by the comparison script)
 each workspace D:/Projects/ws/<prefix>NN gets wip/targets.txt (our name, rom, insns), wip/theirs/<ourname>.c (their file),
 wip/theirs_include/ (their include tree, for the types their sources use) and docs/BATCH_PROMPT.txt (port prompt)."""
import json, os, re, shutil, subprocess, sys
size = int(sys.argv[1]); prefix = sys.argv[2] if len(sys.argv) > 2 else 'x'
base = 'D:/Projects/ext/ragewars-decomp'
extra = json.load(open(os.environ['TEMP'] + '/their_extra.json'))
rows = []
for a, (tname, pct, sz) in extra.items():
    va = int(a, 16)
    ourname = f'func_{va & 0xFFFFFF:08X}'
    rom = va - 0x80400000 + 0x16E000 if 0x80400000 <= va < 0x80500000 else va - 0x80000000 + 0x1000 - 0x200400 + 0x200400 - 0x1FF400 + 0x1FF400 - 0x200400 + 0x1000
    rom = (va & 0xFFFFFF) - 0x1FF400 if va < 0x80400000 else (va & 0xFFFFFF) - 0x400000 + 0x16E000
    f = f'{base}/src/{tname}.c'
    if os.path.exists(f): rows.append((va, ourname, rom, sz // 4, f, tname))
rows.sort()
print(len(rows), 'functions,', sum(r[3] for r in rows), 'insns')
prompt = open('wip/PORT_PROMPT.txt').read()
groups = [rows[i:i + size] for i in range(0, len(rows), size)]
for gi, g in enumerate(groups, 1):
    name = f'{prefix}{gi:02d}'
    subprocess.run([sys.executable, 'tools/mkws.py', name], check=True, capture_output=True)
    ws = f'D:/Projects/ws/{name}'
    os.makedirs(f'{ws}/wip/theirs', exist_ok=True)
    open(f'{ws}/wip/targets.txt', 'w').write('\n'.join(f'{n} 0x{rom:X} {i}' for _, n, rom, i, _, _ in g) + '\n')
    for _, n, rom, i, f, t in g:
        shutil.copy(f, f'{ws}/wip/theirs/{n}.c')
    open(f'{ws}/wip/theirs/NAMES.txt', 'w').write('\n'.join(f'{n} <- {t}' for _, n, _, _, _, t in g) + '\n')
    shutil.copytree(f'{base}/include', f'{ws}/wip/theirs_include', dirs_exist_ok=True)
    open(f'{ws}/docs/BATCH_PROMPT.txt', 'w').write(prompt.replace('@@N@@', name))
    print(name, len(g), sum(r[3] for r in g))
