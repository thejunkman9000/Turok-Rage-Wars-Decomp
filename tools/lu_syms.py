#!/usr/bin/env python3
"""Recover ROM addresses of libultra functions and the symbols they reference.

usage: lu_syms.py <gcc-version> -- <src.c> ...   (run in WSL from the project root)
For every function that matches the ROM exactly (modulo relocations):
  - its own VA from its ROM offset (ROM 0x1000 == VA 0x200400 for main)
  - every R_MIPS_26 (jal/j) target, and every HI16/LO16 pair, resolved to an absolute address
Prints `name = 0xADDR; // type:func|data` lines for symbol_addrs.txt plus a conflict report.
"""
import sys, collections
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))

def va(rom_off, reg):            # ROM offset -> VA
    return 0x200400 + rom_off - 0x1000 if reg == 'main' else 0x400000 + rom_off - 0x16E000

def sx16(v): return v - 0x10000 if v & 0x8000 else v

found = {}                         # name -> {addr: [evidence]}
kinds = {}
def note(name, addr, kind, who):
    found.setdefault(name, collections.defaultdict(list))[addr].append(who)
    kinds.setdefault(name, kind)

for src in srcs:
    path = src if os.path.isabs(src) else f'{LU}/lib/src/{src}'
    res, err = compile_funcs(path)
    if res is None: continue
    text, syms, relocs, relnames = res
    for fname, off, size in syms:
        n = size // 4
        eq, rom_off, reg = search(fname, text, off, size, relocs)
        if eq != n or n < 4: continue                    # exact matches only
        note(fname, va(rom_off, reg), 'func', 'self')
        rw = words(rom[rom_off:rom_off + size]); ow = words(text[off:off + size])
        pend = {}                                        # sym -> list of (idx, rom hi imm, obj hi imm)
        for i in range(n):
            o = off + 4 * i
            if o not in relnames: continue
            t, s = relnames[o]
            if s.startswith('.') or s in ('.text', '.data', '.bss', '.rodata'): continue
            if t == 'R_MIPS_26':
                tgt = ((rw[i] & 0x3FFFFFF) << 2) - ((ow[i] & 0x3FFFFFF) << 2)
                note(s, tgt, 'func', fname)
            elif t == 'R_MIPS_HI16':
                pend.setdefault(s, []).append((rw[i] & 0xFFFF, ow[i] & 0xFFFF))
            elif t == 'R_MIPS_LO16' and pend.get(s):
                hi_r, hi_o = pend[s].pop(0) if len(pend[s]) == 1 else pend[s][-1]
                a_rom = (hi_r << 16) + sx16(rw[i] & 0xFFFF)
                a_obj = (hi_o << 16) + sx16(ow[i] & 0xFFFF)
                note(s, a_rom - a_obj, 'data', fname)

print('# recovered by tools/lu_syms.py (gcc %s)' % ver)
bad = []
for name in sorted(found):
    addrs = found[name]
    if len(addrs) == 1:
        a = next(iter(addrs))
        print(f'{name} = 0x{a:08X}; // type:{kinds[name]}')
    else:
        bad.append((name, {hex(a): v for a, v in addrs.items()}))
for name, a in bad: print(f'# CONFLICT {name}: {a}')
