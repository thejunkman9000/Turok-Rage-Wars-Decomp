#!/usr/bin/env python3
"""usage: rtlbrief.py <dumpfile> : compact view of insn stream in file order: uid  dest <- src"""
import re, sys
txt = open(sys.argv[1]).read()
items = re.split(r'\n(?=\((?:insn|call_insn|jump_insn|note|code_label|barrier)(?:/\w+)? )', txt)
for it in items:
    m = re.match(r'\((insn|call_insn|jump_insn|code_label|note|barrier)(?:/\w+)? (\d+) ', it)
    if not m: continue
    kind, uid = m.group(1), m.group(2)
    if kind == 'note':
        n = re.search(r'"" (NOTE_\w+)', it)
        if n and n.group(1) in ('NOTE_INSN_LOOP_BEG','NOTE_INSN_LOOP_END','NOTE_INSN_LOOP_CONT','NOTE_INSN_LOOP_VTOP'):
            print(f'{uid:>5} {n.group(1)}')
        continue
    if kind == 'code_label':
        print(f'{uid:>5} LABEL'); continue
    if kind == 'barrier': continue
    body = re.sub(r'\s+', ' ', it.split('\n\n')[0])
    body = re.sub(r'\(expr_list.*$', '', body)
    body = re.sub(r'\(insn_list.*$', '', body)
    body = re.sub(r'\(nil\)', '', body)
    body = re.sub(r'\(reg(?:/[a-z]+)?:(\w\w) (\d+)(?: \w+)?\)', lambda m: f'r{m.group(2)}', body)
    body = re.sub(r'\(mem(?:/[a-z]+)?:(\w\w) ', 'mem(', body)
    body = re.sub(r'\(const_int (-?\d+)\)', r'#\1', body)
    body = re.sub(r'\(symbol_ref:SI \("(\w+)"\)\)', r'&\1', body)
    body = re.sub(r'^\((?:insn|call_insn|jump_insn)(?:/\w+)? \d+ \d+ \d+ ', '', body)
    print(f'{uid:>5} {body[:150]}')
