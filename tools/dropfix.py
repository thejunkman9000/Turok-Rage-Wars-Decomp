#!/usr/bin/env python3
"""After a bulk apply: loop cycle -> first differing ROM offset -> drop the function (code or its ro= piece) that owns it.
usage: python tools/dropfix.py [--max N]     handles funcs.txt (game) and funcs_a.txt (ovl_a) entries; dropped names go to wip/integrate_dropped.txt"""
import os, re, subprocess, sys
LIM = int(sys.argv[sys.argv.index('--max') + 1]) if '--max' in sys.argv else 40

def entries():
    out = []
    for fn, sub in (('funcs.txt', 'game'), ('funcs_a.txt', 'ovl_a')):
        for l in open(fn):
            f = l.split('#')[0].split()
            if len(f) < 4 or f[0].startswith('pad_') or f[3] not in ('game', 'ovl_a'): continue
            ro = None
            for e in f[4:]:
                m = re.fullmatch(r'ro=(0x[0-9A-Fa-f]+):(\d+)(?::(\d+))?', e)
                if m: ro = (int(m.group(1), 16), int(m.group(2)))
            out.append((f[0], int(f[1], 16), int(f[2]), f[3], fn, ro))
    return out

def drop(name):
    for fn in ('funcs.txt', 'funcs_a.txt'):
        L = open(fn).read().split('\n')
        L2 = [l for l in L if not (l.split('#')[0].split() and l.split('#')[0].split()[0] == name)]
        if L2 != L: open(fn, 'w', newline='\n').write('\n'.join(L2))
    for sub in ('game', 'ovl_a'):
        c = f'src/{sub}/{name}.c'
        if os.path.exists(c): os.remove(c)
    open('wip/integrate_dropped.txt', 'a').write(name + '\n')

dropped = []
for it in range(LIM):
    p = subprocess.run(['powershell', '-NoProfile', '-File', 'tools/cycle.ps1'], capture_output=True, text=True)
    out = p.stdout + p.stderr
    und = set(re.findall(r"undefined reference to `((?:func|D|jtbl)_[0-9A-Fa-f]{8})'", out))
    if und:                                        # symbols that used to be asm labels inside a range a ported function now covers
        open('wip/subsumed.txt', 'a').write(chr(10).join(sorted(und)) + chr(10)); print('aliasing', sorted(und)); continue
    if 'OK: byte-identical' in out:
        print('byte-identical after', len(dropped), 'drops:', dropped); break
    bad = set(re.findall(r'src/(?:game|ovl_a)/(\w+)\.c:\d+: (?:parse error|.*error|.*undeclared)', out)) | set(re.findall(r'build/src/(?:game|ovl_a)/(\w+)\.o\]', out))
    for m in re.finditer(r"multiple definition of `(\w+)'; build/src/(?:game|ovl_a)/(\w+)\.o", out): bad.add(m.group(2))
    es = {e[0]: e for e in entries()}
    bad = {b for b in bad if b in es}
    if bad:
        for b in bad: drop(b); dropped.append(b)
        print('dropped (build errors):', sorted(bad)); continue
    q = subprocess.run(['wsl', '-d', 'Ubuntu-24.04', '--', 'bash', '/mnt/d/Projects/TurokRageWars/tools/firstdiff.sh', '0x1001'], capture_output=True, text=True)
    offs = [int(x, 16) for x in q.stdout.split()]
    if not offs: print('no diff offsets', out[-400:]); break
    off = offs[0]
    hit = [e for e in entries() if e[1] <= off < e[1] + 4 * e[2]] or [e for e in entries() if e[5] and e[5][0] <= off < e[5][0] + e[5][1] + 16]
    if not hit:                                    # nearest preceding rodata piece / function
        prev = [e for e in entries() if e[5] and e[5][0] <= off] + [e for e in entries() if e[1] <= off]
        hit = [max(prev, key=lambda e: (e[5][0] if e[5] and e[5][0] <= off else e[1]))] if prev else []
    if not hit: print('cannot attribute', hex(off)); break
    print('dropping', hit[0][0], 'first diff', hex(off)); drop(hit[0][0]); dropped.append(hit[0][0])
