#!/usr/bin/env python3
"""Make modern gas reproduce what the original (1990s) assembler produced from GCC's output.

usage: gas_compat.py <lu|game> <file.s> [rodata_va]      (rewrites the file in place)

  * `move rd,rs`                 -> `addu rd,rs,$0`            (old gas; modern gas emits `or`)
  * 3-operand `div/rem/divu/remu` -> explicit expansion         (old gas: div; bnez; nop; break 7; ...; mfhi/mflo;
                                    modern gas moves the div into the bnez delay slot)
  * game code only: `j $31`       -> `j $31; nop` in noreorder  (old gas never filled the return delay slot)
  * `li.s/li.d $fN,<value>`      -> `lui $at,%hi(lit); lwc1/ldc1 $fN,%lo(lit)($at)`, with the literals collected in a
                                    per-object pool at the end of `.rodata` (first-use order, one literal per use - never shared;
                                    floats 4-aligned, doubles 8-aligned) - old gas behaviour.
  * libultra only: old gas only filled a RETURN's delay slot (and never with a load); every call/branch that GCC
                    left to the assembler keeps a nop slot (modern gas would move the previous instruction in).
                    A nop also sits between an FP compare and the following bc1t/bc1f.

rodata: GCC's `.rdata` (strings, jump tables) and the literal pool are one `.rodata` section. With `rodata_va` (the real
build, where the object's rodata is linked at a fixed ROM spot / KSEG0 address) every reference to a rodata label from
code is replaced by its absolute address (found by assembling once with `as -L`), and the pool uses explicit padding so
no alignment directive changes the section size. Without `rodata_va` (diff tools) labels stay relocatable.
"""
import os, re, struct, subprocess, sys, tempfile

REG = r'(\$[a-z0-9]+)'
move_re = re.compile(rf'^([ \t]*)move[ \t]+{REG},[ \t]*{REG}[ \t]*$')
div_re = re.compile(rf'^([ \t]*)(div|divu|rem|remu)[ \t]+{REG},[ \t]*{REG},[ \t]*{REG}[ \t]*$')
ret_re = re.compile(r'^([ \t]*)j[ \t]+\$31[ \t]*$')
lis_re = re.compile(r'^([ \t]*)li\.s[ \t]+(\$f\d+),[ \t]*(\S+)[ \t]*$')
lid_re = re.compile(r'^([ \t]*)li\.d[ \t]+(\$f\d+),[ \t]*(\S+)[ \t]*$')
symidx_re = re.compile(r'^([ \t]*)(lw|lh|lhu|lb|lbu|sw|sh|sb|lwc1|swc1|ldc1|sdc1)[ \t]+(\$\w+),[ \t]*'
                       r'([A-Za-z_.$][\w.$]*(?:[+-]\d+)?)\((\$(?!0\b)\w+)\)[ \t]*$')
imm_div_re = re.compile(r'^[ \t]*(div|divu|rem|remu)[ \t]+\$[a-z0-9]+,[ \t]*\$[a-z0-9]+,[ \t]*[-0-9xXa-fA-F]+[ \t]*$')
rdata_re = re.compile(r'^[ \t]*(\.rdata|\.section[ \t]+\.rdata\b.*|\.section[ \t]+\.rodata\b.*)$')
mnem_re = re.compile(r'^[ \t]*([a-z][a-z0-9.]*)(?![a-z0-9.])(.*)$')
label_tok_re = re.compile(r'[$.][A-Za-z_][A-Za-z0-9_]*')

_label = [0]

BRANCHES = {'j', 'jal', 'jr', 'jalr', 'b', 'beq', 'bne', 'beqz', 'bnez', 'bgez', 'bgtz', 'blez', 'bltz',
            'bgezal', 'bltzal', 'bc1t', 'bc1f'}
LOADS = {'lb', 'lbu', 'lh', 'lhu', 'lw', 'lwl', 'lwr', 'lwc1', 'ld', 'ldc1', 'll', 'l.s', 'l.d'}


STORES = {'sb', 'sh', 'sw', 'sd', 'swc1', 'sdc1', 'swl', 'swr', 's.s', 's.d'}
NODEST = BRANCHES | STORES | {'nop', 'break', 'mtc1', 'mtc0', 'ctc1', 'mult', 'multu', 'div', 'divu'}
reg_re = re.compile(r'\$[A-Za-z0-9]+')


def reg_use(mnemonic, rest):
    """(dest register or None, set of source registers) of one instruction, from its operand text."""
    regs = reg_re.findall(rest)
    if not regs:
        return None, set()
    if mnemonic in NODEST:
        return None, set(regs)
    if mnemonic in LOADS:
        return regs[0], set(regs[1:])
    return regs[0], set(regs[1:])


class Pool:
    """Per-object literal pool: 4-byte floats and 8-byte doubles, first-use order, one literal per use."""

    def __init__(self):
        self.items = []          # (size, value)

    def add(self, size, value):
        # no sharing: the original assembler gave every `li.s/li.d` its own literal (sinf/cosf hold 0.5 twice)
        self.items.append((size, value))
        return len(self.items) - 1

    @staticmethod
    def _data(size, value):
        if size == 4:
            return [f'\t.word\t0x{value:08X}']
        return [f'\t.word\t0x{value >> 32:08X}', f'\t.word\t0x{value & 0xFFFFFFFF:08X}']

    def emit_aligned(self):
        """Pool with alignment directives (used to learn the label offsets, or by the diff tools)."""
        # (the .space keeps gas from moving the .LFLS label past the following .align)
        out = ['\t.section\t.rodata', '.LFLS:', '\t.space\t0']
        for i, (size, value) in enumerate(self.items):
            out.append('\t.align\t2' if size == 4 else '\t.align\t3')
            out.append(f'.LFL{i}:')
            out += self._data(size, value)
        out.append('\t.text')
        return out

    def emit_explicit(self, start, offsets):
        """Pool with explicit padding (no alignment directive, so the section keeps alignment 1)."""
        out, cur = ['\t.section\t.rodata'], start
        for i, (size, value) in enumerate(self.items):
            if offsets[i] > cur:
                out.append(f'\t.space\t{offsets[i] - cur}')
            out += self._data(size, value)
            cur = offsets[i] + size
        out.append('\t.text')
        return out


def expand_div(ind, op, rd, rs, rt):
    _label[0] += 1
    n = _label[0]
    a, b = f'.Ldiv{n}a', f'.Ldiv{n}b'
    signed = op in ('div', 'rem')
    res = 'mfhi' if op in ('rem', 'remu') else 'mflo'
    L = ['.set noreorder', '.set nomacro', '.set noat',
         f'{"div" if signed else "divu"} $0,{rs},{rt}',
         f'bnez {rt},{a}', 'nop', 'break 7', f'{a}:']
    if signed:
        L += ['addiu $1,$0,-1', f'bne {rt},$1,{b}', 'lui $1,0x8000', f'bne {rs},$1,{b}', 'nop', 'break 6', f'{b}:']
    L += [f'{res} {rd}', '.set at', '.set macro', '.set reorder']
    return '\n'.join(ind + x for x in L)


def rodata_labels(text):
    """Assemble `text` once (keeping local labels) and return {label: offset in .rodata}."""
    with tempfile.TemporaryDirectory() as d:
        obj = os.path.join(d, 'p.o')
        r = subprocess.run(['mips-linux-gnu-as', '-EB', '-march=vr4300', '-mabi=32', '-mno-pdr', '-W', '-L',
                            '-I', 'include', '-I', '.', '-o', obj, '-'],
                           input=text, capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError('gas_compat: pass-1 assemble failed:\n' + r.stderr)
        secs = subprocess.run(['mips-linux-gnu-readelf', '-SW', obj], capture_output=True, text=True).stdout
        idx = None
        for line in secs.split('\n'):
            m = re.match(r'\s*\[\s*(\d+)\]\s+(\S+)', line)
            if m and m.group(2) == '.rodata':
                idx = m.group(1)
        if idx is None:
            return {}
        syms = subprocess.run(['mips-linux-gnu-readelf', '-sW', obj], capture_output=True, text=True).stdout
        offsets = {}
        for line in syms.split('\n'):
            f = line.split()
            if len(f) >= 8 and f[6] == idx and f[7] != '.rodata':
                offsets[f[7]] = int(f[1], 16)
        return offsets


def rodata_size(text):
    """Size of the `.rodata` section `text` assembles to (0 if it has none)."""
    with tempfile.TemporaryDirectory() as d:
        obj = os.path.join(d, 'p.o')
        r = subprocess.run(['mips-linux-gnu-as', '-EB', '-march=vr4300', '-mabi=32', '-mno-pdr', '-W', '-L',
                            '-I', 'include', '-I', '.', '-o', obj, '-'],
                           input=text, capture_output=True, text=True)
        if r.returncode:
            raise RuntimeError('gas_compat: size pass failed:\n' + r.stderr)
        secs = subprocess.run(['mips-linux-gnu-readelf', '-SW', obj], capture_output=True, text=True).stdout
        for line in secs.split('\n'):
            m = re.match(r'\s*\[\s*\d+\]\s+\.rodata\s+\S+\s+\S+\s+\S+\s+([0-9a-f]+)', line)
            if m:
                return int(m.group(1), 16)
    return 0


def finalize_rodata(base_lines, pool, ro_va, ro_size=None):
    """Resolve rodata label references to absolute addresses and re-emit the pool with explicit padding."""
    pass1 = '\n'.join(base_lines + (pool.emit_aligned() if pool.items else []))
    offsets = rodata_labels(pass1)
    if not offsets:
        return '\n'.join(base_lines)
    absaddr = {name: ro_va + off for name, off in offsets.items()}

    la_re = re.compile(r'^([ \t]*)la[ \t]+(\$\w+),[ \t]*([A-Za-z_.$][\w.$]*)((?:[+-]\d+)?)[ \t]*$')

    def sub(line):
        st = line.strip()
        if not st or st.endswith(':') or st.startswith('#'):
            return line
        if st.startswith('.') and not st.startswith('.word'):
            return line
        m = la_re.match(line)
        if m and m.group(3) in absaddr:
            # `la reg,label` -> lui/addiu (modern gas would use lui/ori for an absolute constant)
            ind, reg, lab, off = m.groups()
            ref = f'0x{absaddr[lab]:08X}{off}'
            return f'{ind}lui\t{reg},%hi({ref})\n{ind}addiu\t{reg},{reg},%lo({ref})'
        line = label_tok_re.sub(lambda m: f'0x{absaddr[m.group(0)]:08X}' if m.group(0) in absaddr else m.group(0), line)
        if named_re is not None:
            # GCC's names for static data (`P.0`, `zero.4`) do not start with `.` or `$`
            line = named_re.sub(lambda m: f'0x{absaddr[m.group(1)]:08X}', line)
        return line

    names = sorted((n for n in absaddr if n[0] not in '$.'), key=len, reverse=True)
    named_re = re.compile(r'(?<![\w.$])(' + '|'.join(re.escape(n) for n in names) + r')(?![\w.$])') if names else None
    out = [sub(l) for l in '\n'.join(base_lines).split('\n')]
    if pool.items:
        out += pool.emit_explicit(offsets['.LFLS'], [offsets[f'.LFL{i}'] for i in range(len(pool.items))])
        # the object's rodata piece may be longer than its data (4-byte pad before the next object's double)
        end = offsets[f'.LFL{len(pool.items) - 1}'] + pool.items[-1][0]
        if ro_size and ro_size > end:
            out += ['\t.section\t.rodata', f'\t.space\t{ro_size - end}', '\t.text']
    return '\n'.join(out)


def fix(text, mode, ro_va=None, ro_size=None):
    out = []
    pool = Pool()            # float/double literal pool for this object
    noreorder = False        # inside a `.set noreorder` region (GCC fills those delay slots itself)
    prev = None              # mnemonic of the previous real instruction; None after a label/directive
    ih = []                  # (dest, sources) of the last two real instructions
    for line in text.split('\n'):
        st = line.strip()
        if rdata_re.match(line):
            out.append('\t.section\t.rodata')       # GCC's .rdata and our pool are the same section
            prev = None
            continue
        if st.startswith('.set'):
            if 'noreorder' in st:
                noreorder = True
            elif re.search(r'\breorder\b', st):
                noreorder = False
        mm = None
        if st and not st.startswith(('.', '#', '$')) and not st.endswith(':'):
            mm = mnem_re.match(line)
        this = mm.group(1) if mm else None

        m = symidx_re.match(line)
        if m:
            # old gas always used $at for `op reg, sym(idx)`: lui $at,%hi(sym); addu $at,$at,idx; op reg,%lo(sym)($at)
            ind, op, reg, sym, idx = m.groups()
            out.append('\n'.join([f'{ind}.set\tnoat', f'{ind}lui\t$1,%hi({sym})', f'{ind}addu\t$1,$1,{idx}',
                                  f'{ind}{op}\t{reg},%lo({sym})($1)', f'{ind}.set\tat']))
            prev = op
            continue
        m = lid_re.match(line)
        if m:
            value = struct.unpack('>Q', struct.pack('>d', float(m.group(3))))[0]
            ref = f'.LFL{pool.add(8, value)}'
            ind = m.group(1)
            out.append('\n'.join([f'{ind}.set\tnoat', f'{ind}lui\t$1,%hi({ref})',
                                  f'{ind}ldc1\t{m.group(2)},%lo({ref})($1)', f'{ind}.set\tat']))
            prev = 'ldc1'
            continue
        m = lis_re.match(line)
        if m:
            word = struct.unpack('>I', struct.pack('>f', float(m.group(3))))[0]
            ref = f'.LFL{pool.add(4, word)}'
            ind = m.group(1)
            out.append('\n'.join([f'{ind}.set\tnoat', f'{ind}lui\t$1,%hi({ref})',
                                  f'{ind}lwc1\t{m.group(2)},%lo({ref})($1)', f'{ind}.set\tat']))
            prev = 'lwc1'
            continue
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
        # old gas kept a nop between an FP compare and the following bc1t/bc1f
        if mode in ('lu', 'lu2') and this in ('bc1t', 'bc1f', 'bc1tl', 'bc1fl') and prev and prev.startswith('c.'):
            ind = line[:len(line) - len(line.lstrip())]
            if noreorder:
                out.append(f'{ind}nop')
            else:
                out.append(f'{ind}.set\tnoreorder\n{ind}nop\n{ind}.set\treorder')
            prev = 'nop'
        # the original assembler never emitted two FP multiplies back to back (VR4300 multiply erratum): nop between
        if this in ('mul.s', 'mul.d') and prev in ('mul.s', 'mul.d'):
            ind = line[:len(line) - len(line.lstrip())]
            if noreorder:
                out.append(f'{ind}nop')
            else:
                out.append(f'{ind}.set\tnoreorder\n{ind}nop\n{ind}.set\treorder')
            prev = 'nop'
        is_ret = this == 'jr' or (this == 'j' and mm.group(2).strip() == '$31')
        # old gas only moved an instruction into a RETURN's delay slot (and never a load); calls/branches keep a nop
        dep = is_ret and len(ih) == 2 and ih[0][0] is not None and ih[0][0] != '$0' and ih[0][0] in ih[1][1]
        if mode in ('lu', 'lu2') and this in BRANCHES and not noreorder and (not is_ret or prev in LOADS or dep):
            ind = line[:len(line) - len(line.lstrip())]
            out.append(f'{ind}.set\tnoreorder\n{line}\n{ind}nop\n{ind}.set\treorder')
            prev = None
            continue

        out.append(line)
        if this:
            prev = this
            ih = (ih + [reg_use(this, mm.group(2))])[-2:]
        elif st and (st.endswith(':') or st.startswith('$') or st.startswith('.')):
            if not st.startswith(('.set', '.loc', '.ent', '.end', '.frame', '.mask', '.fmask')):
                prev = None

    if ro_va is not None:
        return finalize_rodata(out, pool, ro_va, ro_size)
    if pool.items:
        out.extend(pool.emit_aligned())
    return '\n'.join(out)


if __name__ == '__main__':
    mode, path = sys.argv[1], sys.argv[2]
    ro_va = int(sys.argv[3], 0) if len(sys.argv) > 3 else None
    ro_size = int(sys.argv[4], 0) if len(sys.argv) > 4 else None
    s = open(path).read()
    open(path, 'w', newline='\n').write(fix(s, mode, ro_va, ro_size))
