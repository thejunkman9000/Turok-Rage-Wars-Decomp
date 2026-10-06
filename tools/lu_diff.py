#!/usr/bin/env python3
"""Show word-level differences between a compiled libultra function and its best ROM match.
usage: lu_diff.py <gcc-version> "<gcc flags>" <file.c> <func> [<func> ...]   (run in WSL; pipe output to tools/lu_diff_dis.py)"""
import sys
ver, flags, src, funcs = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
sys.argv = ['lu_match.py', ver] + flags.split() + ['--', src]
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
res, err = compile_funcs(f'{LU}/lib/src/{src}')
if res is None: print('FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
for name, off, size in syms:
    if name not in funcs: continue
    eq, rom_off, reg = search(name, text, off, size, relocs)
    fw = words(text[off:off + size]); rw = words(rom[rom_off:rom_off + size])
    print(f'## {name} ROM 0x{rom_off:X} {eq}/{len(fw)}')
    for i, (a, b) in enumerate(zip(fw, rw)):
        m = 0xFFFFFFFF ^ relocs.get(off + 4 * i, 0)
        print(f'{i:3d} {"  " if (a & m) == (b & m) else "!="} {a:08X} {b:08X}')
