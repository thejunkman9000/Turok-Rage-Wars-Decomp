#!/usr/bin/env python3
"""Make modern gas reproduce what the original (1990s) assembler produced from GCC's output.

usage: gas_compat.py <lu|game> <file.s>      (rewrites the file in place)

  * `move rd,rs`                 -> `addu rd,rs,$0`            (old gas; modern gas emits `or`)
  * 3-operand `div/rem/divu/remu` -> explicit expansion         (old gas: div; bnez; nop; break 7; ...; mfhi/mflo;
                                    modern gas moves the div into the bnez delay slot)
  * game code only: `j $31`       -> `j $31; nop` in noreorder  (old gas never filled the return delay slot)
  * libultra only: old gas only filled a RETURN's delay slot (and never with a load); every call/branch that GCC
                    left to the assembler keeps a nop slot (modern gas would move the previous instruction in).
"""
import re, sys

REG = r'(\$[a-z0-9]+)'
move_re = re.compile(rf'^([ \t]*)move[ \t]+{REG},[ \t]*{REG}[ \t]*$')
div_re = re.compile(rf'^([ \t]*)(div|divu|rem|remu)[ \t]+{REG},[ \t]*{REG},[ \t]*{REG}[ \t]*$')
ret_re = re.compile(r'^([ \t]*)j[ \t]+\$31[ \t]*$')
imm_div_re = re.compile(r'^[ \t]*(div|divu|rem|remu)[ \t]+\$[a-z0-9]+,[ \t]*\$[a-z0-9]+,[ \t]*[-0-9xXa-fA-F]+[ \t]*$')

_label = [0]

BRANCHES = {'j', 'jal', 'jr', 'jalr', 'b', 'beq', 'bne', 'beqz', 'bnez', 'bgez', 'bgtz', 'blez', 'bltz',
            'bgezal', 'bltzal', 'bc1t', 'bc1f'}
LOADS = {'lb', 'lbu', 'lh', 'lhu', 'lw', 'lwl', 'lwr', 'lwc1', 'ld', 'ldc1', 'll', 'l.s', 'l.d'}
mnem_re = re.compile(r'^[ 	]*([a-z][a-z0-9.]*)(?![a-z0-9.])(.*)$')

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
    noreorder = False        # inside a `.set noreorder` region (GCC fills those delay slots itself)
    prev = None              # mnemonic of the previous real instruction; None after a label/directive
    for line in text.split('\n'):
        st = line.strip()
        if st.startswith('.set'):
            if 'noreorder' in st:
                noreorder = True
            elif re.search(r'\breorder\b', st):
                noreorder = False
        mm = None
        if st and not st.startswith(('.', '#', '$')) and not st.endswith(':'):
            mm = mnem_re.match(line)
        this = mm.group(1) if mm else None

        if imm_div_re.match(line):
            sys.stderr.write(f'gas_compat: immediate div form not handled: {line.strip()}\n')
        m = div_re.match(line)
        if m:
            out.append(expand_div(m.group(1), m.group(2), m.group(3), m.group(4), m.group(5)))
            prev = None
            continue
        m = move_re.match(line)
        if m:
            out.append(f'{m.group(1)}addu\t{m.group(2)},{m.group(3)},$0')
            prev = 'addu'
            continue
        m = ret_re.match(line)
        if m and mode == 'game':
            ind = m.group(1)
            out.append(f'{ind}.set\tnoreorder\n{ind}j\t$31\n{ind}nop\n{ind}.set\treorder')
            prev = None
            continue
        is_ret = this == 'jr' or (this == 'j' and mm.group(2).strip() == '$31')
        # old gas only moved an instruction into a RETURN's delay slot (and never a load); calls/branches keep a nop
        if mode == 'lu' and this in BRANCHES and not noreorder and (not is_ret or prev in LOADS):
            ind = line[:len(line) - len(line.lstrip())]
            out.append(f'{ind}.set\tnoreorder\n{line}\n{ind}nop\n{ind}.set\treorder')
            prev = None
            continue

        out.append(line)
        if this:
            prev = this
        elif st and (st.endswith(':') or st.startswith('$') or st.startswith('.')):
            if not st.startswith(('.set', '.loc', '.ent', '.end', '.frame', '.mask', '.fmask')):
                prev = None
    return '\n'.join(out)

if __name__ == '__main__':
    mode, path = sys.argv[1], sys.argv[2]
    s = open(path).read()
    open(path, 'w', newline='\n').write(fix(s, mode))
