#!/usr/bin/env python3
"""Reuse the release-specific C of one release for another (the releases share most of their changes against US v1.1).

usage: python tools/ver_cascade.py <target ver: us|eu|de> <source ver> [--jobs 4] [--write]
Run in the sweep workspace (needs wip/vtargets_<target>.txt from tools/mkvtargets.py, wip/ver/<target>/syms.ld from tools/ver_sweep.py, versions/<source>/ with its manifest and src/).
For every `diff` / `lib` target of the target release (a unit of the 1.1 tree that its release does not reproduce) whose source release has matched C of the same unit name
(versions/<source>/src/<seg>/<name>.c) the source is compiled against the target ROM at the target's offset (tools/chk.py, whole object: `@all=<unit>`) with the flags of the
source release's manifest line.  EXACT units are listed; with --write they are added to versions/<target>/manifest.txt (target ROM offsets, `ro=` piece found in the target ROM)
and their sources copied to versions/<target>/src/.  The `new` targets (release-only functions named func_auto_<VRAM>) are not handled here: their names differ per release."""
import collections, concurrent.futures, os, re, shutil, subprocess, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ver_sweep import mode_flags, ROMS
args = [a for a in sys.argv[1:] if not a.startswith('--')]
T, S = args[0], args[1]
jobs = int(sys.argv[sys.argv.index('--jobs') + 1]) if '--jobs' in sys.argv else 4
rows = {}
for l in open(f'wip/vtargets_{T}.txt'):
    f = l.split()
    if len(f) >= 4 and f[3] in ('diff', 'lib'): rows[f[0]] = (int(f[1], 16), int(f[2]), f[3])
sman = {}
for l in open(f'versions/{S}/manifest.txt'):
    f = l.split('#')[0].split()
    if len(f) >= 4 and not f[0].startswith('pad_'): sman[f[0]] = f
tman = set()
if os.path.exists(f'versions/{T}/manifest.txt'):
    for l in open(f'versions/{T}/manifest.txt'):
        f = l.split('#')[0].split()
        if f: tman.add(f[0])
cands = []
for name, (rom, n, cls) in rows.items():
    f = sman.get(name)
    if not f or name in tman: continue
    seg = f[3]; p = f'versions/{S}/src/{seg}/{name}.c'
    if not os.path.exists(p): continue
    mode = ''
    for e in f[4:]:
        m = re.fullmatch(r'mode=([\w+]+)', e)
        if m: mode = m.group(1)
    cands.append((name, rom, n, seg, p, mode_flags(mode, seg), f))
print(len(cands), 'candidate units of', len(rows), 'diff/lib targets of', T)
if not cands: sys.exit(0)
os.makedirs(f'wip/ver/{T}', exist_ok=True)
lists = []
for k in range(jobs):
    p = f'wip/ver/{T}/casc_{k}.txt'
    open(p, 'w', newline='\n').write(''.join(f'{src} @all={name} 0x{rom:X} {fl}\n' for name, rom, n, seg, src, fl, f in cands[k::jobs]))
    lists.append(p)
env = f"CHK_ROM=/mnt/d/Projects/TurokRageWars/{ROMS[T]} CHK_SYMS=wip/ver/{T}/syms.ld"
def run(p):
    cmd = f"cd /mnt/d/Projects/TurokRageWars && rsync -a include/ ~/trw/include/ && rsync -a versions/ ~/trw/versions/ && {env} python3 tools/chk.py {p} 2>&1"
    return subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '-c', cmd], capture_output=True, text=True, env=dict(os.environ, MSYS_NO_PATHCONV='1')).stdout
res = {}
with concurrent.futures.ThreadPoolExecutor(jobs) as ex:
    for out in ex.map(run, lists):
        for l in out.split('\n'):
            m = re.match(r'(\w+)\s+(\d+) insns\s+(.*)', l)
            if m: res[m.group(1)] = (int(m.group(2)), m.group(3).strip())
ok = []; c = collections.Counter()
for name, rom, n, seg, src, fl, f in cands:
    r = res.get(name)
    if r and r[1].startswith('EXACT') and r[0] == n:
        ok.append((name, rom, n, seg, src, f, r[1])); c['EXACT'] += 1
    else:
        c['other'] += 1
        print('  not reusable:', name, (r[1][:90] if r else 'no result'))
print(dict(c))
if '--write' in sys.argv and ok:
    os.makedirs(f'versions/{T}/src', exist_ok=True)
    lines = open(f'versions/{T}/manifest.txt').read().rstrip('\n').split('\n') if os.path.exists(f'versions/{T}/manifest.txt') else []
    for name, rom, n, seg, src, f, st in ok:
        opts = [e for e in f[4:] if not e.startswith('ro=')]
        m = re.search(r'ro=(0x[0-9A-Fa-f]+):(\d+)', st)
        for e in f[4:]:                                                 # the source release's piece sizes (real size) carry over, its offset is the target's
            mm = re.fullmatch(r'ro=0x[0-9A-Fa-f]+:(\d+)(?::(\d+))?', e)
            if mm and m and int(mm.group(1)) == int(m.group(2)):
                opts.append(f'ro={m.group(1)}:{m.group(2)}' + (f':{mm.group(2)}' if mm.group(2) else ''))
        if m and not any(o.startswith('ro=') for o in opts): opts.append(f'ro={m.group(1)}:{(int(m.group(2)) + 3) & ~3}' + (f':{m.group(2)}' if int(m.group(2)) & 3 else ''))
        lines.append(f'{name} 0x{rom:X} {n} {seg}' + ''.join(' ' + o for o in opts))
        d = f'versions/{T}/src/{seg}'; os.makedirs(d, exist_ok=True); shutil.copyfile(src, f'{d}/{name}.c')
    open(f'versions/{T}/manifest.txt', 'w', newline='\n').write('\n'.join(l for l in lines if l.strip()) + '\n')
    print('written', len(ok), 'units to versions/%s/' % T)
