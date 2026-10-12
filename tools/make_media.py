#!/usr/bin/env python3
"""README media from frames the port's renderer saved (TUROK_SHOTS=first-last:step:divisor -> port/build/fs_NNNNN.bmp, 1920x1440 / divisor).
usage:
  python tools/make_media.py still <in.bmp> <out.png> [width]          one screenshot (default width 640)
  python tools/make_media.py gif <first> <last> <out.gif> [width] [fps]  fs_<first>..fs_<last> (all frames in between that exist) as a looping GIF
      (fps for real speed = 30 / TUROK_SHOTS step: the game renders 30 frames a second in 1-player modes)"""
import glob, os, sys
from PIL import Image

def load(p, width):
    im = Image.open(p).convert('RGB')
    if width and im.width != width: im = im.resize((width, im.height * width // im.width), Image.LANCZOS)
    return im

def still(src, dst, width=640):
    load(src, width).save(dst, optimize=True)
    print(dst, os.path.getsize(dst) // 1024, 'KB')

def gif(first, last, dst, width=400, fps=10):
    """fps = game frames per second of the capture: the 1-player game renders at 30 fps, so TUROK_SHOTS step 3 -> 10 fps (real speed)"""
    files = [p for p in sorted(glob.glob('port/build/fs_*.bmp')) if first <= int(os.path.basename(p)[3:8]) <= last]
    frames = [load(p, width) for p in files]
    pal = frames[len(frames) // 2].quantize(colors=256, method=Image.Quantize.MEDIANCUT)          # one shared palette: small file, no flicker
    q = [f.quantize(palette=pal, dither=Image.Dither.NONE) for f in frames]
    q[0].save(dst, save_all=True, append_images=q[1:], duration=int(1000 / fps), loop=0, optimize=True, disposal=1)
    print(dst, len(q), 'frames', os.path.getsize(dst) // 1024, 'KB')

if __name__ == '__main__':
    a = sys.argv[1:]
    if a and a[0] == 'still': still(a[1], a[2], int(a[3]) if len(a) > 3 else 640)
    elif a and a[0] == 'gif': gif(int(a[1]), int(a[2]), a[3], int(a[4]) if len(a) > 4 else 400, int(a[5]) if len(a) > 5 else 10)
    else: print(__doc__)
