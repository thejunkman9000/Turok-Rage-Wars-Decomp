#!/usr/bin/env python3
"""rtlc.py <dumpfile> [uid_lo uid_hi] : condense gcc RTL dump to one line per insn (uid + compact pattern)"""
import sys, re
t = open(sys.argv[1]).read()
lo = int(sys.argv[2]) if len(sys.argv) > 2 else 0
hi = int(sys.argv[3]) if len(sys.argv) > 3 else 10**9
# split top-level forms starting at "(insn" etc. at column 0
forms = re.split(r'\n(?=\((?:insn|jump_insn|call_insn|note|code_label|barrier) )', t)
for f in forms:
    m = re.match(r'\((insn|jump_insn|call_insn|note|code_label|barrier) (\d+) ', f)
    if not m: continue
    kind, uid = m.group(1), int(m.group(2))
    if uid < lo or uid > hi: continue
    s = ' '.join(f.split())
    s = re.sub(r'\(const_int (-?\d+)\)', r'\1', s)
    s = re.sub(r'\(reg(?:/[a-z]+)?:(\w+) (\d+)(?: \[?\$?(\w+)\]?)?\)', lambda m: f'r{m.group(2)}' + (f':{m.group(3)}' if m.group(3) else ''), s)
    s = re.sub(r'\(mem(?:/[a-z]+)?:(\w+) ', '(mem ', s)
    s = re.sub(r'\{[^}]*\}', '', s)
    s = re.sub(r'\(nil\)', '', s)
    print(s[:230])
