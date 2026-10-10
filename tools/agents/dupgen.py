#!/usr/bin/env python3
"""dupgen.py <base.c> <fn> <rom> <conds comma sep> [maxvariants]: for every simple statement line of function <fn>, generate the variant
`if (COND) { stmt } else { stmt }` (permuter's duplicate-arm trick) and rank all by chk S/R in ONE call (via tools/rv.py spec)."""
import sys, re, json
base, fn, rom, conds = sys.argv[1:5]
src = open(base).read()
i = re.search(r'^[A-Za-z_][\w \*]*\b' + fn + r'\s*\(', src, re.M).start()
lines = src[i:].split('\n')
V = []
names = {}
decl = re.compile(r'^\s*(u8|u16|u32|s8|s16|s32|f32|f64|void|static|extern|register|struct|typedef|SndMgr|M04\w*|B\d+\w*|S7\w*)\b[^=(]*;\s*$')
for k, l in enumerate(lines):
    st = l.strip()
    if not st.endswith(';') or st.startswith(('return', 'break', 'goto', 'case', 'default', 'else', 'do', 'while', 'for', 'if', '}', '{', '#')): continue
    if decl.match(l) or ':' in st.split('=')[0] and not '?' in st: continue
    if st.startswith('register') or st.startswith('asm') or st.startswith('__asm'): continue
    for c in conds.split(','):
        new = list(lines)
        ind = l[:len(l) - len(l.lstrip())]
        new[k] = f'{ind}if ({c}) {{ {st} }} else {{ {st} }}'
        v = src[:i] + '\n'.join(new)
        V.append((k, c, v))
        names[len(V) - 1] = f'{c}@{k}: {st[:40]}'
mx = int(sys.argv[5]) if len(sys.argv) > 5 else 10000
V = V[:mx]
print(len(V), 'variants')
open(__import__('os').environ.get('DUPSPEC','wip/vx/dup_spec.py'), 'w').write(
 'BASE=%r\nFN=%r\nROM=%r\nFLAGS=%r\nNAMES=%r\nVARIANTS=[]\nFULL=%r\n' % (base, fn, rom, '@SN', names, [v[2] for v in V]))
