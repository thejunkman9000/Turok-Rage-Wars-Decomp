#!/usr/bin/env python3
"""regvote.py <listfile> <fn>: align ours vs ROM and print votes of register substitutions ours->rom (GPR and FPR)"""
import sys, os, subprocess, difflib, re, collections
list_file, want = sys.argv[1], sys.argv[2]
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s706')
def dis(b):
    open('/tmp/_rv.bin', 'wb').write(b)
    r = subprocess.run(['mips-linux-gnu-objdump', '-D', '-EB', '-b', 'binary', '-m', 'mips:4300', '-M', 'no-aliases,gpr-names=numeric', '/tmp/_rv.bin'], capture_output=True, text=True)
    out = []
    for l in r.stdout.splitlines():
        m = re.match(r'\s*([0-9a-f]+):\t([0-9a-f]{8})\s+(.*)', l)
        if m: out.append(re.sub(r'\s+', ' ', m.group(3)).strip())
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
    res, err = compile_funcs(f'{ROOTD}/{path}')
    text, syms, relocs, relnames = res
    name, off, size = [s for s in syms if s[0] == func][0]
    A = dis(text[off:off+size]); B = dis(rom[rom_hex:rom_hex+size])
    sm = difflib.SequenceMatcher(None, [norm(x) for x in A], [norm(x) for x in B], autojunk=False)
    votes = collections.defaultdict(collections.Counter)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag != 'equal': continue
        for k in range(i2 - i1):
            ra = re.findall(r'\$f?\d+', A[i1+k]); rb = re.findall(r'\$f?\d+', B[j1+k])
            if len(ra) != len(rb): continue
            for x, y in zip(ra, rb):
                if x != y: votes[x][y] += 1
                else: votes[x][y] += 0
    for x in sorted(votes, key=lambda s: (s[1] == 'f', int(s.lstrip('$f')))):
        c = votes[x]
        tot = sum(c.values())
        if tot: print(x, '->', ', '.join(f'{y}:{n}' for y, n in c.most_common(4) if n))
