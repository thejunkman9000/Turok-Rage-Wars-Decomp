#!/usr/bin/env python3
"""lamove.py <dumpdir> <pseudo> <wantreg> [--max-other N]
Brute force over all DEPENDENCE-LEGAL single-insn moves in the sched1 stream with the local-alloc model (tools/lamodel.py): list the moves
after which the quantity containing <pseudo> (e.g. 135 or r135) gets hard register <wantreg> while at most N other pseudos change their model register."""
import sys, os, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import lamodel

d, ps, want = sys.argv[1], int(sys.argv[2].lstrip('r')), sys.argv[3]
maxother = int(sys.argv[sys.argv.index('--max-other') + 1]) if '--max-other' in sys.argv else 0
want_n = lamodel.NAMES.index(want) if want in lamodel.NAMES else int(want)
ctx = lamodel.load(d)
insns = ctx['insns']
# dependence info per insn
info = []
for x in insns:
    dest, src = lamodel.split_set(x['pat'])
    defs = set(); uses = set(); st = False; ld = False
    if dest is None:
        allr = set(lamodel.regs_in(x['pat']))
        defs = set(allr) if x['pat'].startswith('(parallel') else set()
        uses = allr
    else:
        if dest.startswith('(mem'):
            st = True; uses |= set(lamodel.regs_in(dest)) | set(lamodel.regs_in(src))
        else:
            defs |= set(lamodel.regs_in(dest)); uses |= set(lamodel.regs_in(src))
        if '(mem' in (src or ''): ld = True
    if x['kind'] == 'call_insn': st = True; ld = True
    info.append(dict(uid=x['uid'], defs=defs, uses=uses, st=st, ld=ld))
n = len(insns)
dep = set()
for j in range(n):
    for i in range(j):
        a, b = info[i], info[j]
        if (a['defs'] & b['uses']) or (a['defs'] & b['defs']) or (a['uses'] & b['defs']) or (a['st'] and (b['st'] or b['ld'])) or (a['ld'] and b['st']):
            dep.add((i, j))
uids = [x['uid'] for x in insns]
base = lamodel.by_pseudo(lamodel.simulate(ctx))
print('base', ps, '->', lamodel.regname(base.get(ps)), ' insns', n, ' deps', len(dep))
def legal(order):
    pos = {k: p for p, k in enumerate(order)}
    return all(pos[i] < pos[j] for i, j in dep)
for ui in range(n):
    for ai in range(n):
        if ai == ui or ai + 1 == ui: continue
        order = [k for k in range(n) if k != ui]
        order.insert(order.index(ai) + 1, ui)
        if not legal(order): continue
        r = lamodel.by_pseudo(lamodel.simulate(ctx, [(uids[ui], uids[ai])]))
        if r.get(ps) == want_n:
            others = [p for p in r if p != ps and base.get(p) != r[p]]
            if len(others) <= maxother:
                print(f'move insn {uids[ui]} after insn {uids[ai]}: r{ps} -> {want}; other changes: {others[:8]}')
