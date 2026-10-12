#!/usr/bin/env python3
"""MIPS disassembly in GNU objdump's text style (mips-linux-gnu-objdump -D -mmips:4300 -EB), made with rabbitizer (pip package, no WSL).
port/asm_all.py and port/asm_tail.py parse objdump's text; disassemble(words, vbase) returns the same text so that the per-function asm
(port/build/asm_func) and with it the recompiled twins come out identical without WSL.  `python port/rab_dis.py --check <ref.tsv>` compares
against an objdump reference (vaddr<TAB>word<TAB>text lines) for the instructions inside the game's functions."""
import re, sys
import rabbitizer

rabbitizer.config.pseudos_enablePseudos = True
rabbitizer.config.pseudos_pseudoMove = True
rabbitizer.config.pseudos_pseudoB = True
rabbitizer.config.pseudos_pseudoBal = True
rabbitizer.config.pseudos_pseudoBeqz = True
rabbitizer.config.pseudos_pseudoBnez = True
rabbitizer.config.pseudos_pseudoNegu = True
rabbitizer.config.pseudos_pseudoNeg = False
rabbitizer.config.pseudos_pseudoNot = False
rabbitizer.config.misc_upperCaseImm = False
rabbitizer.config.misc_omit0XOnSmallImm = False
rabbitizer.config.misc_opcodeLJust = 0
rabbitizer.config.regNames_namedRegisters = True
rabbitizer.config.regNames_gprAbiNames = rabbitizer.Abi.O32
rabbitizer.config.regNames_vr4300Cop0NamedRegisters = False
rabbitizer.config.regNames_userFpcCsr = False

_GPRN = 'zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp s8 ra'.split()
GPR = set('zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp s8 ra'.split())
SIGNED_DEC = {'addi', 'addiu', 'daddi', 'daddiu', 'slti', 'sltiu', 'tgei', 'tgeiu', 'tlti', 'tltiu', 'teqi', 'tnei'}   # objdump: decimal
HEX_IMM = {'andi', 'ori', 'xori', 'lui'}                                                                               # objdump: 0x.. (unsigned)
SHIFTS = {'sll', 'srl', 'sra', 'dsll', 'dsrl', 'dsra', 'dsll32', 'dsrl32', 'dsra32'}                                  # objdump: 0x..

def _num(t):
    t = t.strip()
    neg = t.startswith('-')
    v = int(t[1:] if neg else t, 0)
    return -v if neg else v

def _reg(t):
    t = t.strip()
    if t.startswith('$'):
        n = t[1:]
        if n in GPR: return 's8' if n == 'fp' else n
        return t                           # $f0 .. $f31, cop0 / cop2 numbers keep the dollar sign
    return t

def fmt(word, vaddr):
    """objdump-style text of one instruction word at vaddr ('nop', 'lw\\tv0,16(sp)', '.word\\t0x...')"""
    if word == 0: return 'nop'
    if (word & 0xFC00003F) == 0x0000000C:                                # syscall with a code (rabbitizer: invalid)
        code = (word >> 6) & 0xFFFFF
        return 'syscall\t0x%x' % code if code else 'syscall'
    op = word >> 26
    if op == 0x1D:                                                       # jalx (objdump knows it, the VR4300 does not)
        return 'jalx\t0x%x' % ((((vaddr + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)) + 1)   # (objdump shows the MIPS16 mode bit)
    if op == 0 and (word & 0x3F) in (0x0A, 0x0B): return '.word\t0x%x' % word   # movz / movn: not VR4300 instructions
    if op == 0 and 0x18 <= (word & 0x3F) <= 0x1F and (word >> 6) & 0x3FF: return '.word\t0x%x' % word   # mult / div family with rd / sa set
    if op == 0x33: return '.word\t0x%x' % word                           # pref: not a VR4300 instruction for objdump
    if op in (0x10, 0x11, 0x12) and (word >> 25) & 1:                    # COPz with the CO bit: generic form unless it is a known op
        tmp = rabbitizer.Instruction(word, vram=vaddr)
        if not tmp.isValid() or not tmp.isImplemented(): return 'c%d\t0x%x' % (op - 0x10, word & 0x1FFFFFF)
    if op == 0 and (word & 0x3F) == 0x0D and ((word >> 6) & 0xFFFFF) == 0: return 'break'
    if op == 0 and (word & 0x3F) in (0x30, 0x31, 0x32, 0x33, 0x34, 0x36) and ((word >> 6) & 0x3FF) == 0:   # trap without a code
        rs, rt = (word >> 21) & 31, (word >> 16) & 31
        names = {0x30: 'tge', 0x31: 'tgeu', 0x32: 'tlt', 0x33: 'tltu', 0x34: 'teq', 0x36: 'tne'}
        return '%s\t%s,%s' % (names[word & 0x3F], _GPRN[rs], _GPRN[rt])
    if word == 0x00000040: return 'ssnop'
    if word == 0x000000C0: return 'ehb'
    if op == 0 and (word & 0x3F) in (0x22, 0x23, 0x2E, 0x2F) and ((word >> 21) & 31) == 0 and ((word >> 6) & 31) == 0:   # sub(u)/dsub(u) rd,zero,rt
        rt, rd = (word >> 16) & 31, (word >> 11) & 31
        names = {0x22: 'neg', 0x23: 'negu', 0x2E: 'dneg', 0x2F: 'dnegu'}
        return '%s\t%s,%s' % (names[word & 0x3F], _GPRN[rd], _GPRN[rt])
    if op == 0x12 and not (word >> 25) & 1:                              # COP2 moves / branches
        sub = (word >> 21) & 31; rt = (word >> 16) & 31; rd = (word >> 11) & 31
        if sub in (0, 1, 2, 4, 5, 6) and (word & 0x7FF) != 0: return '.word	0x%x' % word
        if sub in (0, 1, 2, 4, 5, 6): return '%s\t%s,$%d' % ({0: 'mfc2', 1: 'dmfc2', 2: 'cfc2', 4: 'mtc2', 5: 'dmtc2', 6: 'ctc2'}[sub], _GPRN[rt], rd)
        if sub == 8 and rt > 3: return '.word\t0x%x' % word
        if sub == 8:
            tgt = (vaddr + 4 + (((word & 0xFFFF) ^ 0x8000) - 0x8000) * 4) & 0xFFFFFFFF
            return '%s\t0x%x' % ({0: 'bc2f', 1: 'bc2t', 2: 'bc2fl', 3: 'bc2tl'}.get(rt & 3), tgt)
    ins = rabbitizer.Instruction(word, vram=vaddr)
    if not ins.isValid() or not ins.isImplemented():
        return '.word\t0x%x' % word
    txt = ins.disassemble()
    mn, _, ops = txt.strip().partition(' ')
    ops = ops.strip()
    if '#' in ops: ops = ops.split('#')[0].strip()
    args = [a.strip() for a in ops.split(',')] if ops else []
    # branches and jumps: absolute targets in hex, objdump's pseudo forms
    if ins.isBranch() or mn in ('b', 'bal'):
        tgt = (vaddr + ins.getBranchOffset()) & 0xFFFFFFFF
        regs = [_reg(a) for a in args[:-1]]
        if mn in ('beq', 'beql', 'bne', 'bnel') and len(regs) == 2 and regs[1] == 'zero':
            mn = {'beq': 'beqz', 'beql': 'beqzl', 'bne': 'bnez', 'bnel': 'bnezl'}[mn]; regs = regs[:1]
            if regs[0] == 'zero' and mn == 'beqz': mn, regs = 'b', []
        if mn == 'bgez' and regs == ['zero']: mn, regs = 'b', []
        if mn == 'bgezal' and regs == ['zero']: mn, regs = 'bal', []
        return '%s\t%s0x%x' % (mn, ''.join(r + ',' for r in regs), tgt)
    if mn in ('addu', 'or', 'daddu') and len(args) == 3:                 # move rd,rs
        r = [_reg(a) for a in args]
        if r[2] == 'zero': return 'move\t%s,%s' % (r[0], r[1])
        if r[1] == 'zero' and mn != 'addu': return 'move\t%s,%s' % (r[0], r[2])      # (objdump: addu rd,zero,rt stays addu)
    if mn in ('addiu', 'ori') and len(args) == 3 and _reg(args[1]) == 'zero':     # li rt,imm
        v = _num(args[2])
        return 'li\t%s,%s' % (_reg(args[0]), ('%d' % v) if mn == 'addiu' else ('0x%x' % (v & 0xFFFF)))
    if mn in ('ctc1', 'cfc1') and len(args) == 2:
        n = args[1].lstrip('$')
        names = {'0': 'c1_fir', '31': 'c1_fcsr'}
        return '%s\t%s,%s' % (mn, _reg(args[0]), names.get(n, '$' + n))
    if mn in ('j', 'jal'):
        tgt = ((vaddr + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
        return '%s\t0x%x' % (mn, tgt)
    out = []
    for k, a in enumerate(args):
        m = re.match(r'^(-?0x[0-9a-fA-F]+|-?\d+)\((\$\w+)\)$', a)
        if m:                                                            # memory operand: decimal offset
            out.append('%d(%s)' % (_num(m.group(1)), _reg(m.group(2))))
        elif re.match(r'^-?(0x[0-9a-fA-F]+|\d+)$', a):
            v = _num(a)
            if mn in SIGNED_DEC: out.append('%d' % v)
            elif mn in HEX_IMM or mn in SHIFTS: out.append('0x%x' % (v & 0xFFFFFFFF))
            else: out.append('0x%x' % (v & 0xFFFFFFFF) if v >= 0 else '%d' % v)
        else:
            out.append(_reg(a))
    return '%s\t%s' % (mn, ','.join(out)) if out else mn

def disassemble(data, vbase):
    """{vaddr: (word, text)} for a big-endian code blob loaded at vbase"""
    """(like objdump, runs of 2 or more zero words - 8+ zero bytes - are left out: objdump prints them as '...')"""
    res = {}
    words = [int.from_bytes(data[off:off + 4], 'big') for off in range(0, len(data) - 3, 4)]
    for k, w in enumerate(words):
        if w == 0 and ((k > 0 and words[k - 1] == 0) or (k + 1 < len(words) and words[k + 1] == 0)): continue
        res[vbase + 4 * k] = (w, fmt(w, vbase + 4 * k))
    return res

if __name__ == '__main__' and len(sys.argv) > 2 and sys.argv[1] == '--check':
    sys.path.insert(0, 'port')
    import asm_all
    inside = set()
    for name, (rom, n) in asm_all.function_list().items():
        try: va = int(name[5:], 16)
        except ValueError: continue
        inside.update(range(va, va + 4 * n, 4))
    bad = {}; total = 0
    for l in open(sys.argv[2]):
        a, w, t = l.rstrip('\n').split('\t', 2)
        a = int(a, 16); w = int(w, 16)
        if a not in inside and '--all' not in sys.argv: continue
        total += 1
        mine = fmt(w, a)
        if mine.replace('\t', ' ') != t.replace('\t', ' '):
            k = t.split()[0]
            bad.setdefault(k, []).append((a, w, t, mine))
    print('checked %d instructions, %d differ' % (total, sum(len(v) for v in bad.values())))
    for k, v in sorted(bad.items(), key=lambda kv: -len(kv[1]))[:40]:
        a, w, t, mine = v[0]
        print('%-8s x%-6d e.g. %08X %08X  objdump: %-32s rab: %s' % (k, len(v), a, w, t.replace('\t', ' '), mine.replace('\t', ' ')))
