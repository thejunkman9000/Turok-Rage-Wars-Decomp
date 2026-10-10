#!/usr/bin/env python3
"""hc.py <base.c> <fn> <rom> <flags...> : greedy hill climb with mutations wrap/swap/dup (see mutgen.py, dupgen.py); objective (S,R) from rvfull.
Writes the best file to wip/c/<fn>.hc.c after every improvement.  Env HC_ROUNDS (default 6), HC_KINDS (default wrap,swap,dup), HC_DUPCONDS."""
import sys, os, subprocess, re, json
base, fn, rom = sys.argv[1:4]; flags = ' '.join(sys.argv[4:]) or '@SN'
rounds = int(os.environ.get('HC_ROUNDS', 6)); kinds = os.environ.get('HC_KINDS', 'wrap,swap,dup').split(',')
conds = os.environ.get('HC_DUPCONDS', 'm')
cur = base
TAG = '_hc' + fn[-4:]
ENV = dict(os.environ, RV_TAG=TAG, DUPSPEC='wip/vx/dup_spec%s.py' % TAG)
def evalfile(path):
    open('wip/vx/hc_one%s.py' % TAG, 'w').write('BASE=%r\nFN=%r\nROM=%r\nFLAGS=%r\nVARIANTS=[[]]\n' % (path, fn, rom, flags))
    out = subprocess.run(['python', 'tools/rv.py', 'wip/vx/hc_one%s.py' % TAG], capture_output=True, text=True, env=ENV).stdout
    m = re.search(r'S=(\d+) R=(\d+)', out)
    if 'EXACT' in out and 'EXACT' in out.split('variants')[0]: return (0, 0)
    return (int(m.group(1)), int(m.group(2))) if m else (9999, 9999)
best = evalfile(cur); print('start', best, flush=True)
for r in range(rounds):
    improved = False
    for kind in kinds:
        if kind == 'dup':
            subprocess.run(['python', 'tools/dupgen.py', cur, fn, rom, conds], capture_output=True, env=ENV)
            # dupgen hardcodes FLAGS '@SN'; patch
            s = open(ENV['DUPSPEC']).read().replace("FLAGS='@SN'", 'FLAGS=%r' % flags); open(ENV['DUPSPEC'], 'w').write(s)
        else:
            subprocess.run(['python', 'tools/mutgen.py', cur, fn, rom, kind] + flags.split(), capture_output=True, env=ENV)
        out = subprocess.run(['python', 'tools/rvfull.py', ENV['DUPSPEC']], capture_output=True, text=True, env=dict(ENV, RV_TOP='1')).stdout
        m = re.search(r'^(\d+) .* S=(\d+) R=(\d+)', out, re.M)
        if not m: continue
        k, S, R = int(m.group(1)), int(m.group(2)), int(m.group(3))
        if (S, R) < best:
            cand = open(f'wip/vx/{fn}_{k}.c').read()
            open(f'wip/c/{fn}.hc.c', 'w').write(cand)
            cur = f'wip/c/{fn}.hc.c'; best = (S, R); improved = True
            print(f'round {r} {kind}: {best}', flush=True)
        if best == (0, 0): break
    if not improved or best == (0, 0): break
print('final', best, cur)
