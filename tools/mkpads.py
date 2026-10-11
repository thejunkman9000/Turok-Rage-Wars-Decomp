#!/usr/bin/env python3
"""Write the src/<subdir>/pad_<ROM>.s files for the `pad_*` lines of a manifest-line list (same format as tools/apply_results.py padfile).

usage (from the project root, where baserom.us.v11.z64 lives):
    python wip/out/mkpads.py wip/out/pad_lines.txt [--dry]
Lines that are not `pad_<ROM> 0x<ROM> <words> <subdir>` are ignored (func_* lines, comments)."""
import struct, sys, os

lst = sys.argv[1]
dry = '--dry' in sys.argv
rom = open('baserom.us.v11.z64', 'rb').read()
n = 0
for l in open(lst):
    f = l.split('#')[0].split()
    if len(f) != 4 or not f[0].startswith('pad_'):
        continue
    a, w, sub = int(f[1], 16), int(f[2]), f[3]
    assert f[0] == 'pad_%06X' % a, f[0]
    out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
           '/* linker padding: stray words between objects, ROM 0x%X */' % a, 'glabel pad_%06X' % a]
    for k in range(w):
        out.append('    /* %X */  .word      0x%08X' % (a + 4 * k, struct.unpack('>I', rom[a + 4 * k:a + 4 * k + 4])[0]))
    out.append('endlabel pad_%06X' % a)
    p = 'src/%s/pad_%06X.s' % (sub, a)
    if not dry:
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, 'w', newline='\n').write('\n'.join(out) + '\n')
    n += 1
print(n, 'pad files', '(dry run)' if dry else 'written')
