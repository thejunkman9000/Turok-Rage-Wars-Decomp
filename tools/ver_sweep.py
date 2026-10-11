#!/usr/bin/env python3
"""Compile every C unit of the US v1.1 tree UNCHANGED and compare it with the same function in another release (the first measurement of a version build).

usage: python tools/ver_sweep.py <us|eu|de> [--limit N] [--jobs 8] [--only name,name] [--sub game|ovl_a]
Needs wip/funcmap_<ver>.txt (tools/ver_funcmap.py) and wip/symmap_<ver>.txt (tools/ver_symmap.py); both are created when missing.  For every unit of funcs.txt /
funcs_a.txt whose function was found in the other ROM it writes a chk list (`<src> <fn> <rom of the other release> <flags>`), runs tools/chk.py with
CHK_ROM=<that ROM> and CHK_SYMS=wip/ver/<ver>/syms.ld (the address map as PROVIDE lines for every symbol name of the repository: relocations are verified against
the other release's addresses) in several WSL processes, and writes wip/ver/<ver>/sweep.txt: `<fn> <verdict> <rom>` with the chk verdict (EXACT = the 1.1 source builds
the other release's bytes as is).  The summary lists the functions that need version-specific code."""
import collections, concurrent.futures, os, re, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
ROMS = {'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64'}
FLAGS = {'sn': '@SN', 'nb': '-fno-builtin', 'sa': '-msplit-addresses', 'r4k': '-mcpu=r4000', 'epi': '@EPI', 'sn272': '@SN272'}

def mode_flags(mode):
    toks = mode.split('+'); out = []
    for t in toks:
        if t in FLAGS: out.append(FLAGS[t])
    return ' '.join(out)

def units():
    res = []
    for fn, default_sub in (('funcs.txt', 'game'), ('funcs_a.txt', 'ovl_a')):
        if not os.path.exists(fn): continue
        for l in open(fn):
            l = l.split('#')[0].strip()
            if not l: continue
            f = l.split()
            name, rom, n, sub = f[0], int(f[1], 16), int(f[2]), f[3]
            mode = ''
            for e in f[4:]:
                m = re.fullmatch(r'mode=([\w+]+)', e)
                if m: mode = m.group(1)
            res.append((name, rom, n, sub, mode))
    return res

def load_map(path):
    m = {}
    for l in open(path):
        a, b, c = l.split()
        a = int(a, 16); b = int(b, 16)
        if a not in m or int(c) > m[a][1]: m[a] = (b, int(c))
    return {a: v[0] for a, v in m.items()}

def build_syms(ver, amap):
    names = {}
    pat = re.compile(r'\s*(?:PROVIDE\()?(\w+)\s*=\s*(0x[0-9A-Fa-f]+)')
    for f in ('symbol_addrs.txt', 'undefined_syms_auto.txt', 'undefined_funcs_auto.txt', 'extra_syms.ld', 'their_syms.ld', 'c_syms.ld', 'their_alias.ld'):
        if not os.path.exists(f): continue
        for l in open(f, encoding='utf-8', errors='replace'):
            m = pat.match(l)
            if m: names[m.group(1)] = int(m.group(2), 16)
    lines = []
    def conv(a):
        # symbol values are the addresses as the sources use them (code in the TLB space 0x002xxxxx, data 0x8xxxxxxx); the map keys are 0x80xxxxxx for code too
        if a in amap: return amap[a]
        if (a | 0x80000000) in amap and a < 0x00800000: return amap[a | 0x80000000] & 0x00FFFFFF
        return None
    for n, a in names.items():
        b = conv(a)
        if b is not None and b != a: lines.append(f'{n} = 0x{b:08X};')
    # generic names that may not be in a symbol file
    for a, b in amap.items():
        if a >= 0x80800000 or a == b: continue
        if a < 0x80200000: lines.append(f'D_{a:08X} = 0x{b:08X};')
        else: lines.append(f'func_{a & 0xFFFFFF:08X} = 0x{b & 0xFFFFFF:08X};')
    os.makedirs(f'wip/ver/{ver}', exist_ok=True)
    inf = []
    if os.path.exists(f'wip/ver/{ver}/syms_inferred.ld'): inf = [l.strip() for l in open(f'wip/ver/{ver}/syms_inferred.ld') if l.strip()]
    open(f'wip/ver/{ver}/syms.ld', 'w', newline='\n').write('\n'.join(sorted(set(lines)) + inf) + '\n')      # inferred addresses come last: chk lets the last definition win
    return len(set(lines)) + len(inf)

def aggregate_inferred(ver, jobs):
    """symbol -> address the other release encodes, from the relocations of every unit whose code matched (CHK_INFER); majority vote, conflicts reported"""
    votes = collections.defaultdict(collections.Counter)
    for k in range(jobs):
        p = f'wip/ver/{ver}/infer_{k}.txt'
        if not os.path.exists(p): continue
        for l in open(p):
            f = l.split()
            if len(f) >= 2: votes[f[0]][int(f[1], 16)] += 1
    out = []; conflicts = []
    for sym, c in votes.items():
        (a, n), = c.most_common(1)
        out.append((sym, a))
        if len(c) > 1: conflicts.append((sym, c.most_common(3)))
    if '--merge' in sys.argv and os.path.exists(f'wip/ver/{ver}/syms_inferred.ld'):          # a partial run: keep the addresses an earlier run inferred for symbols it did not meet again
        have = {s for s, _ in out}
        for l in open(f'wip/ver/{ver}/syms_inferred.ld'):
            m = re.match(r'(\w+) = (0x[0-9A-Fa-f]+);', l)
            if m and m.group(1) not in have: out.append((m.group(1), int(m.group(2), 16)))
    with open(f'wip/ver/{ver}/syms_inferred.ld', 'w', newline='\n') as f:
        for sym, a in sorted(out): f.write(f'{sym} = 0x{a:08X};\n')
    print(f'inferred {len(out)} symbol addresses from the matching code; {len(conflicts)} symbols with conflicting votes')
    for sym, c in conflicts[:6]: print('  conflict', sym, [(hex(a), n) for a, n in c])

def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    ver = args[0]
    def opt(k, d):
        return sys.argv[sys.argv.index(k) + 1] if k in sys.argv else d
    limit = int(opt('--limit', 0)); jobs = int(opt('--jobs', 8)); only = set(opt('--only', '').split(',')) - {''}; sub_only = opt('--sub', '')
    if '--only-file' in sys.argv: only |= set(open(opt('--only-file', '')).read().split())          # one unit name per line (with --merge: a partial re-run keeps the other verdicts)
    if not os.path.exists(f'wip/funcmap_{ver}.txt'): subprocess.run([sys.executable, 'tools/ver_funcmap.py', ver], check=True)
    if not os.path.exists(f'wip/symmap_{ver}.txt'): subprocess.run([sys.executable, 'tools/ver_symmap.py', ver], check=True)
    fmap = {}
    for l in open(f'wip/funcmap_{ver}.txt'):
        f = l.split()
        fmap[f[0]] = (f[3], int(f[4], 16))
    amap = load_map(f'wip/symmap_{ver}.txt')
    print(ver, 'address map entries:', len(amap), ' symbol overrides written:', build_syms(ver, amap))
    gf = []
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#') or not l.strip(): continue
        f = l.split(); gf.append((int(f[0], 16), f[1], int(f[2])))
    gf.sort()
    gfrom = [g[0] for g in gf]
    import bisect
    todo = []; none = []      # todo: (unit, [(fn, rom_other, rom11, insns)], src, flags)
    for name, rom, n, sub, mode in units():
        if only and name not in only: continue
        if sub_only and sub != sub_only: continue
        if not os.path.exists(f'src/{sub}/{name}.c'): continue          # hand-written asm and padding units (.s) are not compiled: they stay asm in another release
        i = bisect.bisect_left(gfrom, rom); fns = []
        while i < len(gf) and gf[i][0] < rom + 4 * n: fns.append(gf[i]); i += 1
        if not fns: fns = [(rom, name, n)]
        if any((fmap.get(g[1]) or ('none', 0))[0] == 'none' for g in fns): none.append((name, n)); continue
        todo.append((name, [(g[1], fmap[g[1]][1], g[0], g[2]) for g in fns], f'src/{sub}/{name}.c', mode_flags(mode or 'sn')))
    if limit: todo = todo[:limit]
    print('units with a counterpart:', len(todo), ' without:', len(none))
    os.makedirs(f'wip/ver/{ver}', exist_ok=True)
    chunks = [todo[i::jobs] for i in range(jobs)]
    lists = []
    for k, ch in enumerate(chunks):
        p = f'wip/ver/{ver}/list_{k}.txt'
        open(p, 'w', newline='\n').write(''.join(f'{src} {fn} 0x{ro:X} {fl}\n' for name, fns, src, fl in ch for fn, ro, r11, ni in fns))
        lists.append(p)
    env = f"CHK_ROM=/mnt/d/Projects/TurokRageWars/{ROMS[ver]} CHK_SYMS=wip/ver/{ver}/syms.ld"
    for k in range(jobs):
        try: os.remove(f'wip/ver/{ver}/infer_{k}.txt')
        except OSError: pass
    def run(p):
        k = re.search(r'_(\d+)\.txt$', p).group(1)
        cmd = f"cd /mnt/d/Projects/TurokRageWars && rsync -a include/ ~/trw/include/ && rsync -a src/ ~/trw/src/ && {env} CHK_INFER=wip/ver/{ver}/infer_{k}.txt python3 tools/chk.py {p} 2>&1"
        return subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV='1')).stdout
    res = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        for out in ex.map(run, lists):
            for l in out.split('\n'):
                m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
                if m: res[m.group(1)] = m.group(3).strip()
    # pass 2: a unit whose object defines other names than the game_funcs ones (ported upstream sources: func_80XXXXXX_de) gets no result by name: compare its whole object .text
    # against the release's code from the unit's position on (@all=<unit>); the functions of a unit are contiguous in the object, so one comparison judges all of them
    redo = [tt for tt in todo if any(res.get(fn) is None for fn, _, _, _ in tt[1])]
    allok = set()
    if redo:
        ins = {nm: nn for nm, _, nn, _, _ in units()}
        lists2 = []
        for k, ch in enumerate([redo[i::jobs] for i in range(jobs)]):
            p2 = f'wip/ver/{ver}/all_{k}.txt'
            open(p2, 'w', newline='\n').write(''.join(f'{src} @all={name} 0x{fns[0][1]:X} {fl}\n' for name, fns, src, fl in ch))
            lists2.append(p2)
        sizes = {}
        with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
            for out in ex.map(run, lists2):
                for l in out.split('\n'):
                    m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
                    if m: sizes[m.group(1)] = (int(m.group(2)), m.group(3).strip())
        for name, fns, src, fl in redo:
            r = sizes.get(name)
            if r is None: continue
            nn, st = r
            if st.startswith('EXACT') and nn == ins.get(name):
                for i, (fn, ro, r11, ni) in enumerate(fns): res[fn] = st if i == 0 else 'EXACT'
                allok.add(name)
            else:
                res[fns[0][0]] = st if not st.startswith('EXACT') else f'SIZE (object {nn} insns, manifest {ins.get(name)})'
        print('whole-object pass:', len(redo), 'units,', len(allok), 'EXACT')
    c = collections.Counter(); bad = []
    lines_out = {}
    if '--merge' in sys.argv and os.path.exists(f'wip/ver/{ver}/sweep.txt'):          # keep the verdicts of the units this run did not look at
        for l in open(f'wip/ver/{ver}/sweep.txt'):
            f0 = l.split(None, 1)
            if f0: lines_out[f0[0]] = l.rstrip('\n')
    with open(f'wip/ver/{ver}/sweep.txt', 'w') as f:
        for name, fns, src, fl in todo:
            vs = [res.get(fn, 'NO RESULT') for fn, ro, r11, ni in fns]
            bad_fn = [(fn, v) for (fn, ro, r11, ni), v in zip(fns, vs) if not v.startswith('EXACT')]
            adj = True
            for (fa, ra, a11, na), (fb, rb, b11, nb) in (zip(fns, fns[1:]) if name not in allok else []):      # (a whole-object match has judged the contiguity already)
                if rb - (ra + 4 * na) != b11 - (a11 + 4 * na): adj = False      # the gap between the functions of the unit differs in the other release
            if bad_fn: v = bad_fn[0][1]; k = 'CODE-EXACT' if v.startswith('CODE-EXACT') else 'diff' if 'differ' in v else 'other'
            elif not adj: v = 'LAYOUT (the functions of this unit are not adjacent in the release)'; k = 'other'
            else:
                pools = sorted(set(re.findall(r'ro=0x[0-9A-Fa-f]+:\d+', ' '.join(vs))))
                v = 'EXACT' + (' ' + pools[0] if pools else '') + (' MULTIPOOL ' + ' '.join(pools[1:]) if len(pools) > 1 else ''); k = 'EXACT'
            lines_out[name] = f'{name} 0x{fns[0][1]:X} {v}' + (f' [{bad_fn[0][0]}]' if bad_fn else '')
            c[k] += 1
            if k != 'EXACT': bad.append((name, v))
        for name, n in none: lines_out[name] = f'{name} - NO COUNTERPART {n} insns'
        for ln in lines_out.values(): f.write(ln + '\n')
    print(dict(c))
    aggregate_inferred(ver, jobs)
    for name, v in bad[:25]: print(' ', name, v[:110])

if __name__ == '__main__': main()
