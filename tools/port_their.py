#!/usr/bin/env python3
"""Add functions that melalawi/ragewars-decomp matches (and our chk confirms EXACT with the sn toolchain) to our manifests.

usage: python tools/port_their.py <chk output file with `<their name> <n> insns EXACT` lines> [--dry]
 - their source file (D:/Projects/ext/ragewars-decomp/src/<name>.c) is copied unchanged to src/game|ovl_a/<our name>.c
 - manifest line `<our name> <rom> <insns> game|ovl_a mode=sn` (mode=sn272 for names in SN272)
 - our name = func_00<address in us-rev1 & 0xFFFFFF>, address from their_extra.json (their symbol table)
 - entries that would overlap an existing manifest entry are skipped and reported"""
import json, os, re, shutil, sys
res = sys.argv[1]; dry = '--dry' in sys.argv
extra = json.load(open(os.environ['TEMP'] + '/their_extra.json'))
byname = {v[0]: int(a, 16) for a, v in extra.items()}
SN272 = set(open('wip/sn272_funcs.txt').read().split()) if os.path.exists('wip/sn272_funcs.txt') else set()
ex = {}
for l in open(res, errors='replace'):
    m = re.match(r'(\S+)\s+(\d+) insns\s+EXACT(?:\s+(ro=0x[0-9A-Fa-f]+:\d+))?', l)
    if m: ex[m.group(1)] = (int(m.group(2)), m.group(3))

def load(fn):
    out = []
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4:
            r = int(f[1], 16); out.append((r, r + 4 * int(f[2]), f[0]))
    return out
existing = load('funcs.txt') + load('funcs_a.txt')
def ros():
    out = []
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(fn):
            for m in re.finditer(r'ro=(0x[0-9A-Fa-f]+):(\d+)', l.split('#')[0]):
                out.append((int(m.group(1), 16), int(m.group(1), 16) + int(m.group(2)), l.split()[0]))
    return out
rodat = ros()
add = {'funcs.txt': [], 'funcs_a.txt': []}
skipped = []
subsumed = []
for name, (n, ro) in sorted(ex.items(), key=lambda kv: byname.get(kv[0], 0)):
    va = byname.get(name)
    if va is None: skipped.append((name, 'unknown address')); continue
    ovl = 0x80400000 <= va < 0x80500000
    rom = (va & 0xFFFFFF) - 0x400000 + 0x16E000 if ovl else (va & 0xFFFFFF) - 0x1FF400
    ours = f'func_{va & 0xFFFFFF:08X}'
    tsz = extra[hex(va)][2] // 4 if hex(va) in extra else n
    n = max(n, tsz)          # their function's real size (chk's count stops at the last return)
    clash = [e for e in existing if e[0] < rom + 4 * max(n, tsz) and rom < e[1]]
    inside = [e for e in clash if e[0] >= rom and e[1] <= rom + 4 * tsz]
    if clash and (len(inside) != len(clash) or '--subsume' not in sys.argv):
        skipped.append((name, 'overlaps ' + ','.join(c[2] for c in clash[:3]))); continue
    if clash:
        n = tsz
        for c in inside:
            subsumed.append(c[2]); existing.remove(c)
    if ro:
        o = int(ro.split(':')[0][3:], 16); sz = int(ro.split(':')[1])
        rc = [r for r in rodat if r[0] < o + sz and o < r[1]]
        if rc: skipped.append((name, 'rodata overlaps ' + rc[0][2])); continue
        rodat.append((o, o + sz, ours))
    sub = 'ovl_a' if ovl else 'game'
    mode = 'sn272' if name in SN272 else 'sn'
    add['funcs_a.txt' if ovl else 'funcs.txt'].append(f'{ours} 0x{rom:X} {n} {sub} mode={mode}' + (f' {ro}' if ro else ''))
    existing.append((rom, rom + 4 * n, ours))
    if not dry:
        shutil.copy(f'D:/Projects/ext/ragewars-decomp/src/{name}.c' if os.path.exists(f'D:/Projects/ext/ragewars-decomp/src/{name}.c') else f'D:/Projects/ext/ragewars-decomp/src/fuzzy/{name}.c', f'src/{sub}/{ours}.c')
for fn, lines in add.items():
    if lines and not dry:
        t = open(fn).read()
        open(fn, 'w', newline='\n').write(t.rstrip('\n') + '\n' + '\n'.join(lines) + '\n')
for fn in ('funcs.txt', 'funcs_a.txt'):
    if subsumed and not dry:
        L = open(fn).read().split(chr(10))
        L = [l for l in L if not (l.split('#')[0].split() and l.split('#')[0].split()[0] in subsumed)]
        open(fn, 'w', newline=chr(10)).write(chr(10).join(L))
for c in subsumed:
    for sub in ('game', 'ovl_a'):
        f = f'src/{sub}/{c}.c'
        if os.path.exists(f) and not dry: os.remove(f)
if subsumed and not dry:
    open('wip/subsumed.txt', 'a').write(chr(10).join(subsumed) + chr(10))      # tools/gen_alias.py keeps these names as linker symbols
print('subsumed', len(subsumed))
print('added', sum(len(v) for v in add.values()), 'skipped', len(skipped))
for s in skipped[:30]: print('  skip', *s)
