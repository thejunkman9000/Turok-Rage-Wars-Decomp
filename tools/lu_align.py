"""Sequence-aligned diff of our compiled function against the ROM (handles inserted/missing instructions).
usage: python tools/lu_align.py build_ud.json <func> [context]
Lines: ' ' equal, '-' only in ours, '+' only in ROM.  Branch offsets / relocated operands are compared by mnemonic."""
import sys, json, difflib, rabbitizer
d = {f['name']: f for f in json.load(open(sys.argv[1]))}[sys.argv[2]]
ctx = int(sys.argv[3]) if len(sys.argv) > 3 else 3
BR = {'beq','bne','beqz','bnez','bgez','bgtz','blez','bltz','beql','bnel','beqzl','bnezl','bgezl','bgtzl','blezl','bltzl','bc1t','bc1f','bc1tl','bc1fl','j','jal'}
def dis(w):
    return rabbitizer.Instruction(int(w, 16)).disassemble()
n = len(d['words'])
ours, rom = [], []
for w, m in zip(d['words'], d['mask']):
    t = dis(w); ours.append((t.split()[0] if m or t.split()[0] in BR else t, t, bool(m)))
for w in d['romwords'][:n + 40]:
    t = dis(w); rom.append((t.split()[0] if t.split()[0] in BR else t, t, False))
# ROM words that are lui/addiu/lw/etc. relocated in ours are compared by mnemonic only
ours_k = [o[0] for o in ours]
rom_k = []
for r, o in zip(rom, ours + [None] * len(rom)):
    rom_k.append(r[0])
sm = difflib.SequenceMatcher(None, ours_k, [r[0] if True else '' for r in rom], autojunk=False)
out = []
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        for k in range(i1, i2): out.append((' ', f'{k:3d} {ours[k][1]}'))
    else:
        for k in range(i1, i2): out.append(('-', f'{k:3d} {ours[k][1]}'))
        for k in range(j1, j2): out.append(('+', f'    {rom[k][1]}'))
# print hunks with context
idx = [i for i, (t, _) in enumerate(out) if t != ' ']
keep = set()
for i in idx:
    for k in range(max(0, i - ctx), min(len(out), i + ctx + 1)): keep.add(k)
prev = -2
for i in sorted(keep):
    if i != prev + 1: print('   ...')
    print(out[i][0], out[i][1]); prev = i
