#!/usr/bin/env python3
"""Promote hand-written asm functions (src/<subdir>/<name>.s) to their matched C source (src/<subdir>/<name>.c must exist).

usage: python tools/to_c.py [--ovl] <name> [<name> ...]
Moves trailing `.word ... linker padding` words into pad_<ROM>.s, deletes the .s and rewrites the manifest entry
(funcs.txt, or funcs_a.txt with --ovl which also adds mode=lu).  Run tools/cycle.ps1 afterwards."""
import re, sys, os
args = sys.argv[1:]
ovl = '--ovl' in args
if ovl: args.remove('--ovl')
sub = 'ovl_a' if ovl else 'libultra'
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
lines = open(manifest).read().split('\n')
for name in args:
    p = f'src/{sub}/{name}.s'
    t = open(p).read().split('\n')
    pad = []
    for l in t:
        m = re.match(r'\s*/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/\s+\.word\s+0x[0-9A-Fa-f]+\s*/\* linker padding', l)
        if m: pad.append((int(m.group(1), 16), m.group(2)))
    for i, l in enumerate(lines):
        f = l.split('#')[0].split()
        if f and f[0] == name:
            n = int(f[2]) - len(pad)
            extra = ' '.join(f[4:]) if len(f) > 4 else ''
            if ovl and 'mode=lu' not in extra: extra = (extra + ' mode=lu').strip()
            lines[i] = f'{name} {f[1]} {n} {sub}' + (' ' + extra if extra else '')
            if pad:
                rom = pad[0][0]
                lines.insert(i + 1, f'pad_{rom:06X} 0x{rom:X} {len(pad)} {sub}')
            break
    else:
        sys.exit(f'{name} not in {manifest}')
    if pad:
        rom = pad[0][0]
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
               f'/* linker padding: stray words between objects, ROM 0x{rom:X} */', f'glabel pad_{rom:06X}']
        for r, w in pad: out.append(f'    /* {r:X} */  .word      0x{w.upper()}')
        out.append(f'endlabel pad_{rom:06X}')
        open(f'src/{sub}/pad_{rom:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
    os.remove(p)
open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
