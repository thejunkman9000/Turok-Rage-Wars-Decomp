#!/usr/bin/env python3
"""greedy_pin2.py <base.c> <fn> <rom> <out.c> var:reg ... : greedy pin search; each pin also gets a keep-alive `asm("" : : "r"(var))` at the marker line
(`/*KEEP*/` in the base file; one asm statement listing every pinned variable)."""
import sys, re, subprocess, os
base, fn, rom, out = sys.argv[1:5]
cands = [a.split(':') for a in sys.argv[5:]]
text = open(base).read()
assert '/*KEEP*/' in text
pinned = {}
def build(text, pins):
    t = text
    for var, reg in pins.items():
        pat = re.compile(r'^(\s+)((?:u8|u16|u32|s8|s16|s32|G_Node|G_Seg|int|char|Gfx)\b[^;=\n]*?)\b' + re.escape(var) + r';', re.M)
        m = pat.search(t)
        if not m: return None
        t = t[:m.start()] + f'{m.group(1)}register {m.group(2)}{var} asm("${reg}");' + t[m.end():]
    use = '__asm__("" : : ' + ', '.join(f'"r"({v})' for v in pins) + ');' if pins else ''
    return t.replace('/*KEEP*/', use)
def score(paths):
    r = subprocess.run(['python3', 'tools/vb.py', fn, rom, '--jobs', '3'] + paths, capture_output=True, text=True)
    res = {}
    for l in r.stdout.splitlines():
        m = re.match(r'(\S+): structural=(\d+) operand=(\d+)', l)
        if m: res[m.group(1)] = (int(m.group(2)), int(m.group(3)))
    return res
os.makedirs('wip/gp', exist_ok=True)
open('wip/gp/cur.c', 'w').write(build(text, {}))
best = score(['wip/gp/cur.c'])['wip/gp/cur.c']
print('start', best, flush=True)
while True:
    files = {}
    for var, reg in cands:
        if var in pinned: continue
        p2 = dict(pinned); p2[var] = reg
        t2 = build(text, p2)
        if t2 is None: continue
        p = f'wip/gp/d_{var}_{reg}.c'
        open(p, 'w').write(t2); files[p] = (var, reg)
    if not files: break
    res = score(list(files))
    ranked = sorted(((3*s+o, s, o, p) for p, (s, o) in res.items()))
    top = ranked[0]
    print('round best', top, files[top[3]], 'cur', 3*best[0]+best[1], flush=True)
    if top[0] >= 3*best[0] + best[1]: break
    var, reg = files[top[3]]
    pinned[var] = reg
    best = (top[1], top[2])
    open(out, 'w').write(build(text, pinned))
print('final', best, pinned)
