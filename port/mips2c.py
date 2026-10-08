#!/usr/bin/env python3
"""Static recompiler: MIPS (splat/GNU asm text) -> C, for functions that have no C source.
Registers become a local array r[32]; loads/stores are plain C pointer accesses (so the big-endian clang pipeline gives them
MIPS semantics); calls (jal sym) are C calls with a0-a3 (+ stack arguments found at the call site) and the result in v0;
the function's own stack frame is a local array.  Integer ISA + single/double FPU subset; no jump tables.

usage (library):  recompile_function(asm_text, name, known)  -> C source text   (known: set of function names with a host definition)
usage (cli):      mips2c.py in.s funcname"""
import os, re, sys
STRUCTARGS = set(open('port/recomp_structargs.txt').read().split()) if os.path.exists('port/recomp_structargs.txt') else set()      # functions that take or pass the 40-byte UI context by value: its words are a big-endian memory image on the native side

REGS = {n: i for i, n in enumerate('zero at v0 v1 a0 a1 a2 a3 t0 t1 t2 t3 t4 t5 t6 t7 s0 s1 s2 s3 s4 s5 s6 s7 t8 t9 k0 k1 gp sp fp ra'.split())}
REGS['s8'] = 30
def reg(tok):
    tok = tok.strip().lstrip('$')
    return REGS[tok] if tok in REGS else int(tok)
FREGS = {}
for _i, _n in enumerate(['fv0', 'fv0f', 'fv1', 'fv1f', 'ft0', 'ft0f', 'ft1', 'ft1f', 'ft2', 'ft2f', 'ft3', 'ft3f', 'fa0', 'fa0f', 'fa1', 'fa1f',
                         'ft4', 'ft4f', 'ft5', 'ft5f', 'fs0', 'fs0f', 'fs1', 'fs1f', 'fs2', 'fs2f', 'fs3', 'fs3f', 'fs4', 'fs4f', 'fs5', 'fs5f']):
    FREGS[_n] = _i
def freg(tok):
    t = tok.strip().lstrip('$')
    if t in FREGS: return FREGS[t]
    return int(t.lstrip('f'))

def sym_addr(s):
    m = re.match(r'(?:D_|func_|L)([0-9A-Fa-f]{6,8})$', s)
    if m: return int(m.group(1), 16)
    raise ValueError('unknown symbol ' + s)

def simm(v):
    v &= 0xFFFF
    return v - 0x10000 if v >= 0x8000 else v

def sym_expr(txt):
    m = re.match(r'(\w+)\s*(?:([+-])\s*(0x[0-9A-Fa-f]+|\d+))?$', txt.strip())
    if not m: raise ValueError('bad symbol expression ' + txt)
    v = sym_addr(m.group(1))
    if m.group(2):
        d = int(m.group(3), 0)
        v = v + d if m.group(2) == '+' else v - d
    return v

def imm(tok):
    tok = tok.strip()
    m = re.match(r'%hi\((.*)\)$', tok)
    if m: return ((sym_expr(m.group(1)) + 0x8000) >> 16) & 0xFFFF
    m = re.match(r'%lo\((.*)\)$', tok)
    if m: return sym_expr(m.group(1)) & 0xFFFF
    return eval(tok, {}, {})

def parse(text, name, extend=0):
    """instructions of `name`; with extend=k the next k glabel chunks are appended (as labels) - used when a branch leaves the chunk"""
    out = []; inside = False; extra = 0
    for l in text.split('\n'):
        s = re.sub(r'/\*.*?\*/', '', l).strip()
        if s.startswith('glabel ') or s.startswith('alabel '):
            lab = s.split()[1]
            if lab == name: inside = True
            elif s.startswith('glabel') and inside:
                if extra >= extend: break
                extra += 1; out.append(('label', lab))
            elif inside: out.append(('label', lab))
            continue
        if s.startswith('endlabel'):
            if inside and len(s.split()) > 1 and s.split()[1] == name and not extend: break
            continue
        if s.startswith(('enddlabel', 'dlabel', 'jlabel', 'endjlabel', 'nonmatching')): continue
        if not inside or not s or (s.startswith('.') and not s.startswith('.L')): continue
        m = re.match(r'(\.L\w+):$', s)
        if m: out.append(('label', m.group(1))); continue
        m = re.match(r'(\w[\w.]*)\s*(.*)$', s)
        if m: out.append(('ins', m.group(1), [o.strip() for o in re.split(r',(?![^(]*\))', m.group(2))] if m.group(2) else []))
    return out

def parse(text, name, extend=0, prepend=0):
    """instructions of `name`; the chunks around it (prepend before, extend after, split at glabels) are included as labelled code,
    so branches that cross a (false) function split still resolve"""
    chunks = []; cur = None
    for l in text.split('\n'):
        s = re.sub(r'/\*.*?\*/', '', l).strip()
        if s.startswith(('glabel ', 'alabel ')):
            lab = s.split()[1]
            if s.startswith('glabel') or cur is None:
                cur = (lab, []); chunks.append(cur)
            else:
                cur[1].append(('label', lab))
            continue
        if cur is None or s.startswith(('endlabel', 'enddlabel', 'dlabel', 'jlabel', 'endjlabel', 'nonmatching')): continue
        if s.startswith('.jtbl'): cur[1].append(('jtbl', s.split()[1:])); continue
        if not s or (s.startswith('.') and not s.startswith('.L')): continue
        m = re.match(r'(\.L\w+):$', s)
        if m: cur[1].append(('label', m.group(1))); continue
        m = re.match(r'(\w[\w.]*)\s*(.*)$', s)
        if m: cur[1].append(('ins', m.group(1), [o.strip() for o in re.split(r',(?![^(]*\))', m.group(2))] if m.group(2) else []))
    idx = next((k for k, c in enumerate(chunks) if c[0] == name), None)
    if idx is None: return []
    out = []
    for k in range(max(0, idx - prepend), min(len(chunks), idx + extend + 1)):
        out.append(('label', chunks[k][0])); out.extend(chunks[k][1])
    return out

FPSIG = None
ARGC = {}
ALLARGC = {}        # integer argument registers read by every function (from the ROM code), used to widen prototypes that declare fewer parameters
def fpsigs():
    global FPSIG
    if FPSIG is None:
        import fpsig
        FPSIG = fpsig.load()
        for n in ('sqrtf', 'sinf', 'cosf', 'tanf', 'fabsf', 'floorf', 'ceilf'): FPSIG.setdefault(n, ('f', ['f']))
        for n in ('atan2f', 'powf', 'fmodf'): FPSIG.setdefault(n, ('f', ['f', 'f']))
    return FPSIG

CT = {'i': 'u32', 'f': 'float', 'd': 'double'}
def arg_exprs(types):
    """C argument expressions (reading the MIPS o32 argument registers / stack words) for a prototype's parameter types"""
    out = []; word = 0
    for idx, t in enumerate(types):
        if t == 'd': word = (word + 1) & ~1
        if (idx == 0 and t in ('f', 'd')) or (idx == 1 and t in ('f', 'd') and types[0] in ('f', 'd')):
            out.append('f[%d]' % (12 + 2 * idx) if t == 'f' else 'gd(f, %d)' % (12 + 2 * idx))
        else:
            def w(k): return 'r[%d]' % (4 + k) if k < 4 else '*(u32 *)(r[29] + %d)' % (0x10 + 4 * (k - 4))
            if t == 'i': out.append(w(word))
            elif t == 'f': out.append('u2f(%s)' % w(word))
            else: out.append('u2d(%s, %s)' % (w(word), w(word + 1)))
        word += 2 if t == 'd' else 1
    return out

def fa_read_first(items):
    """does the function read the float argument registers (f12-f15) before writing them?"""
    written = set(); n = lambda tok: freg(tok)
    for it in items:
        if it[0] != 'ins': continue
        m, ops = it[1], it[2]
        try:
            if m in ('lwc1', 'ldc1'): written.add(n(ops[0])); continue
            if m == 'mtc1': written.add(n(ops[1])); continue
            if m in ('swc1', 'sdc1'):
                r = n(ops[0])
                if r in (12, 13, 14, 15) and r not in written: return True
                continue
            if m == 'mfc1':
                r = n(ops[1])
                if r in (12, 13, 14, 15) and r not in written: return True
                continue
            if m.startswith('c.'):
                for o in ops[:2]:
                    r = n(o)
                    if r in (12, 13, 14, 15) and r not in written: return True
                continue
            if re.match(r'(add|sub|mul|div|mov|neg|abs|sqrt|cvt|trunc|round|floor|ceil)', m) and ('.s' in m or '.d' in m or '.w' in m):
                for o in ops[1:]:
                    r = n(o)
                    if r in (12, 13, 14, 15) and r not in written: return True
                written.add(n(ops[0]))
                if m.endswith('.d') or 'd.' in m: written.add(n(ops[0]) + 1)
        except Exception:
            continue
    return False

BR = {'beqzl', 'bnezl', 'beq', 'bne', 'beql', 'bnel', 'bgez', 'bltz', 'blez', 'bgtz', 'bgezl', 'bltzl', 'blezl', 'bgtzl', 'beqz', 'bnez', 'b', 'bc1t', 'bc1f', 'bc1tl', 'bc1fl'}
def label_name(t): return 'L_' + t.lstrip('.').replace('.', '_')
R = lambda i: 'r[%d]' % i
F = lambda i: 'f[%d]' % i

def gen_ins(m, ops, known, ctx):
    if m in ('nop',): return ''
    if m == 'break': return '__builtin_trap();'
    if m in ('sync', 'cache'): return ''
    if m in ('addu', 'add', 'addi', 'addiu', 'subu', 'sub', 'and', 'or', 'xor', 'nor', 'slt', 'sltu', 'sllv', 'srlv', 'srav', 'move', 'li', 'negu', 'not', 'slti', 'sltiu', 'mul'):
        if m == 'move': return '%s = %s;' % (R(reg(ops[0])), R(reg(ops[1])))
        if m == 'li': return '%s = (u32)%s;' % (R(reg(ops[0])), imm(ops[1]))
        if m == 'negu': return '%s = -%s;' % (R(reg(ops[0])), R(reg(ops[1])))
        if m == 'not': return '%s = ~%s;' % (R(reg(ops[0])), R(reg(ops[1])))
        d, a = reg(ops[0]), reg(ops[1]); b = ops[2]
        if m in ('addi', 'addiu'): e = '%s + (u32)(s32)%d' % (R(a), simm(imm(b)))
        elif m in ('addu', 'add'): e = '%s + %s' % (R(a), R(reg(b)))
        elif m in ('subu', 'sub'): e = '%s - %s' % (R(a), R(reg(b)))
        elif m == 'mul': e = '(u32)((s32)%s * (s32)%s)' % (R(a), R(reg(b)))
        elif m == 'and': e = '%s & %s' % (R(a), R(reg(b)))
        elif m == 'or': e = '%s | %s' % (R(a), R(reg(b)))
        elif m == 'xor': e = '%s ^ %s' % (R(a), R(reg(b)))
        elif m == 'nor': e = '~(%s | %s)' % (R(a), R(reg(b)))
        elif m == 'slt': e = '(u32)((s32)%s < (s32)%s)' % (R(a), R(reg(b)))
        elif m == 'sltu': e = '(u32)(%s < %s)' % (R(a), R(reg(b)))
        elif m == 'slti': e = '(u32)((s32)%s < (s32)%d)' % (R(a), simm(imm(b)))
        elif m == 'sltiu': e = '(u32)(%s < (u32)(s32)%d)' % (R(a), simm(imm(b)))
        elif m == 'sllv': e = '%s << (%s & 31)' % (R(reg(ops[1])), R(reg(ops[2])))
        elif m == 'srlv': e = '%s >> (%s & 31)' % (R(reg(ops[1])), R(reg(ops[2])))
        elif m == 'srav': e = '(u32)((s32)%s >> (%s & 31))' % (R(reg(ops[1])), R(reg(ops[2])))
        return '%s = %s;' % (R(d), e)
    if m in ('andi', 'ori', 'xori'):
        op = {'andi': '&', 'ori': '|', 'xori': '^'}[m]
        v = imm(ops[2]) & 0xFFFF
        return '%s = %s %s %du;' % (R(reg(ops[0])), R(reg(ops[1])), op, v)
    if m == 'lui':
        v = (imm(ops[1]) & 0xFFFF) << 16
        return '%s = %du;' % (R(reg(ops[0])), v)
    if m in ('sll', 'srl', 'sra'):
        sh = imm(ops[2])
        if m == 'sll': return '%s = %s << %d;' % (R(reg(ops[0])), R(reg(ops[1])), sh)
        if m == 'srl': return '%s = %s >> %d;' % (R(reg(ops[0])), R(reg(ops[1])), sh)
        return '%s = (u32)((s32)%s >> %d);' % (R(reg(ops[0])), R(reg(ops[1])), sh)
    if m in ('mult', 'multu'):
        a, b = R(reg(ops[0])), R(reg(ops[1]))
        if m == 'mult': return '{ s64 p_ = (s64)(s32)%s * (s32)%s; lo = (u32)p_; hi = (u32)(p_ >> 32); }' % (a, b)
        return '{ u64 p_ = (u64)%s * %s; lo = (u32)p_; hi = (u32)(p_ >> 32); }' % (a, b)
    if m in ('div', 'divu'):
        a, b = R(reg(ops[-2])), R(reg(ops[-1]))
        if m == 'div': return 'if (%s) { lo = (u32)((s32)%s / (s32)%s); hi = (u32)((s32)%s %% (s32)%s); }' % (b, a, b, a, b)
        return 'if (%s) { lo = %s / %s; hi = %s %% %s; }' % (b, a, b, a, b)
    if m == 'mflo': return '%s = lo;' % R(reg(ops[0]))
    if m == 'mfhi': return '%s = hi;' % R(reg(ops[0]))
    if m == 'mtlo': return 'lo = %s;' % R(reg(ops[0]))
    if m == 'mthi': return 'hi = %s;' % R(reg(ops[0]))
    if m in ('lw', 'lh', 'lhu', 'lb', 'lbu', 'sw', 'sh', 'sb', 'lwc1', 'swc1', 'ldc1', 'sdc1'):
        mm = re.match(r'(.*)\((\$?\w+)\)$', ops[1])
        off = simm(imm(mm.group(1) or '0')); base = R(reg(mm.group(2)))
        addr = '(%s + (u32)(s32)%d)' % (base, off)
        if m in ('lwc1', 'swc1', 'ldc1', 'sdc1'):
            fr = freg(ops[0])
            if m == 'lwc1': return '{ u32 w_ = *(u32 *)%s; memcpy(&%s, &w_, 4); }' % (addr, F(fr))
            if m == 'swc1': return '{ u32 w_; memcpy(&w_, &%s, 4); *(u32 *)%s = w_; }' % (F(fr), addr)
            if fr % 2 == 1:     # an odd register holds a single (doubles use even registers): the 64-bit save/restore moves only its own 32 bits (low word),
                                # otherwise restoring $f21 would also overwrite $f22 with a stale value
                if m == 'ldc1': return '{ u32 w_ = *(u32 *)(%s + 4); memcpy(&%s, &w_, 4); }' % (addr, F(fr))
                return '{ u32 w_; memcpy(&w_, &%s, 4); *(u32 *)%s = 0; *(u32 *)(%s + 4) = w_; }' % (F(fr), addr, addr)
            if m == 'ldc1': return '{ u32 hi_ = *(u32 *)%s, lo_ = *(u32 *)(%s + 4); memcpy(&%s, &hi_, 4); memcpy(&%s, &lo_, 4); }' % (addr, addr, F(fr + 1) if False else F(fr), F(fr + 1))
            return '{ u32 hi_, lo_; memcpy(&hi_, &%s, 4); memcpy(&lo_, &%s, 4); *(u32 *)%s = hi_; *(u32 *)(%s + 4) = lo_; }' % (F(fr), F(fr + 1), addr, addr)
        t = R(reg(ops[0]))
        if m == 'lw': return '%s = *(u32 *)%s;' % (t, addr)
        if m == 'lh': return '%s = (u32)(s32)*(s16 *)%s;' % (t, addr)
        if m == 'lhu': return '%s = *(u16 *)%s;' % (t, addr)
        if m == 'lb': return '%s = (u32)(s32)*(s8 *)%s;' % (t, addr)
        if m == 'lbu': return '%s = *(u8 *)%s;' % (t, addr)
        if m == 'sw': return '*(u32 *)%s = %s;' % (addr, t)
        if m == 'sh': return '*(u16 *)%s = (u16)%s;' % (addr, t)
        if m == 'sb': return '*(u8 *)%s = (u8)%s;' % (addr, t)
    if m == 'mtc1': return '{ u32 w_ = %s; memcpy(&%s, &w_, 4); }' % (R(reg(ops[0])), F(freg(ops[1])))
    if m == 'mfc1': return '{ u32 w_; memcpy(&w_, &%s, 4); %s = w_; }' % (F(freg(ops[1])), R(reg(ops[0])))
    if m in ('add.s', 'sub.s', 'mul.s', 'div.s'):
        op = {'add': '+', 'sub': '-', 'mul': '*', 'div': '/'}[m[:3]]
        return '%s = %s %s %s;' % (F(freg(ops[0])), F(freg(ops[1])), op, F(freg(ops[2])))
    if m in ('add.d', 'sub.d', 'mul.d', 'div.d'):
        op = {'add': '+', 'sub': '-', 'mul': '*', 'div': '/'}[m[:3]]
        return 'sd(f, %d, gd(f, %d) %s gd(f, %d));' % (freg(ops[0]), freg(ops[1]), op, freg(ops[2]))
    if m == 'mov.d': return 'sd(f, %d, gd(f, %d));' % (freg(ops[0]), freg(ops[1]))
    if m == 'neg.d': return 'sd(f, %d, -gd(f, %d));' % (freg(ops[0]), freg(ops[1]))
    if m == 'abs.d': return 'sd(f, %d, fabs(gd(f, %d)));' % (freg(ops[0]), freg(ops[1]))
    if m == 'sqrt.d': return 'sd(f, %d, sqrt(gd(f, %d)));' % (freg(ops[0]), freg(ops[1]))
    if m == 'cvt.d.s': return 'sd(f, %d, (double)%s);' % (freg(ops[0]), F(freg(ops[1])))
    if m == 'cvt.s.d': return '%s = (float)gd(f, %d);' % (F(freg(ops[0])), freg(ops[1]))
    if m == 'cvt.d.w': return '{ u32 w_; memcpy(&w_, &%s, 4); sd(f, %d, (double)(s32)w_); }' % (F(freg(ops[1])), freg(ops[0]))
    if m in ('trunc.w.d', 'cvt.w.d'): return '{ s32 w_ = (s32)gd(f, %d); memcpy(&%s, &w_, 4); }' % (freg(ops[1]), F(freg(ops[0])))
    if m in ('round.w.s', 'floor.w.s', 'ceil.w.s'):
        fn = {'round': 'rintf', 'floor': 'floorf', 'ceil': 'ceilf'}[m.split('.')[0]]
        return '{ s32 w_ = (s32)%s(%s); memcpy(&%s, &w_, 4); }' % (fn, F(freg(ops[1])), F(freg(ops[0])))
    if m in ('round.w.d', 'floor.w.d', 'ceil.w.d'):
        fn = {'round': 'rint', 'floor': 'floor', 'ceil': 'ceil'}[m.split('.')[0]]
        return '{ s32 w_ = (s32)%s(gd(f, %d)); memcpy(&%s, &w_, 4); }' % (fn, freg(ops[1]), F(freg(ops[0])))
    if m.startswith('c.') and m.endswith('.d'):
        k = m[2:-2]; cmp = {'lt': '<', 'le': '<=', 'eq': '==', 'ult': '<', 'ule': '<=', 'ueq': '=='}[k]
        return 'fcc = gd(f, %d) %s gd(f, %d);' % (freg(ops[0]), cmp, freg(ops[1]))
    if m in ('mov.s',): return '%s = %s;' % (F(freg(ops[0])), F(freg(ops[1])))
    if m in ('neg.s',): return '%s = -%s;' % (F(freg(ops[0])), F(freg(ops[1])))
    if m in ('abs.s',): return '%s = fabsf(%s);' % (F(freg(ops[0])), F(freg(ops[1])))
    if m in ('sqrt.s',): return '%s = sqrtf(%s);' % (F(freg(ops[0])), F(freg(ops[1])))
    if m == 'cvt.s.w': return '{ u32 w_; memcpy(&w_, &%s, 4); %s = (float)(s32)w_; }' % (F(freg(ops[1])), F(freg(ops[0])))
    if m in ('trunc.w.s', 'cvt.w.s'): return '{ s32 w_ = (s32)%s; memcpy(&%s, &w_, 4); }' % (F(freg(ops[1])), F(freg(ops[0])))
    if m.startswith('c.') and m.endswith('.s'):
        k = m[2:-2]; a, b = F(freg(ops[0])), F(freg(ops[1]))
        cmp = {'lt': '<', 'le': '<=', 'eq': '==', 'ult': '<', 'ule': '<=', 'ueq': '=='}[k]
        return 'fcc = %s %s %s;' % (a, cmp, b)
    raise ValueError('unsupported instruction: %s %s' % (m, ops))

def cond(m, ops):
    if m in ('beq', 'beql'): return '%s == %s' % (R(reg(ops[0])), R(reg(ops[1])))
    if m in ('bne', 'bnel'): return '%s != %s' % (R(reg(ops[0])), R(reg(ops[1])))
    if m in ('beqz', 'beqzl'): return '%s == 0' % R(reg(ops[0]))
    if m in ('bnez', 'bnezl'): return '%s != 0' % R(reg(ops[0]))
    if m in ('bgez', 'bgezl'): return '(s32)%s >= 0' % R(reg(ops[0]))
    if m in ('bltz', 'bltzl'): return '(s32)%s < 0' % R(reg(ops[0]))
    if m in ('blez', 'blezl'): return '(s32)%s <= 0' % R(reg(ops[0]))
    if m in ('bgtz', 'bgtzl'): return '(s32)%s > 0' % R(reg(ops[0]))
    if m in ('bc1t', 'bc1tl'): return 'fcc'
    if m in ('bc1f', 'bc1fl'): return '!fcc'
    if m == 'b': return '1'
    raise ValueError(m)

def is_ctl(m): return m in BR or m in ('j', 'jr', 'jal', 'jalr')

def call_args(pending_stack):
    """a0-a3 plus any stack-passed arguments stored at 0x10(sp), 0x14(sp)... since the previous call"""
    extra = []
    k = 0x10
    while k in pending_stack: extra.append('stk[(%d)/4]' % k); k += 4
    return ['r[4]', 'r[5]', 'r[6]', 'r[7]'] + [('*(u32 *)(r[29] + %d)' % (0x10 + 4 * i)) for i in range(len(extra))]


_DEST_FIRST = {'addu', 'add', 'addi', 'addiu', 'subu', 'sub', 'and', 'or', 'xor', 'nor', 'slt', 'sltu', 'sllv', 'srlv', 'srav', 'move', 'li', 'negu', 'not',
               'slti', 'sltiu', 'mul', 'andi', 'ori', 'xori', 'lui', 'sll', 'srl', 'sra', 'lw', 'lh', 'lhu', 'lb', 'lbu', 'mflo', 'mfhi', 'mfc1', 'cfc1', 'mfc0'}
def int_arg_count(items):
    """number of integer argument registers (a0-a3) the function reads before writing them"""
    written = set(); n = 0
    for it in items:
        if it[0] != 'ins': continue
        m, ops = it[1], it[2]
        regs = [re.findall(r'\$(zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra)(?![\w])', o) for o in ops]
        flat = [r for rs in regs for r in rs]
        if m in ('jal', 'jalr'):
            if m == 'jalr' and ops: 
                for r in regs[0]:
                    if r in ('a0', 'a1', 'a2', 'a3') and r not in written: n = max(n, int(r[1]) + 1)
            written.update(('a0', 'a1', 'a2', 'a3'))
            continue
        if m in _DEST_FIRST and ops:
            srcs = [r for rs in regs[1:] for r in rs]; dest = regs[0]
        elif m in ('mtc1', 'ctc1', 'mtc0'):
            srcs = regs[0] if regs else []; dest = []
        else:
            srcs = flat; dest = []
        for r in srcs:
            if r in ('a0', 'a1', 'a2', 'a3') and r not in written: n = max(n, int(r[1]) + 1)
        for r in dest: written.add(r)
    return n

def recompile_function(text, name, known, max_stack_args=0):
    sg = fpsigs().get(name)
    entry_goto = False
    for ext, pre in ((0, 0), (1, 0), (0, 1), (1, 1), (2, 0), (0, 2), (2, 2), (3, 3), (5, 5)):
        items = parse(text, name, ext, pre)
        if not items: raise ValueError('function %s not found' % name)
        labels = {it[1] for it in items if it[0] == 'label'}
        targets = {it[2][-1] for it in items if it[0] == 'ins' and it[1] in BR and it[2]} | {it[2][0] for it in items if it[0] == 'ins' and it[1] == 'j' and it[2][0].startswith('.L')}
        entry_goto = pre > 0
        if targets <= labels: break
    else:
        raise ValueError('unresolved branch targets: ' + ' '.join(sorted(targets - labels)[:3]))
    if sg and ('?' in sg[1] or sg[0] == 'l'): raise ValueError('unsupported float signature')
    if fa_read_first(items) and (sg is None or not any(t in ('f', 'd') for t in sg[1])): raise ValueError('float parameters of unknown type')
    ARGC[name] = int_arg_count(items)
    # frame size and incoming stack args
    frame = 0; inargs = 0
    for it in items:
        if it[0] == 'ins' and it[1] in ('addiu', 'addi') and it[2][0] in ('$sp', 'sp') and it[2][1] in ('$sp', 'sp'):
            v = simm(imm(it[2][2]))
            if v < 0: frame = max(frame, -v)
    for it in items:
        if it[0] == 'ins' and it[1] in ('lw', 'lh', 'lhu', 'lb', 'lbu', 'lwc1'):
            mm = re.match(r'(.*)\(\$?sp\)$', it[2][1])
            if mm and imm(mm.group(1) or '0') >= frame + 0x10:      # (frame may be 0: a leaf without its own stack frame still reads its stack arguments at 16($sp)...)
                inargs = max(inargs, (imm(mm.group(1)) - frame - 0x10) // 4 + 1)
    if frame:      # the address of the incoming argument area is taken (a struct passed by value, handed on by pointer): all of it (up to 10 words, 7 on the stack) must arrive
        for it in items:
            if it[0] == 'ins' and it[1] in ('addiu', 'addi') and it[2][1] in ('$sp', 'sp') and it[2][0] not in ('$sp', 'sp'):
                v = simm(imm(it[2][2]))
                if frame + 4 <= v < frame + 0x40: inargs = max(inargs, 7)
    inargs = min(inargs, 20)
    jtargets = [t for it in items if it[0] == 'jtbl' for t in it[1]]
    body = []
    regconst = {}
    pending = set()
    saved_slots = set()
    seen_call = False
    i = 0
    code_consts = set()
    while i < len(items):
        it = items[i]
        if it[0] == 'jtbl':
            i += 1; continue
        if it[0] == 'label':
            body.append('%s:;' % label_name(it[1])); regconst.clear(); i += 1; continue
        _, m, ops = it
        if is_ctl(m):
            j = i + 1
            while j < len(items) and items[j][0] == 'label': j += 1
            if j >= len(items): dm, dops, delay = 'nop', [], ''
            else:
                dm, dops = items[j][1], items[j][2]
                if is_ctl(dm): raise ValueError('branch in delay slot')
                delay = gen_ins(dm, dops, known, None)
            tail = '{ return (u32)((u32 (*)())%s)(r[4], r[5], r[6], r[7]); }'
            if m in BR:
                if ops[-1] not in labels:                          # conditional tail call into another function
                    act = '%s ' % delay + tail % ops[-1]
                    if (m.endswith('l') and m != 'b') or m in ('bc1tl', 'bc1fl'): body.append('if (%s) { %s }' % (cond(m, ops), act))
                    else: body.append('{ int c_ = %s; %s if (c_) { %s } }' % (cond(m, ops), delay, tail % ops[-1]))
                    i = min(j + 1, len(items)); continue
                tgt = label_name(ops[-1])
                if (m.endswith('l') and m != 'b') or m in ('bc1tl', 'bc1fl'): body.append('if (%s) { %s goto %s; }' % (cond(m, ops), delay, tgt))
                else: body.append('{ int c_ = %s; %s if (c_) goto %s; }' % (cond(m, ops), delay, tgt))
            elif m == 'j':
                if ops[0] in labels: body.append('%s goto %s;' % (delay, label_name(ops[0])))
                else: body.append('%s ' % delay + tail % ops[0])
            elif m == 'jr':
                if reg(ops[0]) != 31:
                    if not jtargets: raise ValueError('jr to non-ra (jump table?)')
                    cases = ' '.join('case %du: goto %s;' % (int(t[2:], 16), label_name(t)) for t in sorted(set(jtargets)))
                    jn_ = len([b for b in body if 'jr_again' in b]) 
                    body.append('{ u32 jr_ = %s; %s jr_again%d:; switch (jr_) { %s default: { u32 g_ = port_unresolve(jr_); if (g_ != jr_) { jr_ = g_; goto jr_again%d; } __builtin_trap(); } } }' % (R(reg(ops[0])), delay, jn_, cases, jn_))
                else:
                    body.append('%s return r[2];' % delay)
            elif m in ('jal', 'jalr'):
                if m == 'jal': target = ops[0]
                else: target = None
                # stack-passed arguments: stores to 0x10(sp).. since the last call
                if dm in ('sw', 'swc1', 'sdc1'):                 # an argument store in the delay slot counts too
                    mm = re.match(r'(.*)\(\$?sp\)$', dops[1])
                    if mm:
                        off = simm(imm(mm.group(1) or '0'))
                        if dm == 'sw' and not seen_call and reg(dops[0]) in (16, 17, 18, 19, 20, 21, 22, 23, 30, 31): saved_slots.add(off)
                        elif 0x10 <= off < 0x70 and off not in saved_slots:
                            pending.add(('sp', off))
                            if dm == 'sdc1': pending.add(('sp', off + 4))
                nargs = 4
                while ('sp', 0x10 + 4 * (nargs - 4)) in pending: nargs += 1
                args = ['r[4]', 'r[5]', 'r[6]', 'r[7]'] + ['*(u32 *)(r[29] + %d)' % (0x10 + 4 * k) for k in range(nargs - 4)]
                if target in STRUCTARGS: args = [args[0]] + ['__builtin_bswap32(%s)' % a for a in args[1:]]      # struct words go to native code as the memory image
                sw = lambda k: '*(u32 *)(r[29] + %d)' % (0x10 + 4 * k)
                if target == 'osGetTime':                        # u64 result comes back in v0 (high) : v1 (low)
                    body.append('%s { u64 v_ = ((u64 (*)())osGetTime)(); r[2] = (u32)(v_ >> 32); r[3] = (u32)v_; }' % delay)
                elif target in ('__udivdi3', '__umoddi3', '__divdi3', '__moddi3'):        # 64-bit helpers: operands in a0:a1 / a2:a3 (hi:lo), result in v0:v1
                    op = {'__udivdi3': ('u64', '/'), '__umoddi3': ('u64', '%'), '__divdi3': ('s64', '/'), '__moddi3': ('s64', '%')}[target]
                    body.append('%s { %s x_ = (%s)(((u64)r[4] << 32) | r[5]), y_ = (%s)(((u64)r[6] << 32) | r[7]); u64 v_ = y_ ? (u64)(x_ %s y_) : 0; r[2] = (u32)(v_ >> 32); r[3] = (u32)v_; }' % (delay, op[0], op[0], op[0], op[1]))
                elif target in ('__cmpdi2', '__ucmpdi2'):
                    sg_ = 's64' if target == '__cmpdi2' else 'u64'
                    body.append('%s { %s x_ = (%s)(((u64)r[4] << 32) | r[5]), y_ = (%s)(((u64)r[6] << 32) | r[7]); r[2] = x_ < y_ ? 0 : (x_ == y_ ? 1 : 2); }' % (delay, sg_, sg_, sg_))
                elif target in ('__floatdisf', '__floatdidf', '__floatundisf', '__floatundidf'):
                    cv = 's64' if 'undi' not in target else 'u64'
                    if target.endswith('f'): body.append('%s f[0] = (float)(%s)(((u64)r[4] << 32) | r[5]);' % (delay, cv))
                    else: body.append('%s sd(f, 0, (double)(%s)(((u64)r[4] << 32) | r[5]));' % (delay, cv))
                elif target in ('__fixdfdi', '__fixsfdi', '__fixunsdfdi', '__fixunssfdi'):
                    src = 'gd(f, 12)' if 'df' in target else 'f[12]'
                    ty = 's64' if 'uns' not in target else 'u64'
                    body.append('%s { %s v_ = (%s)%s; r[2] = (u32)((u64)v_ >> 32); r[3] = (u32)v_; }' % (delay, ty, ty, src))
                elif target == 'osSetTimer':                     # (t, pad, countdown_hi, countdown_lo | interval_hi, interval_lo, mq, msg on the stack)
                    body.append('%s r[2] = (u32)((u32 (*)())osSetTimer)(r[4], ((u64)r[6] << 32) | r[7], ((u64)%s << 32) | %s, %s, %s);' % (delay, sw(0), sw(1), sw(2), sw(3)))
                elif target is not None and target in fpsigs() and '?' not in fpsigs()[target][1] and fpsigs()[target][0] != 'l':
                    rt, types = fpsigs()[target]
                    if ALLARGC.get(target, 0) > len(types): types = list(types) + ['i'] * (ALLARGC[target] - len(types))
                    cargs = arg_exprs(types)
                    proto = '%s (*)(%s)' % ({'f': 'float', 'd': 'double', 'v': 'void', 'i': 'u32'}[rt], ', '.join(CT[t] for t in types) or 'void')
                    call = '((%s)%s)(%s)' % (proto, target, ', '.join(cargs))
                    if rt == 'f': body.append('%s f[0] = %s;' % (delay, call))
                    elif rt == 'd': body.append('%s sd(f, 0, %s);' % (delay, call))
                    elif rt == 'v': body.append('%s %s;' % (delay, call))
                    else: body.append('%s r[2] = (u32)%s;' % (delay, call))
                elif target is not None:
                    body.append('%s r[2] = (u32)((u32 (*)())%s)(%s);' % (delay, target, ', '.join(args)))
                else:
                    body.append('%s r[2] = (u32)((u32 (*)())port_resolve(%s))(%s);' % (delay, R(reg(ops[0])), ', '.join(args)))
                pending = set(); seen_call = True
            i = min(j + 1, len(items)); continue
        # remember stores to outgoing argument slots
        if m in ('sw', 'swc1', 'sdc1'):
            mm = re.match(r'(.*)\(\$?sp\)$', ops[1])
            if mm:
                off = simm(imm(mm.group(1) or '0'))
                if m == 'sw' and not seen_call and reg(ops[0]) in (16, 17, 18, 19, 20, 21, 22, 23, 30, 31):
                    saved_slots.add(off)                          # callee-saved register spill, not an argument
                elif 0x10 <= off < 0x70 and off not in saved_slots:
                    pending.add(('sp', off))
                    if m == 'sdc1': pending.add(('sp', off + 4))
        txt = gen_ins(m, ops, known, None)
        # function addresses materialised as constants (lui + addiu/ori, possibly with other instructions in between):
        # use the real function symbol so that the value is a host pointer
        try:
            if m == 'lui':
                regconst[reg(ops[0])] = (imm(ops[1]) & 0xFFFF) << 16
            elif m in ('addiu', 'addi', 'ori') and reg(ops[1]) in regconst:
                base = regconst[reg(ops[1])]
                v = (base + simm(imm(ops[2]))) & 0xFFFFFFFF if m != 'ori' else base | (imm(ops[2]) & 0xFFFF)
                regconst[reg(ops[0])] = v
                if isinstance(known, dict) and v in known and 0x200000 <= v < 0x450000:
                    txt = 'r[%d] = (u32)%s;' % (reg(ops[0]), known[v])
            else:
                mdest = re.match(r'r\[(\d+)\] = ', txt)
                if mdest: regconst.pop(int(mdest.group(1)), None)
        except Exception:
            pass
        body.append(txt); i += 1
    # frame storage: sp points into a local array
    stk_words = max(frame // 4 + 16 + 8, 64)
    fname_ = name + '_rc' if sg else name
    sig = 'u32 %s(u32 a0, u32 a1, u32 a2, u32 a3%s) {' % (fname_, ''.join(', u32 a%d' % (4 + k) for k in range(inargs)))
    NULLGUARD = set(open('port/recomp_nullguard.txt').read().split()) if os.path.exists('port/recomp_nullguard.txt') else set()      # functions the game calls with a NULL first argument that the original tolerates or never reaches
    pre = ['port_rc_enter("%s", a0, a1, a2, a3);' % name] + (['if (!a0) return 0;      /* port guard */'] if name in NULLGUARD else []) + [ 'u32 r[32]; float *f = g_fpr; u32 lo = 0, hi = 0; int fcc = 0; u32 stk[%d] = { 0 }; int i_;' % (stk_words + 32),
           'for (i_ = 0; i_ < 32; i_++) r[i_] = 0;',
           ('r[4] = a0; r[5] = __builtin_bswap32(a1); r[6] = __builtin_bswap32(a2); r[7] = __builtin_bswap32(a3); r[31] = 0;' if name in STRUCTARGS else 'r[4] = a0; r[5] = a1; r[6] = a2; r[7] = a3; r[31] = 0;'),
           'r[29] = (u32)&stk[%d];' % (stk_words),
           ] + ['*(u32 *)((u32)&stk[%d] + %d) = %sa%d%s;' % (stk_words, 0x10 + 4 * k, '__builtin_bswap32(' if name in STRUCTARGS else '', 4 + k, ')' if name in STRUCTARGS else '') for k in range(inargs)]
    # incoming stack args live above the frame: caller frame offset = frame + 0x10 + 4k relative to the entry sp
    # we put them at (entry sp) + 0x10 + 4k, i.e. stk[stk_words + 4 + k]
    if entry_goto: body.insert(0, 'goto %s;' % label_name(name))
    text = '\n'.join([sig] + ['    ' + l for l in pre + body] + ['    return r[2];', '}'])
    if sg:
        rt, types = sg
        if ALLARGC.get(name, 0) > len(types): types = list(types) + ['i'] * (ALLARGC[name] - len(types))     # prototype declared fewer parameters than the code reads
        cparams = ', '.join('%s p%d' % (CT[t], i) for i, t in enumerate(types)) or 'void'
        words = [None] * 24; setf = []; word = 0
        for idx, t in enumerate(types):
            if t == 'd': word = (word + 1) & ~1
            if (idx == 0 and t in ('f', 'd')) or (idx == 1 and t in ('f', 'd') and types[0] in ('f', 'd')):
                setf.append('g_fpr[%d] = p%d;' % (12 + 2 * idx, idx) if t == 'f' else 'sd(g_fpr, %d, p%d);' % (12 + 2 * idx, idx))
            elif word < 24:
                if t == 'i': words[word] = 'p%d' % idx
                elif t == 'f': words[word] = 'f2u(p%d)' % idx
                else:
                    words[word] = 'd2hi(p%d)' % idx
                    if word + 1 < 24: words[word + 1] = 'd2lo(p%d)' % idx
            word += 2 if t == 'd' else 1
        nwords = max(4, inargs + 4)
        callargs = ', '.join(w or '0' for w in words[:nwords])
        retexpr = {'f': 'g_fpr[0]', 'd': 'gd(g_fpr, 0)', 'v': '', 'i': '(u32)r_'}[rt]
        rtc = {'f': 'float', 'd': 'double', 'v': 'void', 'i': 'u32'}[rt]
        wrapper = '%s %s(%s) { u32 r_; %s r_ = %s_rc(%s); (void)r_; %s }' % (rtc, name, cparams, ' '.join(setf), name, callargs, ('return %s;' % retexpr) if rt != 'v' else '')
        text += '\n' + wrapper
    return text

def main():
    path, name = sys.argv[1], sys.argv[2]
    print(recompile_function(open(path, encoding='utf-8').read(), name, set()))

if __name__ == '__main__':
    main()
