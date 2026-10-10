#!/usr/bin/env python3
"""Share of 'picture' pixels in the game area of a port screenshot: neither near-black nor the flat red the renderer clears 3D views to.
python port/imgstat.py shot.png   (a rendered 3D scene or menu: > 0.3; black / flat red 3D views with only the HUD: < 0.05)"""
import sys
from PIL import Image
im = Image.open(sys.argv[1]).convert('RGB'); w, h = im.size
box = im.crop((int(w * 0.14), int(h * 0.12), int(w * 0.86), int(h * 0.96)))
px = box.getdata() if not hasattr(box, 'get_flattened_data') else box.get_flattened_data()
n = 0; t = 0
for r, g, b in px:
    t += 1
    if r + g + b > 60 and not (r > 200 and g < 40 and b < 40): n += 1
print(f'{n / t:.3f}')
