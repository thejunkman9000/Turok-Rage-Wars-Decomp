#!/usr/bin/env python3
"""Write c_syms.ld: linker symbols for every D_XXXXXXXX / func_XXXXXXXX name used by the C sources
(splat only defines the ones its remaining asm still references)."""
import re, glob
names = set()
for p in glob.glob('src/**/*.c', recursive=True) + glob.glob('include/*.h'):
    t = open(p, encoding='utf-8', errors='replace').read()
    names.update(re.findall(r'\b(?:D|func)_[0-9A-Fa-f]{8}\b', t))
    names.update(re.findall(r'\bjtbl_[0-9A-Fa-f]{8}\b', t))
out = []
for n in sorted(names):
    out.append(f'{n} = 0x{n.split("_")[1].upper()};')
open('c_syms.ld', 'w', newline='\n').write('\n'.join(out) + '\n')
print(len(out), 'symbols')
