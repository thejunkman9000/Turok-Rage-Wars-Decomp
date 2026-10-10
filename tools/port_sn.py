#!/usr/bin/env python3
"""Integrate agent results that match only under the sn toolchain (flags field carries @SN / @SN272 and -m*/-f*/@EPI tokens).

usage: python tools/port_sn.py <workspace dir> [--dry]
 results line: <fn> <rom hex> <insns> EXACT [ro=0xROM:size] <flags...> # note ;  C file: <ws>/wip/out/<fn>.c
 manifest mode:  sn272 | sn[+sa][+r4k][+epi][+nb]   (@SN272 -> sn272; -msplit-addresses -> +sa; -mcpu=r4000 -> +r4k; @EPI -> +epi; -fno-builtin -> +nb)
 entries overlapping an existing manifest entry (or an existing ro= piece) are skipped and reported."""
import os, re, shutil, sys
ws = sys.argv[1]; dry = '--dry' in sys.argv
def load(fn):
    out = []
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4: r = int(f[1], 16); out.append((r, r + 4 * int(f[2]), f[0]))
    return out
existing = load('funcs.txt') + load('funcs_a.txt')
SKIP = set(open('wip/port_skip.txt').read().split()) if os.path.exists('wip/port_skip.txt') else set()
rodat = []
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        for m in re.finditer(r'ro=(0x[0-9A-Fa-f]+):(\d+)', l.split('#')[0]): rodat.append((int(m.group(1), 16), int(m.group(1), 16) + int(m.group(2)), l.split()[0]))
add = {'funcs.txt': [], 'funcs_a.txt': []}; skipped = []
seen = {}                      # source text -> (manifest file, index, end rom): group files (several functions, one file) become ONE entry
for l in open(f'{ws}/wip/out/results.txt', errors='replace'):
    body = l.split('#')[0].split()
    if len(body) < 4 or body[3] != 'EXACT' or not body[0].startswith('func_'): continue
    name, rom, n = body[0], int(body[1], 16), int(body[2]); rest = body[4:]
    note = l.split('#', 1)[1] if '#' in l else ''
    mm = re.search(r'flags:\s*((?:[@-]\S+[ 	]*)+)', note)
    if mm: rest += [t.rstrip('.,;') for t in mm.group(1).split()]
    rest = [t.strip('[]') for t in rest]                                                                  # `[flags: @SN -fno-builtin]` spelling of some workers
    rest = [u for t in rest for u in ((t, t.split('=', 1)[1]) if t.startswith('flags=') else (t,))]       # `flags=@SN` spelling of some workers
    if not any(t in ('@SN', '@SN272') for t in rest): continue
    if name in SKIP: skipped.append((name, 'port_skip')); continue
    ro = next((t for t in rest if t.startswith('ro=')), None)
    src = f'{ws}/wip/out/{name}.c'
    if not os.path.exists(src): skipped.append((name, 'no source')); continue
    txt = open(src, errors='replace').read()
    if txt in seen:
        mf, ix, end = seen[txt]
        if end == rom:                                   # next function of the same file: extend the first entry
            f = add[mf][ix].split(); f[2] = str(int(f[2]) + n); add[mf][ix] = ' '.join(f)
            seen[txt] = (mf, ix, rom + 4 * n); existing.append((rom, rom + 4 * n, name))
        else: skipped.append((name, 'same file as an earlier entry, not contiguous'))
        continue
    clash = [e for e in existing if e[0] < rom + 4 * n and rom < e[1]]
    if clash: skipped.append((name, 'overlaps ' + clash[0][2])); continue
    if ro:
        o = int(ro.split(':')[0][3:], 16); sz = int(ro.split(':')[1].split(':')[0])
        rc = [r for r in rodat if r[0] < o + sz and o < r[1]]
        if rc: skipped.append((name, 'rodata overlaps ' + rc[0][2])); continue
        rodat.append((o, o + sz, name))
    if '@SN272' in rest: mode = 'sn272'
    else:
        mode = 'sn'
        if '-msplit-addresses' in rest: mode += '+sa'
        if '-mcpu=r4000' in rest: mode += '+r4k'
        if '@EPI' in rest: mode += '+epi'
    if '-fno-builtin' in rest: mode += '+nb'
    if '-fno-thread-jumps' in rest: mode += '+ntj'
    if '-fno-rerun-cse-after-loop' in rest: mode += '+nrc'
    if '-fno-expensive-optimizations' in rest: mode += '+neo'
    if '-fno-strength-reduce' in rest: mode += '+nsr'
    ovl = rom >= 0x16E000
    sub = 'ovl_a' if ovl else 'game'
    add['funcs_a.txt' if ovl else 'funcs.txt'].append(f'{name} 0x{rom:X} {n} {sub} mode={mode}' + (f' {ro}' if ro else ''))
    seen[txt] = ('funcs_a.txt' if ovl else 'funcs.txt', len(add['funcs_a.txt' if ovl else 'funcs.txt']) - 1, rom + 4 * n)
    existing.append((rom, rom + 4 * n, name))
    if not dry:
        shutil.copy(src, f'src/{sub}/{name}.c')
        for h in os.listdir(f'{ws}/include'):
            if h.endswith('_types.h') and not os.path.exists(f'include/{h}') and h in open(src, errors='replace').read(): shutil.copy(f'{ws}/include/{h}', f'include/{h}')
for fn, lines in add.items():
    if lines and not dry:
        t = open(fn).read()
        open(fn, 'w', newline='\n').write(t.rstrip('\n') + '\n' + '\n'.join(lines) + '\n')
print('added', sum(len(v) for v in add.values()), 'skipped', len(skipped))
for s in skipped: print('  skip', *s)
