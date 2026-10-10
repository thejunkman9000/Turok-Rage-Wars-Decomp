#!/usr/bin/env python3
"""gm.py <base.c> <func> <rom hex> <first_line> <last_line> <out.c> [--pins "name:type:reg,name2:type:reg,..."] [--decls "l1-l2"] [flags...]
Greedy mutation search (run in WSL from /mnt/d/Projects/ws/s705; see tools/gm.ps1).  Mutations tried on lines first_line..last_line (1-based,
one statement per line is best):
  - move one line to another position
  - insert `__asm__ volatile("");` after / before a line
  - wrap a line in `do { ... } while (0);`
  - duplicate-free pin toggles from --pins: replace the declaration `type name;` (must appear on its own line in the file) by
    `register type name __asm__("$reg");` (only for candidate names given).
Accepts a mutation when the score (aligned structural diff * 1000 + operand diffs * 10 + positional diffs) improves; restarts the scan.
Keeps going until no improvement or 40 accepted steps."""
import sys, os, subprocess, re, difflib
args = sys.argv[1:]
pins = []
flags = []
pos = []
i = 0
while i < len(args):
    if args[i] == '--pins':
        for item in args[i + 1].split(','):
            n, t, r = item.split(':')
            t = t.replace('_', ' ')
            pins.append((n, t, r))
        i += 2
    elif args[i].startswith('@') or args[i].startswith('-f'):
        flags.append(args[i]); i += 1
    else:
        pos.append(args[i]); i += 1
base, func, rom_hex, l1, l2, outp = pos[:6]
flags = flags or ['@SN']
l1 = int(l1); l2 = int(l2)
sys.argv = ['lu_match.py', '2.8.1', '-O3 -fforce-addr -fno-builtin -mcpu=r4300', '--', 'x.c']
code = open('tools/lu_match.py').read().split("tot = ex = 0")[0]
exec(compile(code, 'lu_match', 'exec'))
ROOTD = os.path.expanduser('~/trw_s705')
P = 'mips-linux-gnu'
romoff = int(rom_hex, 16)
def dis(b):
    open('/tmp/_gm.bin', 'wb').write(b)
    o = subprocess.run([P + '-objdump', '-D', '-z', '-b', 'binary', '-mmips:4000', '-EB', '--no-show-raw-insn', '/tmp/_gm.bin'], capture_output=True, text=True).stdout
    return [l.split(':\t', 1)[1].replace('\t', ' ').strip() for l in o.splitlines() if ':\t' in l]
def norm(x):
    x = re.sub(r'\b(zero|at|v0|v1|a0|a1|a2|a3|t\d|s\d|s8|k0|k1|gp|sp|fp|ra)\b', 'R', x)
    x = re.sub(r'\$f\d+', 'F', x)
    x = re.sub(r'0x[0-9a-f]+', 'N', x); x = re.sub(r'-?\d+', 'N', x)
    return x
cache = {}
def evaluate(text):
    if text in cache: return cache[text]
    path = f'{ROOTD}/wip/_gm_eval.c'
    open(path, 'w').write(text)
    extra[:] = flags
    r = (10**9, 0, 0, 0)
    try:
        res, err = compile_funcs(path)
        if res is not None:
            t, syms, relocs, relnames = res
            c = [s for s in syms if s[0] == func]
            if c:
                name, off, size = c[0]
                ow = [int.from_bytes(t[off + i:off + i + 4], 'big') & (0xFFFFFFFF ^ relocs.get(off + i, 0)) for i in range(0, size, 4)]
                rw = [int.from_bytes(rom[romoff + i:romoff + i + 4], 'big') & (0xFFFFFFFF ^ relocs.get(off + i, 0)) for i in range(0, size, 4)]
                p = sum(1 for a, b in zip(ow, rw) if a != b)
                A = dis(b''.join(w.to_bytes(4, 'big') for w in ow)); B = dis(b''.join(w.to_bytes(4, 'big') for w in rw))
                sm = difflib.SequenceMatcher(None, [norm(x) for x in A], [norm(x) for x in B], autojunk=False)
                ops = [o for o in sm.get_opcodes() if o[0] != 'equal']
                stru = sum(max(i2 - i1, j2 - j1) for tg, i1, i2, j1, j2 in ops)
                opd = 0
                sm2 = difflib.SequenceMatcher(None, [x.split()[0] for x in A], [x.split()[0] for x in B], autojunk=False)
                for tg, i1, i2, j1, j2 in sm2.get_opcodes():
                    if tg == 'equal':
                        for k in range(i2 - i1):
                            if A[i1 + k] != B[j1 + k]: opd += 1
                r = (stru * 1000 + opd * 10 + p, stru, opd, p)
    except Exception as e:
        pass
    cache[text] = r
    return r
text = open(base).read()
lines = text.split('\n')
def mutations(cur):
    L = cur.split('\n')
    # the block may shift if lines inserted; track by scanning for the original span length from l1 to l2+delta
    delta = len(L) - len(lines)
    b0 = l1 - 1; b1 = l2 + delta
    idxs = list(range(b0, b1))
    for i in idxs:
        s = L[i]
        if not s.strip() or s.strip().startswith(('}', '{', '#', 'else')) or s.strip().endswith('{'): continue
        indent = re.match(r'\s*', s).group(0)
        for j in idxs:
            if j == i: continue
            M = L[:]; x = M.pop(i); M.insert(j, x)
            yield '\n'.join(M), f'move {i}->{j}'
        M = L[:]; M.insert(i + 1, indent + '__asm__ volatile("");'); yield '\n'.join(M), f'asm after {i}'
        M = L[:]; M.insert(i, indent + '__asm__ volatile("");'); yield '\n'.join(M), f'asm before {i}'
        if s.rstrip().endswith(';'):
            M = L[:]; M[i] = indent + 'do { ' + s.strip() + ' } while (0);'; yield '\n'.join(M), f'dowhile {i}'
    for (n, t, r) in pins:
        pat = re.compile(r'^(\s*)' + re.escape(t) + r'\s*' + re.escape(n) + r'\s*;', re.M)
        if pat.search(cur):
            yield pat.sub(lambda m: f'{m.group(1)}register {t} {n} __asm__("${r}");', cur, count=1), f'pin {n}'
best = text
bs = evaluate(best)
print('start', bs, flush=True)
steps = 0
improved = True
while improved and steps < 40:
    improved = False
    for cand, desc in mutations(best):
        if cand == best: continue
        s = evaluate(cand)
        if s[0] < bs[0]:
            best, bs = cand, s
            steps += 1
            improved = True
            print('accept', desc, bs, flush=True)
            open(outp, 'w').write(best)
            break
open(outp, 'w').write(best)
print('final', bs, flush=True)
