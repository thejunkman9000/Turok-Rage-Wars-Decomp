#!/usr/bin/env python3
"""sn_expand.py <file.s> : expand the assembler load macros `lw $N,sym` (sym = bare symbol, optional +off) of cc1 output into
`lui $N,%hi(sym)` / `lw $N,%lo(sym)($N)`.  The original assembler counted such a macro as two instructions for the mflo/mult hazard
(ROM: `mflo; lui; lw; mult` without nop); GNU as counts it as one and inserts a nop.  In-place rewrite."""
import re, sys
p = sys.argv[1]
src = open(p).read().split('\n')
rx = re.compile(r'^(\s*)(lw|lh|lhu|lb|lbu)(\s+)(\$\d+),\s*([A-Za-z_.][\w.$]*(?:[+-]\d+)?)\s*$')
out = []
for l in src:
    m = rx.match(l)
    if m:
        ind, op, sp, reg, sym = m.groups()
        out.append(f'{ind}lui{sp}{reg},%hi({sym})')
        out.append(f'{ind}{op}{sp}{reg},%lo({sym})({reg})')
    else:
        out.append(l)
open(p, 'w').write('\n'.join(out))
