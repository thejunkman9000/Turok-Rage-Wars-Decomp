#!/usr/bin/env python3
"""Turn the small leftover splat asm chunks inside a ROM range (linker padding between functions: every object was
padded to 16 bytes with stray words) into src/<subdir>/pad_<rom>.s files made of `.word`s.

usage: python tools/mkpad.py <rom_start_hex> <rom_end_hex> [--subdir libultra]
Prints the funcs.txt lines to add.  Only chunks that contain no `glabel` with real code are expected here; run it
after `tools/cycle.ps1` (needs asm/*.s) and then re-run the cycle.
"""
import re, glob, os, sys

lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
subdir = 'libultra'
if '--subdir' in sys.argv:
    subdir = sys.argv[sys.argv.index('--subdir') + 1]
INSN = re.compile(r'^\s*/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/')
os.makedirs(f'src/{subdir}', exist_ok=True)
for p in sorted(glob.glob('asm/*.s')):
    words = []
    for l in open(p, encoding='utf-8'):
        m = INSN.match(l)
        if m:
            words.append((int(m.group(1), 16), int(m.group(3), 16)))
    if not words or not (lo <= words[0][0] and words[-1][0] < hi):
        continue
    start = words[0][0]
    if len(words) > 8:
        print(f'# skipped {p}: {len(words)} words at 0x{start:X}', file=sys.stderr)
        continue
    name = f'pad_{start:06X}'
    text = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
            f'/* linker padding: stray words between objects, ROM 0x{start:X} */',
            f'glabel {name}']
    for rom, w in words:
        text.append(f'    /* {rom:X} */  .word      0x{w:08X}')
    text += [f'endlabel {name}', '']
    with open(f'src/{subdir}/{name}.s', 'w', encoding='utf-8', newline='\n') as f:
        f.write('\n'.join(text))
    print(f'{name} 0x{start:X} {len(words)} {subdir}')
