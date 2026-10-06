#!/usr/bin/env python3
"""Batch-check candidate C files against the ROM (run in WSL from /mnt/d/Projects/TurokRageWars after wsl_sync).

usage: chk.py <list-file>
list line:  <src path relative to src/libultra or wip/>  <function>  <rom_hex>  [extra gcc flags...]
Prints per function: EXACT, or the number of differing words with the first few (ours vs ROM), plus the literal pool
location found from lui/lwc1 relocations (`ro=0xROM:bytes`) when the object has .rodata."""
import sys, os, struct
list_file = sys.argv[1]
sys.argv = ['lu_match.py', '2.8.1', '-O2 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw')
okf = open('chk_ok.txt', 'w')

for line in open(list_file):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:] if len(f) > 3 else ['-O2', '-fforce-addr', '-fno-builtin', '-mcpu=r4300']
    full = path if os.path.isabs(path) else f'{ROOTD}/src/libultra/{path}'
    if not os.path.exists(full): full = f'{ROOTD}/{path}'
    res, err = compile_funcs(full)
    if res is None:
        print(f'{func:28s} COMPILE FAIL: {err}'); continue
    text, syms, relocs, relnames = res
    cand = [s for s in syms if s[0] == func]
    if not cand:
        print(f'{func:28s} not found in object (have: {[s[0] for s in syms]})'); continue
    name, off, size = cand[0]
    n = size // 4
    fw = words(text[off:off + size]); rw = words(rom[rom_hex:rom_hex + size])
    bad = []
    for i, (a, b) in enumerate(zip(fw, rw)):
        m = 0xFFFFFFFF ^ relocs.get(off + 4 * i, 0)
        if (a & m) != (b & m): bad.append(i)
    # literal pool location from HI16/LO16 relocs against .rodata
    ro = LAST.get('ro', b'')
    pool = ''
    if ro:
        addrs = []
        pend = {}
        for i in range(n):
            o = off + 4 * i
            if o in relnames and relnames[o][1] == '.rodata':
                t = relnames[o][0]
                if t == 'R_MIPS_HI16': pend[i] = rw[i] & 0xFFFF
                elif t == 'R_MIPS_LO16' and pend:
                    hi = pend[max(pend)]; lo = rw[i] & 0xFFFF; lo = lo - 0x10000 if lo & 0x8000 else lo
                    # addend (offset of the entry inside the pool) is in our own object's immediate
                    own = fw[i] & 0xFFFF; own = own - 0x10000 if own & 0x8000 else own
                    addrs.append(((hi << 16) + lo) - own)
        if addrs:
            base = min(addrs)
            pool = f'  ro=0x{(base & 0x1FFFFFFF) + 0xC00:X}:{len(ro)}'
    status = 'EXACT' if not bad else f'{len(bad)} words differ'
    print(f'{func:28s} {n:4d} insns  {status}{pool}')
    if not bad:
        sub = os.path.dirname(path) or 'libultra'
        ro_opt = pool.strip() if pool else ''
        okf.write(f'{func} 0x{rom_hex:X} {n} {sub} {ro_opt}'.rstrip() + '\n')
    for i in bad[:4]:
        print(f'      [{i}] ours {fw[i]:08X}  rom {rw[i]:08X}')

okf.close()
