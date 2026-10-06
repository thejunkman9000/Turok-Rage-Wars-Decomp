#!/usr/bin/env python3
"""Find a definition order of a C file's functions whose compiled object lists the functions in a wanted order.
(GCC 2.8.1 -O3 does not emit functions in source order; the order depends on definition/declaration/inlining.)

usage (inside WSL, in ~/trw):  python3 tools/orderfind.py <file.c> <sym1,sym2,...> [--protos]
The file is split into a preamble (everything before the first function definition at column 0) and one chunk per
top-level function (a chunk ends with a line `}`).  Every permutation of the chunks is compiled; the first one whose
`nm -n` order of the wanted symbols equals the wanted order is written to <file.c>.order and printed.
With --protos the permutation is also applied to a block of prototypes (one per function) inserted after the preamble.
"""
import itertools, os, re, subprocess, sys, tempfile

path = sys.argv[1]
want = sys.argv[2].split(',')
protos = '--protos' in sys.argv
src = open(path).read()
lines = src.split('\n')
# function chunks: start at a column-0 line that has '(' and ends with '{' ; end at the next line == '}'
chunks, pre, cur, infn = [], [], [], False
for l in lines:
    if not infn and re.match(r'^[A-Za-z_].*\(.*\)\s*\{\s*$', l):
        infn = True
        cur = [l]
        continue
    if infn:
        cur.append(l)
        if l == '}':
            chunks.append('\n'.join(cur))
            infn = False
            cur = []
        continue
    pre.append(l)
pre = '\n'.join(pre)
names = []
for c in chunks:
    m = re.match(r'^[A-Za-z_][\w\s\*]*?\b(\w+)\s*\(', c)
    names.append(m.group(1))
sig = {}
for n, c in zip(names, chunks):
    sig[n] = c.split('{')[0].strip() + ';'
tmp = tempfile.mkdtemp()
tried = 0
for perm in itertools.permutations(range(len(chunks))):
    body = '\n\n'.join(chunks[i] for i in perm)
    text = pre + '\n'
    if protos:
        text += '\n'.join(sig[names[i]] for i in perm) + '\n'
    text += '\n' + body + '\n'
    cf = os.path.join(tmp, 'o.c')
    open(cf, 'w').write(text)
    r = subprocess.run(['bash', os.path.expanduser('~/trw/tools/permcc.sh'), cf, '-o', os.path.join(tmp, 'o.o')],
                       capture_output=True, text=True, cwd=os.path.expanduser('~/trw'))
    tried += 1
    if r.returncode:
        continue
    nm = subprocess.run(['mips-linux-gnu-nm', '-n', os.path.join(tmp, 'o.o')], capture_output=True, text=True).stdout
    order = [l.split()[2] for l in nm.split('\n') if len(l.split()) == 3 and l.split()[1] in 'Tt' and l.split()[2] in want]
    if order == want:
        open(path + '.order', 'w').write(text)
        print('found after', tried, 'tries: definition order', [names[i] for i in perm])
        break
else:
    print('no permutation gave the wanted order (tried', tried, ')')
