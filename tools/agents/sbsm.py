#!/usr/bin/env python3
"""aligned-diff metrics for many list lines.  usage: sbsm.py <listfile> ; prints per line: structural operand ours rom (one line per list line, in order)
list line: <path> <fn> <rom_hex> [flags]   (env TARGET_N: number of rom insns to compare, default = ours)"""
import sys, os, struct, subprocess, difflib, re
list_file = sys.argv[1]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s706')
def dis(b):
    open('/tmp/_sbsm.bin', 'wb').write(b)
    r = subprocess.run(['mips-linux-gnu-objdump', '-D', '-EB', '-b', 'binary', '-m', 'mips:4300', '-M', 'no-aliases,gpr-names=numeric', '/tmp/_sbsm.bin'], capture_output=True, text=True)
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
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:]
    fp = f'{ROOTD}/{path}'
    try:
        res, err = compile_funcs(fp)
    except Exception as e:
        res = None; err = str(e)
    if res is None:
        print('COMPILE FAIL', err[:100]); continue
    text, syms, relocs, relnames = res
    cand = [s for s in syms if s[0] == func]
    if not cand: print('NOTFOUND'); continue
    name, off, size = cand[0]
    ours = text[off:off+size]
    nrom = int(os.environ.get('TARGET_N', size // 4))
    theirs = rom[rom_hex:rom_hex+4*nrom]
    A = dis(ours); B = dis(theirs)
    an = [norm(x[2]) for x in A]; bn = [norm(x[2]) for x in B]
    sm = difflib.SequenceMatcher(None, an, bn, autojunk=False)
    nstruct = 0; nop = 0; fs = 99999; fo = 99999; wl, wh = [int(x) for x in os.environ.get('WIN', '0,0').split(',')]; ws = 0; wo = 0
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == 'equal':
            for k in range(i2 - i1):
                a = A[i1+k]; b = B[j1+k]
                m = 0xFFFFFFFF ^ relocs.get(off + 4*(i1+k), 0)
                if (a[1] & m) != (b[1] & m):
                    nop += 1; fo = min(fo, j1 + k)
                    if wl <= j1 + k <= wh: wo += 1
        else:
            nstruct += max(i2-i1, j2-j1); fs = min(fs, j1)
            ws += sum(1 for q in range(j1, max(j2, j1 + (i2 - i1))) if wl <= q <= wh)
    print(f'{path} structural={nstruct} operand={nop} ours={len(A)} rom={len(B)} firststruct={fs} firstop={fo} winstruct={ws} winop={wo}')
