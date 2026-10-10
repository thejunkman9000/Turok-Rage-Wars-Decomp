#!/usr/bin/env python3
"""List the game functions that no matched C covers yet, counting by ROM address range (a span entry in funcs.txt / funcs_a.txt
covers every function inside it, which a name comparison does not see).

usage: python tools/remaining.py [--exclude-ws s801,s802,...] [--sizes] [--no-skip]
  --exclude-ws  leave out the targets of workers that are still running (D:/Projects/ws/<name>/wip/targets.txt)
  --no-skip     keep the functions of wip/skip_funcs.txt (padding words / hand-written asm no C can match)
Prints the count, the total instructions and the names (name:insns with --sizes), sorted by address."""
import os, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
cover = []                                           # (rom start, rom end)
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 3 and not f[0].startswith('pad_'):
            try: s = int(f[1], 16); cover.append((s, s + 4 * int(f[2])))
            except ValueError: pass
cover.sort()
def covered(a, b):                                   # most of the function lies in a matched entry (a stray head word may sit before the real entry)
    ov = sum(max(0, min(b, e) - max(a, s)) for s, e in cover)
    return ov * 4 >= (b - a) * 3
ex = set()
for w in ([x for x in (sys.argv[sys.argv.index('--exclude-ws') + 1].split(',')) if x] if '--exclude-ws' in sys.argv else []):
    t = 'D:/Projects/ws/%s/wip/targets.txt' % w
    if os.path.exists(t): ex |= {l.split()[0] for l in open(t) if l.strip()}
sk = set(open('wip/skip_funcs.txt').read().split()) if os.path.exists('wip/skip_funcs.txt') and '--no-skip' not in sys.argv else set()
rem = []
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) >= 3 and f[1].startswith('func_'):
        va = int(f[1][5:], 16)
        rom = va - 0x400000 + 0x16E000 if 0x400000 <= va < 0x500000 else va - 0x1FF400
        n = int(f[2])
        if covered(rom, rom + 4 * n) or f[1] in ex or f[1] in sk: continue
        rem.append((f[1], n))
rem.sort()
print(len(rem), 'functions,', sum(n for _, n in rem), 'insns')
print(' '.join(('%s:%d' % x) if '--sizes' in sys.argv else x[0] for x in rem))
