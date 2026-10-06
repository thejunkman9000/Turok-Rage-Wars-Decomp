#!/usr/bin/env python3
"""Make modern gas reproduce what the original (1990s) assembler produced from GCC's output.

usage: gas_compat.py <lu|game> <file.s>      (rewrites the file in place)

  * `move rd,rs`                 -> `addu rd,rs,$0`            (old gas; modern gas emits `or`)
  * 3-operand `div/rem/divu/remu` -> explicit expansion         (old gas: div; bnez; nop; break 7; ...; mfhi/mflo;
                                    modern gas moves the div into the bnez delay slot)
  * game code only: `j $31`       -> `j $31; nop` in noreorder  (old gas never filled the return delay slot)
"""
import re, sys

REG = r'(\$[a-z0-9]+)'
move_re = re.compile(rf'^([ \t]*)move[ \t]+{REG},[ \t]*{REG}[ \t]*$')
div_re = re.compile(rf'^([ \t]*)(div|divu|rem|remu)[ \t]+{REG},[ \t]*{REG},[ \t]*{REG}[ \t]*$')
ret_re = re.compile(r'^([ \t]*)j[ \t]+\$31[ \t]*$')
imm_div_re = re.compile(r'^[ \t]*(div|divu|rem|remu)[ \t]+\$[a-z0-9]+,[ \t]*\$[a-z0-9]+,[ \t]*[-0-9xXa-fA-F]+[ \t]*$')

_label = [0]

def expand_div(ind, op, rd, rs, rt):
    _label[0] += 1
    n = _label[0]
    a, b = f'.Ldiv{n}a', f'.Ldiv{n}b'
    signed = op in ('div', 'rem')
    res = 'mfhi' if op in ('rem', 'remu') else 'mflo'
    L = [f'.set noreorder', f'.set nomacro', f'.set noat',
         f'{"div" if signed else "divu"} $0,{rs},{rt}',
         f'bnez {rt},{a}', 'nop', 'break 7', f'{a}:']
    if signed:
        L += ['addiu $1,$0,-1', f'bne {rt},$1,{b}', 'lui $1,0x8000', f'bne {rs},$1,{b}', 'nop', 'break 6', f'{b}:']
    L += [f'{res} {rd}', '.set at', '.set macro', '.set reorder']
    return '\n'.join(ind + x for x in L)

def fix(text, mode):
    out = []
    for line in text.split('\n'):
        if imm_div_re.match(line):
            sys.stderr.write(f'gas_compat: immediate div form not handled: {line.strip()}\n')
        m = div_re.match(line)
        if m:
            out.append(expand_div(m.group(1), m.group(2), m.group(3), m.group(4), m.group(5))); continue
        m = move_re.match(line)
        if m:
            out.append(f'{m.group(1)}addu\t{m.group(2)},{m.group(3)},$0'); continue
        m = ret_re.match(line)
        if m and mode == 'game':
            ind = m.group(1)
            out.append(f'{ind}.set\tnoreorder\n{ind}j\t$31\n{ind}nop\n{ind}.set\treorder'); continue
        out.append(line)
    return '\n'.join(out)

if __name__ == '__main__':
    mode, path = sys.argv[1], sys.argv[2]
    s = open(path).read()
    open(path, 'w', newline='\n').write(fix(s, mode))
