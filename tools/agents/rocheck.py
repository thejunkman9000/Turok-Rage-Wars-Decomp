#!/usr/bin/env python3
"""rocheck.py <file.c> <fn> <rom hex of fn> [tokens]: verify literal-pool usage of a function against the ROM:
 (1) every hi/lo reloc pair that points into our .rodata is decoded in the ROM; (rom address - our pool offset) must be ONE constant (= pool base)
 (2) the pool bytes of our object are compared with the ROM bytes at that base (jump-table words/relocs and the leading alignment pad are reported separately)."""
import sys, os, struct
a = sys.argv[1:]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
os.chdir('/mnt/d/Projects/ws/s702')
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = a[3:] or ['@SN']
res, err = compile_funcs(os.path.expanduser('~/trw_s702/') + a[0])
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
fn = a[1]; rom_hex = int(a[2], 16)
name, off, size = [s for s in syms if s[0] == fn][0]
n = size // 4
fw = words(text[off:off+size]); rw = words(rom[rom_hex:rom_hex+size])
sx = lambda v: v - 0x10000 if v & 0x8000 else v
pend = {}; bases = set(); offs = []
for i in range(n):
    o = off + 4*i
    if o not in relnames or relnames[o][1] not in ('.rodata', '.rdata'): continue
    t = relnames[o][0]
    if t == 'R_MIPS_HI16': pend[i] = (rw[i] & 0xFFFF, fw[i] & 0xFFFF)
    elif t == 'R_MIPS_LO16' and pend:
        k = max(pend); hi, ownhi = pend[k]
        rom_addr = ((hi << 16) + sx(rw[i] & 0xFFFF)) & 0xFFFFFFFF
        own = (ownhi << 16) + sx(fw[i] & 0xFFFF)
        bases.add(rom_addr - own); offs.append((i, own, rom_addr))
print('pool base candidates (rom addr - our offset):', [hex(b) for b in sorted(bases)])
if len(bases) != 1: print('INCONSISTENT pool offsets:', [(i, hex(o), hex(r)) for i, o, r in offs]); sys.exit(1)
base = list(bases)[0]
ro = LAST.get('ro', b'')
rb = (base & 0x1FFFFFFF) + 0xC00 if base >= 0x80000000 else base
r = rom[rb:rb+len(ro)]
bad = [i for i in range(0, len(ro), 4) if ro[i:i+4] != r[i:i+4]]
print(f'ours {len(ro)} bytes at rom 0x{rb:X}; differing words:', [(hex(i), ro[i:i+4].hex(), r[i:i+4].hex()) for i in bad])
