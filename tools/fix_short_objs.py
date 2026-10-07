#!/usr/bin/env python3
"""After a build: compare every game / overlay-A object's .text size (from build/turok_ragewars.map, copied to the path
given) with the instruction count in the manifest (funcs.txt, funcs_a.txt).  Shorter objects (chk counted stray words
after e.g. an infinite loop) get their count reduced and a pad_<ROM> entry for the missing words; longer objects are
reported.   usage: python tools/fix_short_objs.py <map file> [--dry]"""
import re, sys, struct, os
mp = sys.argv[1]; dry = '--dry' in sys.argv
rom = open('baserom.us.v11.z64', 'rb').read()
sizes = {}
for l in open(mp, encoding='utf-8', errors='replace'):
    m = re.match(r'^ \.text\s+0x[0-9a-f]+\s+0x([0-9a-f]+) build/src/(game|ovl_a)/(\w+)\.o', l)
    if m and int(m.group(1), 16): sizes[(m.group(2), m.group(3))] = int(m.group(1), 16)
for manifest, sub in (('funcs.txt', 'game'), ('funcs_a.txt', 'ovl_a')):
    if not os.path.exists(manifest): continue
    lines = open(manifest).read().split('\n')
    new = []; drop = set()
    for i, l in enumerate(lines):
        f = l.split('#')[0].split()
        if len(f) < 4 or f[3] != sub or (sub, f[0]) not in sizes or f[0].startswith('pad_'): continue
        n = int(f[2]); act = sizes[(sub, f[0])] // 4
        if act < n:
            a = int(f[1], 16) + 4 * act; k = n - act
            print(f'short: {f[0]} {n} -> {act}, pad {k} words at 0x{a:X}')
            f[2] = str(act); lines[i] = ' '.join(f)
            if not dry: open('wip/n_overrides.txt', 'a').write(f'{f[0]} {act}' + chr(10))
            new.append(f'pad_{a:06X} 0x{a:X} {k} {sub}')
            out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
                   f'/* linker padding: stray words between objects, ROM 0x{a:X} */', f'glabel pad_{a:06X}']
            for j in range(k):
                w = struct.unpack('>I', rom[a + 4 * j:a + 4 * j + 4])[0]
                out.append(f'    /* {a + 4 * j:X} */  .word      0x{w:08X}')
            out.append(f'endlabel pad_{a:06X}')
            if not dry: open(f'src/{sub}/pad_{a:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
        elif act > n:
            # a multi-function object (deferred inline helpers, jump-table pieces, shared pool): it covers the following
            # ROM words too.  Extend the count and absorb the manifest entries inside the span; the build decides.
            st = int(f[1], 16); en = st + 4 * act
            print(f'LONG: {f[0]} manifest {n} object {act}: extending, absorbing entries in 0x{st:X}..0x{en:X}')
            f[2] = str(act); lines[i] = ' '.join(f)
            if not dry:
                open('wip/n_overrides.txt', 'a').write(f'{f[0]} {act}' + chr(10))
                for j, l2 in enumerate(lines):
                    g = l2.split('#')[0].split()
                    if len(g) >= 4 and g[3] == sub and j != i and st < int(g[1], 16) < en:
                        drop.add(j)
                        if not g[0].startswith('pad_'):
                            open('wip/absorbed.txt', 'a').write(g[0] + chr(10))
                            q = f'src/{sub}/{g[0]}.c'
                            if os.path.exists(q): os.remove(q)
                        else:
                            q = f'src/{sub}/{g[0]}.s'
                            if os.path.exists(q): os.remove(q)
    lines = [l for j, l in enumerate(lines) if j not in drop]
    if not dry:
        have = {l.split()[0] for l in lines if l.split()}
        lines += [e for e in new if e.split()[0] not in have]
        open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
