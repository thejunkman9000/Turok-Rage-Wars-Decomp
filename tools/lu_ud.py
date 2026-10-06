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
    for tag, a0, a1, b0, b1 in sm.get_opcodes():
        if tag == 'equal': continue
        for x in ours[a0:a1]: print(f'  < {x}')
        for x in rom[b0:b1]: print(f'  > {x}')
        print('  ---')
