#!/usr/bin/env python3
"""Contact sheets of captured frames: python tools/sheet.py <glob> [--cols 4] [--per 12] [--scale 0.5] [--out port/build/sheet]
Every cell is labelled with the file's frame number; sheets are written as <out>_<n>.png."""
import glob, re, sys
from PIL import Image, ImageDraw
args = sys.argv[1:]
def opt(name, default):
    if name in args:
        i = args.index(name); v = args[i + 1]; del args[i:i + 2]; return type(default)(v)
    return default
cols = opt('--cols', 4); per = opt('--per', 12); scale = opt('--scale', 0.5); out = opt('--out', 'port/build/sheet')
files = sorted(f for a in args for f in glob.glob(a))
if not files: print('no files'); sys.exit(1)
for n in range(0, len(files), per):
    chunk = files[n:n + per]
    ims = [Image.open(f).convert('RGB') for f in chunk]
    w, h = int(ims[0].width * scale), int(ims[0].height * scale)
    rows = (len(ims) + cols - 1) // cols
    sheet = Image.new('RGB', (cols * w, rows * h))
    for i, (f, im) in enumerate(zip(chunk, ims)):
        im = im.resize((w, h), Image.LANCZOS); d = ImageDraw.Draw(im)
        m = re.search(r'(\d+)\.\w+$', f); d.rectangle([0, 0, 44, 12], fill=(0, 0, 0)); d.text((2, 0), m.group(1) if m else f, fill=(255, 255, 0))
        sheet.paste(im, ((i % cols) * w, (i // cols) * h))
    p = '%s_%02d.png' % (out, n // per); sheet.save(p); print(p, len(chunk))
