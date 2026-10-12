#!/usr/bin/env python3
"""Bisect which matched-C function stops the attract-demo bots from moving: twin a subset (statically recompiled from the ROM), rebuild, run
port/demomove.ps1 and call the run "moving" when the last 4 camera samples hold >= 3 distinct positions.  Assumes one culprit (halving).
usage: python wip/bisect_ai.py <names file>   (production c_skip in wip/c_skip.prod.txt; progress in wip/bisect_ai.log)"""
import os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
LOG = 'wip/bisect_ai.log'
base = open('wip/c_skip.prod.txt').read().split()

def log(s):
    print(s); sys.stdout.flush(); open(LOG, 'a').write(s + '\n')

def sh(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)

def moving(names, tag):
    env = dict(os.environ, PORT_NO_ASM_REGEN='1')
    sh([sys.executable, 'port/bisect_c.py', 'set'] + base + names, env=env)
    keep = set(open('port/recomp.txt').read().split())
    for f in os.listdir('port/native/recomp'):                     # stale twins of the previous round would shadow the C
        n = f[:-2]
        if re.fullmatch(r'func_[0-9A-F]{8}', n) and n not in keep:
            for q in ('port/native/recomp/' + f, 'port/build/obj_c/ar_%s.obj' % n):
                try: os.remove(q)
                except OSError: pass
    sh([sys.executable, 'port/build_clang.py'])
    sh(['powershell', '-ExecutionPolicy', 'Bypass', '-File', 'port/relink.ps1'])
    out = sh(['powershell', '-ExecutionPolicy', 'Bypass', '-File', 'port/demomove.ps1', '-Prefix', tag]).stdout
    pos = [l.strip() for l in out.split('\n') if re.match(r'\s+-?\d', l)]
    last = pos[-4:]
    ok = len(set(last)) >= 3
    log(f'{tag}: {len(names)} twinned -> {"MOVING" if ok else "static"}  {last}')
    return ok

N = [0]
def test(names):
    N[0] += 1
    return moving(names, f'bmin{N[0]}')

def minimize(cand, fixed):
    """smallest subset S of cand with test(S + fixed) moving (test(cand + fixed) is known to move); several culprits allowed"""
    if len(cand) == 1: return cand
    a, b = cand[:len(cand) // 2], cand[len(cand) // 2:]
    if test(a + fixed): return minimize(a, fixed)
    if test(b + fixed): return minimize(b, fixed)
    ma = minimize(a, b + fixed)                       # culprits in both halves: shrink one with the other twinned, then the other
    mb = minimize(b, ma + fixed)
    return ma + mb

def main():
    cand = open(sys.argv[1]).read().split()
    if '--min' in sys.argv:
        log(f'minimize: {len(cand)} candidates')
        res = minimize(cand, [])
        log('MINIMAL ' + ' '.join(res))
        import shutil
        shutil.copy('wip/c_skip.prod.txt', 'port/c_skip.txt'); shutil.copy('wip/recomp.prod.txt', 'port/recomp.txt')
        sh([sys.executable, 'port/bisect_c.py', 'regen'], env=dict(os.environ, PORT_NO_ASM_REGEN='1'))
        log('production twin lists restored (rebuild + relink still needed)')
        return
    log(f'start: {len(cand)} candidates')
    r = 0
    while len(cand) > 1:
        r += 1
        half = cand[:len(cand) // 2]
        if moving(half, f'bai{r}a'): cand = half
        else:
            other = cand[len(cand) // 2:]
            if moving(other, f'bai{r}b'): cand = other
            else:
                log('neither half alone makes them move: more than one culprit; stopping with ' + ' '.join(cand)); break
        log(f'round {r}: {len(cand)} left: ' + ' '.join(cand[:12]))
    log('RESULT ' + ' '.join(cand))
    # restore production (bisect_c.py reset would delete the production c_skip.txt): the saved lists, then regenerate the twins
    import shutil
    shutil.copy('wip/c_skip.prod.txt', 'port/c_skip.txt'); shutil.copy('wip/recomp.prod.txt', 'port/recomp.txt')
    sh([sys.executable, 'port/bisect_c.py', 'regen'], env=dict(os.environ, PORT_NO_ASM_REGEN='1'))
    log('production twin lists restored (rebuild + relink still needed)')

if __name__ == '__main__': main()
