#!/usr/bin/env python3
"""score.py <listfile>  (run in WSL from /mnt/d/Projects/ws/s705 after rsync, see tools/score.ps1)
For every list line (path func rom flags...) compile and print: positional diff words, aligned structural diff words, operand diffs,
first aligned differing insn index.  Metrics ignore relocation fields."""
import sys, os, subprocess, re, difflib
lst = sys.argv[1]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s705')
P = 'mips-linux-gnu'
def dis(b):
    open('/tmp/_sc.bin', 'wb').write(b)
    o = subprocess.run([P + '-objdump', '-D', '-z', '-b', 'binary', '-mmips:4000', '-EB', '--no-show-raw-insn', '/tmp/_sc.bin'], capture_output=True, text=True).stdout
    return [l.split(':\t', 1)[1].replace('\t', ' ').strip() for l in o.splitlines() if ':\t' in l]
def norm(x):
    x = re.sub(r'\b(zero|at|v0|v1|a0|a1|a2|a3|t\d|s\d|s8|k0|k1|gp|sp|fp|ra)\b', 'R', x)
    x = re.sub(r'\$f\d+', 'F', x)
    x = re.sub(r'0x[0-9a-f]+', 'N', x); x = re.sub(r'-?\d+', 'N', x)
    return x
def mn(x): return x.split()[0] if x else ''
for line in open(lst):
    line = line.split('#')[0].strip()
    if not line: continue
    f = line.split()
    path, func, rom_hex = f[0], f[1], int(f[2], 16)
    extra[:] = f[3:]
    full = path if os.path.isabs(path) else f'{ROOTD}/{path}'
    res, err = compile_funcs(full)
    if res is None:
        print(f'{path} COMPILE FAIL {err[:1]}'); continue
    text, syms, relocs, relnames = res
    c = [s for s in syms if s[0] == func]
    if not c: print(f'{path} {func} not found'); continue
    name, off, size = c[0]
    ours = text[off:off + size]
    romb = rom[rom_hex:rom_hex + size]
    # mask relocs
    ow = [int.from_bytes(ours[i:i + 4], 'big') & (0xFFFFFFFF ^ relocs.get(off + i, 0)) for i in range(0, size, 4)]
    rw = [int.from_bytes(romb[i:i + 4], 'big') & (0xFFFFFFFF ^ relocs.get(off + i, 0)) for i in range(0, size, 4)]
    pos = sum(1 for a, b in zip(ow, rw) if a != b)
    A = dis(b''.join(w.to_bytes(4, 'big') for w in ow)); B = dis(b''.join(w.to_bytes(4, 'big') for w in rw))
    sm = difflib.SequenceMatcher(None, [norm(x) for x in A], [norm(x) for x in B], autojunk=False)
    ops = [o for o in sm.get_opcodes() if o[0] != 'equal']
    stru = sum(max(i2 - i1, j2 - j1) for t, i1, i2, j1, j2 in ops)
    first = ops[0][1] if ops else -1
    sm2 = difflib.SequenceMatcher(None, [mn(x) for x in A], [mn(x) for x in B], autojunk=False)
    opd = 0
    for t, i1, i2, j1, j2 in sm2.get_opcodes():
        if t == 'equal':
            for k in range(i2 - i1):
                if A[i1 + k] != B[j1 + k]: opd += 1
    print(f'{os.path.basename(path):40s} pos={pos:4d} struct={stru:4d} hunks={len(ops):3d} opdiff={opd:4d} first={first} n={size//4}')
