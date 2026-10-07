#!/usr/bin/env python3
"""Integrate a worker's results into the main tree.

usage: python tools/apply_results.py <workspace dir> [--game] [--ovl] [--dry]
Reads <ws>/wip/out/results.txt; for every EXACT line copies <ws>/wip/out/<fn>.c to src/<subdir>/ (libultra by default,
ovl_a with --ovl, game with --game), copies new headers (include/*_types.h not yet present), and updates the manifest:
 - hasm function present in the manifest (libultra/ovl): tools/to_c.py semantics (pad from ROM words after the C insns)
 - --game: new manifest entry  <fn> <rom> <insns> game  (+pad entry if the splat function is longer than the C code)
Compile mode from the `flags:` text: -msplit-addresses -> lu4; `-O2 -mcpu=r4300` -> lu3; `-O2 -fforce-addr` -> lu2; default -> lu.
Run tools/cycle.ps1 afterwards; fix whatever it reports."""
import re, sys, os, shutil, struct, subprocess
ws = sys.argv[1]
ovlgame = '--ovlgame' in sys.argv      # game-style results for overlay A functions (func_004xxxxx): manifest funcs_a.txt, src/ovl_a
game = '--game' in sys.argv or ovlgame
ovl = '--ovl' in sys.argv
dry = '--dry' in sys.argv
sub = 'ovl_a' if ovlgame else ('game' if game else ('ovl_a' if ovl else 'libultra'))
manifest = 'funcs_a.txt' if (ovl or ovlgame) else 'funcs.txt'
rom = open('baserom.us.v11.z64', 'rb').read()
gf = {}
if game:
    for l in open('docs/game_funcs.txt'):
        if l.startswith('#'): continue
        f = l.split(); gf[f[1]] = (int(f[0], 16), int(f[2]))
os.makedirs(f'src/{sub}', exist_ok=True)
for h in os.listdir(f'{ws}/include'):
    if h.endswith('_types.h'):
        a, b = f'{ws}/include/{h}', f'include/{h}'
        if not os.path.exists(b) or (os.path.getmtime(a) > os.path.getmtime(b) and open(a, 'rb').read() != open(b, 'rb').read()):
            shutil.copy(a, b); print('header updated:', h)
n_over = dict(l.split() for l in open('wip/n_overrides.txt')) if os.path.exists('wip/n_overrides.txt') else {}
n_over = {k: int(v) for k, v in n_over.items()}
ro_over = dict(l.split() for l in open('wip/ro_overrides.txt')) if os.path.exists('wip/ro_overrides.txt') else {}
start_over = dict(l.split() for l in open('wip/start_overrides.txt')) if os.path.exists('wip/start_overrides.txt') else {}
mode_over = dict(l.split() for l in open('wip/mode_overrides.txt')) if os.path.exists('wip/mode_overrides.txt') else {}
excluded = set(open('wip/groups_excluded.txt').read().split()) if os.path.exists('wip/groups_excluded.txt') else set()
def r_special(l):
    """extra build flags a result line asks for, as a '+tok' suffix for the manifest mode"""
    t = ''
    body = l.split('#', 1)[1] if '#' in l else ''
    if '-fno-builtin' in l and 'does not need' not in body: t += '+nb'
    if '-fno-thread-jumps' in l: t += '+ntj'
    if 'NOFILL' in l: t += '+nf'
    if 'luret' in l or 'bare `j $31` keeps nop' in l: t += '+luret'
    if 'without -mcpu' in l or 'plain -O2' in l: t += '+o2'
    return t
lines = open(manifest).read().split('\n')
have = {l.split('#')[0].split()[0]: i for i, l in enumerate(lines) if l.split('#')[0].split()}
todo = []
for l in open(f'{ws}/wip/out/results.txt'):
    f = l.split('#')[0].split()
    if len(f) < 4 or f[3] != 'EXACT': continue
    if 'gcc 2.7' in l or '-msplit-addresses' in l or 'low-region' in l:
        print('skipping (special compiler):', f[0]); continue
    fn, r, n = f[0], int(f[1], 16), int(f[2])
    if fn in start_over: r = int(start_over[fn], 16)
    ro = [t for t in f[4:] if t.startswith('ro=')]
    if fn in ro_over: ro = [ro_over[fn]]
    fl = ' '.join(f[4:])
    if '-msplit-addresses' in fl: mode = 'lu4'
    elif '-fforce-addr' in fl and '-O2' in fl: mode = 'lu2'
    elif '-O2' in fl and '-mcpu=r4300' in fl: mode = 'lu3'
    else: mode = 'lu'
    if game:
        mode = ''
        if r_special(l): mode = 'lu3' + r_special(l)
        if fn in mode_over: mode = mode_over[fn]
    todo.append((fn, r, n, ro, mode))
absorbed = set(open('wip/absorbed.txt').read().split()) if os.path.exists('wip/absorbed.txt') else set()
# several results whose source file is one and the same combined file defining all of them = one multi-function object
# (gcc 'inline' deferral, shared literal pool): the primary (lowest ROM) keeps the file, the others are absorbed; the
# build then reports the object as longer than the manifest count and tools/fix_short_objs.py extends it.
def _defines(txt, nm):
    return re.search(r'^[A-Za-z_][^;{}]*[ *]' + nm + r'\s*\([^;{}]*\)\s*\{', txt, re.M) is not None
_by = {}
for t in todo:
    sp = f'{ws}/wip/out/{t[0]}.c'
    if os.path.exists(sp): _by.setdefault(open(sp, errors='replace').read(), []).append(t)
grouped = set()
for txt, ts in _by.items():
    mem = [t for t in ts if _defines(txt, t[0])]
    if len(mem) > 1:
        mem.sort(key=lambda t: t[1])
        for t in mem[1:]:
            grouped.add(t[0]); absorbed.add(t[0])
        grouped.add(mem[0][0])
        print('group object:', mem[0][0], '+', [t[0] for t in mem[1:]])
if not dry and absorbed: open('wip/absorbed.txt', 'w').write(chr(10).join(sorted(absorbed)) + chr(10))
todo = [t for t in todo if t[0] not in absorbed and (t[0] not in excluded or t[0] in grouped)]
def padfile(a, n):
    words = [(a + 4 * k, '%08X' % struct.unpack('>I', rom[a + 4 * k:a + 4 * k + 4])[0]) for k in range(n)]
    out = ['.include "macro.inc"', '', '.set noat', '.set noreorder', '', '.section .text, "ax"', '',
           f'/* linker padding: stray words between objects, ROM 0x{a:X} */', f'glabel pad_{a:06X}']
    for r, w in words: out.append(f'    /* {r:X} */  .word      0x{w}')
    out.append(f'endlabel pad_{a:06X}')
    if not dry: open(f'src/{sub}/pad_{a:06X}.s', 'w', newline='\n').write('\n'.join(out) + '\n')
new = []
for fn, r, n, ro, mode in todo:
    src = f'{ws}/wip/out/{fn}.c'
    if not os.path.exists(src): print('missing', src); continue
    if game:
        if fn not in gf: print('not a game function:', fn); continue
        r0, total = gf[fn]
        if r > r0 and (r - r0) % 4 == 0 and (r - r0) // 4 < total:
            k = (r - r0) // 4              # leading stray words before the real function start
            new.append(f'pad_{r0:06X} 0x{r0:X} {k} {sub}'); padfile(r0, k)
            r0, total = r, total - k
        if fn in n_over: n = n_over[fn]
        if fn != 'func_0024E2B4': n = min(n, total)           # chk may count the next object's first words (infinite-loop tails)
        opts = ' '.join(ro)
        entry = f'{fn} 0x{r0:X} {n} {sub}' + (' ' + opts if opts else '') + (f' mode={mode}' if mode else '')
        if fn in have: lines[have[fn]] = entry
        else: new.append(entry)
        if n < total:
            a = r0 + 4 * n
            new.append(f'pad_{a:06X} 0x{a:X} {total - n} {sub}'); padfile(a, total - n)
    else:
        if fn not in have: print('not in manifest:', fn); continue
        f = lines[have[fn]].split()
        start, total = int(f[1], 16), int(f[2])
        extra = [t for t in f[4:] if not t.startswith('mode=')] if len(f) > 4 else []
        extra = [t for t in extra if not (t.startswith('ro=') and ro)] + ro
        if mode: extra.append(f'mode={mode}')
        lines[have[fn]] = ' '.join([fn, f'0x{start:X}', str(n), sub] + extra)
        if n < total:
            a = start + 4 * n
            new.append(f'pad_{a:06X} 0x{a:X} {total - n} {sub}'); padfile(a, total - n)
        p = f'src/{sub}/{fn}.s'
        if os.path.exists(p) and not dry: os.remove(p)
    if not dry: shutil.copy(src, f'src/{sub}/{fn}.c')
have_names = set(have)
uniq = []
for e in new:
    nm = e.split()[0]
    if nm in have_names: continue
    have_names.add(nm); uniq.append(e)
new = uniq
lines += new
# overlapping ro= pieces (a worker's piece may run into the next function's literals): truncate at the next piece.
# Pieces of funcs.txt and funcs_a.txt share the main image's data area, so look at both manifests.
other = 'funcs_a.txt' if manifest == 'funcs.txt' else 'funcs.txt'
olines = open(other).read().split(chr(10)) if os.path.exists(other) else []
ros = []
for tag, ls in ((0, lines), (1, olines)):
    for i, l in enumerate(ls):
        for t in l.split('#')[0].split()[4:]:
            m = re.fullmatch(r'ro=0x([0-9A-Fa-f]+):(\d+)', t)
            if m: ros.append((int(m.group(1), 16), int(m.group(2)), tag, i, t))
ros.sort()
changed_other = False
for a, b in zip(ros, ros[1:]):
    if a[0] + a[1] > b[0]:
        tgt = lines if a[2] == 0 else olines
        tgt[a[3]] = tgt[a[3]].replace(a[4], f'ro=0x{a[0]:X}:{b[0] - a[0]}')
        if a[2] == 1: changed_other = True
if changed_other and not dry: open(other, 'w', newline=chr(10)).write(chr(10).join(olines).rstrip(chr(10)) + chr(10))
# a function whose chk count runs into the next function (e.g. ends in an infinite loop): shrink it
ents = []
for i, l in enumerate(lines):
    f = l.split('#')[0].split()
    if len(f) >= 4 and f[3] == sub:
        ents.append((int(f[1], 16), i))
ents.sort()
for (ra, ia), (rb, ib) in zip(ents, ents[1:]):
    f = lines[ia].split()
    if ra + 4 * int(f[2]) > rb and rb > ra:
        f[2] = str((rb - ra) // 4); lines[ia] = ' '.join(f)
if not dry: open(manifest, 'w', newline='\n').write('\n'.join(lines).rstrip('\n') + '\n')
print(len(todo), 'exact results processed;', len(new), 'new manifest lines')
