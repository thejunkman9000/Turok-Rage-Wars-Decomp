#!/usr/bin/env python3
"""Contact sheet of every map's part-11 occupancy grid (run after tools/dump_maps.py): assets/map_grids.png"""
import struct, glob, math, os
from PIL import Image, ImageDraw
ds = sorted(glob.glob('assets/maps/*'))[:36]
S, cols = 200, 6
sheet = Image.new('RGB', (cols * (S + 10), 6 * (S + 24)), (25, 25, 35)); dr = ImageDraw.Draw(sheet)
for i, d in enumerate(ds):
    b = open(d + '/part11.bin', 'rb').read(); n = struct.unpack('>I', b[4:8])[0]; w = math.isqrt(n)
    im = Image.new('L', (w, w)); im.putdata([255 if v else 40 for v in b[8:8 + n]])
    im = im.resize((S, S), Image.NEAREST)
    x = (i % cols) * (S + 10) + 5; y = (i // cols) * (S + 24) + 18
    sheet.paste(im.convert('RGB'), (x, y)); dr.text((x, y - 14), os.path.basename(d)[3:], fill=(255, 220, 120))
sheet.save('assets/map_grids.png'); print(sheet.size)
