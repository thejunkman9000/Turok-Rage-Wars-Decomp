#!/usr/bin/env python3
"""Integrate a worker's results and make the build byte-identical again, dropping functions that break it.

usage: python tools/integrate.py <ws dir> [--game|--ovl]
1. tools/apply_results.py (new manifest entries / C files)   2. tools/cycle.ps1   3. on MISMATCH find the function that
contains the first differing ROM offset, drop it again (manifest entry + its .c, pad entries stay valid) and repeat.
Dropped functions are listed in wip/integrate_dropped.txt (retry them by hand)."""
import subprocess, sys, re, os
ws = sys.argv[1]
flag = [a for a in sys.argv[2:] if a in ('--game', '--ovl')]
game = '--game' in flag; ovl = '--ovl' in flag
manifest = 'funcs_a.txt' if ovl else 'funcs.txt'
sub = 'game' if game else ('ovl_a' if ovl else 'libultra')
before = {l.split()[0] for l in open(manifest) if l.strip() and not l.startswith('#')}
r = subprocess.run([sys.executable, 'tools/apply_results.py', ws] + flag, capture_output=True, text=True)
print(r.stdout[-400:], r.stderr[-400:])
after = [l for l in open(manifest).read().split('\n') if l.strip()]
applied = {l.split()[0] for l in after if l.split()[0] not in before or True}
def entries():
    out = []
    for l in open(manifest):
        f = l.split('#')[0].split()
        if len(f) >= 4: out.append((f[0], int(f[1], 16), int(f[2]), f[3], l.rstrip('\n')))
    return out
cand = {n for n, _, _, s, _ in entries() if s == sub and not n.startswith('pad_')} 
dropped = []
for it in range(40):
    p = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/cycle.ps1'], capture_output=True, text=True)
    out = p.stdout + p.stderr
    if 'OK: byte-identical' in out:
        print('byte-identical after', it, 'drops'); break
    bad = set(re.findall(r'src/' + sub + r'/(\w+)\.c:\d+: (?:parse error|.*error|.*undeclared)', out)) | set(re.findall(r'build/src/' + sub + r'/(\w+)\.o\]', out))
    for m in re.finditer(r'src/' + sub + r'/(\w+)\.c:\(\.text[^)]*\): multiple definition of `\w+\'; build/src/' + sub + r'/(\w+)\.o:', out):
        bad.update(m.groups())
    bad = {b for b in bad if b in cand}
    if bad:
        ls = open(manifest).read().split(chr(10))
        ls = [l for l in ls if not (l.split('#')[0].split() and l.split('#')[0].split()[0] in bad)]
        open(manifest, 'w', newline=chr(10)).write(chr(10).join(ls))
        for b in bad:
            c = f'src/{sub}/{b}.c'
            if os.path.exists(c): os.remove(c)
            cand.discard(b); dropped.append(b)
        print('dropped (compile errors):', sorted(bad)); continue
    if 'undefined reference' in out:
        print(out[-1500:]); print('link error; stopping'); break
    q = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '/mnt/d/Projects/TurokRageWars/tools/firstdiff.sh', '0x1001'], capture_output=True, text=True)
    offs = [int(x, 16) for x in q.stdout.split()]
    if not offs: print('no diff offsets?', out[-500:]); break
    off = offs[0]
    es = [e for e in entries() if e[3] == sub and not e[0].startswith('pad_') and e[0] in cand]
    hit = [e for e in es if e[1] <= off < e[1] + 4 * e[2]]
    if not hit:
        sc = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '/mnt/d/Projects/TurokRageWars/tools/symcheck2.sh'], capture_output=True, text=True)
        rows = [l.split() for l in sc.stdout.split(chr(10)) if l.strip()]
        if rows:
            va = int(rows[0][0], 16) if False else int(rows[0][2], 16)       # expected address of the lowest displaced symbol
            rom_dev = (va - 0x1FF400) if va < 0x400000 else None
            prev = [e for e in es if rom_dev is not None and e[1] + 4 * e[2] <= rom_dev + 0x40 and e[1] < rom_dev]
            hit = [max(prev, key=lambda e: e[1])] if prev else []
    if not hit:
        prev = [e for e in es if e[1] <= off]
        hit = [max(prev, key=lambda e: e[1])] if prev else []
    if not hit: print('cannot attribute offset', hex(off)); break
    name = hit[0][0]
    print('dropping', name, 'first diff', hex(off))
    ls = open(manifest).read().split('\n')
    ls = [l for l in ls if not (l.split('#')[0].split() and l.split('#')[0].split()[0] == name)]
    open(manifest, 'w', newline='\n').write('\n'.join(ls))
    c = f'src/{sub}/{name}.c'
    if os.path.exists(c): os.remove(c)
    dropped.append(name); cand.discard(name)
open('wip/integrate_dropped.txt', 'a').write('\n'.join(dropped) + ('\n' if dropped else ''))
print('dropped:', dropped)
