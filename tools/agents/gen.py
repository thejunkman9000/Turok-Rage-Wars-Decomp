#!/usr/bin/env python3
"""gen.py: generate func_00235AD0 block-0 variants from a spec and hill-climb with vb2 (Windows python driving WSL).
spec = {'order': [names...], 'opt': {...}}"""
import sys, os, re, json, random, subprocess, itertools, copy

BASE = open('wip/c/v36.c', encoding='utf-8').read()   # aggregate fe version
env = dict(os.environ, MSYS_NO_PATHCONV='1')


def build(spec):
    o = spec['opt']
    order = spec['order']
    s = BASE
    decl = ''
    for key, nm, reg in (('px', 'xf', '$f1'), ('pw', 'wf', '$f3'), ('py', 'yf', '$f2')):
        v = o.get(key)
        if v == 1:
            decl += '    register f32 %s __asm__("%s");\n' % (nm, reg)
        elif v == 2:
            decl += '    f32 %s;\n' % nm
    s = s.replace("    s32 idx;\n", "    s32 idx;\n" + decl, 1)
    X = 'xf' if o.get('px') else 'o->x'
    W = 'wf' if o.get('pw') else 'o->width'
    Y = 'yf' if o.get('py') else 'o->y'
    x1 = f'{X} + {W}' if o.get('x1order') == 'xw' else f'{W} + {X}'
    y1 = f'{Y} + o->height' if o.get('y1order', 'yh') == 'yh' else f'o->height + {Y}'
    if o.get('mx'):
        x1 = None
    if o.get('my'):
        y1 = None
    v0m = 'o->unkC' if o.get('v0form', 'unkC') == 'unkC' else 'o->unk110'
    v1m = 'o->unk114' if o.get('v1form', 'unk114') == 'unk114' else 'o->unk10'
    T = {
        'S1': 'o->unkC = 1.0f;', 'S2': 'o->unk10 = 1.0f;', 'S3': 'o->unkC = o->unk110;', 'S4': 'o->unk10 = o->unk114;',
        'WL': 'wf = o->width;', 'YL': 'yf = o->y;', 'XL': 'xf = o->x;',
        'X0': f'x0 = (s32){X};', 'Y0': f'y0 = (s32){Y};',
        'X1': (f'x1 = (s32)({x1});' if x1 else 'x1 = (s32)xf;'), 'Y1': (f'y1 = (s32)({y1});' if y1 else 'y1 = (s32)yf;'),
        'XA': ('xf = xf + wf;' if o.get('x1order', 'xw') == 'xw' else 'xf = wf + xf;'), 'YA': 'yf = yf + o->height;',
        'V0': f'vs0 = (s32)(2.0f * {W} * {v0m});', 'V1': f'vs1 = (s32)(2.0f * o->height * {v1m});',
        'W': 'wm1 = D_800E28D0 - 1;', 'H': 'hm1 = D_800E28D4 - 1;',
    }
    names = [n for n in order
             if not (n == 'WL' and not o.get('pw')) and not (n == 'YL' and not o.get('py')) and not (n == 'XL' and not o.get('px'))
             and not (n == 'XA' and not o.get('mx')) and not (n == 'YA' and not o.get('my'))]
    body = '\n'.join('    ' + T[n] for n in names)
    a = s.index('    o->unkC = 1.0f;')
    b = s.index('    hm1 = D_800E28D4 - 1;') + len('    hm1 = D_800E28D4 - 1;')
    return s[:a] + body + s[b:]


def valid(spec):
    o = spec['opt']
    order = spec['order']
    pos = {n: i for i, n in enumerate(order)}

    def before(a, b):
        return a not in pos or b not in pos or pos[a] < pos[b]
    ok = before('S1', 'S3') and before('S2', 'S4') and before('S1', 'S2')
    if o.get('v0form', 'unkC') == 'unkC':
        ok = ok and before('S3', 'V0')
    if o.get('v1form', 'unk114') == 'unk10':
        ok = ok and before('S4', 'V1')
    if o.get('px'):
        ok = ok and before('XL', 'X0') and before('XL', 'X1')
    if o.get('pw'):
        ok = ok and before('WL', 'X1') and before('WL', 'V0')
    if o.get('py'):
        ok = ok and before('YL', 'Y0') and before('YL', 'Y1')
    if o.get('mx'):
        ok = ok and before('X0', 'XA') and before('XA', 'X1') and before('XL', 'XA') and before('WL', 'XA')
    if o.get('my'):
        ok = ok and before('Y0', 'YA') and before('YA', 'Y1') and before('YL', 'YA')
    return ok


def neighbors(spec):
    out = []
    order = spec['order']
    n = len(order)
    seen = set()

    def add(sp):
        k = json.dumps(sp, sort_keys=True)
        if k in seen or not valid(sp):
            return
        seen.add(k)
        out.append(sp)
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            L = order[:]
            x = L.pop(i)
            L.insert(j, x)
            sp = copy.deepcopy(spec)
            sp['order'] = L
            add(sp)
    pinvals = [0, 2] if os.environ.get('NOPIN') else [0, 1, 2]
    for key, vals in [('px', pinvals), ('pw', pinvals), ('py', pinvals), ('mx', [0, 1]), ('my', [0, 1]), ('x1order', ['xw', 'wx']), ('y1order', ['yh', 'hy']),
                      ('v0form', ['unkC', 'unk110']), ('v1form', ['unk114', 'unk10'])]:
        for v in vals:
            if spec['opt'].get(key) == v:
                continue
            sp = copy.deepcopy(spec)
            sp['opt'][key] = v
            add(sp)
    return out


def evaluate(specs, tag, jobs=6):
    os.makedirs('wip/gen', exist_ok=True)
    txt = []
    for sp in specs:
        txt.append('//==== ' + json.dumps(sp, sort_keys=True))
        txt.append(build(sp))
    open(f'wip/gen/{tag}.txt', 'w', encoding='utf-8').write('\n'.join(txt) + '\n')
    cmd = (f'cd /mnt/d/Projects/ws/s905 && python3 tools/vb2.py func_00235AD0 0x366D0 --file wip/gen/{tag}.txt '
           f'--jobs {jobs} --top 100000 2>&1 | grep -v Warning | grep structural=')
    r = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=env)
    res = {}
    for l in r.stdout.splitlines():
        m = re.match(r'wip/vb/v(\d+)\.c: structural=(\d+) operand=(\d+) exact=(\d) movs=(\d) n=(\d+)', l)
        if m:
            res[int(m.group(1))] = (int(m.group(2)), int(m.group(3)), int(m.group(4)), int(m.group(6)))
    scored = []
    for k, sp in enumerate(specs):
        v = res.get(k + 1)
        if v is None:
            continue
        scored.append(((0 if v[2] else 1), v[0] * 3 + v[1], v, sp))
    scored.sort(key=lambda t: (t[0], t[1]))
    return scored


if __name__ == '__main__':
    start = json.loads(open(sys.argv[1]).read())
    rounds = int(sys.argv[2]) if len(sys.argv) > 2 else 10
    outp = sys.argv[3] if len(sys.argv) > 3 else 'wip/gen/best.json'
    cur = start
    cs = evaluate([cur], 'cur')
    best = cs[0]
    print('start', best[2], flush=True)
    for r in range(rounds):
        nb = neighbors(cur)
        sc = evaluate(nb, f'r{r}')
        if not sc:
            break
        top = sc[0]
        print(f'round {r}: {len(nb)} neighbors, best {top[2]}', flush=True)
        if top[1] < best[1] or (top[0] < best[0]):
            best = top
            cur = top[3]
            json.dump(cur, open(outp, 'w'))
            open('wip/c/gen_best.c', 'w', encoding='utf-8').write(build(cur))
            print('  adopted', json.dumps(cur, sort_keys=True), flush=True)
        else:
            print('  no improvement', flush=True)
            break
    print('final', best[2], json.dumps(best[3], sort_keys=True))
