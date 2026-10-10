#!/usr/bin/env python3
"""Compare screenshots of two runs: python port/imgdiff.py <dirA> <dirB> [prefix]  or  python port/imgdiff.py a.png b.png [diff.png]
For every file name present in both directories prints the share of pixels that differ by more than 24 (of 255) in any channel; with two files it
also writes a diff image (red = differs).  The window title bar and border are ignored (top 32 px)."""
import os, sys
from PIL import Image, ImageChops

def cmp(a, b, out=None):
    A = Image.open(a).convert('RGB'); B = Image.open(b).convert('RGB')
    if A.size != B.size: return None, 'size %s vs %s' % (A.size, B.size)
    A = A.crop((0, 32, A.width, A.height)); B = B.crop((0, 32, B.width, B.height))
    d = ImageChops.difference(A, B).convert('L').point(lambda v: 255 if v > 24 else 0)
    n = sum(1 for v in d.getdata() if v)
    if out:
        red = Image.merge('RGB', (d, Image.new('L', d.size, 0), Image.new('L', d.size, 0)))
        Image.blend(A, red, 0.5).save(out)
    return 100.0 * n / (d.width * d.height), ''

if __name__ == '__main__':
    x, y = sys.argv[1], sys.argv[2]
    if os.path.isdir(x) and os.path.isdir(y):
        pre = sys.argv[3] if len(sys.argv) > 3 else ''
        for f in sorted(os.listdir(x)):
            if f.endswith('.png') and f.startswith(pre) and os.path.exists(os.path.join(y, f)):
                r, note = cmp(os.path.join(x, f), os.path.join(y, f))
                print('%-16s %s' % (f, ('%.2f%% differ' % r) if r is not None else note))
    else:
        r, note = cmp(x, y, sys.argv[3] if len(sys.argv) > 3 else None)
        print(('%.2f%% differ' % r) if r is not None else note)
