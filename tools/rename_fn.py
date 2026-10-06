#!/usr/bin/env python3
"""Rename a function everywhere: funcs.txt, src/<sub>/<old>.{s,c}, symbol_addrs.txt and every reference in src/ and wip/.

usage: python tools/rename_fn.py <old> <new> [<old> <new> ...]
`old` is normally an auto-name like func_002C5320 (or a previous guess); its VRAM address is taken from the name
(func_XXXXXXXX), from symbol_addrs.txt, or from the hasm file's first instruction comment.  Run tools/cycle.ps1 afterwards.
"""
import re, os, glob, sys

args = sys.argv[1:]
pairs = list(zip(args[0::2], args[1::2]))
funcs = open('funcs.txt', encoding='utf-8').read().split('\n')
funcs_a = open('funcs_a.txt', encoding='utf-8').read().split('\n')
sym = open('symbol_addrs.txt', encoding='utf-8').read().split('\n')
files = glob.glob('src/**/*.[sch]', recursive=True) + glob.glob('wip/*.c') + glob.glob('include/*.h')

for old, new in pairs:
    pat = re.compile(rf'(?<![\w$.]){re.escape(old)}(?![\w$.])')
    # funcs.txt
    sub = None
    for lst in (funcs, funcs_a):
        for i, l in enumerate(lst):
            f = l.split('#')[0].split()
            if f and f[0] == old:
                sub = f[3] if len(f) > 3 else 'libultra'
                lst[i] = pat.sub(new, l)
    # source files
    for sp in (f'src/{sub}/{old}.s', f'src/{sub}/{old}.c') if sub else ():
        if os.path.exists(sp):
            os.rename(sp, sp.replace(f'/{old}.', f'/{new}.'))
    va = None
    m = re.fullmatch(r'func_([0-9A-Fa-f]{8})', old)
    if m:
        va = int(m.group(1), 16)
    for l in sym:
        m2 = re.match(rf'\s*{re.escape(old)}\s*=\s*(0x[0-9A-Fa-f]+)', l)
        if m2:
            va = int(m2.group(1), 16)
    # symbol_addrs: rename or add
    found = False
    for i, l in enumerate(sym):
        if re.match(rf'\s*{re.escape(old)}\s*=', l):
            sym[i] = pat.sub(new, l); found = True
    if not found and va is not None and not any(re.match(r'\s*' + re.escape(new) + r'\s*=', l) for l in sym):
        sym.append(f'{new} = 0x{va:08X}; // type:func')
    # references
    n = 0
    for p in glob.glob('src/**/*.[sch]', recursive=True) + glob.glob('wip/*.c') + glob.glob('include/*.h'):
        try:
            t = open(p, encoding='utf-8').read()
        except UnicodeDecodeError:
            continue
        t2 = pat.sub(new, t)
        if t2 != t:
            open(p, 'w', encoding='utf-8', newline='\n').write(t2); n += 1
    print(f'{old} -> {new}: {n} file(s) updated' + ('' if va is not None else '  (no address found!)'))

open('funcs.txt', 'w', encoding='utf-8', newline='\n').write('\n'.join(funcs).rstrip('\n') + '\n')
open('funcs_a.txt', 'w', encoding='utf-8', newline='\n').write('\n'.join(funcs_a).rstrip('\n') + '\n')
open('symbol_addrs.txt', 'w', encoding='utf-8', newline='\n').write('\n'.join(sym).rstrip('\n') + '\n')
