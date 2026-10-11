#!/usr/bin/env python3
"""loopctx.py <rtl dump> [k] : for the k-th (default all) NOTE_INSN_LOOP_BEG of a gcc RTL dump print the 10 insns before it and 6 after, one condensed line each (uid + pattern)."""
import re, sys
t = open(sys.argv[1]).read()
forms = []
for m in re.finditer(r'\((insn|jump_insn|call_insn|note|code_label|barrier)(?:/\w+)? (\d+) .*?(?=\n\((?:insn|jump_insn|call_insn|note|code_label|barrier)|\Z)', t, re.S):
    s = ' '.join(m.group(0).split())
    s = re.sub(r'\(const_int (-?\d+)\)', r'\1', s)
    s = re.sub(r'\(reg(?:/[a-z]+)?:\w+ (\d+)(?: \[?\$?(\w+)\]?)?\)', lambda q: 'r' + q.group(1) + (':' + q.group(2) if q.group(2) else ''), s)
    s = re.sub(r'\{[^}]*\}', '', s); s = re.sub(r'\(nil\)', '', s)
    forms.append((int(m.group(2)), s))
beg = [i for i, (u, s) in enumerate(forms) if 'LOOP_BEG' in s]
ks = [int(sys.argv[2])] if len(sys.argv) > 2 else range(len(beg))
for k in ks:
    b = beg[k]
    print('=== loop', k, 'LOOP_BEG uid', forms[b][0])
    for u, s in forms[max(0, b - 10):b + 7]:
        if 'NOTE_INSN_DELETED' in s: continue
        print('  ', s[:220])
