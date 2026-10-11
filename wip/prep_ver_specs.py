#!/usr/bin/env python3
"""Stage EU/DE worker results for tools/integrate.py --version: rename func_auto_ units to their release VRAM (some workers named them by ROM offset),
keep only NEW rows whose function results.txt calls EXACT (pad rows are kept), copy sources + include/ into wip/stage/<ws>/ and write wip/stage/<ws>.spec.
usage: python wip/prep_ver_specs.py <eu|de> <ws> [<ws> ...]"""
import os, re, shutil, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
OVL = {'eu': 0x176000, 'de': 0x166000, 'us': 0x164000}

def vram(rom, seg, ver):
    if seg == 'ovl_a': return rom - OVL[ver] + 0x400000
    return rom - 0x1000 + 0x200400

def main():
    ver, wss = sys.argv[1], sys.argv[2:]
    for ws in wss:
        src = f'D:/Projects/ws/{ws}'
        res = open(f'{src}/wip/out/results.txt', encoding='utf-8', errors='replace').read()
        exact = {l.split()[0] for l in res.split('\n') if len(l.split()) > 3 and l.split()[3] == 'EXACT'}
        st = f'wip/stage/{ws}'
        shutil.rmtree(st, ignore_errors=True); os.makedirs(f'{st}/wip/out')
        if os.path.isdir(f'{src}/include'): shutil.copytree(f'{src}/include', f'{st}/include')
        out = [f'ws {os.path.abspath(st)}']; ren = {}
        for l in open(f'{src}/wip/out/manifest.txt', encoding='utf-8', errors='replace'):
            f = l.split('#')[0].split()
            if len(f) < 5 or f[0] not in ('NEW', 'PAD'): continue
            name, rom, n, seg = f[1], int(f[2], 16), int(f[3]), f[4]
            if seg not in ('game', 'ovl_a', 'libultra'): print(ws, 'bad segment, skipped:', l.strip()); continue
            if name.startswith('pad_'): out.append(' '.join(f)); continue
            if name not in exact: print(ws, 'not EXACT in results, skipped:', name); continue
            new = name
            if name.startswith('func_auto_'):
                new = 'func_auto_%08X' % vram(rom, seg, ver)
                if new != name: ren[name] = new
            p = f'{src}/wip/out/{name}.c'
            if not os.path.exists(p): print(ws, 'no source, skipped:', name); continue
            t = open(p, encoding='utf-8', errors='replace').read()
            for a, b in ren.items(): t = re.sub(r'\b%s\b' % a, b, t)
            open(f'{st}/wip/out/{new}.c', 'w', encoding='utf-8', newline='\n').write(t)
            out.append(' '.join(['NEW', new] + f[2:]))
        if ren: print(ws, 'renamed:', ', '.join(f'{a}->{b}' for a, b in ren.items()))
        open(f'wip/stage/{ws}.spec', 'w', newline='\n').write('\n'.join(out) + '\n')
        print(ws, len(out) - 1, 'rows staged')

if __name__ == '__main__': main()
