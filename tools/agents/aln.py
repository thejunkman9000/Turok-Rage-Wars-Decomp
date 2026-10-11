#!/usr/bin/env python3
"""aln.py <file.c> <fn> <rom hex> [lo hi] [-- tokens]  (WSL, ws root): full ALIGNED listing of ours vs ROM (mnemonic alignment); rows in ROM order.
marks: '  ' identical, '!!' same mnemonic, different operands, '##' inserted/deleted/changed.  lo/hi = window in ROM insn indices."""
import sys, os, subprocess, re, difflib
a = sys.argv[1:]
toks = ['@SN']
if '--' in a:
    k = a.index('--'); toks = a[k+1:] or ['@SN']; a = a[:k]
path, func, rom_hex = a[0], a[1], int(a[2], 16)
WLO = int(a[3]) if len(a) > 3 else 0
WHI = int(a[4]) if len(a) > 4 else 10**9
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
os.chdir('/mnt/d/Projects/ws/s902')
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = toks
ROOTD = os.path.expanduser('~/trw_s902')
res, err = compile_funcs(f'{ROOTD}/{path}')
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
name, off, size = [s for s in syms if s[0] == func][0]
ours = text[off:off+size]
nrom = int(os.environ.get('NROM', '0')) or size // 4
romb = rom[rom_hex:rom_hex+nrom*4]
def dis(b):
    open('/tmp/_aln.bin','wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump','-D','-b','binary','-mmips:4000','-EB','--no-show-raw-insn','-M','no-aliases','/tmp/_aln.bin'],capture_output=True,text=True).stdout
    return [l.split(':\t',1)[1].replace('\t',' ').strip() for l in o.splitlines() if ':\t' in l]
A = dis(ours); B = dis(romb)
relw = set((o - off)//4 for o in relocs if off <= o < off+size)
def mn(s): return s.split()[0]
def full(s, i, isours):
    m = mn(s)
    if m in ('j','jal'): return m
    if m in ('beq','bne','blez','bgtz','bltz','bgez','beql','bnel','bltzl','bgezl','blezl','bgtzl','bc1t','bc1f'):
        return re.sub(r'(,)[^,]*$', ',T', s) if ',' in s else m+' T'
    if isours and i in relw: return re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', s)
    return s
sm = difflib.SequenceMatcher(None, [mn(x) for x in A], [mn(x) for x in B], autojunk=False)
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        for k in range(i2-i1):
            fa = full(A[i1+k], i1+k, True); fb = full(B[j1+k], j1+k, False)
            same = fa == fb
            if not same and (i1+k) in relw:
                same = fa == re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', B[j1+k])
            j = j1+k
            if WLO <= j < WHI: print(f"{'  ' if same else '!!'} {i1+k:3d} {A[i1+k]:34s}| {j:3d} {B[j]}")
    else:
        for k in range(max(i2-i1, j2-j1)):
            x = f'{i1+k:3d} {A[i1+k]}' if i1+k < i2 else ''
            y = f'{j1+k:3d} {B[j1+k]}' if j1+k < j2 else ''
            j = j1+k if j1+k < j2 else j2
            if WLO <= j < WHI: print(f'## {x:38s}| {y}')
