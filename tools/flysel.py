#!/usr/bin/env python3
"""Pick the fly-through frames out of a TUROK_SHOTS capture and build a contact sheet of just those:
    python tools/flysel.py [--glob 'port/build/fs_*.bmp'] [--out port/build/flysel] [--cols 6] [--scale 0.5]
A frame is `menu` when its left fifth is grey metal (the level-select screen), `black` when nearly empty, `hud` when the hourglass/score HUD
is on (gameplay), anything else is `fly`.  Prints the label of every frame and writes <out>_<n>.png sheets of the fly frames."""
import glob, re, sys
import numpy as np
from PIL import Image
args = sys.argv[1:]
def opt(name, default):
    if name in args:
        i = args.index(name); v = args[i + 1]; del args[i:i + 2]; return type(default)(v)
    return default
pat = opt('--glob', 'port/build/fs_*.bmp'); out = opt('--out', 'port/build/flysel'); cols = opt('--cols', 6); scale = opt('--scale', 0.5)
files = sorted(glob.glob(pat))
if not files: print('no files'); sys.exit(1)
ims = [np.asarray(Image.open(f).convert('RGB'), dtype=np.int16) for f in files]
h, w = ims[0].shape[:2]
labels = []
for f, a in zip(files, ims):
    if a.mean() < 4: labels.append('black'); continue
    strip = a[int(h * 0.1):, :w // 5]                                   # level-select screen: grey metal frame down the left side (low saturation, bright)
    if strip.mean() > 60 and (strip.max(axis=2) - strip.min(axis=2)).mean() < 30: labels.append('menu'); continue
    hud = a[int(h * 0.06):int(h * 0.2), int(w * 0.02):int(w * 0.14)]      # top-left: the player count + hourglass, white digits on the scene
    labels.append('hud' if (hud.min(axis=2) > 200).sum() > 25 else 'fly')
for f, l in zip(files, labels): print(re.search(r'(\d+)\.\w+$', f).group(1), l)
sel = [f for f, l in zip(files, labels) if l == 'fly']
print('fly frames:', len(sel))
if sel:
    from subprocess import call
    call([sys.executable, 'tools/sheet.py', *sel, '--cols', str(cols), '--per', str(cols * 5), '--scale', str(scale), '--out', out])
