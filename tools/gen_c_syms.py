#!/usr/bin/env python3
"""Write c_syms.ld: linker symbols for every D_XXXXXXXX / func_XXXXXXXX name used by the C sources
(splat only defines the ones its remaining asm still references)."""
import re, glob
names = set()
for p in glob.glob('src/**/*.c', recursive=True) + glob.glob('include/*.h'):
    t = open(p, encoding='utf-8', errors='replace').read()
    names.update(re.findall(r'\b(?:D|func)_[0-9A-Fa-f]{8}\b', t))
    names.update(re.findall(r'\bjtbl_[0-9A-Fa-f]{8}\b', t))
theirs = set()                      # names whose address comes from their_syms.ld (melalawi's spelling is the de-version address, not ours)
try:
    theirs = set(re.findall(r'PROVIDE\((\w+) =', open('their_syms.ld').read()))
except OSError:
    pass
out = []
for n in sorted(names - theirs):
    v = int(n.split('_')[1], 16)
    if n.startswith('func_') and v >= 0x80000000: v &= 0x00FFFFFF   # KSEG0 spelling of a TLB-mapped code address
    out.append(f'{n} = 0x{v:08X};')
open('c_syms.ld', 'w', newline='\n').write('\n'.join(out) + '\n')
print(len(out), 'symbols')
