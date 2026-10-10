#!/usr/bin/env python3
"""Decomp progress chart from the manifests: python tools/progress_chart.py out.png"""
import sys
from PIL import Image, ImageDraw
done = {}
for fn in ('funcs.txt', 'funcs_a.txt'):
    for l in open(fn):
        f = l.split('#')[0].split()
        if len(f) >= 4 and not f[0].startswith('pad_') and f[3] in ('game', 'ovl_a'): done[f[0]] = int(f[2])
tot = {'main': [0, 0, 0, 0], 'ovl': [0, 0, 0, 0]}
for l in open('docs/game_funcs.txt'):
    f = l.split()
    if len(f) < 3 or not f[1].startswith('func_'): continue
    k = 'ovl' if int(f[1][5:], 16) >= 0x400000 and int(f[1][5:], 16) < 0x500000 else 'main'
    t = tot[k]; t[1] += 1; t[3] += int(f[2])
    if f[1] in done: t[0] += 1; t[2] += int(f[2])
W, H = 900, 330
im = Image.new('RGB', (W, H), (24, 26, 34)); d = ImageDraw.Draw(im)
d.text((20, 14), 'Turok: Rage Wars - matching decompilation (game code, by instructions)', fill=(240, 240, 240))
rows = [('Main image', tot['main']), ('Overlay A', tot['ovl']), ('All game code', [a + b for a, b in zip(tot['main'], tot['ovl'])])]
for i, (nm, t) in enumerate(rows):
    y = 60 + i * 80; pct = 100 * t[2] / t[3]
    d.text((20, y), nm, fill=(200, 200, 210)); d.rectangle((20, y + 20, W - 40, y + 46), fill=(50, 54, 68))
    d.rectangle((20, y + 20, 20 + (W - 60) * pct / 100, y + 46), fill=(90, 190, 130))
    d.text((28, y + 27), f'{pct:.1f}%   {t[2]:,}/{t[3]:,} insns   {t[0]}/{t[1]} functions', fill=(10, 20, 15))
im.save(sys.argv[1] if len(sys.argv) > 1 else 'assets/progress.png')
print([(n, round(100 * t[2] / t[3], 1)) for n, t in rows])
