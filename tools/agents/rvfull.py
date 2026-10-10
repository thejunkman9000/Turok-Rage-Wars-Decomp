#!/usr/bin/env python3
"""rvfull.py <spec.py> : like rv.py but spec.FULL is a list of complete file texts."""
import sys, runpy, os
spec = runpy.run_path(sys.argv[1])
open('wip/vx/_full_base.c', 'w').write(spec['FULL'][0])
# reuse rv.py by faking VARIANTS as (old,new) of a placeholder: write files directly
import re, subprocess
FN, ROM, FLAGS = spec['FN'], spec['ROM'], spec.get('FLAGS', '@SN')
os.makedirs('wip/vx', exist_ok=True)
lst = []
for k, t in enumerate(spec['FULL']):
    p = f'wip/vx/{FN}_{k}.c'
    open(p, 'w', newline='\n').write(t)
    lst.append(f'{p} {FN} {ROM} {FLAGS}')
open('wip/vx/list%s.txt' % os.environ.get('RV_TAG',''), 'w').write('\n'.join(lst) + '\n')
out = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'env', 'CHKSIDE=1', 'bash', '/mnt/d/Projects/ws/s703/tools/fchk.sh', 'wip/vx/list%s.txt' % os.environ.get('RV_TAG','')], capture_output=True, text=True).stdout
lines = [l for l in out.splitlines() if l.startswith(FN + ' ') or 'COMPILE FAIL' in l or 'not found' in l]
import difflib, rabbitizer
def norm(s):
    s = re.sub(r'\$\w+', 'R', s); s = re.sub(r'\. \+ 4 \+ \(.*?\)', 'L', s); s = re.sub(r'func_[0-9A-F]+', 'F', s)
    return re.sub(r'-?0x[0-9A-Fa-f]+', 'N', s)
def aligned(path):
    try: a, b = [l.split() for l in open(path)]
    except Exception: return None
    a = [int(x, 16) for x in a]; b = [int(x, 16) for x in b][:len(a) + 4]
    d = lambda w, i: rabbitizer.Instruction(w, 0x80000000 + 4 * i).disassemble()
    A = [d(w, i) for i, w in enumerate(a)]; B = [d(w, i) for i, w in enumerate(b)]
    sm = difflib.SequenceMatcher(None, [norm(x) for x in A], [norm(x) for x in B], autojunk=False)
    S = R = I = 0
    for t, i1, i2, j1, j2 in sm.get_opcodes():
        if t == 'equal':
            for k in range(i2 - i1):
                if re.findall(r'\$\w+', A[i1 + k]) != re.findall(r'\$\w+', B[j1 + k]): R += 1
                ia = re.findall(r'-?0x[0-9A-Fa-f]+', re.sub(r'\. \+ 4 \+ \(.*?\)', '', A[i1 + k])); ib = re.findall(r'-?0x[0-9A-Fa-f]+', re.sub(r'\. \+ 4 \+ \(.*?\)', '', B[j1 + k]))
                if len(ia) == len(ib) and any(x != y and x != '0x0' for x, y in zip(ia, ib)): I += 1
        else: S += max(i2 - i1, j2 - j1)
    return S, R + I
res = []
names = spec.get('NAMES', {})
for k, l in enumerate(lines):
    if 'EXACT' in l: key = (0, 0)
    elif 'words differ' in l:
        sr = aligned(f'wip/side/{FN}_{k}__{FN}.txt'); key = sr if sr else (9999, 9999)
    else: key = (99999, 0)
    res.append((key, k, l.strip()[:60]))
res.sort()
for key, k, l in res[:int(os.environ.get('RV_TOP', 12))]:
    print(k, names.get(k, ''), l, f'S={key[0]} R={key[1]}')
print(len(lines), 'variants,', sum(1 for r in res if r[0] == (0, 0)), 'EXACT')
