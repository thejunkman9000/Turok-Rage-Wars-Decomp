#!/usr/bin/env python3
"""Park objects that define more than one ROM function (gcc 'inline' deferral, shared pools): they cannot be built
per function.  usage: python tools/park_groups.py <file with lines `obj.o: sym sym ...` from nm> 
Moves src/{game,ovl_a}/<fn>.c to wip/groups/, drops the manifest lines, lists names in wip/groups_excluded.txt and
keeps the symbols resolvable through extra_syms.ld (they stay asm)."""
import re, sys, os, shutil
names = set()
for l in open(sys.argv[1]):
    if ':' not in l: continue
    for s in l.split(':', 1)[1].split():
        if re.fullmatch(r'func_[0-9A-F]{8}', s): names.add(s)
os.makedirs('wip/groups', exist_ok=True)
excl = set(open('wip/groups_excluded.txt').read().split()) if os.path.exists('wip/groups_excluded.txt') else set()
ext = open('extra_syms.ld').read()
for manifest in ('funcs.txt', 'funcs_a.txt'):
    L = open(manifest).read().split('\n')
    out = [l for l in L if not (l.split() and l.split()[0] in names and len(l.split()) > 3 and not l.split()[0].startswith('pad_'))]
    open(manifest, 'w', newline='\n').write('\n'.join(out))
for n in sorted(names):
    for d in ('game', 'ovl_a'):
        p = f'src/{d}/{n}.c'
        if os.path.exists(p): shutil.move(p, f'wip/groups/{n}.c')
    if n not in excl:
        open('wip/groups_excluded.txt', 'a').write(n + '\n'); excl.add(n)
    if f'{n} = ' not in ext:
        ext += f'{n} = 0x{n[5:]};\n'
open('extra_syms.ld', 'w', newline='\n').write(ext)
print(len(names), 'functions parked')
