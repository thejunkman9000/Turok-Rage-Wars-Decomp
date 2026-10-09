#!/usr/bin/env python3
"""Replace several per-function manifest entries by ONE whole-object C file.

usage: python tools/apply_object.py <obj> <c file> <rom start hex> <c insns> <ro=0xROM:bytes|-> <mode|-> <name,name,...> [--subdir libultra] [--pad ROM:words]
The listed function entries (and their src/<subdir>/<name>.{c,s} files) are removed from funcs.txt, the object file is copied to
src/<subdir>/<obj>.c and the entry `<obj> <rom> <insns> <subdir> [ro=..] [mode=..]` is added.  --pad adds a pad_<rom> entry
(+file from the ROM bytes)."""
import sys, os, shutil, struct
a = sys.argv[1:]
subdir = 'libultra'; pads = []
if '--subdir' in a:
    i = a.index('--subdir'); subdir = a[i + 1]; del a[i:i + 2]
while '--pad' in a:
    i = a.index('--pad'); pads.append(a[i + 1]); del a[i:i + 2]
obj, cfile, rom, n, ro, mode, names = a[:7]
names = set(names.split(','))
manifest = 'funcs.txt'
rom_data = open('baserom.us.v11.z64', 'rb').read()
lines = open(manifest).read().split('\n')
keep = []
for l in lines:
    f = l.split('#')[0].split()
    if f and f[0] in names:
        continue
    keep.append(l)
extra = ''
if ro != '-': extra += ' ' + ro
if mode != '-': extra += ' mode=' + mode
keep.append(f'{obj} {rom} {n} {subdir}{extra}')
for p in pads:
    r, w = p.split(':'); r = int(r, 16); w = int(w)
    if not any(l.split() and l.split()[0] == f'pad_{r:06X}' for l in keep):
        keep.append(f'pad_{r:06X} 0x{r:X} {w} {subdir}')
        words = [(r + 4 * k, '%08X' % struct.unpack('>I', rom_data[r + 4 * k:r + 4 * k + 4])[0]) for k in range(w)]
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
               f'/* linker padding: stray words between objects, ROM 0x{r:X} */', f'glabel pad_{r:06X}']
        for x, y in words: out.append(f'    /* {x:X} */  .word      0x{y}')
        out.append(f'endlabel pad_{r:06X}')
        open(f'src/{subdir}/pad_{r:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
open(manifest, 'w', newline='\n').write('\n'.join(keep).rstrip('\n') + '\n')
for nm in names:
    for ext in ('c', 's'):
        p = f'src/{subdir}/{nm}.{ext}'
        if os.path.exists(p): os.remove(p)
shutil.copy(cfile, f'src/{subdir}/{obj}.c')
print('object', obj, 'installed;', len(names), 'entries removed')
