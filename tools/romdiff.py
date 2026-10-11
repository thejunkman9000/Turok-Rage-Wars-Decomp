#!/usr/bin/env python3
"""Where does a release workspace's build differ from the release ROM, and which unit owns the bytes?  (runs in WSL)

usage:  python3 /mnt/d/Projects/TurokRageWars/tools/romdiff.py <workspace> [--clusters N] [--objs]
   reads  ~/trw_<ws>/build/turok_ragewars.z64  (the build)  and  /mnt/d/Projects/ws/<ws>/<BASEROM>  (the release)
   prints the first N clusters of differing bytes with their owner:
     unit:<name>   a kept C unit of funcs.txt / funcs_a.txt (its code range)      ro:<name>  its rodata piece (ro= entry)
     asm:<file>    splat asm file that starts at or before the offset              data       the unsplit data blob
   --objs also compares every kept unit's object (.text / .rodata size) with its manifest entry: the first unit whose object is
   larger or smaller than the ROM range it has to fill is where a length shift starts (everything after it differs).
"""
import bisect, glob, os, re, subprocess, sys

ws = sys.argv[1]
ncl = int(sys.argv[sys.argv.index('--clusters') + 1]) if '--clusters' in sys.argv else 40
root = f'/mnt/d/Projects/ws/{ws}'
build = os.path.expanduser(f'~/trw_{ws}/build')
mk = open(f'{root}/Makefile').read()
rom_name = re.search(r'BASEROM\s*:=\s*(\S+)', mk).group(1)
a = open(f'{build}/turok_ragewars.z64', 'rb').read()
b = open(f'{root}/{rom_name}', 'rb').read()
print(f'build {len(a)} bytes, release {len(b)} bytes (delta {len(a) - len(b):+d})')

units = []            # (rom_start, rom_end, kind, name)
objs = []             # (name, subdir, insns, rom, ro)
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(f'{root}/{fn}'):
        f = l.split('#')[0].split()
        if len(f) < 4: continue
        name, rom, n, sub = f[0], int(f[1], 16), int(f[2]), f[3]
        units.append((rom, rom + 4 * n, 'unit', name))
        ro = None
        for e in f[4:]:
            m = re.fullmatch(r'ro=(0x[0-9A-Fa-f]+):(\d+)(?::(\d+))?', e)
            if m:
                ro = (int(m.group(1), 16), int(m.group(2)))
                units.append((ro[0], ro[0] + ro[1], 'ro', name))
        objs.append((name, sub, n, rom, ro))
units.sort()
starts = [u[0] for u in units]
asm_starts = sorted(int(os.path.basename(p)[:-2], 16) for p in glob.glob(f'{root}/asm/*.s') if re.fullmatch(r'[0-9A-Fa-f]+\.s', os.path.basename(p)))

def owner(off):
    i = bisect.bisect_right(starts, off) - 1
    # units never overlap except a ro piece inside the data area: scan back a few
    for j in range(i, max(-1, i - 3), -1):
        s, e, kind, name = units[j]
        if s <= off < e: return f'{kind}:{name}'
    k = bisect.bisect_right(asm_starts, off) - 1
    return f'asm:{asm_starts[k]:X}.s' if k >= 0 else 'header'

n = min(len(a), len(b)); k = 0; clusters = []
while k < n and len(clusters) < ncl:
    while k < n and a[k] == b[k]: k += 1
    if k >= n: break
    s = k; last = k
    while k < n and k - last < 64:
        if a[k] != b[k]: last = k
        k += 1
    clusters.append((s, last))
print(f'first {len(clusters)} clusters:')
for s, e in clusters:
    print(f'  0x{s:X}..0x{e:X} ({e - s + 1} bytes)  owner {owner(s)}' + ('' if owner(s) == owner(e) else f' .. {owner(e)}')
          + (f'   built {a[s:s + 8].hex()} release {b[s:s + 8].hex()}' if e - s < 16 else ''))

if '--objs' in sys.argv:
    print('object sizes against the manifest:')
    bad = 0
    for name, sub, insns, rom, ro in sorted(objs, key=lambda t: t[3]):
        o = f'{build}/src/{sub}/{name}.o'
        if not os.path.exists(o): continue
        out = subprocess.run(['mips-linux-gnu-objdump', '-h', o], capture_output=True, text=True).stdout
        sz = {}
        for m in re.finditer(r'^\s*\d+\s+(\.\w+)\s+([0-9a-f]+)', out, re.M): sz[m.group(1)] = int(m.group(2), 16)
        t = sz.get('.text', 0); r = sz.get('.rodata', 0)
        bt = insns * 4
        if t != bt or (ro and r != ro[1] and r + 8 < ro[1]):
            bad += 1
            if bad <= 60: print(f'  {name} rom 0x{rom:X}: .text {t} vs manifest {bt}' + (f', .rodata {r} vs ro {ro[1]}' if ro else ''))
    print(f'  {bad} unit(s) whose object size differs from the manifest range')
