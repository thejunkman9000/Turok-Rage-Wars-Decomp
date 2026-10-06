#!/usr/bin/env python3
"""Integrate a worker's results into the main tree.

usage: python tools/apply_results.py <workspace dir> [--game] [--ovl] [--dry]
Reads <ws>/wip/out/results.txt; for every EXACT line copies <ws>/wip/out/<fn>.c to src/<subdir>/ (libultra by default,
ovl_a with --ovl, game with --game), copies new headers (include/*_types.h not yet present), and updates the manifest:
 - hasm function present in the manifest (libultra/ovl): tools/to_c.py semantics (pad from ROM words after the C insns)
 - --game: new manifest entry  <fn> <rom> <insns> game  (+pad entry if the splat function is longer than the C code)
Compile mode from the `flags:` text: -msplit-addresses -> lu4; `-O2 -mcpu=r4300` -> lu3; `-O2 -fforce-addr` -> lu2; default -> lu.
Run tools/cycle.ps1 afterwards; fix whatever it reports."""
import re, sys, os, shutil, struct, subprocess
ws = sys.argv[1]
game = '--game' in sys.argv
ovl = '--ovl' in sys.argv
dry = '--dry' in sys.argv
sub = 'game' if game else ('ovl_a' if ovl else 'libultra')
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
rom = open('baserom.us.v11.z64', 'rb').read()
gf = {}
if game:
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#'): continue
        f = l.split(); gf[f[1]] = (int(f[0], 16), int(f[2]))
os.makedirs(f'src/{sub}', exist_ok=True)
for h in os.listdir(f'{ws}/include'):
    if h.endswith('_types.h') and not os.path.exists(f'include/{h}'):
        shutil.copy(f'{ws}/include/{h}', f'include/{h}'); print('new header', h)
lines = open(manifest).read().split('\n')
have = {l.split('#')[0].split()[0]: i for i, l in enumerate(lines) if l.split('#')[0].split()}
todo = []
for l in open(f'{ws}/wip/out/results.txt'):
    f = l.split('#')[0].split()
    if len(f) < 4 or f[3] != 'EXACT': continue
    fn, r, n = f[0], int(f[1], 16), int(f[2])
    ro = [t for t in f[4:] if t.startswith('ro=')]
    fl = ' '.join(f[4:])
    if '-msplit-addresses' in fl: mode = 'lu4'
    elif '-fforce-addr' in fl and '-O2' in fl: mode = 'lu2'
    elif '-O2' in fl and '-mcpu=r4300' in fl: mode = 'lu3'
    else: mode = 'lu'
    if game: mode = ''
    todo.append((fn, r, n, ro, mode))
def padfile(a, n):
    words = [(a + 4 * k, '%08X' % struct.unpack('>I', rom[a + 4 * k:a + 4 * k + 4])[0]) for k in range(n)]
    out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
           f'/* linker padding: stray words between objects, ROM 0x{a:X} */', f'glabel pad_{a:06X}']
    for r, w in words: out.append(f'    /* {r:X} */  .word      0x{w}')
    out.append(f'endlabel pad_{a:06X}')
    if not dry: open(f'src/{sub}/pad_{a:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
new = []
for fn, r, n, ro, mode in todo:
    src = f'{ws}/wip/out/{fn}.c'
    if not os.path.exists(src): print('missing', src); continue
    if game:
        if fn not in gf: print('not a game function:', fn); continue
        r0, total = gf[fn]
        opts = ' '.join(ro)
        entry = f'{fn} 0x{r0:X} {n} game' + (' ' + opts if opts else '')
        if fn in have: lines[have[fn]] = entry
        else: new.append(entry)
        if n < total:
            a = r0 + 4 * n
            new.append(f'pad_{a:06X} 0x{a:X} {total - n} game'); padfile(a, total - n)
    else:
        if fn not in have: print('not in manifest:', fn); continue
        f = lines[have[fn]].split()
        start, total = int(f[1], 16), int(f[2])
        extra = [t for t in f[4:] if not t.startswith('mode=')] if len(f) > 4 else []
        extra = [t for t in extra if not (t.startswith('ro=') and ro)] + ro
        if mode: extra.append(f'mode={mode}')
        lines[have[fn]] = ' '.join([fn, f'0x{start:X}', str(n), sub] + extra)
        if n < total:
            a = start + 4 * n
            new.append(f'pad_{a:06X} 0x{a:X} {total - n} {sub}'); padfile(a, total - n)
        p = f'src/{sub}/{fn}.s'
        if os.path.exists(p) and not dry: os.remove(p)
    if not dry: shutil.copy(src, f'src/{sub}/{fn}.c')
lines = [l for l in lines]
lines += new
if not dry: open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
print(len(todo), 'exact results processed;', len(new), 'new manifest lines')
