#!/usr/bin/env python3
"""one-off patch of port/mips2c.py: floating point calling convention + shared FPU register file"""
p = 'port/mips2c.py'
s = open(p, newline='').read()
if 'FPSIG' in s:
    print('already patched'); raise SystemExit

def sub(old, new, count=1):
    global s
    if old not in s:
        print('MISSING:', old[:90]); raise SystemExit(1)
    s = s.replace(old, new, count)

# --- helpers -------------------------------------------------------------------------------------------------------------
sub("BR = {'beqzl',", '''FPSIG = None
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
        if idx < 2 and t in ('f', 'd') and all(x in ('f', 'd') for x in types[:idx]) is not None:
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

BR = {'beqzl',''', 1)

# --- shared FPU register file --------------------------------------------------------------------------------------------
sub("""    pre = ['port_rc_enter("%s", a0, a1, a2, a3);' % name, 'u32 r[32]; float f[32]; u32 lo = 0, hi = 0; int fcc = 0; u32 stk[%d]; int i_;' % (stk_words + 32),
           'for (i_ = 0; i_ < 32; i_++) { r[i_] = 0; f[i_] = 0; }',""",
    """    pre = ['port_rc_enter("%s", a0, a1, a2, a3);' % name, 'u32 r[32]; float *f = g_fpr; u32 lo = 0, hi = 0; int fcc = 0; u32 stk[%d]; int i_;' % (stk_words + 32),
           'for (i_ = 0; i_ < 32; i_++) r[i_] = 0;',""")

# --- calls with float arguments / results ---------------------------------------------------------------------------------
sub("                elif target is not None:\n                    body.append('%s r[2] = (u32)((u32 (*)())%s)(%s);' % (delay, target, ', '.join(args)))",
    """                elif target is not None and target in fpsigs() and '?' not in fpsigs()[target][1] and fpsigs()[target][0] != 'l':
                    rt, types = fpsigs()[target]
                    cargs = arg_exprs(types)
                    proto = '%s (*)(%s)' % ({'f': 'float', 'd': 'double', 'v': 'void', 'i': 'u32'}[rt], ', '.join(CT[t] for t in types) or 'void')
                    call = '((%s)%s)(%s)' % (proto, target, ', '.join(cargs))
                    if rt == 'f': body.append('%s f[0] = %s;' % (delay, call))
                    elif rt == 'd': body.append('%s sd(f, 0, %s);' % (delay, call))
                    elif rt == 'v': body.append('%s %s;' % (delay, call))
                    else: body.append('%s r[2] = (u32)%s;' % (delay, call))
                elif target is not None:
                    body.append('%s r[2] = (u32)((u32 (*)())%s)(%s);' % (delay, target, ', '.join(args)))""")

# --- function entry: float arguments of unknown type are not supported; typed ones get a wrapper -------------------------------
sub("    entry_goto = False\n    for ext, pre in",
    """    sg = fpsigs().get(name)
    entry_goto = False
    for ext, pre in""")
sub("    # frame size and incoming stack args",
    """    if sg and ('?' in sg[1] or sg[0] == 'l'): raise ValueError('unsupported float signature')
    if fa_read_first(items) and (sg is None or not any(t in ('f', 'd') for t in sg[1])): raise ValueError('float parameters of unknown type')
    # frame size and incoming stack args""")
sub("    sig = 'u32 %s(u32 a0, u32 a1, u32 a2, u32 a3%s) {' % (name, ''.join(', u32 a%d' % (4 + k) for k in range(inargs)))",
    "    fname_ = name + '_rc' if sg else name\n    sig = 'u32 %s(u32 a0, u32 a1, u32 a2, u32 a3%s) {' % (fname_, ''.join(', u32 a%d' % (4 + k) for k in range(inargs)))")
sub("    if entry_goto: body.insert(0, 'goto %s;' % label_name(name))\n    return '\\n'.join([sig] + ['    ' + l for l in pre + body] + ['    return r[2];', '}'])",
    """    if entry_goto: body.insert(0, 'goto %s;' % label_name(name))
    text = '\\n'.join([sig] + ['    ' + l for l in pre + body] + ['    return r[2];', '}'])
    if sg:
        rt, types = sg
        cparams = ', '.join('%s p%d' % (CT[t], i) for i, t in enumerate(types)) or 'void'
        words = [None] * 8; setf = []; word = 0
        for idx, t in enumerate(types):
            if t == 'd': word = (word + 1) & ~1
            if idx < 2 and t in ('f', 'd'):
                setf.append('g_fpr[%d] = p%d;' % (12 + 2 * idx, idx) if t == 'f' else 'sd(g_fpr, %d, p%d);' % (12 + 2 * idx, idx))
            elif word < 8:
                if t == 'i': words[word] = 'p%d' % idx
                elif t == 'f': words[word] = 'f2u(p%d)' % idx
                else:
                    words[word] = 'd2hi(p%d)' % idx
                    if word + 1 < 8: words[word + 1] = 'd2lo(p%d)' % idx
            word += 2 if t == 'd' else 1
        nwords = max(4, inargs + 4)
        callargs = ', '.join(w or '0' for w in words[:nwords])
        retexpr = {'f': 'g_fpr[0]', 'd': 'gd(g_fpr, 0)', 'v': '', 'i': '(u32)r_'}[rt]
        rtc = {'f': 'float', 'd': 'double', 'v': 'void', 'i': 'u32'}[rt]
        wrapper = '%s %s(%s) { u32 r_; %s r_ = %s_rc(%s); (void)r_; %s }' % (rtc, name, cparams, ' '.join(setf), name, callargs, ('return %s;' % retexpr) if rt != 'v' else '')
        text += '\\n' + wrapper
    return text""")
open(p, 'w', newline='').write(s)
print('patched mips2c')
