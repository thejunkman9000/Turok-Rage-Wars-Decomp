"""Register every code range of a release that no manifest unit covers as a hand-written asm unit (hasm_<ROM6>.s, built by tools/mkhasm.py
from the workspace's splat asm).  usage: python wip/adopt_gaps.py <us|eu|de> <workspace> [--apply]"""
import re, os, sys, subprocess, shutil, glob
ver, ws = sys.argv[1], sys.argv[2]
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
lay = dict(re.findall(r'(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', open(ws + '/ver_layout.txt').read()))
mce, os_, oe = [int(lay[k], 16) for k in ('MAIN_CODE_END', 'OVL_START', 'OVL_END')]
iv = []
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(f'{ws}/{fn}'):
        f = l.split('#')[0].split()
        if len(f) >= 4: iv.append((int(f[1], 16), int(f[2]) * 4))
iv.sort()
gaps = []
for lo, hi in ((0x1000, mce), (os_, oe)):
    cur = lo
    for a, n in iv:
        if a + n <= lo or a >= hi: continue
        if a > cur: gaps.append((cur, a))
        cur = max(cur, a + n)
    if cur < hi: gaps.append((cur, hi))
INSN = re.compile(r'^\s*/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/')
rom2file = {}
for p in glob.glob(ws + '/asm/*.s'):
    for l in open(p, encoding='utf-8'):
        m = INSN.match(l)
        if m: rom2file[int(m.group(1), 16)] = p
glab = {}
for p in set(rom2file.values()):
    last = None; pend = None
    for l in open(p, encoding='utf-8'):
        m = re.match(r'^\s*glabel\s+(\S+)', l)
        if m: pend = m.group(1)
        m = INSN.match(l)
        if m:
            if pend: glab[int(m.group(1), 16)] = pend; pend = None
chunks = []
for a, b in gaps:
    cur = a
    while cur < b:
        p = rom2file.get(cur)
        if p is None: print('no asm at', hex(cur)); cur += 4; continue
        e = cur
        while e < b and rom2file.get(e) == p: e += 4
        chunks.append((cur, e)); cur = e

INSNL = re.compile(r'^\s*/\*\s*([0-9A-Fa-f]+)\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/\s*(\S.*)$')
LDEF = re.compile(r'^\s*(\.L[0-9A-Za-z_]+):')
LUSE = re.compile(r'\.L[0-9A-Za-z_]+')
parsed = {}
def parse(p):
    if p in parsed: return parsed[p]
    items = []; pend = []; defined = set()
    for l in open(p, encoding='utf-8'):
        l = l.rstrip('\n')
        m = re.match(r'^\s*(glabel|alabel|dlabel)\s+(\S+)', l)
        if m: pend.append(('g', m.group(2))); continue
        m = LDEF.match(l)
        if m: pend.append(('l', m.group(1))); defined.add(m.group(1)); continue
        m = INSNL.match(l)
        if m: items.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3).upper(), m.group(4), pend)); pend = []
    parsed[p] = items
    return items
def build(name, a, e, seg):
    p = rom2file[a]; items = [it for it in parse(p) if a <= it[0] < e]
    defined = {n for it in items for k, n in it[4] if k == 'l'}
    out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '.set gp=64', '', '.section .text, "ax"', '',
           f'/* assembly kept as it is in this release, ROM 0x{a:X}-0x{e:X} (VRAM 0x{items[0][1]:08X}) */']
    for rom, vram, word, text, pend in items:
        for k, n in pend:
            out.append(f'.globl {n}\n{n}:' if k == 'g' else f'{n}:')
        uses = LUSE.findall(text.split('/*')[0])
        if uses and any(u not in defined for u in uses) or text.lstrip().startswith('.word') and False:
            out.append(f'    /* {rom:X} {vram:08X} {word} */  .word 0x{word}')
        elif re.match(r'^\s*\.(word|byte|half|float|double|asciz|ascii|space|fill)\b', text) or text.lstrip().startswith('.'):
            out.append(f'    /* {rom:X} {vram:08X} {word} */  .word 0x{word}')
        else:
            out.append(f'    /* {rom:X} {vram:08X} {word} */  {text}')
    return '\n'.join(out) + '\n'
rows = []
for a, e in chunks:
    seg = 'ovl_a' if a >= os_ else ('libultra' if a >= 0xB0000 else 'game')
    name = 'hasm_%06X' % a
    rows.append((name, a, e, seg))
print(len(rows), 'chunks', sum((e - a) // 4 for _, a, e, _ in rows), 'words')
if '--apply' not in sys.argv: sys.exit()
man = []
for name, a, e, seg in rows:
    d = f'{ROOT}/versions/{ver}/src/{seg}'; os.makedirs(d, exist_ok=True)
    open(f'{d}/{name}.s', 'w', encoding='utf-8', newline='\n').write(build(name, a, e, seg))
    man.append(f'{name} 0x{a:X} {(e - a) // 4} {seg}')
with open(f'{ROOT}/versions/{ver}/manifest.txt', 'a') as f: f.write('\n'.join(man) + '\n')
