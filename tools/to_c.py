#!/usr/bin/env python3
"""Promote hand-written asm functions (src/<subdir>/<name>.s) to their matched C source (src/<subdir>/<name>.c must exist).

usage: python tools/to_c.py [--ovl] <name>[@ro=0xROM:bytes][#insns] [...]
`#insns` is the instruction count of the compiled C (as printed by tools/chk.ps1); when given, the remaining words of the
hasm function are taken from the ROM as linker padding, otherwise only words marked `linker padding` in the .s are.
Writes pad_<ROM>.s, deletes the .s and rewrites the manifest entry (funcs.txt, or funcs_a.txt with --ovl which also adds
mode=lu).  Run tools/cycle.ps1 afterwards."""
import re, sys, os, struct
args = sys.argv[1:]
ovl = '--ovl' in args
if ovl: args.remove('--ovl')
sub = 'ovl_a' if ovl else 'libultra'
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
rom = open('baserom.us.v11.z64', 'rb').read()
lines = open(manifest).read().split('\n')
for arg in args:
    arg, _, cn = arg.partition('#')
    name, _, ro = arg.partition('@')
    ro = ro.replace('@', ' ')
    p = f'src/{sub}/{name}.s'
    pad = []
    if cn:
        for i, l in enumerate(lines):
            f = l.split('#')[0].split()
            if f and f[0] == name:
                start = int(f[1], 16); total = int(f[2])
                for k in range(int(cn), total):
                    a = start + 4 * k
                    pad.append((a, '%08X' % struct.unpack('>I', rom[a:a + 4])[0]))
    else:
        for l in open(p).read().split('\n'):
            m = re.match(r'\s*/\*\s*([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/\s+\.word\s+0x[0-9A-Fa-f]+\s*/\* linker padding', l)
            if m: pad.append((int(m.group(1), 16), m.group(2)))
    for i, l in enumerate(lines):
        f = l.split('#')[0].split()
        if f and f[0] == name:
            n = int(f[2]) - len(pad)
            extra = ' '.join(f[4:]) if len(f) > 4 else ''
            if ro: extra = (extra + ' ' + ro).strip()
            if ovl and 'mode=lu' not in extra: extra = (extra + ' mode=lu').strip()
            lines[i] = f'{name} {f[1]} {n} {sub}' + (' ' + extra if extra else '')
            if pad:
                a0 = pad[0][0]
                lines.insert(i + 1, f'pad_{a0:06X} 0x{a0:X} {len(pad)} {sub}')
            break
    else:
        sys.exit(f'{name} not in {manifest}')
    if pad:
        a0 = pad[0][0]
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
               f'/* linker padding: stray words between objects, ROM 0x{a0:X} */', f'glabel pad_{a0:06X}']
        for r, w in pad: out.append(f'    /* {r:X} */  .word      0x{w.upper()}')
        out.append(f'endlabel pad_{a0:06X}')
        open(f'src/{sub}/pad_{a0:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
    if os.path.exists(p): os.remove(p)
open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
