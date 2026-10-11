#!/usr/bin/env python3
"""Post-process splat's asm output.

Nintendo's linker padded libultra objects to 16 bytes with *garbage* (stray bytes of other code), which
splat disassembles as real instructions. When such a "padding instruction" is a branch to a local label
that lives in a neighbouring file, the link fails. Replace any instruction that references an undefined
local label (.Lxxxxxxxx) with the identical raw `.word`, so the bytes are unchanged and nothing dangles.

usage: python tools/fix_asm.py            (run from the project root, after `splat split`)
"""
import re, glob, sys

LABEL_DEF = re.compile(r'^\s*(\.L[0-9A-Fa-f]+):')
LABEL_USE = re.compile(r'\.L[0-9A-Fa-f]+')
# splat line: `    /* ROM VRAM WORD */  instr  operands`
INSTR = re.compile(r'^(\s*/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+([0-9A-Fa-f]{8})\s*\*/)\s+\S')

NOT_VR4300 = {'movz', 'movn', 'pref', 'prefx', 'ldxc1', 'lwxc1', 'sdxc1', 'swxc1', 'madd.s', 'madd.d', 'msub.s', 'msub.d', 'nmadd.s', 'nmadd.d', 'nmsub.s', 'nmsub.d',
              'recip.s', 'recip.d', 'rsqrt.s', 'rsqrt.d', 'alnv.ps', 'luxc1', 'suxc1', 'movf', 'movt', 'movz.s', 'movn.s', 'movz.d', 'movn.d', 'movf.s', 'movt.s', 'movf.d', 'movt.d'}

BRANCH = re.compile(r'^(?:b|bal|beq|bne|beql|bnel|beqz|bnez|beqzl|bnezl|bgez|bgtz|blez|bltz|bgezl|bgtzl|blezl|bltzl|bgezal|bltzal|bgezall|bltzall|bc1t|bc1f|bc1tl|bc1fl)$')
WORDSYM = re.compile(r'^\s*\.word\s+(D_|func_|D_auto_|func_auto_)([0-9A-Fa-f]{6,8})\s*$')

def fix(path):
    lines = open(path, encoding='utf-8').read().split('\n')
    defined = {m.group(1) for l in lines if (m := LABEL_DEF.match(l))}
    changed = 0
    for i, l in enumerate(lines):
        m = INSTR.match(l)
        if not m: continue
        rest = l[m.end(1):]
        uses = LABEL_USE.findall(rest)
        plain = re.sub(r'/\*.*?\*/', '', rest).strip()
        mn = re.match(r'\s*([a-z][a-z0-9.]*)', plain)
        word = int(m.group(3), 16); vram = int(m.group(2), 16)
        # a j/jal whose target lies outside the code (nothing is mapped under 0x200000 or above the overlay) is stray linker padding, not a call
        tgt = ((vram + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        stray_jump = (word >> 26) in (2, 3) and (tgt < 0x200000 or tgt >= 0x500000)
        # a branch to a data symbol cannot be code (a branch to a function name could be a hand-written tail branch: keep it symbolic)
        stray_branch = bool(mn and BRANCH.match(mn.group(1)) and re.search(r',?\s*D_\w+\s*$', plain))
        # a data word that spimdisasm took for a pointer into the hardware registers / outside the code: the number says the same
        ws = WORDSYM.match(plain)
        stray_word = False
        if ws:
            v = int(ws.group(2), 16)
            stray_word = (ws.group(1).startswith('D_') and v >= 0xA0000000) or (ws.group(1).startswith('func_') and (v < 0x200000 or v >= 0x500000))
        if (uses and any(u not in defined for u in uses)) or (mn and mn.group(1) in NOT_VR4300) or stray_jump or stray_branch or stray_word:       # data that spimdisasm decoded as a MIPS IV+ instruction: gas -march=vr4300 rejects it
            lines[i] = f'{m.group(1)}  .word      0x{m.group(3)} /* was: {plain} */'          # (a comment inside the comment would end it early, e.g. `/* handwritten instruction */`: `plain` has none)
            changed += 1
    if changed:
        open(path, 'w', encoding='utf-8', newline='\n').write('\n'.join(lines))
    return changed

total = 0
for p in sorted(glob.glob('asm/*.s')):
    n = fix(p)
    if n: print(f'{p}: {n} instruction(s) -> .word'); total += n
print(f'fix_asm: {total} fixed')

# splat writes a stub .c for every `c` subsegment that has no source yet; where a
# hand-written .s of the same name exists the stub would define the same symbols a second time, so delete it.
import os
removed = 0
for sp in glob.glob('src/**/*.s', recursive=True):
    cp = sp[:-2] + '.c'
    if os.path.exists(cp):
        # (splat also writes `void f(void) {}` skeletons for trivial functions) - a name cannot have both sources
        os.remove(cp)
        removed += 1
if removed:
    print(f'fix_asm: removed {removed} stub .c file(s) shadowed by .s sources')
