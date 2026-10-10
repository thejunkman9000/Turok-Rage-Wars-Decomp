#!/usr/bin/env python3
"""vrun.py (run in WSL) <template.c> <fn> <rom hex> <nrom insns> [xflags|-]
Template syntax: groups  @@{ alt1 @@| alt2 @@| alt3 @@}  expand to the cartesian product (max 3000 variants).
Each variant is compiled with the @SN pipeline and scored with the aligned metric of evalsn.py (0 = structurally identical
incl. registers).  Best variant is written to <template>.best.c next to the template (windows ws).  Prints the top 12."""
import sys, os, re, itertools, shutil, subprocess
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import evalsn
from multiprocessing import Pool

import difflib
def metric2(ours, rom):
    a = [re.sub(r'<[^>]*>', '', x[1]).split(';')[0].split()[0] if x[1].split() else '' for x in ours]
    b = [re.sub(r'<[^>]*>', '', x[1]).split(';')[0].split()[0] if x[1].split() else '' for x in rom]
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return sum(max(i2 - i1, j2 - j1) for tag, i1, i2, j1, j2 in sm.get_opcodes() if tag != 'equal')
tpl, fn, rom, n = sys.argv[1:5]
xf = sys.argv[5] if len(sys.argv) > 5 else '-'
xf = '' if xf == '-' else xf
src = open(tpl).read()
pat = re.compile(r'@@\{(.*?)@@\}', re.S)
groups = pat.findall(src)
alts = [[a for a in g.split('@@|')] for g in groups]
combos = list(itertools.product(*alts)) if alts else [()]
if len(combos) > 3000:
    print('too many variants', len(combos)); sys.exit(1)
R = evalsn.R
os.makedirs(R + '/wip/var', exist_ok=True)
files = []
for k, c in enumerate(combos):
    it = iter(c)
    s = pat.sub(lambda m: next(it), src)
    p = f'wip/var/{fn}_{k}.c'
    open(R + '/' + p, 'w').write(s)
    files.append(p)
rom_i = evalsn.disasm_rom(int(rom, 16), int(n))
res = []
with Pool(int(os.environ.get('VJ', '4'))) as pool:
    for arg, ours in pool.imap(evalsn.compile_ours, [(f, fn, xf) for f in files]):
        if ours is None:
            res.append((10**6, arg, 0)); continue
        res.append((metric2(ours, rom_i) if os.environ.get('VM') == 'struct' else evalsn.metric(ours, rom_i), arg, len(ours)))
order = sorted(range(len(res)), key=lambda i: res[i][0])
for i in order[:12]:
    print(f'{res[i][0]:4d} insns={res[i][2]} variant {i} {combos[i] if len(combos[i])<8 else ""}'.replace('\n', '\n')[:300])
best = order[0]
shutil.copy(R + '/' + files[best], tpl[:-2] + '.best.c')
print('best ->', tpl[:-2] + '.best.c', 'metric', res[best][0])
