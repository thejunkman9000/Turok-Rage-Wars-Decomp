#!/usr/bin/env python3
"""Regenerate the `main` segment's subsegments in turok_ragewars.yaml from funcs.txt.

usage: python tools/gen_yaml.py        (from the project root; then run splat + tools/fix_asm.py)

funcs.txt line:  <name> <rom_start> <instruction_count> <src subdir> [ro=<rom_offset>:<bytes>]
  - code: asm covers every gap between the listed functions.
  - ro=...: the function's float-literal pool / rodata lives at that ROM offset; the big data blob after the code is
    split around these pieces so the object's `.rodata` is linked at exactly that spot (rodata_map.txt tells
    tools/cc.sh where, so `li.s` literals can be addressed absolutely).
The block between the BEGIN/END GENERATED markers is replaced.
"""
import os, re, sys

MAIN_START, MAIN_CODE_END, DATA_END = 0x1000, 0xC76B0, 0x160000
OVL_START, OVL_END = 0x16E000, 0x1BCDA0
if os.environ.get('VER_LAYOUT'):          # another release: a file of `NAME = 0xVALUE` lines (MAIN_CODE_END, DATA_END, OVL_START, OVL_END) written by tools/mkver.py
    for _l in open(os.environ['VER_LAYOUT']):
        _m = re.match(r'\s*(MAIN_START|MAIN_CODE_END|DATA_END|OVL_START|OVL_END)\s*=\s*(0x[0-9A-Fa-f]+)', _l)
        if _m: globals()[_m.group(1)] = int(_m.group(2), 16)
funcs, ros, modes = [], [], []
real_sizes = {}      # name -> size of the data proper when the piece is larger (alignment tail comes from the ROM)
for line in open('funcs.txt'):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    name, rom, n, sub = f[:4]
    funcs.append((int(rom, 16), int(n), name, sub))
    for extra in f[4:]:
        mm = re.fullmatch(r'mode=([\w+]+)', extra)
        if mm:
            modes.append((name, mm.group(1)))
            continue
        m = re.fullmatch(r'ro=(0x[0-9A-Fa-f]+):(\d+)(?::(\d+))?', extra)
        if not m: sys.exit(f'bad option {extra!r} for {name}')
        ros.append((int(m.group(1), 16), int(m.group(2)), name, sub))
        if m.group(3): real_sizes[name] = int(m.group(3))
# overlay A objects keep their float literals / jump tables in the main image's data area: their ro= pieces go in the same list
if os.path.exists('funcs_a.txt'):
    for line in open('funcs_a.txt'):
        line = line.split('#')[0].strip()
        if not line: continue
        f = line.split()
        for extra in f[4:]:
            m = re.fullmatch(r'ro=(0x[0-9A-Fa-f]+):(\d+)(?::(\d+))?', extra)
            if m:
                ros.append((int(m.group(1), 16), int(m.group(2)), f[0], f[3]))
                if m.group(3): real_sizes[f[0]] = int(m.group(3))
funcs.sort(); ros.sort()

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

# data blob after the code: split around owned rodata pieces. Pieces and the blobs after them go in the rodata group.
if not ros:
    lines.append(f'      - [0x{MAIN_CODE_END:X}, bin, rsp_and_data_unsplit]')
else:
    first_ro = ros[0][0]
    if first_ro > MAIN_CODE_END: lines.append(f'      - [0x{MAIN_CODE_END:X}, bin, rsp_and_data_0]')      # an owned rodata piece right at the start of the blob (func_002014A4 ro=0xC76B0) leaves it empty: splat rejects a zero-size segment
    cur = first_ro
    k = 1
    for off, size, name, sub in ros:
        if off < cur: sys.exit(f'rodata overlap at 0x{off:X} ({name})')
        if off > cur:
            lines.append(f'      - {{start: 0x{cur:X}, type: bin, name: data_{k}, linker_section_order: .rodata, linker_section: .data}}')
            k += 1
        lines.append(f'      - [0x{off:X}, .rodata, {sub}/{name}]')
        cur = off + size
    if cur < DATA_END:
        lines.append(f'      - {{start: 0x{cur:X}, type: bin, name: data_{k}, linker_section_order: .rodata, linker_section: .data}}')
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


# ---- overlay A (ROM 0x16E000-0x1BCDA0, VRAM 0x400000): funcs_a.txt, same line format (no ro= support yet) ----
oros = []
if os.path.exists('funcs_a.txt'):
    ofuncs = []
    for line in open('funcs_a.txt'):
        line = line.split('#')[0].strip()
        if not line: continue
        f = line.split()
        name, rom, n, sub = f[:4]
        for extra in f[4:]:
            mm = re.fullmatch(r'mode=([\w+]+)', extra)
            if mm: modes.append((name, mm.group(1))); continue
            mr = re.fullmatch(r'ro=(0x[0-9A-Fa-f]+):(\d+)(?::(\d+))?', extra)
            if mr: continue          # overlay objects' literals live in the main image's rodata area: collected above with the main pieces
            sys.exit(f'overlay A entry {name}: option {extra!r} not supported')
        ofuncs.append((int(rom, 16), int(n), name, sub))
    ofuncs.sort()
    olines, pos = [], OVL_START
    for rom, n, name, sub in ofuncs:
        if rom < pos: sys.exit(f'overlap: {name} at 0x{rom:X} starts before 0x{pos:X}')
        if rom > pos or not olines and rom == OVL_START and False:
            olines.append(f'      - [0x{pos:X}, asm]')
        olines.append(f'      - [0x{rom:X}, c, {sub}/{name}]')
        pos = rom + 4 * n
    if pos < OVL_END: olines.append(f'      - [0x{pos:X}, asm]')
    if not olines: olines = [f'      - [0x{OVL_START:X}, asm]']
    # the overlay's rodata/data tail (0x1BCDA0..): split around the rodata pieces owned by C objects
    oros.sort()
    if not oros:
        olines.append(f'      - [0x{OVL_END:X}, bin, ovl_a_tail]')
    else:
        cur, k = OVL_END, 0
        for off, size, name, sub in oros:
            if off < cur: sys.exit(f'overlay rodata overlap at 0x{off:X} ({name})')
            if off > cur:
                olines.append(f'      - {{start: 0x{cur:X}, type: bin, name: ovl_a_data_{k}, linker_section_order: .rodata, linker_section: .data}}')
                k += 1
            olines.append(f'      - [0x{off:X}, .rodata, {sub}/{name}]')
            cur = off + size
        olines.append(f'      - {{start: 0x{cur:X}, type: bin, name: ovl_a_data_{k}, linker_section_order: .rodata, linker_section: .data}}')
    y = open('turok_ragewars.yaml', newline='').read().replace(chr(13) + chr(10), chr(10))
    B2, E2 = '      # BEGIN GENERATED ovl_a subsegments (tools/gen_yaml.py)', '      # END GENERATED'
    k = y.index(B2)
    k2 = y.index(E2, k)
    y = y[:k] + B2 + chr(10) + chr(10).join(olines) + chr(10) + y[k2:]
    open('turok_ragewars.yaml', 'w', newline=chr(10)).write(y)
    # mode_map is written below; make sure overlay modes are included

# map for tools/cc.sh: <source name> <rodata ROM offset> <bytes>
with open('rodata_map.txt', 'w', newline='\n') as f:
    f.write('# generated by tools/gen_yaml.py: <source name> <rodata rom offset> <bytes>\n')
    for off, size, name, sub in ros:
        f.write(f'{name} 0x{off:X} {size}' + (f' {real_sizes[name]}' if name in real_sizes else '') + '\n')
with open('mode_map.txt', 'w', newline='\n') as f:
    f.write('# generated by tools/gen_yaml.py: <source name> <cc.sh mode override>\n')
    for name, mode in modes:
        f.write(f'{name} {mode}\n')
print(f'{len(funcs)} functions, {len(ros)} rodata pieces -> yaml updated')
