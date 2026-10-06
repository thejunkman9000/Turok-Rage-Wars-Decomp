#!/usr/bin/env python3
"""Regenerate the `main` segment's subsegments in turok_ragewars.yaml from funcs.txt.

usage: python tools/gen_yaml.py        (from the project root; then run splat + tools/fix_asm.py)
The block between the BEGIN/END GENERATED markers is replaced; asm covers every gap between functions.
"""
import re, sys

MAIN_START, MAIN_CODE_END = 0x1000, 0xC7010
funcs = []
for line in open('funcs.txt'):
    line = line.split('#')[0].strip()
    if not line: continue
    name, rom, n, sub = line.split()
    funcs.append((int(rom, 16), int(n), name, sub))
funcs.sort()

lines = [f'      - [0x{MAIN_START:X}, asm, entry]']
pos = MAIN_START
first = True
for rom, n, name, sub in funcs:
    end = rom + 4 * n
    if rom < pos:
        sys.exit(f'overlap: {name} at 0x{rom:X} starts before 0x{pos:X}')
    if rom > pos and not (first and rom == MAIN_START):
        if pos != MAIN_START:                      # the very first asm chunk is `entry` (already emitted)
            lines.append(f'      - [0x{pos:X}, asm]')
    lines.append(f'      - [0x{rom:X}, c, {sub}/{name}]')
    pos = end
    first = False
if pos < MAIN_CODE_END:
    lines.append(f'      - [0x{pos:X}, asm]')
lines.append(f'      - [0x{MAIN_CODE_END:X}, bin, rsp_and_data_unsplit]')
block = '\n'.join(lines)

y = open('turok_ragewars.yaml', newline='').read().replace('\r\n', '\n')
B, E = '      # BEGIN GENERATED main subsegments (tools/gen_yaml.py)', '      # END GENERATED'
if B in y:
    y = re.sub(re.escape(B) + r'.*?' + re.escape(E), B + '\n' + block + '\n' + E, y, flags=re.S)
else:
    m = re.search(r'(  - name: main\n    type: code\n    start: 0x1000\n    vram: 0x200400\n    subsegments:\n)(.*?)(\n\n  # 56 KB)', y, re.S)
    if not m: sys.exit('could not find the main segment block')
    y = y[:m.start(2)] + B + '\n' + block + '\n' + E + y[m.end(2):]
open('turok_ragewars.yaml', 'w', newline='\n').write(y)
print(f'{len(funcs)} functions -> yaml updated')
