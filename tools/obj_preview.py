#!/usr/bin/env python3
"""Quick painter's-algorithm preview of a mapdump OBJ (textures averaged per material).
usage: python tools/obj_preview.py mapdump/<name>/map.obj out.png [yaw_deg pitch_deg]"""
import sys, os, math
from PIL import Image, ImageDraw
obj, out = sys.argv[1], sys.argv[2]
yaw = math.radians(float(sys.argv[3])) if len(sys.argv) > 3 else math.radians(35)
pitch = math.radians(float(sys.argv[4])) if len(sys.argv) > 4 else math.radians(35)
d = os.path.dirname(obj)
avg = {}
def color(mat):
    if mat in avg: return avg[mat]
    c = (128, 128, 128)
    try:
        im = Image.open(f'{d}/../{mat[1:] and "tex_" + mat[1:] + ".tga"}').convert('RGBA').resize((1, 1), Image.BOX)
        r, g, b, a = im.getpixel((0, 0)); c = (r, g, b)
    except Exception: pass
    avg[mat] = c; return c
V = []; T = []; mat = ''
for l in open(obj):
    if l.startswith('v '): V.append(tuple(map(float, l.split()[1:4])))
    elif l.startswith('usemtl'): mat = l.split()[1]
    elif l.startswith('f '):
        T.append(([int(t.split('/')[0]) - 1 for t in l.split()[1:4]], mat))
cx = sum(v[0] for v in V) / len(V); cy = sum(v[1] for v in V) / len(V); cz = sum(v[2] for v in V) / len(V)
def tr(v):
    x, y, z = v[0] - cx, v[1] - cy, v[2] - cz
    x, z = x * math.cos(yaw) - z * math.sin(yaw), x * math.sin(yaw) + z * math.cos(yaw)
    y, z = y * math.cos(pitch) - z * math.sin(pitch), y * math.sin(pitch) + z * math.cos(pitch)
    return x, y, z
P = [tr(v) for v in V]
ext = max(max(abs(p[0]), abs(p[1])) for p in sorted(P, key=lambda p: -abs(p[0]))[len(P) // 100:]) or 1
W = 1100; sc = W / 2 / ext * 0.95
tris = sorted(T, key=lambda t: -sum(P[i][2] for i in t[0]))
im = Image.new('RGB', (W, W), (20, 20, 30)); dr = ImageDraw.Draw(im)
for idx, m in tris:
    pts = [(W / 2 + P[i][0] * sc, W / 2 - P[i][1] * sc) for i in idx]
    dr.polygon(pts, fill=color(m))
im.save(out)
print(len(V) // 3, 'triangles ->', out)
