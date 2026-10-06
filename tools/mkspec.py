#!/usr/bin/env python3
"""Print a tools/mkhasm.py spec covering every function of the splat-generated asm in a ROM range.

usage: python tools/mkspec.py <rom_start_hex> <rom_end_hex> [--names names.txt]

Functions are taken from the `glabel`s of asm/*.s.  A glabel that follows an exit (`jr`/`j`) and covers only a few
words that end on a 16-byte boundary is linker padding (stray words left behind when every object was padded to 16
bytes) and is merged into the previous function.  `names.txt` lines `<rom_hex> <new name>` rename functions.
Output lines:  <name> <start> <end>
"""
import re, glob, sys

lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
names = {}
if '--names' in sys.argv:
    for l in open(sys.argv[sys.argv.index('--names') + 1]):
        l = l.split('#')[0].split()
        if len(l) == 2:
            names[int(l[0], 16)] = l[1]

INSN = re.compile(r'^\s*/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/\s*(\S.*)$')
funcs = []                         # [name, start, end, first mnemonic]
for p in sorted(glob.glob('asm/*.s')):
    cur = None
    for l in open(p, encoding='utf-8'):
        m = re.match(r'^glabel (\w+)', l)
        if m:
            cur = [m.group(1), None, None, '']
            funcs.append(cur)
            continue
        m = INSN.match(l)
        if m and cur is not None:
            rom = int(m.group(1), 16)
            if cur[1] is None:
                cur[1] = rom
                cur[3] = m.group(4).split()[0]
            cur[2] = rom + 4
funcs = sorted(f for f in funcs if f[1] is not None and lo <= f[1] < hi)

merged = []
for f in funcs:
    size = (f[2] - f[1]) // 4
    prev = merged[-1] if merged else None
    if prev and prev[2] == f[1] and size <= 3 and f[1] % 16 != 0 and f[2] % 16 == 0 and f[3] != 'addiu':
        prev[2] = f[2]
        continue
    merged.append(f)
for name, start, end, _ in merged:
    print(f'{names.get(start, name)} 0x{start:X} 0x{min(end, hi):X}')
