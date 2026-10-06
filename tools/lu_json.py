#!/usr/bin/env python3
"""Compile a libultra C file and dump functions + the ROM window to compare, as JSON (run in WSL).
usage: lu_json.py <gcc-version> "<flags>" <file.c-or-abs-path> <out.json> [name=0xROMOFF ...]
`name=0xROMOFF` forces the ROM start for a function; otherwise the best anchor match is used."""
import sys, json
ver, flags, src, outp = sys.argv[1:5]
force = {a.split('=')[0]: int(a.split('=')[1], 16) for a in sys.argv[5:]}
sys.argv = ['lu_match.py', ver] + flags.split() + ['--', src]
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
path = src if os.path.isabs(src) else f'{LU}/lib/src/{src}'
res, err = compile_funcs(path)
if res is None: print('FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
out = []
for name, off, size in syms:
    n = size // 4
    ro = force.get(name)
    if ro is None:
        eq, ro, reg = search(name, text, off, size, relocs)
    fw = [f'{w:08X}' for w in words(text[off:off + size])]
    mask = [relocs.get(off + 4 * i, 0) for i in range(n)]
    names = [relnames.get(off + 4 * i, ('', ''))[1] for i in range(n)]
    rw = [f'{w:08X}' for w in words(rom[ro:ro + size + 64])] if ro is not None else []
    out.append(dict(name=name, rom=ro, words=fw, mask=mask, relnames=names, romwords=rw))
json.dump(out, open(outp, 'w'))
print('wrote', outp, len(out), 'functions')
