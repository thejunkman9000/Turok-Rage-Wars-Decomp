"""Instruction-level diff of compiled libultra functions vs the ROM (Windows side; needs rabbitizer).
usage: python tools/lu_ud.py <json> [function ...]
Relocated operands are masked so only real code differences show. '<' = ours, '>' = ROM."""
import sys, json, difflib, rabbitizer

def norm(word, mask):
    w = int(word, 16)
    i = rabbitizer.Instruction(w & ~mask if mask else w)
    s = i.disassemble()
    if mask:
        s = s.split()[0] + ' <reloc>'
    return s

data = json.load(open(sys.argv[1]))
want = set(sys.argv[2:])
for f in data:
    if want and f['name'] not in want: continue
    n = len(f['words'])
    ours = [norm(w, m) for w, m in zip(f['words'], f['mask'])]
    rom = [norm(w, m) for w, m in zip(f['romwords'][:n + 8], f['mask'] + [0] * 8)]
    # trim the ROM side after the last jr ra (+delay slot) that follows our length
    sm = difflib.SequenceMatcher(None, ours, rom, autojunk=False)
    ratio = sm.ratio()
    print(f"## {f['name']}  ROM 0x{f['rom']:X}  {n} insns  similarity {ratio:.2f}" if f['rom'] is not None else f"## {f['name']} (not found)")
    # symbol addresses implied by the ROM words at relocated positions (valid where the code lines up)
    syms, pend = {}, {}
    for i, (w, m, nm) in enumerate(zip(f['words'], f['mask'], f['relnames'])):
        if not m or not nm or i >= len(f['romwords']): continue
        rw = int(f['romwords'][i], 16)
        if m == 0x03FFFFFF and (rw >> 26) in (2, 3):
            syms.setdefault(nm, set()).add((rw & 0x3FFFFFF) << 2)
        elif m == 0xFFFF and (int(w, 16) >> 26) == 0x0F:                  # lui = HI16
            pend.setdefault(nm, []).append(rw & 0xFFFF)
        elif m == 0xFFFF and pend.get(nm):                                # lo16 consumer
            hi = pend[nm][-1]; lo = rw & 0xFFFF; lo = lo - 0x10000 if lo & 0x8000 else lo
            syms.setdefault(nm, set()).add(((hi << 16) + lo) & 0xFFFFFFFF)
    if syms:
        print('  symbols: ' + ', '.join(f"{k}=" + '/'.join(f'0x{a:08X}' for a in sorted(v)) for k, v in sorted(syms.items())))
    for tag, a0, a1, b0, b1 in sm.get_opcodes():
        if tag == 'equal': continue
        for x in ours[a0:a1]: print(f'  < {x}')
        for x in rom[b0:b1]: print(f'  > {x}')
        print('  ---')
