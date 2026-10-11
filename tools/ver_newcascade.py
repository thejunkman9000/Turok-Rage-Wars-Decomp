#!/usr/bin/env python3
"""Reuse the matched release-only functions (func_auto_<VRAM>) of one release for another: Europe and Germany share most of their changes against US v1.1, but
the same function has another address, so its name differs and tools/ver_cascade.py (same unit name) cannot pair them.

usage: python tools/ver_newcascade.py <target ver> <source ver> [--jobs 4] [--write]
For every `new` target of wip/vtargets_<target>.txt the source release's units (versions/<source>/manifest.txt) are searched for the same instruction stream
(normalised: j/jal targets, lui / load / store / addiu immediates masked; same length).  A candidate is renamed to the target's name, compiled against the
target ROM with tools/chk.py (CHK_INFER: the target addresses of every release-only symbol it uses - D_auto_* / func_auto_* of the source release - are read
from the relocations), its release-only names are translated, and it is checked again: only plain EXACT units are kept.  --write adds them to
versions/<target>/manifest.txt, versions/<target>/src/ and the symbols to versions/<target>/syms.ld.  Needs wip/ver/<target>/syms.ld (tools/ver_sweep.py)."""
import concurrent.futures, os, re, struct, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ver_sweep import mode_flags, ROMS
from ver_funcmap import norm as _norm
args = [a for a in sys.argv[1:] if not a.startswith('--')]
T, S = args[0], args[1]
jobs = int(sys.argv[sys.argv.index('--jobs') + 1]) if '--jobs' in sys.argv else 4
WRITE = '--write' in sys.argv
romT = open(ROMS[T], 'rb').read(); romS = open(ROMS[S], 'rb').read()
OVL = {'us': 0x164000, 'eu': 0x176000, 'de': 0x166000}

def words(rom, off, n): return list(struct.unpack('>%dI' % n, rom[off:off + 4 * n]))
def norm(ws):
    out = _norm(ws)
    return tuple((w >> 16) if (isinstance(w, int) and (ws[i] >> 26) == 9 and ((ws[i] >> 21) & 31) not in (0, 29)) else w for i, w in enumerate(out))
def vram(rom, seg, ver): return rom - OVL[ver] + 0x400000 if seg == 'ovl_a' else rom - 0x1000 + 0x200400

def wsl(cmd):
    return subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV='1')).stdout

def main():
    targets = []
    for l in open(f'wip/vtargets_{T}.txt'):
        f = l.split()
        if len(f) >= 4 and f[3] == 'new': targets.append((f[0], int(f[1], 16), int(f[2])))
    have = set()
    if os.path.exists(f'versions/{T}/manifest.txt'):
        have = {l.split()[0] for l in open(f'versions/{T}/manifest.txt') if l.strip()}
    src = {}
    for l in open(f'versions/{S}/manifest.txt'):
        f = l.split('#')[0].split()
        if len(f) < 4 or f[0].startswith('pad_'): continue
        p = f'versions/{S}/src/{f[3]}/{f[0]}.c'
        if not os.path.exists(p): continue
        n = int(f[2]); src.setdefault((n, norm(words(romS, int(f[1], 16), n))), []).append((f, p))
    ssyms = open(f'versions/{S}/syms.ld').read() if os.path.exists(f'versions/{S}/syms.ld') else ''
    cands = []
    for name, rom, n in targets:
        if name in have: continue
        hit = src.get((n, norm(words(romT, rom, n))))
        if hit: cands.append((name, rom, n, hit[0][0], hit[0][1]))
    print(len(cands), 'of', len(targets), f'new targets of {T} have the same code as a matched unit of {S}')
    if not cands: return
    os.makedirs(f'wip/ver/{T}/ncasc', exist_ok=True)
    work = f'wip/ver/{T}/ncasc'
    # source-release symbol addresses of every release-only name (func_auto_ of the source units = their own VRAM)
    lines = [ssyms]
    for l in open(f'versions/{S}/manifest.txt'):
        f = l.split('#')[0].split()
        if len(f) >= 4 and f[0].startswith('func_auto_'): lines.append(f'{f[0]} = 0x{int(f[0][10:], 16):08X};')
    open(f'{work}/src_syms.ld', 'w', newline='\n').write('\n'.join(lines) + '\n')
    def chk(listfile, extra_syms, infer=None):
        env = f"CHK_ROM=/mnt/d/Projects/TurokRageWars/{ROMS[T]} CHK_SYMS=wip/ver/{T}/ncasc/{extra_syms}" + (f' CHK_INFER={infer}' if infer else '')
        return wsl(f"cd /mnt/d/Projects/TurokRageWars && rsync -a include/ ~/trw/include/ && mkdir -p ~/trw/wip/ver/{T}/ncasc && rsync -a wip/ver/{T}/ncasc/ ~/trw/wip/ver/{T}/ncasc/ && cat wip/ver/{T}/syms.ld wip/ver/{T}/ncasc/{extra_syms}.in > wip/ver/{T}/ncasc/{extra_syms} && {env} python3 tools/chk.py {listfile} 2>&1")
    # pass 1: renamed copies with the source release's symbols -> inferred target addresses
    rows = []
    for name, rom, n, f, p in cands:
        t = open(p, encoding='utf-8').read()
        t = re.sub(r'\b%s\b' % f[0], name, t)
        q = f'{work}/{name}.c'; open(q, 'w', encoding='utf-8', newline='\n').write(t)
        mode = ''.join(m.group(1) for e in f[4:] for m in [re.fullmatch(r'mode=([\w+]+)', e)] if m)
        rows.append((name, rom, n, f, q, mode_flags(mode, f[3])))
    open(f'{work}/s1.ld.in', 'w', newline='\n').write(open(f'{work}/src_syms.ld').read())
    def batch(k, tag, extra, infer):
        p = f'{work}/{tag}_{k}.txt'
        open(p, 'w', newline='\n').write(''.join(f'{q} {name} 0x{rom:X} {fl}\n' for name, rom, n, f, q, fl in rows[k::jobs]))
        return chk(p, extra, infer)
    inf = f'{work}/infer.txt'
    if os.path.exists(inf): os.remove(inf)
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex: list(ex.map(lambda k: batch(k, 'p1', 's1.ld', inf), range(jobs)))
    tgt = {}
    if os.path.exists(inf):
        for l in open(inf):
            g = l.split()
            if len(g) >= 3 and re.match(r'(D|func)_auto_', g[0]): tgt.setdefault(g[0], {}).setdefault(g[1], 0); tgt[g[0]][g[1]] += 1
    ren = {}
    for s, votes in tgt.items():
        a = int(max(votes, key=votes.get), 16)
        new = ('D_auto_%08X' if s.startswith('D_') else 'func_auto_%08X') % a
        if new != s: ren[s] = new
    # pass 2: translated names, target addresses
    newsyms = set()
    for name, rom, n, f, q, fl in rows:
        t = open(q, encoding='utf-8').read()
        for a, b in ren.items(): t = re.sub(r'\b%s\b' % a, b, t)
        open(q, 'w', encoding='utf-8', newline='\n').write(t)
        newsyms.update(re.findall(r'\b(?:D|func)_auto_[0-9A-F]{8}\b', t))
    s2 = [f'{s} = 0x{s[-8:]};' for s in sorted(newsyms)]
    open(f'{work}/s2.ld.in', 'w', newline='\n').write('\n'.join(s2) + '\n')
    res = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        for out in ex.map(lambda k: batch(k, 'p2', 's2.ld', None), range(jobs)):
            for l in out.split('\n'):
                m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
                if m: res[m.group(1)] = (int(m.group(2)), m.group(3).strip())
    ok = [r for r in rows if res.get(r[0], (0, ''))[1].startswith('EXACT') and res[r[0]][0] == r[2]]
    for r in rows:
        if r not in ok: print('  not reusable:', r[0], 'from', r[3][0], res.get(r[0], (0, 'no result'))[1][:80])
    print(len(ok), 'EXACT of', len(rows), 'candidates')
    if not WRITE or not ok: return
    man = open(f'versions/{T}/manifest.txt').read().rstrip('\n').split('\n') if os.path.exists(f'versions/{T}/manifest.txt') else []
    used = set()
    for name, rom, n, f, q, fl in ok:
        st = res[name][1]; opts = [e for e in f[4:] if not e.startswith('ro=')]
        m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', st)
        if m: opts.append(f'ro={m.group(1)}:{(int(m.group(2)) + 3) & ~3}' + (f':{m.group(2)}' if int(m.group(2)) & 3 else ''))
        seg = f[3]; man.append(f'{name} 0x{rom:X} {n} {seg}' + ''.join(' ' + o for o in opts))
        d = f'versions/{T}/src/{seg}'; os.makedirs(d, exist_ok=True)
        t = open(q, encoding='utf-8').read(); open(f'{d}/{name}.c', 'w', encoding='utf-8', newline='\n').write(t)
        used.update(re.findall(r'\bD_auto_[0-9A-F]{8}\b', t))
    open(f'versions/{T}/manifest.txt', 'w', newline='\n').write('\n'.join(l for l in man if l.strip()) + '\n')
    sp = f'versions/{T}/syms.ld'; cur = open(sp).read() if os.path.exists(sp) else ''
    add = [f'{s} = 0x{s[-8:]};' for s in sorted(used) if s not in cur]
    if add: open(sp, 'a', newline='\n').write('\n'.join(add) + '\n')
    print('written', len(ok), f'units to versions/{T}/ (+{len(add)} symbols)')

if __name__ == '__main__': main()
