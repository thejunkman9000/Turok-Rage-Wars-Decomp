#!/usr/bin/env python3
"""Work list for matching the code of another release that our US v1.1 C does not reproduce.

usage: python tools/mkvtargets.py <us|eu|de> <release workspace dir (tools/mkver.py --out)> [--out wip/vtargets_<ver>.txt]
Needs (main tree): wip/ver/<ver>/sweep.txt (tools/ver_sweep.py), wip/funcmap_<ver>.txt (tools/ver_funcmap.py); and the release workspace after `tools\\cycle.ps1` (its asm/ is
the splat disassembly of the release ROM: every function that is still assembler there is a target).
Output line:   <name> <release ROM offset hex> <insns> <class> [score=<chk score>] [unit=<1.1 unit>]
  class diff : the function exists in both releases (same name), the 1.1 C unit does not reproduce the release (a few words differ, another callee, a changed constant ...)
  class new  : only the release has it (no 1.1 counterpart), named func_auto_<release VRAM> by splat
  class lib  : libultra / libaudio unit of the 1.1 tree that differs in the release (another SDK version)
Sorted by class and size; the small `diff` ones first (fewest differing words)."""
import glob, os, re, sys
ver, ws = sys.argv[1], sys.argv[2].replace('/', '\\')
out = sys.argv[sys.argv.index('--out') + 1] if '--out' in sys.argv else f'wip/vtargets_{ver}.txt'
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sweep = {}
for l in open(f'wip/ver/{ver}/sweep.txt'):
    f = l.split(None, 2)
    if len(f) == 3: sweep[f[0]] = f[2].strip()
fmap = {}
for l in open(f'wip/funcmap_{ver}.txt'):
    f = l.split(); fmap[f[0]] = (f[3], int(f[4], 16), int(f[2]))
units = {}
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4: units[f[0]] = (int(f[1], 16), int(f[2]), f[3])
kept = set()
for fn in ('funcs.txt', 'funcs_a.txt'):
    p = os.path.join(ws, fn)
    if os.path.exists(p):
        for l in open(p):
            f = l.split('#')[0].split()
            if f: kept.add(f[0])
rows = []
for name, v in sweep.items():
    if v.startswith('EXACT') or 'NO COUNTERPART' in v or name in kept or name not in units or name.startswith('pad_'): continue
    st = fmap.get(name)
    if not st or st[0] == 'none': continue
    sub = units[name][2]
    m = re.search(r'(\d+) words differ', v); sc = re.search(r'score=(\d+)', v)
    cls = 'lib' if sub == 'libultra' else 'diff'
    rows.append((cls, int(sc.group(1)) if sc else 9999, name, st[1], units[name][1], f'score={sc.group(1)}' if sc else v.split('[')[0].strip()[:40].replace(' ', '_')))
# release-only functions: assembler of the release workspace that carries a splat auto name
news = []
for p in glob.glob(os.path.join(ws, 'asm', '*.s')):
    t = open(p, encoding='utf-8', errors='replace').read()
    for m in re.finditer(r'^glabel (func_auto_[0-9A-Fa-f]+)\n(.*?)^endlabel \1', t, re.S | re.M):
        body = m.group(2); n = len(re.findall(r'^\s*/\*', body, re.M)); first = re.search(r'/\*\s*([0-9A-F]+)\s', body)
        if first: news.append((m.group(1), int(first.group(1), 16), n))
news.sort(key=lambda r: r[1])
# probable 1.1 counterparts of the release-only functions: the 1.1 functions without a code-content match (funcmap status `none`) lie between two mapped neighbours; the
# release functions that lie between the same neighbours in the release are their rewritten versions.  Pair them in order with an alignment on the sizes (a function can
# be added or removed): `unit=<1.1 name>` tells the agent where to start from (the 1.1 source).
import bisect
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from mkver import LAYOUT
lay = LAYOUT[ver]
fl = []                                                                    # (1.1 rom, name, insns, status, release rom)
for l in open(f'wip/funcmap_{ver}.txt'):
    f = l.split(); fl.append((int(f[1], 16), f[0], int(f[2]), f[3], int(f[4], 16)))
fl.sort()
hint = {}
for ovl in (False, True):
    reg = [e for e in fl if (e[0] >= 0x16E000) == ovl]
    lo_, hi_ = (lay['OVL_START'], lay['OVL_END']) if ovl else (0x1000, lay['MAIN_CODE_END'])
    mp = [e for e in reg if e[3] != 'none' and lo_ <= e[4] < hi_]
    tails = []; prv = [None] * len(mp)                                    # longest run that keeps the 1.1 order (as in tools/mkver.py)
    for i, e in enumerate(mp):
        j = bisect.bisect_left([mp[q][4] for q in tails], e[4])
        if j > 0: prv[i] = tails[j - 1]
        if j == len(tails): tails.append(i)
        else: tails[j] = i
    ok = []; k = tails[-1] if tails else None
    while k is not None: ok.append(mp[k]); k = prv[k]
    ok.reverse()
    okset = {e[1] for e in ok}
    rel_news = [r for r in news if lo_ <= r[1] < hi_]
    pos = 0; run = []
    def flush(run, E, S):
        cand = [r for r in rel_news if E <= r[1] < S]
        if not run or not cand: return
        A = [(e[1], e[2]) for e in run]; B = [(r[0], r[2]) for r in cand]
        SK = 0.7                                                          # cost of leaving a function unpaired
        D = [[0.0] * (len(B) + 1) for _ in range(len(A) + 1)]; T = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
        for i in range(len(A) + 1):
            for j in range(len(B) + 1):
                if i == 0 and j == 0: continue
                best = (1e9, 0)
                if i and D[i - 1][j] + SK < best[0]: best = (D[i - 1][j] + SK, 1)
                if j and D[i][j - 1] + SK < best[0]: best = (D[i][j - 1] + SK, 2)
                if i and j:
                    c = abs(A[i - 1][1] - B[j - 1][1]) / (max(A[i - 1][1], B[j - 1][1]) + 6.0)
                    if D[i - 1][j - 1] + c < best[0]: best = (D[i - 1][j - 1] + c, 3)
                D[i][j], T[i][j] = best
        i, j = len(A), len(B)
        while i or j:
            t = T[i][j]
            if t == 3: hint[B[j - 1][0]] = A[i - 1][0]; i -= 1; j -= 1
            elif t == 1: i -= 1
            else: j -= 1
    E = lo_
    for e in reg:
        if e[1] in okset:
            flush(run, E, e[4]); run = []; E = e[4] + 4 * e[2]
        elif e[3] == 'none': run.append(e)
    flush(run, E, hi_)
with open(out, 'w', newline='\n') as f:
    for cls, sc, name, rom, n, note in sorted(rows, key=lambda r: (r[0], r[1])):
        f.write(f'{name} 0x{rom:X} {n} {cls} {note}\n')
    for name, rom, n in news: f.write(f'{name} 0x{rom:X} {n} new' + (f' unit={hint[name]}' if name in hint else '') + '\n')
print(f'{len(hint)} of the release-only functions have a probable 1.1 counterpart (unit=)')
print(f'{len(rows)} units that differ ({sum(1 for r in rows if r[0] == "diff")} game, {sum(1 for r in rows if r[0] == "lib")} libultra), {len(news)} release-only functions ({sum(n for _, _, n in news)} insns) -> {out}')
