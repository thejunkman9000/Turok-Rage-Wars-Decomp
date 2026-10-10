#!/usr/bin/env python3
"""side-by-side / aligned diff.  usage: sbs.py <listfile> <func> [full]   (list line for func as for chk.py)"""
import sys, os, struct, subprocess, difflib, re
list_file, want = sys.argv[1], sys.argv[2]
full = len(sys.argv) > 3
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s706')
def dis(b, base=0):
    open('/tmp/_sbs.bin', 'wb').write(b)
    r = subprocess.run(['mips-linux-gnu-objdump', '-D', '-EB', '-b', 'binary', '-m', 'mips:4300', '-M', 'no-aliases,gpr-names=numeric', '/tmp/_sbs.bin'], capture_output=True, text=True)
    out = []
    for l in r.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\t([0-9a-f]{8})\s+(.*)', l)
        if m: out.append((int(m.group(1), 16), int(m.group(2), 16), re.sub(r'\s+', ' ', m.group(3)).strip()))
    return out
def norm(t):
    t = re.sub(r'\$\d+|\$f\d+', 'R', t)
    t = re.sub(r'-?0x[0-9a-f]+|-?\d+', 'N', t)
    return t
for line in open(list_file):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    if f[1] != want: continue
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:]
    fp = f'{ROOTD}/{path}'
    res, err = compile_funcs(fp)
    if res is None: print('COMPILE FAIL', err); sys.exit()
    text, syms, relocs, relnames = res
    name, off, size = [s for s in syms if s[0] == func][0]
    ours = text[off:off+size]
    theirs = rom[rom_hex:rom_hex+size+ (0 if True else 0)]
    A = dis(ours); B = dis(theirs)
    # mask relocs in raw compare
    an = [norm(x[2]) for x in A]; bn = [norm(x[2]) for x in B]
    sm = difflib.SequenceMatcher(None, an, bn, autojunk=False)
    nstruct = 0; nop = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i2 - i1):
                a = A[i1+k]; b = B[j1+k]
                wa = a[1]; wb = b[1]
                m = 0xFFFFFFFF ^ relocs.get(off + 4*(i1+k), 0)
                same = (wa & m) == (wb & m)
                if not same: nop += 1
                if full or not same:
                    print(f'{i1+k:4d} {a[2]:36s} {"  " if same else "!!"} {j1+k:4d} {b[2]}')
        else:
            nstruct += max(i2-i1, j2-j1)
            for k in range(max(i2-i1, j2-j1)):
                a = A[i1+k][2] if i1+k < i2 else ''
                b = B[j1+k][2] if j1+k < j2 else ''
                print(f'{i1+k if i1+k<i2 else "":>4} {a:36s} ## {j1+k if j1+k<j2 else "":>4} {b}')
    print(f'structural={nstruct} operand={nop} ours={len(A)} rom={len(B)}')
