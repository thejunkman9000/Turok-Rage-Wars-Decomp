#!/usr/bin/env python3
"""ad.py <file.c> <fn> <rom hex> [tokens]  (WSL, from ~/trw_s702 after fk.sh copied the file): ALIGNED diff of ours vs ROM.
prints '##' structural diffs (insn inserted/deleted/different mnemonic) and '!!' same-mnemonic-but-different-operand lines (relocs/branch targets ignored)."""
import sys, os, subprocess, re, difflib
a = sys.argv[1:]
path, func, rom_hex = a[0], a[1], int(a[2], 16)
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
os.chdir('/mnt/d/Projects/ws/s702')
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
extra[:] = a[3:] or ['@SN']
ROOTD = os.path.expanduser('~/trw_s702')
res, err = compile_funcs(f'{ROOTD}/{path}')
if res is None: print('COMPILE FAIL', err); sys.exit(1)
text, syms, relocs, relnames = res
name, off, size = [s for s in syms if s[0] == func][0]
ours = text[off:off+size]
romb = rom[rom_hex:rom_hex+size]
def dis(b, rel):
    open('/tmp/_ad.bin','wb').write(b)
    o = subprocess.run(['mips-linux-gnu-objdump','-D','-b','binary','-mmips:4000','-EB','--no-show-raw-insn','-M','no-aliases','/tmp/_ad.bin'],capture_output=True,text=True).stdout
    r = []
    for l in o.splitlines():
        if ':\t' in l: r.append(l.split(':\t',1)[1].replace('\t',' ').strip())
    return r
A = dis(ours, True); B = dis(romb, False)
relw = set(off//4 * 0 + (o - off)//4 for o in relocs if off <= o < off+size)
def norm(s, i=None, isours=False):
    m = s.split()[0]
    return m
def full(s, i, isours):
    mn = s.split()[0]
    t = s
    if mn in ('j','jal'): return mn
    if re.match(r'b|bc1', mn) or mn in ('beq','bne','blez','bgtz','bltz','bgez','beql','bnel','bltzl','bgezl','blezl','bgtzl'):
        # mask last operand (target)
        return re.sub(r'(,)[^,]*$', ',T', t) if ',' in t else mn+' T'
    if isours and i in relw:
        return re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', t)
    return t
an = [norm(x) for x in A]; bn = [norm(x) for x in B]
sm = difflib.SequenceMatcher(None, an, bn, autojunk=False)
nstruct = noper = 0
out = []
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag == 'equal':
        for k in range(i2-i1):
            fa = full(A[i1+k], i1+k, True); fb = full(B[j1+k], j1+k, False)
            # ignore reloc-only imm differences
            if fa != fb:
                # compare after masking immediates when ours is reloc
                if (i1+k) in relw:
                    fb2 = re.sub(r'(-?0x[0-9a-f]+|-?\d+)(\(|$)', r'R\2', B[j1+k])
                    if fa == fb2: continue
                noper += 1; out.append(f'!! {i1+k:3d} {A[i1+k]:34s}| {j1+k:3d} {B[j1+k]}')
    else:
        nstruct += max(i2-i1, j2-j1)
        for k in range(max(i2-i1, j2-j1)):
            x = f'{i1+k:3d} {A[i1+k]}' if i1+k < i2 else ''
            y = f'{j1+k:3d} {B[j1+k]}' if j1+k < j2 else ''
            out.append(f'## {x:38s}| {y}')
print('\n'.join(out))
print(f'structural={nstruct} operand={noper}  (ours {len(A)} insns, rom {len(B)})')
