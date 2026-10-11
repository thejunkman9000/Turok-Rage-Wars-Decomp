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
    if not os.path.exists(f'wip/funcmap_{ver}.txt'): subprocess.run([sys.executable, 'tools/ver_funcmap.py', ver], check=True)
    if not os.path.exists(f'wip/symmap_{ver}.txt'): subprocess.run([sys.executable, 'tools/ver_symmap.py', ver], check=True)
    fmap = {}
    for l in open(f'wip/funcmap_{ver}.txt'):
        f = l.split()
        fmap[f[0]] = (f[3], int(f[4], 16))
    amap = load_map(f'wip/symmap_{ver}.txt')
    print(ver, 'address map entries:', len(amap), ' symbol overrides written:', build_syms(ver, amap))
    todo = []; none = []
    for name, rom, n, sub, mode in units():
        if only and name not in only: continue
        if sub_only and sub != sub_only: continue
        st = fmap.get(name)
        if not st or st[0] == 'none': none.append((name, n)); continue
        todo.append((name, st[1], f'src/{sub}/{name}.c', mode_flags(mode or 'sn')))
    if limit: todo = todo[:limit]
    print('units with a counterpart:', len(todo), ' without:', len(none))
    os.makedirs(f'wip/ver/{ver}', exist_ok=True)
    chunks = [todo[i::jobs] for i in range(jobs)]
    lists = []
    for k, ch in enumerate(chunks):
        p = f'wip/ver/{ver}/list_{k}.txt'
        open(p, 'w', newline='\n').write(''.join(f'{src} {name} 0x{rom:X} {fl}\n' for name, rom, src, fl in ch))
        lists.append(p)
    env = f"CHK_ROM=/mnt/d/Projects/TurokRageWars/{ROMS[ver]} CHK_SYMS=wip/ver/{ver}/syms.ld"
    for k in range(jobs):
        try: os.remove(f'wip/ver/{ver}/infer_{k}.txt')
        except OSError: pass
    def run(p):
        k = os.path.basename(p)[5:-4]
        cmd = f"cd /mnt/d/Projects/TurokRageWars && rsync -a include/ ~/trw/include/ && rsync -a src/ ~/trw/src/ && {env} CHK_INFER=wip/ver/{ver}/infer_{k}.txt python3 tools/chk.py {p} 2>&1"
        return subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV='1')).stdout
    res = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        for out in ex.map(run, lists):
            for l in out.split('\n'):
                m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
                if m: res[m.group(1)] = m.group(3).strip()
    c = collections.Counter(); bad = []
    with open(f'wip/ver/{ver}/sweep.txt', 'w') as f:
        for name, rom, src, fl in todo:
            v = res.get(name, 'NO RESULT')
            f.write(f'{name} 0x{rom:X} {v}\n')
            k = 'EXACT' if v.startswith('EXACT') else 'CODE-EXACT' if v.startswith('CODE-EXACT') else 'diff' if re.match(r'\d+ words? differ|\d+ differ', v) or 'differ' in v else 'other'
            c[k] += 1
            if k != 'EXACT': bad.append((name, v))
        for name, n in none: f.write(f'{name} - NO COUNTERPART {n} insns\n')
    print(dict(c))
    aggregate_inferred(ver, jobs)
    for name, v in bad[:25]: print(' ', name, v[:110])

if __name__ == '__main__': main()
