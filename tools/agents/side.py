#!/usr/bin/env python3
"""side-by-side diff in WSL: python3 tools/side.py <list-line-style args: path func rom flags...>  (run from workspace root, after fchk.sh rsync)"""
import sys, os, subprocess
a = sys.argv[1:]
path, func, rom_hex = a[0], a[1], int(a[2], 16)
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = a[3:]
ROOTD = os.path.expanduser('~/trw_s705')
full = f'{ROOTD}/{path}'
res, err = compile_funcs(full)
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
name, off, size = [s for s in syms if s[0] == func][0]
ours = text[off:off+size]
romb = rom[rom_hex:rom_hex+size+16]
def dis(b):
    open('/tmp/_s.bin','wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump','-D','-z','-b','binary','-mmips:4000','-EB','--no-show-raw-insn','/tmp/_s.bin'],capture_output=True,text=True).stdout
    r = []
    for l in o.splitlines():
        if ':\t' in l: r.append(l.split(':\t',1)[1].replace('\t',' '))
    return r
A = dis(ours); B = dis(romb)
aw = [ours[i:i+4].hex() for i in range(0,len(ours),4)]; bw = [romb[i:i+4].hex() for i in range(0,len(romb),4)]
for i in range(max(len(A),len(B))):
    x = A[i] if i < len(A) else ''; y = B[i] if i < len(B) else ''
    mk = 0xFFFFFFFF ^ relocs.get(off + 4*i, 0)
    m = ' ' if (i<len(aw) and i<len(bw) and (int(aw[i],16)&mk)==(int(bw[i],16)&mk)) else '!'
    print(f'{i:3d} {m} {x:34s}| {y}')
