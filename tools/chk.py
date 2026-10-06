#!/usr/bin/env python3
"""Batch-check candidate C files against the ROM (run in WSL from /mnt/d/Projects/TurokRageWars after wsl_sync).

usage: chk.py <list-file>
list line:  <src path relative to src/libultra or wip/>  <function>  <rom_hex>  [extra gcc flags...]
Prints per function: EXACT, or the number of differing words with the first few (ours vs ROM), plus the literal pool
location found from lui/lwc1 relocations (`ro=0xROM:bytes`) when the object has .rodata."""
import sys, os, struct
list_file = sys.argv[1]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw')
okf = open('chk_ok.txt', 'w')

import re as _re
_SYMS = {}
for _f in ('symbol_addrs.txt', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt', 'hardware_regs.ld', 'extra_syms.ld'):
    try:
        for _l in open(os.path.join(os.path.expanduser('~/trw') if False else '.', _f), encoding='utf-8', errors='replace'):
            _m = _re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', _l)
            if _m: _SYMS[_m.group(1)] = int(_m.group(2), 16)
    except OSError:
        pass
def _symaddr(n):
    m = _re.fullmatch(r'(?:D|func|jtbl)_([0-9A-Fa-f]{8})', n)
    if m: return int(m.group(1), 16)
    return _SYMS.get(n)
def reloc_check(off, n, fw, rw, relnames):
    """verify that the symbol+addend of every relocation resolves to what the ROM encodes; returns list of word indexes"""
    badr = []
    hi = {}
    sx = lambda v: v - 0x10000 if v & 0x8000 else v
    for i in range(n):
        o = off + 4 * i
        if o not in relnames: continue
        t, sym = relnames[o]
        a = _symaddr(sym)
        if a is None or sym.startswith('.'): continue
        if t == 'R_MIPS_26':
            exp = ((a + ((fw[i] & 0x3FFFFFF) << 2)) >> 2) & 0x3FFFFFF
            if exp != (rw[i] & 0x3FFFFFF): badr.append(i)
        elif t == 'R_MIPS_HI16':
            hi[sym] = rw[i] & 0xFFFF
        elif t == 'R_MIPS_LO16' and sym in hi:
            rom_addr = ((hi[sym] << 16) + sx(rw[i] & 0xFFFF)) & 0xFFFFFFFF
            exp = (a + sx(fw[i] & 0xFFFF)) & 0xFFFFFFFF
            if rom_addr != exp: badr.append(i)
    return badr

CACHE = {}

for line in open(list_file):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:] if len(f) > 3 else ['-O3', '-fforce-addr', '-fno-builtin', '-mcpu=r4300']
    full = path if os.path.isabs(path) else f'{ROOTD}/src/libultra/{path}'
    if not os.path.exists(full): full = f'{ROOTD}/{path}'
    key = (full, tuple(extra))
    if key not in CACHE:
        CACHE[key] = (compile_funcs(full), dict(LAST))
    (res, err), last = CACHE[key]
    LAST.clear(); LAST.update(last)
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
    rbad = reloc_check(off, n, fw, rw, relnames) if not bad else []
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
    status = ('EXACT' if not rbad else f'RELOC-MISMATCH(words {rbad[:4]})') if not bad else f'{len(bad)} words differ'
    if bad:
        import difflib
        def mn(w):
            op = w >> 26
            if op == 0: return ('s', w & 0x3F)
            if op == 1: return ('r', (w >> 16) & 0x1F)
            if op == 0x11:
                rs = (w >> 21) & 0x1F
                return ('c', rs, w & 0x3F) if rs in (16, 17) else ('c', rs, (w >> 16) & 3)
            return op
        rw2 = words(rom[rom_hex:rom_hex + size + 64])
        a_mn = [mn(w) for w in fw]; b_mn = [mn(w) for w in rw2]
        sm = difflib.SequenceMatcher(None, a_mn, b_mn, autojunk=False)
        score = 0
        for tag, i1, i2, j1, j2 in sm.get_opcodes():
            if tag == 'equal':
                for k in range(i1, i2):
                    m = 0xFFFFFFFF ^ relocs.get(off + 4 * k, 0)
                    kind = a_mn[k]
                    if kind in (2, 3):
                        m &= 0xFC000000
                    elif kind in (4, 5, 6, 7, 20, 21, 22, 23) or (isinstance(kind, tuple) and (kind[0] == 'r' and kind[1] < 4 or kind[0] == 'c' and kind[1] == 8)):
                        m &= 0xFFFF0000
                    if (fw[k] & m) != (rw2[j1 + (k - i1)] & m): score += 1
            else:
                score += max(i2 - i1, j2 - j1) + 2
        status += f'  score={score}'
    print(f'{func:28s} {n:4d} insns  {status}{pool}')
    if not bad:
        sub = os.path.dirname(path) or 'libultra'
        ro_opt = pool.strip() if pool else ''
        okf.write(f'{func} 0x{rom_hex:X} {n} {sub} {ro_opt}'.rstrip() + '\n')
    for i in bad[:4]:
        print(f'      [{i}] ours {fw[i]:08X}  rom {rw[i]:08X}')

okf.close()
