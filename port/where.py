#!/usr/bin/env python3
"""Symbolize crash lines from port_log.txt using port/build/turok.map.  usage: python port/where.py [port_log.txt]"""
import re, sys, bisect
syms = []; base = None
for l in open('port/build/turok.map', errors='replace'):
    m = re.match(r'\s*Preferred load address is ([0-9a-f]+)', l)
    if m: base = int(m.group(1), 16)
    m = re.match(r'\s*[0-9a-f]{4}:[0-9a-f]{8}\s+(\S+)\s+([0-9a-f]{8})', l)
    if m and base is not None and int(m.group(2), 16) >= base: syms.append((int(m.group(2), 16) - base, m.group(1)))
syms.sort(); keys = [s[0] for s in syms]
def where(rva):
    i = bisect.bisect_right(keys, rva) - 1
    return f'{syms[i][1]}+0x{rva - syms[i][0]:X}' if i >= 0 else '?'
seen = set()
for l in open(sys.argv[1] if len(sys.argv) > 1 else 'port_log.txt', errors='replace'):
    m = re.search(r'rva=([0-9A-F]+)', l)
    if m and ('crash', m.group(1)) not in seen:
        seen.add(('crash', m.group(1))); print('CRASH at', where(int(m.group(1), 16)), l.strip()[:90])
    m = re.search(r'stack rvas:(.*)', l)
    if m and ('stack', m.group(1)) not in seen:
        seen.add(('stack', m.group(1)))
        for r in m.group(1).split():
            print('   ', r, where(int(r, 16)))
