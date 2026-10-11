#!/usr/bin/env python3
"""Re-check the `diff` / `lib` targets of a release inside its build workspace: many are false positives of the sweep (tools/chk.py did not read c_syms.ld /
their_alias.ld, so a callee or data name whose release address lives only there looked like a relocation mismatch; `+inl` units were compiled without
GAS_INLINE; sources that define the function under melalawi's name).  Here the unchanged 1.1 source of every target unit is compiled in the release
workspace (its symbol files hold the release's addresses), whole object (`@all=<unit>`), with the unit's real flags; EXACT units are listed.

usage: python tools/ver_recheck.py <us|eu|de> <workspace name (v10 / veu / vde)> [--jobs 4] [--write]
--write adds them to versions/<ver>/manifest.txt (+ sources in versions/<ver>/src/).  Run tools/mkver.py + the workspace's cycle.ps1 afterwards."""
import concurrent.futures, os, re, shutil, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ver_sweep import mode_flags, ROMS
args = [a for a in sys.argv[1:] if not a.startswith('--')]
ver, ws = args[0], args[1]
jobs = int(sys.argv[sys.argv.index('--jobs') + 1]) if '--jobs' in sys.argv else 4
WS = f'D:/Projects/ws/{ws}'

def main():
    units = {}
    for fn in ('funcs.txt', 'funcs_a.txt'):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) >= 4: units[f[0]] = f
    have = set()
    if os.path.exists(f'versions/{ver}/manifest.txt'): have = {l.split()[0] for l in open(f'versions/{ver}/manifest.txt') if l.strip()}
    rows = []
    for l in open(f'wip/vtargets_{ver}.txt'):
        f = l.split()
        if len(f) < 4 or f[3] not in ('diff', 'lib') or f[0] in have or f[0] not in units: continue
        u = units[f[0]]; seg = u[3]; p = f'src/{seg}/{f[0]}.c'
        if not os.path.exists(p): continue
        mode = ''.join(m.group(1) for e in u[4:] for m in [re.fullmatch(r'mode=([\w+]+)', e)] if m)
        rows.append((f[0], int(f[1], 16), int(f[2]), seg, p, mode, u))
    print(len(rows), 'diff/lib targets with a 1.1 source')
    os.makedirs(f'{WS}/wip/recheck', exist_ok=True)
    for name, rom, n, seg, p, mode, u in rows: shutil.copyfile(p, f'{WS}/wip/recheck/{name}.c')
    subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', f'cd /mnt/d/Projects/ws/{ws} && bash tools/wsl_sync.sh >/dev/null 2>&1'], env=dict(os.environ, MSYS_NO_PATHCONV='1'))
    groups = {}
    for r in rows: groups.setdefault('inl' in r[5].split('+'), []).append(r)
    batches = []
    for inl, lst in groups.items():
        for k in range(jobs):
            part = lst[k::jobs]
            if not part: continue
            p = f'{WS}/wip/recheck/list_{int(inl)}_{k}.txt'
            open(p, 'w', newline='\n').write(''.join(f'wip/recheck/{name}.c @all={name}:{n} 0x{rom:X} {mode_flags(mode, seg)}\n' for name, rom, n, seg, _, mode, u in part))
            batches.append((inl, os.path.basename(p)))
    def run(b):
        inl, lst = b
        cmd = f"cd /mnt/d/Projects/ws/{ws} && CHK_ROM=/mnt/d/Projects/TurokRageWars/{ROMS[ver]} {'GAS_INLINE=1 ' if inl else ''}python3 tools/chk.py wip/recheck/{lst} 2>&1"
        return subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV='1')).stdout
    res = {}
    with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
        for out in ex.map(run, batches):
            for l in out.split('\n'):
                m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
                if m: res[m.group(1)] = (int(m.group(2)), m.group(3).strip())
    ok = []
    for r in rows:
        st = res.get(r[0])
        if st and st[1].startswith('EXACT') and st[0] == r[2]: ok.append((r, st[1]))
        else: print('  still differs:', r[0], (st[1][:90] if st else 'no result'))
    print(len(ok), 'EXACT of', len(rows))
    if '--write' not in sys.argv or not ok: return
    man = open(f'versions/{ver}/manifest.txt').read().rstrip('\n').split('\n') if os.path.exists(f'versions/{ver}/manifest.txt') else []
    for (name, rom, n, seg, p, mode, u), st in ok:
        opts = [e for e in u[4:] if not e.startswith('ro=')]
        m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', st)
        if m:
            sz = int(m.group(2)); r4 = (sz + 3) & ~3; real = sz if r4 != sz else None
            for e in u[4:]:                                       # the 1.1 piece says how many of its bytes are the object's own (size:real)
                mm = re.fullmatch(r'ro=0x[0-9A-Fa-f]+:(\d+):(\d+)', e)
                if mm and int(mm.group(1)) == r4: real = int(mm.group(2))
            opts.append(f'ro={m.group(1)}:{r4}' + (f':{real}' if real is not None else ''))
        man.append(f'{name} 0x{rom:X} {n} {seg}' + ''.join(' ' + o for o in opts))
        d = f'versions/{ver}/src/{seg}'; os.makedirs(d, exist_ok=True); shutil.copyfile(p, f'{d}/{name}.c')
    open(f'versions/{ver}/manifest.txt', 'w', newline='\n').write('\n'.join(l for l in man if l.strip()) + '\n')
    print('written', len(ok), f'units to versions/{ver}/')

if __name__ == '__main__': main()
