#!/usr/bin/env python3
"""List every function of the splat asm (main image + overlay A) with simple statistics -> docs/game_funcs.txt.

columns: rom  name  insns  calls  callers  flags   (flags: L leaf, F float ops, S switch (jr non-ra), P prints/strings? no)
"""
import re, glob, collections
funcs = []
cur = None
for p in ['asm/entry.s', 'asm/16E000.s']:
    for l in open(p, encoding='utf-8'):
        m = re.match(r'glabel (\S+)', l)
        if m:
            cur = {'name': m.group(1), 'rom': None, 'ins': [], 'calls': set(), 'file': p}
            funcs.append(cur)
            continue
        m = re.match(r'\s*/\*\s*([0-9A-F]+)\s+([0-9A-F]+)\s+([0-9A-F]{8})\s*\*/\s*(.*)', l)
        if m and cur is not None:
            if cur['rom'] is None: cur['rom'] = int(m.group(1), 16)
            txt = m.group(4).strip()
            cur['ins'].append(txt)
            mj = re.match(r'jal\s+(\S+)', txt)
            if mj: cur['calls'].add(mj.group(1))
callers = collections.Counter()
for f in funcs:
    for c in f['calls']: callers[c] += 1
out = []
for f in sorted(funcs, key=lambda f: f['rom'] or 0):
    fl = ''
    if not f['calls']: fl += 'L'
    if any(re.search(r'\.[sd]\b', i.split()[0]) for i in f['ins'] if i): fl += 'F'
    if any(re.match(r'jr\s+\$(?!ra)', i) for i in f['ins']): fl += 'S'
    out.append(f"0x{f['rom']:06X} {f['name']} {len(f['ins'])} {len(f['calls'])} {callers[f['name']]} {fl}")
open('docs/game_funcs.txt', 'w', newline='\n').write('# rom name insns distinct-callees callers flags(L=leaf F=float S=switch)\n' + '\n'.join(out) + '\n')
print(len(out), 'functions')
