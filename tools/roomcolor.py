#!/usr/bin/env python3
"""Classify the room of a captured frame by its average colour: python tools/roomcolor.py <bmp> [<bmp> ...]  -> prints `<file> r g b -> red|green|blue|other`."""
import sys
from PIL import Image, ImageStat
for f in sys.argv[1:]:
    r, g, b = ImageStat.Stat(Image.open(f).convert('RGB')).mean
    k = 'green' if g > r * 1.15 and g > b * 1.15 else 'red' if r > g * 1.5 and r > b * 1.5 else 'blue' if b > r * 1.15 and b > g * 1.05 else 'other'
    print('%s %.0f %.0f %.0f -> %s' % (f, r, g, b, k))
