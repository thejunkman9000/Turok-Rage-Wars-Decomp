#!/usr/bin/env python3
"""rv.py <spec.py> : try many source variants in ONE chk call, rank by chk words and by aligned structural diff.
spec.py defines: BASE (path), FN, ROM ('0x..'), FLAGS (string, e.g. '@SN'), VARIANTS = list of lists of (old,new[,'all']) replacements.
Writes wip/vx/<FN>_<k>.c.  Output: k  chk-line  [S=structural hunks insns, R=register-diff insns].  RV_TOP=n to show more.  --save N copies variant N to wip/c/<FN>.best.c"""
import sys, os, re, subprocess, runpy, difflib
spec = runpy.run_path(sys.argv[1])
base = open(spec['BASE'], encoding='utf-8').read()
FN, ROM, FLAGS = spec['FN'], spec['ROM'], spec.get('FLAGS', '@SN')
os.makedirs('wip/vx', exist_ok=True)
lst = []; files = []
for k, v in enumerate(spec['VARIANTS']):
    s = base; ok = True
    for r in v:
        old, new = r[0], r[1]
        n = s.count(old)
        if n == 0 or (n > 1 and len(r) < 3):
            print(f'variant {k}: replacement not unique/found ({n}x): {old[:50]!r}'); ok = False; break
        s = s.replace(old, new)
    if not ok: continue
    p = f'wip/vx/{FN}_{k}.c'
    open(p, 'w', encoding='utf-8', newline='\n').write(s)
    files.append((k, p)); lst.append(f'{p} {FN} {ROM} {FLAGS}')
open('wip/vx/list%s.txt' % os.environ.get('RV_TAG',''), 'w').write('\n'.join(lst) + '\n')
env = dict(os.environ); env['CHKSIDE'] = '1'
out = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'env', 'CHKSIDE=1', 'bash', '/mnt/d/Projects/ws/s703/tools/fchk.sh', 'wip/vx/list%s.txt' % os.environ.get('RV_TAG','')], capture_output=True, text=True).stdout
lines = [l for l in out.splitlines() if l.startswith(FN + ' ') or ('not found' in l) or ('COMPILE FAIL' in l)]
try:
    import rabbitizer
except ImportError:
    rabbitizer = None
def norm(s):
    s = re.sub(r'\$\w+', 'R', s); s = re.sub(r'\. \+ 4 \+ \(.*?\)', 'L', s); s = re.sub(r'func_[0-9A-F]+', 'F', s)
    return re.sub(r'-?0x[0-9A-Fa-f]+', 'N', s)
def aligned(path):
    try: a, b = [l.split() for l in open(path)]
    except Exception: return None
    a = [int(x, 16) for x in a]; b = [int(x, 16) for x in b][:len(a) + 4]
    d = lambda w, i: rabbitizer.Instruction(w, 0x80000000 + 4 * i).disassemble()
    A = [d(w, i) for i, w in enumerate(a)]; B = [d(w, i) for i, w in enumerate(b)]
    na = [norm(x) for x in A]; nb = [norm(x) for x in B]
    sm = difflib.SequenceMatcher(None, na, nb, autojunk=False)
    S = 0; R = 0; I = 0
    for t, i1, i2, j1, j2 in sm.get_opcodes():
        if t == 'equal':
            for k in range(i2 - i1):
                ra = re.findall(r'\$\w+', A[i1 + k]); rb = re.findall(r'\$\w+', B[j1 + k])
                if ra != rb: R += 1
                ia = re.findall(r'-?0x[0-9A-Fa-f]+', re.sub(r'\. \+ 4 \+ \(.*?\)', '', A[i1 + k])); ib = re.findall(r'-?0x[0-9A-Fa-f]+', re.sub(r'\. \+ 4 \+ \(.*?\)', '', B[j1 + k]))
                if len(ia) == len(ib) and any(x != y and x != '0x0' for x, y in zip(ia, ib)): I += 1
        else:
            S += max(i2 - i1, j2 - j1)
    # tail of ROM beyond our function is not counted: subtract trailing inserts
    return S, R, I
res = []
for (k, p), l in zip(files, lines):
    m = re.search(r'(\d+) words differ(?:\s+score=(\d+))?', l)
    if 'EXACT' in l: key = (0, 0, 0, 0)
    elif m:
        sr = aligned(f'wip/side/{os.path.basename(p)[:-2]}__{FN}.txt') if rabbitizer else None
        key = (sr[0] if sr else 9999, sr[1] + (sr[2] if sr else 0), int(m.group(1)), int(m.group(2) or 0), sr[2] if sr else 0)
    else: key = (99999, 0, 0, 0)
    res.append((key, k, l.strip()))
res.sort()
names = spec.get('NAMES', {})
for key, k, l in res[:int(os.environ.get('RV_TOP', 12))]:
    print(k, names.get(k, ''), l[:60], f'S={key[0]} R={key[1]}' + (f' I={key[4]}' if len(key) > 4 else ''))
print(f'{len(files)} variants, {sum(1 for r in res if r[0]==(0,0,0,0))} EXACT')
if '--save' in sys.argv:
    n = int(sys.argv[sys.argv.index('--save') + 1])
    open(f'wip/c/{FN}.best.c', 'w').write(open(f'wip/vx/{FN}_{n}.c').read())
