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
INSTR = re.compile(r'^(\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/)\s+\S')

def fix(path):
    lines = open(path, encoding='utf-8').read().split('\n')
    defined = {m.group(1) for l in lines if (m := LABEL_DEF.match(l))}
    changed = 0
    for i, l in enumerate(lines):
        m = INSTR.match(l)
        if not m: continue
        uses = LABEL_USE.findall(l[m.end(1):])
        if uses and any(u not in defined for u in uses):
            lines[i] = f'{m.group(1)}  .word      0x{m.group(2)} /* was: {l[m.end(1):].strip()} */'
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
