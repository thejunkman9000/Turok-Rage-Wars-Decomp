#!/usr/bin/env python3
"""Delta-debug which matched C sources break the port: find a small set of sources that, run as recompiled twins, makes the scripted 1-player
level test pass.

usage: python port/bisect_auto.py <candidates file> [--base <names file>] [--oracle lvl|demo]
  candidates : func_XXXXXXXX names (one per line) known to fix the problem when ALL are forced to twins
  --base     names that are always forced (the output of port/pass_through.py)
The oracle (lvltest.ps1): no CRASH in port/build/run.log, the game reaches state 13 and the picture is > 0.3 non-black.
Progress is appended to wip/bisect_auto.log; the result is the minimal set found (1-minimal under chunk removal)."""
import os, re, subprocess, sys, glob, time
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
LOG = 'wip/bisect_auto.log'
cache = {}
RUNS = int(sys.argv[sys.argv.index('--runs') + 1]) if '--runs' in sys.argv else 1

def log(s):
    print(s); sys.stdout.flush()
    open(LOG, 'a').write(s + '\n')

def sh(args, **kw):
    return subprocess.run(args, capture_output=True, text=True, **kw)

def clean_stale():
    keep = set(open('port/recomp.txt').read().split())
    for p in glob.glob('port/native/recomp/func_*.c'):
        n = os.path.basename(p)[:-2]
        if re.fullmatch(r'func_[0-9A-F]{8}', n) and n not in keep:
            for q in (p, f'port/build/obj_c/ar_{n}.obj'):
                try: os.remove(q)
                except OSError: pass

def test(names, base):
    key = frozenset(names)
    if key in cache: return cache[key]
    t0 = time.time()
    allnames = sorted(set(names) | set(base))
    sh([sys.executable, 'port/bisect_c.py', 'set'] + allnames, env=dict(os.environ, PORT_NO_ASM_REGEN='1'))
    clean_stale()
    sh([sys.executable, 'port/build_clang.py'])
    sh(['powershell', '-NoProfile', '-File', 'port\\relink.ps1'])
    ok = True; crash = False; reached = True; share = 1.0
    for k in range(RUNS):                          # a bad build fails about half of the scripted runs: it only counts as good when every run passes
        r = sh(['powershell', '-NoProfile', '-File', 'port\\lvltest.ps1', '-Prefix', 'bauto'])
        m = re.search(r'best share of non-black pixels: ([0-9.]+)', r.stdout)
        s = float(m.group(1)) if m else 0.0
        runlog = open('port/build/run.log', errors='replace').read() if os.path.exists('port/build/run.log') else ''
        c = 'CRASH(raw' in runlog
        rch = bool(re.search(r'game state: g=\w+ st=13', runlog))
        crash |= c; reached &= rch; share = min(share, s)
        if c or not rch or s <= 0.3: ok = False; break
    cache[key] = ok
    log(f'  test {len(names)} names: crash={crash} st13={reached} share={share:.2f} -> {"PASS" if ok else "fail"} (up to {RUNS} runs)  ({time.time() - t0:.0f}s)')
    return ok

def ddmin(S, base):
    n = 2
    while len(S) >= 2:
        size = max(1, len(S) // n)
        chunks = [S[i:i + size] for i in range(0, len(S), size)]
        reduced = False
        for c in chunks:
            if test(c, base): S = c; n = 2; reduced = True; log(f'subset works: {len(S)} left'); break
        if not reduced:
            for c in chunks:
                comp = [x for x in S if x not in c]
                if comp and test(comp, base): S = comp; n = max(n - 1, 2); reduced = True; log(f'complement works: {len(S)} left'); break
        if not reduced:
            if n >= len(S): break
            n = min(len(S), n * 2)
    return S

def main():
    cands = [l.strip() for l in open(sys.argv[1]) if l.strip()]
    base = []
    if '--base' in sys.argv: base = [l.strip() for l in open(sys.argv[sys.argv.index('--base') + 1]) if l.strip()]
    log(f'bisect_auto: {len(cands)} candidates, {len(base)} base names')
    S = ddmin(cands, base)
    log('RESULT minimal set: ' + ' '.join(S))
    sh([sys.executable, 'port/bisect_c.py', 'set'] + sorted(set(base)), env=dict(os.environ, PORT_NO_ASM_REGEN='1'))

if __name__ == '__main__':
    main()
