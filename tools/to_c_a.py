#!/usr/bin/env python3
"""Promote an overlay-A hand-written asm function to its matched C source (src/ovl_a/<name>.c must exist and match).

usage: python tools/to_c_a.py <name> [<name> ...]
Reads src/ovl_a/<name>.s, moves its trailing `.word ... linker padding` words into src/ovl_a/pad_<ROM>.s, deletes the .s,
and rewrites its funcs_a.txt entry (insn count without padding, mode=lu).  Run tools/cycle.ps1 afterwards."""
import re, sys, os
lines = open('funcs_a.txt').read().split('\n')
for name in sys.argv[1:]:
    p = f'src/ovl_a/{name}.s'
    t = open(p).read().split('\n')
    pad = []
    for l in t:
        m = re.match(r'\s*/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/\s+\.word\s+0x[0-9A-Fa-f]+\s*/\* linker padding', l)
        if m: pad.append((int(m.group(1), 16), m.group(2)))
    for i, l in enumerate(lines):
        f = l.split('#')[0].split()
        if f and f[0] == name:
            n = int(f[2]) - len(pad)
            lines[i] = f'{name} {f[1]} {n} ovl_a mode=lu'
            if pad:
                rom = pad[0][0]
                lines.insert(i + 1, f'pad_{rom:X} 0x{rom:X} {len(pad)} ovl_a')
            break
    else:
        sys.exit(f'{name} not in funcs_a.txt')
    if pad:
        rom = pad[0][0]
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
               f'/* linker padding: stray words between objects, ROM 0x{rom:X} */', f'glabel pad_{rom:X}']
        for r, w in pad: out.append(f'    /* {r:X} */  .word      0x{w.upper()}')
        out.append(f'endlabel pad_{rom:X}')
        open(f'src/ovl_a/pad_{rom:X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
    os.remove(p)
open('funcs_a.txt', 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
