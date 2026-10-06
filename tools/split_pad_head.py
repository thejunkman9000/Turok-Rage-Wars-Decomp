#!/usr/bin/env python3
"""Split leading stray words (linker padding of the previous object) off a hasm function.

usage: python tools/split_pad_head.py [--ovl] <function> <n words>
Rewrites src/<subdir>/<function>.s (drops the first n instruction lines, the primary glabel stays), moves them to
pad_<ROM>.s, and fixes the manifest entry (start += 4n, insns -= n).  References `<function> + 0x..` in other hasm
sources are rewritten to plain `<function>` (the symbol now is the real entry point)."""
import re, sys, os, struct, glob
args = sys.argv[1:]
ovl = '--ovl' in args
if ovl: args.remove('--ovl')
fn, n = args[0], int(args[1])
sub = 'ovl_a' if ovl else 'libultra'
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
rom = open('baserom.us.v11.z64', 'rb').read()
lines = open(manifest).read().split('\n')
for i, l in enumerate(lines):
    f = l.split('#')[0].split()
    if f and f[0] == fn:
        start = int(f[1], 16); total = int(f[2]); rest = f[4:]
        lines[i] = ' '.join([fn, '0x%X' % (start + 4 * n), str(total - n), sub] + rest)
        a0 = start
        words = [(a0 + 4 * k, '%08X' % struct.unpack('>I', rom[a0 + 4 * k:a0 + 4 * k + 4])[0]) for k in range(n)]
        lines.insert(i, f'pad_{a0:06X} 0x{a0:X} {n} {sub}')
        break
else:
    sys.exit('not in manifest')
open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
       f'/* linker padding: stray words between objects, ROM 0x{a0:X} */', f'glabel pad_{a0:06X}']
for r, w in words: out.append(f'    /* {r:X} */  .word      0x{w}')
out.append(f'endlabel pad_{a0:06X}')
open(f'src/{sub}/pad_{a0:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
p = f'src/{sub}/{fn}.s'
t = open(p).read().split('\n')
INSN = re.compile(r'^\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s*\*/')
removed = 0
res = []
for l in t:
    if removed < n and INSN.match(l):
        removed += 1
        continue
    res.append(l)
res = [re.sub(r'ROM 0x[0-9A-F]+-', 'ROM 0x%X-' % (start + 4 * n), l) if l.startswith('/* hand-written') else l for l in res]
open(p, 'w', newline='\n').write('\n'.join(res))
for q in glob.glob('src/**/*.s', recursive=True):
    s = open(q).read()
    s2 = re.sub(r'\b' + re.escape(fn) + r' \+ 0x[0-9A-Fa-f]+', fn, s)
    if s2 != s: open(q, 'w', newline='\n').write(s2); print('fixed refs in', q)
print(f'{fn}: {n} words moved to pad_{a0:06X}')
