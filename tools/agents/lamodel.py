#!/usr/bin/env python3
"""lamodel.py <dumpdir> [--move UID:AFTER_UID ...]
Model of gcc 2.8.1 local-alloc (block_alloc ties + qty_compare priority + find_free_reg first fit) for ONE basic block (block 0 by default),
fed from the condensed sched1 RTL <dumpdir>/sched.txt (RTLC_W=5000 python3 tools/rtlc.py a.i.sched > sched.txt; produced from tools/dump.sh output)
and the pseudo statistics of <dumpdir>/a.i.lreg; a.i.greg gives the real dispositions for comparison.
--move UID:AFTER moves insn UID right after insn AFTER in the stream before modelling (what-if experiments).
Import: lamodel.load(dumpdir) -> ctx;  lamodel.simulate(ctx, moves) -> dict(qty=..., order=..., res=..., log=...)."""
import re, sys, math

FIRST_PSEUDO = 66
NAMES = ['zero', 'at', 'v0', 'v1', 'a0', 'a1', 'a2', 'a3', 't0', 't1', 't2', 't3', 't4', 't5', 't6', 't7',
         's0', 's1', 's2', 's3', 's4', 's5', 's6', 's7', 't8', 't9']


def load(d, blk=0, seg_uid=None):
    lines = open(d + '/sched.txt').read().split('\n')
    lreg = open(d + '/a.i.lreg').read()
    greg = open(d + '/a.i.greg').read()
    stat = {}
    for m in re.finditer(r'^Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?(.*)$', lreg, re.M):
        r = int(m.group(1)); rest = m.group(5)
        dies = re.search(r'dies in (\d+) place', rest)
        cc = re.search(r'crosses (\d+) call', rest)
        stat[r] = dict(refs=int(m.group(2)), length=int(m.group(3)), blk=(int(m.group(4)) if m.group(4) is not None else None),
                       dies=(int(dies.group(1)) if dies else 1), calls=(int(cc.group(1)) if cc else 0))
    disp = {}
    sec = greg[greg.index('Register dispositions'):]
    if 'Hard regs used' in sec:
        sec = sec[:sec.index('Hard regs used')]
    for m in re.finditer(r'(\d+) in (\d+)', sec):
        disp[int(m.group(1))] = int(m.group(2))
    segs = []           # straight-line segments separated by jump / label / barrier
    cur = []
    for ln in lines:
        m = re.match(r'\((insn|jump_insn|call_insn|code_label|barrier|note) (\d+) ', ln)
        if not m:
            continue
        kind, uid = m.group(1), int(m.group(2))
        if kind == 'note':
            continue
        if kind in ('jump_insn', 'code_label', 'barrier'):
            if kind == 'jump_insn' and cur:
                pm0 = re.match(r'\(\w+ \d+ \d+ \d+ (\(.*?\)) \d+ ', ln)
                cur.append(dict(uid=uid, kind='jump_insn', pat=pm0.group(1) if pm0 else ln,
                                dead=[int(x) for x in re.findall(r'REG_DEAD r(\d+)\b', ln)], unused=[]))
            if cur:
                segs.append(cur)
            cur = []
            continue
        dead = [int(x) for x in re.findall(r'REG_DEAD r(\d+)\b', ln)]
        unused = [int(x) for x in re.findall(r'REG_UNUSED r(\d+)\b', ln)]
        pm = re.match(r'\(\w+ \d+ \d+ \d+ (\(.*?\)) \d+ ', ln)
        pat = pm.group(1) if pm else ln
        cur.append(dict(uid=uid, kind=kind, pat=pat, dead=dead, unused=unused))
    if cur:
        segs.append(cur)
    if seg_uid is None:
        insns = segs[0]
        if insns and insns[-1]['kind'] == 'jump_insn':
            insns = insns[:-1]
    else:
        insns = next(sg for sg in segs if any(x['uid'] == seg_uid for x in sg))
        if insns and insns[-1]['kind'] == 'jump_insn':
            insns = insns[:-1]
        found = False
        for x in insns:
            m = re.match(r'\(set (r\d+)', x['pat'].strip())
            if m:
                r = int(m.group(1)[1:])
                if r in stat and stat[r]['blk'] is not None:
                    blk = stat[r]['blk']; found = True; break
    return dict(stat=stat, disp=disp, insns=insns, blk=blk)


def regs_in(s):
    return [int(x) for x in re.findall(r'\br(\d+)\b', s)]


def split_set(pat):
    m = re.match(r'\(set (.*)\)$', pat.strip())
    if not m:
        return None, None
    s = m.group(1)
    if s.startswith('('):
        depth = 0
        for i, ch in enumerate(s):
            if ch == '(':
                depth += 1
            elif ch == ')':
                depth -= 1
                if depth == 0:
                    break
        return s[:i + 1], s[i + 1:].strip()
    sp = s.index(' ')
    return s[:sp], s[sp + 1:].strip()


def top_operands(src):
    src = src.strip()
    if re.fullmatch(r'r\d+(:\w+)?', src):
        return [int(re.match(r'r(\d+)', src).group(1))]
    m = re.match(r'\((\w+)(?::\w+)? (.*)\)$', src)
    if not m:
        return []
    op = m.group(1)
    if op in ('mem', 'sign_extend', 'zero_extend', 'symbol_ref', 'const_double', 'high', 'lo_sum', 'subreg', 'float', 'fix',
              'unsigned_float', 'float_extend'):
        return []
    res = []
    for t in re.findall(r'\([^()]*(?:\([^()]*\)[^()]*)*\)|\S+', m.group(2)):
        mm = re.fullmatch(r'r(\d+)(:\w+)?', t)
        res.append(int(mm.group(1)) if mm else None)
    return res


def pri(q):
    n = q['refs']
    lg = int(math.floor(math.log2(n))) if n > 0 else 0
    ln = max(q['death'] - q['birth'], 1)
    return int((lg * n * 1.0 / ln) * 10000)


def simulate(ctx, moves=()):
    stat, insns0, blk = ctx['stat'], ctx['insns'], ctx['blk']
    insns = [dict(x) for x in insns0]
    for u, af in moves:
        ix = next(i for i, x in enumerate(insns) if x['uid'] == u)
        x = insns.pop(ix)
        jx = next(i for i, y in enumerate(insns) if y['uid'] == af)
        insns.insert(jx + 1, x)
    reg_qty = {}
    for r, s in stat.items():
        if r >= FIRST_PSEUDO:
            reg_qty[r] = -2 if (s['blk'] == blk and s['dies'] == 1) else -1
    qty = []

    def new_qty(r, birth):
        qty.append(dict(regs=[r], birth=birth, death=-1, refs=stat[r]['refs'], calls=stat[r]['calls']))
        reg_qty[r] = len(qty) - 1

    log = []
    insn_no = 0
    for ins in insns:
        insn_no += 1
        dest, src = split_set(ins['pat'])
        win_reg = None
        if ins['kind'] == 'insn' and dest is not None and re.fullmatch(r'r\d+(:\w+)?', dest):
            sreg = int(re.match(r'r(\d+)', dest).group(1))
            for o in top_operands(src):
                if o is None or o < FIRST_PSEUDO:
                    continue
                if reg_qty.get(o, -1) < 0 or o == sreg or reg_qty.get(sreg, -1) != -2:
                    continue
                if o in ins['dead']:
                    qi = reg_qty[o]
                    reg_qty[sreg] = qi
                    qty[qi]['regs'].append(sreg)
                    qty[qi]['refs'] += stat[sreg]['refs']
                    qty[qi]['calls'] += stat[sreg]['calls']
                    win_reg = o
                    log.append(f'insn {ins["uid"]}: tie r{sreg} -> r{o} (q{qi})')
                    break
        for r in ins['dead']:
            if r == win_reg:
                continue
            if r >= FIRST_PSEUDO and reg_qty.get(r, -1) >= 0:
                qty[reg_qty[r]]['death'] = 2 * insn_no
        if dest is not None and not dest.startswith('(mem'):
            for r in set(regs_in(dest)):
                if r >= FIRST_PSEUDO:
                    if reg_qty.get(r) == -2:
                        new_qty(r, 2 * insn_no)
                    if reg_qty.get(r, -1) >= 0:
                        qty[reg_qty[r]]['death'] = -1
        if dest is None and ins['pat'].startswith('(parallel'):
            for r in regs_in(ins['pat']):
                if r >= FIRST_PSEUDO and reg_qty.get(r) == -2:
                    new_qty(r, 2 * insn_no)
        for r in ins['unused']:
            if r >= FIRST_PSEUDO and reg_qty.get(r, -1) >= 0:
                qty[reg_qty[r]]['death'] = 2 * insn_no + 1
    order = sorted(range(len(qty)), key=lambda i: (-pri(qty[i]), i))
    used_at = {}
    res = {}
    for i in order:
        q = qty[i]
        cand = list(range(2, 26))
        if q['calls'] > 0:
            cand = [r for r in cand if 16 <= r <= 23]
        res[i] = None
        for r in cand:
            if all(not (q['birth'] < d2 and b2 < q['death']) for (b2, d2) in used_at.get(r, [])):
                used_at.setdefault(r, []).append((q['birth'], q['death']))
                res[i] = r
                break
    return dict(qty=qty, order=order, res=res, log=log)


def regname(x):
    return NAMES[x] if x is not None and x < 26 else str(x)


def by_pseudo(sim):
    """-> {pseudo: hard reg} for every pseudo of every quantity"""
    out = {}
    for i, q in enumerate(sim['qty']):
        for r in q['regs']:
            out[r] = sim['res'][i]
    return out


if __name__ == '__main__':
    d = sys.argv[1]
    moves = []
    args = sys.argv[1:]
    for i, a in enumerate(args):
        if a == '--move':
            u, af = args[i + 1].split(':')
            moves.append((int(u), int(af)))
    seg = None
    for i, a in enumerate(args):
        if a == '--seg':
            seg = int(args[i + 1])
    ctx = load(d, 0, seg)
    sim = simulate(ctx, moves)
    qty, order, res, disp = sim['qty'], sim['order'], sim['res'], ctx['disp']
    print('ord  qty  regs                          refs  birth death   prio   model  real')
    for k, i in enumerate(order):
        q = qty[i]
        real = [disp.get(r) for r in q['regs']]
        print('%3d %4d  %-30s %4d %6d %6d %7d  %-6s %s' % (k, i, ','.join('r%d' % r for r in q['regs']), q['refs'], q['birth'], q['death'],
                                                       pri(q), regname(res[i]), ','.join(regname(x) for x in real)))
    for l in sim['log']:
        print(l)
