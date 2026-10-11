#!/usr/bin/env python3
"""Integrate an agent's results into the main tree from a manifest-change spec (the `NEW` lines of an agent's wip/out/manifest.txt, or a hand-written one).

usage: python tools/integrate.py <spec file> [--ws <agent workspace>] [--version us|eu|de] [--dry]
Spec lines (everything after '#' is a comment):
  ws <dir>                                      agent workspace (also given by --ws): its wip/out/<name>.c are the sources, its include/*.h the new headers
  NEW <name> <rom hex> <insns> <seg> [opts...]  a manifest entry in final form (seg: game | ovl_a | libultra).  Every existing entry that overlaps its ROM range is replaced.
  OLD <name> ...                                informational (the old entry; the overlap rule removes it), checked: it must exist
  DEL <name>                                    remove an entry without a replacement (e.g. a duplicate)
  PAD <name> <rom hex> <words> <seg>            same as NEW for pad_* entries (the pad .s is written from the ROM)
The tool then: writes funcs.txt / funcs_a.txt (entries keep their order, new ones are appended), checks that the replaced ROM ranges are still covered exactly (no hole, no
growth), copies the C sources of the new non-pad entries to src/<seg>/ and writes pad_*.s for new pad entries, removes the sources of entries that disappeared, adds the new
function entries to docs/game_funcs.txt and copies new/changed headers (never common.h / libaudio.h / macro.inc).  Run tools/gen_yaml.py + tools/cycle.ps1 afterwards.

--version <ver>: the results are specific to ANOTHER RELEASE (ROM offsets of that release).  Entries go to versions/<ver>/manifest.txt (one file for both segments), sources and pad
units to versions/<ver>/src/<seg>/, new headers to include/ (shared).  tools/mkver.py merges that directory into the release workspace; the main manifests and docs are not touched."""
import os, re, shutil, struct, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
args = sys.argv[1:]
dry = '--dry' in args
ws = args[args.index('--ws') + 1] if '--ws' in args else None
version = args[args.index('--version') + 1] if '--version' in args else None
spec = [a for i, a in enumerate(args) if not a.startswith('--') and (i == 0 or args[i - 1] not in ('--ws', '--version'))][0]
SEGDIR = {'game': 'game', 'ovl_a': 'ovl_a', 'libultra': 'libultra'}
ROMS = {None: 'baserom.us.v11.z64', 'us': 'baserom.us.v10.z64', 'eu': 'baserom.eu.z64', 'de': 'baserom.de.z64'}
VDIR = f'versions/{version}' if version else None

def read(fn): return open(fn, encoding='utf-8', newline='').read().replace('\r\n', '\n')
def parse(l):
    f = l.split('#')[0].split()
    return f if len(f) >= 4 else None
def manifest_of(seg): return 'V' if version else ('funcs_a.txt' if seg == 'ovl_a' else 'funcs.txt')
def mpath(key): return f'{VDIR}/manifest.txt' if key == 'V' else key
def srcdir(sd): return f'{VDIR}/src/{sd}' if version else f'src/{sd}'

if version:
    os.makedirs(VDIR, exist_ok=True)
    lines = {'V': read(mpath('V')).rstrip('\n').split('\n') if os.path.exists(mpath('V')) else []}
    lines['V'] = [l for l in lines['V'] if l.strip() or False]
else:
    lines = {fn: read(fn).rstrip('\n').split('\n') for fn in ('funcs.txt', 'funcs_a.txt')}
news = []; olds = []; dels = []
for l in read(spec).split('\n'):
    t = l.split('#')[0].strip()
    if not t: continue
    f = t.split()
    if f[0] == 'ws': ws = ws or f[1]; continue
    if f[0] in ('NEW', 'PAD'): news.append(f[1:])
    elif f[0] == 'OLD': olds.append(f[1:])
    elif f[0] == 'DEL': dels.append(f[1])
    else: print('spec line ignored:', l); continue
rom = open(ROMS[version], 'rb').read()

def existing():
    out = []
    for fn in lines:
        for i, l in enumerate(lines[fn]):
            f = parse(l)
            if f: out.append((int(f[1], 16), int(f[2]), f[0], fn, i))
    return out

removed = []                                          # (rom, insns, name, file) of every replaced / deleted entry
for o in olds:
    if not any(e[2] == o[0] for e in existing()): print('OLD entry not found (already integrated?):', o[0])
for name in dels:
    for r, n, nm, fn, i in existing():
        if nm == name: lines[fn][i] = None; removed.append((r, n, nm, fn))
    for fn in lines: lines[fn] = [l for l in lines[fn] if l is not None]
added = []
for e in news:
    name, r, n, seg = e[0], int(e[1], 16), int(e[2]), e[3]
    fn = manifest_of(seg)
    for r2, n2, nm2, fn2, i2 in existing():
        if fn2 == fn and r2 < r + 4 * n and r < r2 + 4 * n2:
            if nm2 == name and r2 == r and n2 == n:
                print('entry updated in place:', name)
            lines[fn2][i2] = None; removed.append((r2, n2, nm2, fn2))
    lines[fn] = [l for l in lines[fn] if l is not None]
    lines[fn].append(' '.join(e)); added.append((r, n, name, fn, e))
# coverage: the ROM ranges that the replaced entries covered (minus the ones that were re-added identically) must be covered by the new entries exactly
for fn in lines:
    old = set(); new = set()
    for r, n, nm, f2 in removed:
        if f2 == fn: old.update(range(r, r + 4 * n, 4))
    for r, n, nm, f2, e in added:
        if f2 == fn: new.update(range(r, r + 4 * n, 4))
    for w in sorted(old - new)[:3]: print('HOLE in', mpath(fn), 'at', hex(w), '(covered by a replaced entry, not by a new one)')
    if not version:
        for w in sorted(new - old)[:3]: print('GROWTH in', fn, 'at', hex(w), '(covered by a new entry, not by a replaced one)')
# overlap check of the whole manifest
for fn in lines:
    ents = sorted((int(parse(l)[1], 16), int(parse(l)[2]), parse(l)[0]) for l in lines[fn] if parse(l))
    for (r1, n1, a), (r2, n2, b) in zip(ents, ents[1:]):
        if r1 + 4 * n1 > r2: print('OVERLAP', mpath(fn), a, hex(r1), n1, 'and', b, hex(r2))
names_after = {parse(l)[0] for fn in lines for l in lines[fn] if parse(l)}
if not dry:
    for fn in lines: open(mpath(fn), 'w', encoding='utf-8', newline='\n').write('\n'.join(lines[fn]) + '\n')
# ---- sources
for r, n, nm, fn in removed:
    if nm in names_after: continue
    for sd in SEGDIR.values():
        for ext in ('.c', '.s'):
            p = f'{srcdir(sd)}/{nm}{ext}'
            if os.path.exists(p):
                print('remove', p)
                if not dry: os.remove(p)
for r, n, name, fn, e in added:
    seg = e[3]; sd = SEGDIR[seg]
    if name.startswith('pad_'):
        out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '', f'/* linker padding: stray words between objects, ROM 0x{r:X} */', f'glabel pad_{r:06X}']
        for k in range(n): out.append('    /* %X */  .word      0x%08X' % (r + 4 * k, struct.unpack('>I', rom[r + 4 * k:r + 4 * k + 4])[0]))
        out.append(f'endlabel pad_{r:06X}')
        assert name == 'pad_%06X' % r, name
        p = f'{srcdir(sd)}/{name}.s'
        if not dry: os.makedirs(os.path.dirname(p), exist_ok=True); open(p, 'w', newline='\n').write('\n'.join(out) + '\n')
        print('pad', p, n, 'words')
        continue
    src = f'{ws}/wip/out/{name}.c'
    if not os.path.exists(src) and os.path.exists(f'{ws}/wip/out/units/{name}.s'):      # a hand-written assembly unit of the original (not C): its .s is the source
        t = read(f'{ws}/wip/out/units/{name}.s')
        if not dry: os.makedirs(srcdir(sd), exist_ok=True); open(f'{srcdir(sd)}/{name}.s', 'w', encoding='utf-8', newline='\n').write(t)
        print('hand-written unit', f'{srcdir(sd)}/{name}.s')
        if not version:
            ha = read('docs/hand_asm.txt')
            if not re.search(r'(?m)^' + re.escape(name) + r'\b', ha) and not dry:
                open('docs/hand_asm.txt', 'w', newline='\n').write(ha.rstrip('\n') + f'\n{name}   # {e[3]} hand-written assembly (agent {os.path.basename(ws)})\n')
        continue
    if not os.path.exists(src): print('MISSING SOURCE', src); continue
    t = read(src)
    if not dry: os.makedirs(srcdir(sd), exist_ok=True); open(f'{srcdir(sd)}/{name}.c', 'w', encoding='utf-8', newline='\n').write(t)
    print('source', f'{srcdir(sd)}/{name}.c')
    if not version and os.path.exists(f'src/{sd}/{name}.s'):      # the unit was an assembly placeholder: the C file replaces it
        print('remove', f'src/{sd}/{name}.s')
        if not dry: os.remove(f'src/{sd}/{name}.s')
# ---- docs/game_funcs.txt: new function entries of game / ovl_a (the US v1.1 universe only)
if not version:
    gl = read('docs/game_funcs.txt').rstrip('\n').split('\n')
    have = {int(l.split()[0], 16): l for l in gl if l.strip() and not l.startswith('#')}
    nadd = 0
    starts_ = sorted(have)
    for r, n, name, fn, e in added:
        if name.startswith('pad_') or e[3] == 'libultra': continue
        if r in have:                                             # the row exists: carry a longer function over when no other row starts inside it
            f = have[r].split()
            if f[1] == name and int(f[2]) != n and not any(r < s < r + 4 * n for s in starts_):
                gl[gl.index(have[r])] = '0x%06X %s %d %s' % (r, name, n, ' '.join(f[3:])); nadd += 1
            continue
        gl.append('0x%06X %s %d 0 0 ' % (r, name, n)); nadd += 1
    if nadd and not dry:
        head = [l for l in gl if l.startswith('#')]; body = sorted((l for l in gl if l.strip() and not l.startswith('#')), key=lambda l: int(l.split()[0], 16))
        open('docs/game_funcs.txt', 'w', newline='\n').write('\n'.join(head + body) + '\n')
    print('docs/game_funcs.txt: added', nadd)
# ---- headers
if ws and os.path.isdir(f'{ws}/include'):
    for h in sorted(os.listdir(f'{ws}/include')):
        if not h.endswith('.h') or h in ('common.h', 'libaudio.h', 'macro.inc'): continue
        a, b = f'{ws}/include/{h}', f'include/{h}'
        if not os.path.exists(b) or open(a, 'rb').read() != open(b, 'rb').read():
            if os.path.exists(b) and version: print('header differs from the shared one, NOT copied (a release must not change a shared header):', h); continue
            if os.path.exists(b) and os.path.getmtime(a) < os.path.getmtime(b): print('header older than the project copy, kept:', h); continue
            if not dry: shutil.copyfile(a, b)
            print('header', h)
print('done' + (' (dry run)' if dry else ''))
