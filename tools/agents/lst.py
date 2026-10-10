#!/usr/bin/env python3
"""usage: lst.py <listfile> <fn> [LO_ HI_] : print our compiled insns (objdump, numbered) for the list line of fn, ROM insns side by side by index (no alignment)"""
import sys, os, struct, subprocess, re
list_file, want = sys.argv[1], sys.argv[2]
LO_ = int(sys.argv[3]) if len(sys.argv) > 3 else 0
HI_ = int(sys.argv[4]) if len(sys.argv) > 4 else 10**9
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s706')
def dis(b):
    open('/tmp/_lst.bin', 'wb').write(b)
    r = subprocess.run(['mips-linux-gnu-objdump', '-D', '-EB', '-b', 'binary', '-m', 'mips:4300', '-M', 'no-aliases,gpr-names=numeric', '/tmp/_lst.bin'], capture_output=True, text=True)
    out = []
    for l in r.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\t([0-9a-f]{8})\s+(.*)', l)
        if m: out.append(re.sub(r'\s+', ' ', m.group(3)).strip())
    return out
for line in open(list_file):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    if f[1] != want: continue
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:]
    res, err = compile_funcs(f'{ROOTD}/{path}')
    text, syms, relocs, relnames = res
    name, off, size = [s for s in syms if s[0] == func][0]
    A = dis(text[off:off+size]); B = dis(rom[rom_hex:rom_hex+size])
    for i in range(LO_, min(HI_ + 1, max(len(A), len(B)))):
        a = A[i] if i < len(A) else ''
        b = B[i] if i < len(B) else ''
        print(f'{i:4d} {a:34s} | {b}')
