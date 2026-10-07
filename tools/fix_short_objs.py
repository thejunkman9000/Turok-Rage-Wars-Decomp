#!/usr/bin/env python3
"""After a build: compare every game object's .text size (from build/turok_ragewars.map, copied to the path given)
with the instruction count in funcs.txt.  Shorter objects (chk counted stray words after e.g. an infinite loop) get their
count reduced and a pad_<ROM> entry for the missing words; longer objects are reported.
usage: python tools/fix_short_objs.py <map file> [--dry]"""
import re, sys, struct, os
mp = sys.argv[1]; dry = '--dry' in sys.argv
rom = open('baserom.us.v11.z64', 'rb').read()
sizes = {}
for l in open(mp, encoding='utf-8', errors='replace'):
    m = re.match(r'^ \.text\s+0x[0-9a-f]+\s+0x([0-9a-f]+) build/src/game/(\w+)\.o', l)
    if m and int(m.group(1), 16): sizes[m.group(2)] = int(m.group(1), 16)
lines = open('funcs.txt').read().split('\n')
new = []
for i, l in enumerate(lines):
    f = l.split('#')[0].split()
    if len(f) < 4 or f[3] != 'game' or f[0] not in sizes or f[0].startswith('pad_'): continue
    n = int(f[2]); act = sizes[f[0]] // 4
    if act < n:
        a = int(f[1], 16) + 4 * act; k = n - act
        print(f'short: {f[0]} {n} -> {act}, pad {k} words at 0x{a:X}')
        f[2] = str(act); lines[i] = ' '.join(f)
        if not dry: open('wip/n_overrides.txt', 'a').write(f'{f[0]} {act}' + chr(10))
        new.append(f'pad_{a:06X} 0x{a:X} {k} game')
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
               f'/* linker padding: stray words between objects, ROM 0x{a:X} */', f'glabel pad_{a:06X}']
        for j in range(k):
            w = struct.unpack('>I', rom[a + 4 * j:a + 4 * j + 4])[0]
            out.append(f'    /* {a + 4 * j:X} */  .word      0x{w:08X}')
        out.append(f'endlabel pad_{a:06X}')
        if not dry: open(f'src/game/pad_{a:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
    elif act > n:
        print(f'LONG: {f[0]} manifest {n} object {act}')
if not dry:
    have = {l.split()[0] for l in lines if l.split()}
    lines += [e for e in new if e.split()[0] not in have]
    open('funcs.txt', 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
