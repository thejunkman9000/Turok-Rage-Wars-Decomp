#!/usr/bin/env python3
"""one-off: jump table (switch) support: asm_all emits `.jtbl` lines, mips2c turns `jr $reg` into a switch"""
import re

# ---- asm_all.py: find the tables ----------------------------------------------------------------------------------------------
p = 'port/asm_all.py'
s = open(p, newline='').read()
if 'jump_tables' not in s:
    s = s.replace("def function_text(name, vaddr, n, ins, rom_base):\n    lo, hi = vaddr, vaddr + 4 * n\n    targets = set()",
'''_ROMWORDS = None
def jump_tables(lo, hi):
    """runs of >= 3 consecutive ROM words that are word-aligned addresses inside [lo, hi): switch tables of that function"""
    global _ROMWORDS
    if _ROMWORDS is None:
        r = rom(); nw = len(r) // 4
        _ROMWORDS = struct.unpack('>%dI' % nw, r[:nw * 4])
    ws = _ROMWORDS; runs = []
    i = 0x0C0000 // 4
    while i < len(ws):
        if lo <= ws[i] < hi and ws[i] % 4 == 0:
            j = i
            while j < len(ws) and lo <= ws[j] < hi and ws[j] % 4 == 0: j += 1
            if j - i >= 3: runs.append(list(ws[i:j]))
            i = j
        else: i += 1
    return runs

def function_text(name, vaddr, n, ins, rom_base):
    lo, hi = vaddr, vaddr + 4 * n
    targets = set()
    has_jr = any((ins[a][0] & 0xFC1FFFFF) == 0x00000008 and ((ins[a][0] >> 21) & 31) != 31 for a in range(lo, hi, 4) if a in ins)   # jr $reg (not ra)
    tables = jump_tables(lo, hi) if has_jr else []
    for run in tables: targets.update(run)''', 1)
    s = s.replace("    return '\\n'.join(out) + '\\n'\n\ndef tail_functions():",
                  "    for run in tables: out.append('.jtbl ' + ' '.join('.L%08X' % t for t in run))\n    return '\\n'.join(out) + '\\n'\n\ndef tail_functions():", 1)
    open(p, 'w', newline='').write(s)
    print('patched asm_all')

# ---- mips2c.py -----------------------------------------------------------------------------------------------------------------
p = 'port/mips2c.py'
s = open(p, newline='').read()
if "'jtbl'" not in s:
    # parse: keep .jtbl lines
    s = s.replace("        if not s or (s.startswith('.') and not s.startswith('.L')): continue\n        m = re.match(r'(\\.L\\w+):$', s)\n        if m: cur[1].append(('label', m.group(1))); continue",
                  "        if s.startswith('.jtbl'): cur[1].append(('jtbl', s.split()[1:])); continue\n        if not s or (s.startswith('.') and not s.startswith('.L')): continue\n        m = re.match(r'(\\.L\\w+):$', s)\n        if m: cur[1].append(('label', m.group(1))); continue", 1)
    # jr non-ra: switch over the table entries
    s = s.replace("                if reg(ops[0]) != 31: raise ValueError('jr to non-ra (jump table?)')\n                body.append('%s return r[2];' % delay)",
                  """                if reg(ops[0]) != 31:
                    if not jtargets: raise ValueError('jr to non-ra (jump table?)')
                    cases = ' '.join('case %du: goto %s;' % (int(t[2:], 16), label_name(t)) for t in sorted(set(jtargets)))
                    body.append('{ u32 jr_ = %s; %s switch (jr_) { %s default: __builtin_trap(); } }' % (R(reg(ops[0])), delay, cases))
                else:
                    body.append('%s return r[2];' % delay)""", 1)
    s = s.replace("    body = []\n    regconst = {}", "    jtargets = [t for it in items if it[0] == 'jtbl' for t in it[1]]\n    body = []\n    regconst = {}", 1)
    # jtbl items must be ignored by the generation loop
    s = s.replace("        if it[0] == 'label':\n            body.append('%s:;' % label_name(it[1])); regconst.clear(); i += 1; continue",
                  "        if it[0] == 'jtbl':\n            i += 1; continue\n        if it[0] == 'label':\n            body.append('%s:;' % label_name(it[1])); regconst.clear(); i += 1; continue", 1)
    open(p, 'w', newline='').write(s)
    print('patched mips2c')
