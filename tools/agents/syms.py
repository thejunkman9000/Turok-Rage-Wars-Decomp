#!/usr/bin/env python3
"""syms.py <file.c rel ~/trw_s806 or wip path> [tokens]  (WSL, from ws root): compile with the @SN pipeline and list function symbols (name, offset, size)."""
import sys, os
a = sys.argv[1:]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
os.chdir('/mnt/d/Projects/ws/s806')
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = a[1:] or ['@SN']
res, err = compile_funcs(os.path.expanduser('~/trw_s806/') + a[0])
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
for n, o, s in sorted(syms, key=lambda x: x[1]): print(f'{n:24s} off=0x{o:X} size={s} ({s//4} insns)')
print('text bytes', len(text), 'ro bytes', len(LAST.get('ro', b'')))
