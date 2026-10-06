#!/usr/bin/env python3
"""Replace several consecutive manifest entries (hasm functions) by ONE C object (src/<subdir>/<obj>.c holding all of them).

usage: python tools/merge_c.py [--ovl] <obj> <first-function> <last-function> <c insns> [ro=0xROM:bytes] [mode=..]
The entries from <first-function> to <last-function> (inclusive, in manifest order) are removed together with their .s
files; the object entry `<obj> <first rom> <c insns> <subdir> [opts]` is added, and whatever remains of the old range
(linker padding) is written to pad_<ROM>.s using the ROM bytes."""
import sys, os, struct
args = sys.argv[1:]
ovl = '--ovl' in args
if ovl: args.remove('--ovl')
obj, first, last, cn = args[:4]; opts = args[4:]
cn = int(cn)
sub = 'ovl_a' if ovl else 'libultra'
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
rom = open('baserom.us.v11.z64', 'rb').read()
lines = open(manifest).read().split('\n')
names = [l.split('#')[0].split()[0] if l.split('#')[0].split() else None for l in lines]
i0, i1 = names.index(first), names.index(last)
ents = [l.split() for l in lines[i0:i1 + 1] if l.strip()]
start = int(ents[0][1], 16)
end = int(ents[-1][1], 16) + 4 * int(ents[-1][2])
total = (end - start) // 4
for e in ents:
    p = f'src/{sub}/{e[0]}.s'
    if os.path.exists(p): os.remove(p)
new = [f'{obj} 0x{start:X} {cn} {sub}' + (' ' + ' '.join(opts) if opts else '')]
if cn < total:
    a0 = start + 4 * cn
    words = [(a0 + 4 * k, '%08X' % struct.unpack('>I', rom[a0 + 4 * k:a0 + 4 * k + 4])[0]) for k in range(total - cn)]
    out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
           f'/* linker padding: stray words between objects, ROM 0x{a0:X} */', f'glabel pad_{a0:06X}']
    for r, w in words: out.append(f'    /* {r:X} */  .word      0x{w}')
    out.append(f'endlabel pad_{a0:06X}')
    open(f'src/{sub}/pad_{a0:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
    new.append(f'pad_{a0:06X} 0x{a0:X} {total - cn} {sub}')
lines[i0:i1 + 1] = new
open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
print(f'{obj}: {total} insns replaced, C has {cn}, padding {total - cn}')
