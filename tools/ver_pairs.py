#!/usr/bin/env python3
"""For every open target of a release (wip/vtargets_<target>.txt) find the most similar already matched unit of another release.

usage: python tools/ver_pairs.py <target ver> <source ver> [--out wip/vpairs_<target>_<source>.txt] [--min 0.5]
The PAL releases (Europe, Germany) differ from each other mostly in constants and tables, not in code shape: a function that is open in Germany is
usually a close variant of a function that is matched in Europe.  Similarity = Jaccard of the 3-grams of the normalised instruction streams
(tools/ver_funcmap.norm: j/jal targets and lui / load / store immediates masked).  Output line:
  <target name> <insns> <best source unit> <insns> <similarity> <source file under versions/<source>/src>   (or `-` when nothing reaches --min)"""
import glob, os, struct, sys
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
sys.path.insert(0, os.path.join(ROOT, 'tools'))
from ver_funcmap import norm
from ver_sweep import ROMS
args = [a for a in sys.argv[1:] if not a.startswith('--')]
T, S = args[0], args[1]
out = sys.argv[sys.argv.index('--out') + 1] if '--out' in sys.argv else f'wip/vpairs_{T}_{S}.txt'
MIN = float(sys.argv[sys.argv.index('--min') + 1]) if '--min' in sys.argv else 0.5
romT = open(ROMS[T], 'rb').read(); romS = open(ROMS[S], 'rb').read()

def words(rom, off, n): return list(struct.unpack('>%dI' % n, rom[off:off + 4 * n]))
def grams(ws):
    n = norm(ws)
    return set(tuple(n[i:i + 3]) for i in range(max(1, len(n) - 2)))

src = []                                              # matched units of the source release: (name, insns, grams, path)
for l in open(f'versions/{S}/manifest.txt'):
    f = l.split('#')[0].split()
    if len(f) < 4 or f[0].startswith('pad_') or f[3] not in ('game', 'ovl_a', 'libultra'): continue
    name, rom, n, seg = f[0], int(f[1], 16), int(f[2]), f[3]
    if n < 4: continue
    p = f'versions/{S}/src/{seg}/{name}.c'
    src.append((name, n, grams(words(romS, rom, n)), p if os.path.exists(p) else '-'))
res = []
for l in open(f'wip/vtargets_{T}.txt'):
    f = l.split()
    if len(f) < 4: continue
    name, rom, n = f[0], int(f[1], 16), int(f[2])
    g = grams(words(romT, rom, n)); best = (0.0, None)
    for s in src:
        if abs(s[1] - n) > max(8, n // 3): continue
        j = len(g & s[2]) / max(1, len(g | s[2]))
        if j > best[0]: best = (j, s)
    if best[1] and best[0] >= MIN: res.append(f'{name} {n} {best[1][0]} {best[1][1]} {best[0]:.2f} {best[1][3]}')
    else: res.append(f'{name} {n} - 0 {best[0]:.2f} -')
open(out, 'w').write('\n'.join(res) + '\n')
hit = [r for r in res if ' - ' not in r]
print(len(res), 'targets,', len(hit), 'with a similar matched unit in', S, '->', out)
