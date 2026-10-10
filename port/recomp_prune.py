#!/usr/bin/env python3
"""Drop from port/recomp.txt every function that matched C already defines under the other decompilation's name.

recomp_select.py recompiles every asm-index function that is not a manifest entry.  A function that our old split had as a small
fragment (func_00220A5C) is part of a bigger ported source now: the C defines it under their name (func_8021F5BC_de ...), the ROM link
aliases our name to it (their_syms.ld / their_alias.ld) and gen_syms.py does the same for the port - but a recompiled twin
`func_00220A5C` would be defined too and, linking first (ar_ objects sort before the C), shadow the matched C.  The twin is the weaker
choice (struct-by-value arguments, float conventions); the C is what the old port used for these functions.

usage: python port/recomp_prune.py   (after recomp_select.py, before gen_recomp.py)"""
import glob, os, re, sys
os.chdir(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

DEF = re.compile(r'^[\w][\w\s\*]*?\b(func_[0-9A-Fa-f]{8}_\w+|[A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*\{', re.M)

def main():
    their = {}
    for m in re.finditer(r'^PROVIDE\((\w+) = 0x(00[0-9A-Fa-f]{6})\);', open('their_syms.ld').read(), re.M): their[m.group(1)] = int(m.group(2), 16)
    cskip = set(open('port/c_skip.txt').read().split()) if os.path.exists('port/c_skip.txt') else set()
    overrides = {os.path.basename(p)[:-2] for p in glob.glob('port/overrides/*.c')}
    covered = {}
    for p in glob.glob('src/game/*.c') + glob.glob('src/ovl_a/*.c'):
        stem = os.path.basename(p)[:-2]
        if stem in cskip or stem in overrides: continue
        for m in DEF.finditer(open(p, errors='replace').read()):
            n = m.group(1)
            if n in their and not re.fullmatch(r'func_[0-9A-F]{8}', n): covered[their[n]] = n
    names = [l.strip() for l in open('port/recomp.txt') if l.strip()]
    keep, drop = [], []
    for n in names:
        (drop if re.fullmatch(r'func_[0-9A-F]{8}', n) and int(n[5:], 16) in covered else keep).append(n)
    open('port/recomp.txt', 'w', newline='\n').write('\n'.join(keep) + '\n')
    print(f'recomp_prune: {len(drop)} functions dropped (matched C defines them under their names), {len(keep)} left')
    if '--list' in sys.argv: print(' '.join(drop))

if __name__ == '__main__':
    main()
