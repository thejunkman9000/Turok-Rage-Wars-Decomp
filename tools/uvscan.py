#!/usr/bin/env python3
"""uvscan.py <map.obj> [--top N] : find triangles of a TUROK_MAPDUMP export whose texture mapping is degenerate or stretched (UV area tiny / anisotropic compared with the 3D area),
i.e. surfaces that show streaks.  Prints, per texture, the number of suspicious triangles and the world-space box of the worst ones."""
import collections, math, re, sys
path = sys.argv[1]; top = int(sys.argv[sys.argv.index('--top') + 1]) if '--top' in sys.argv else 15
V = []; VT = []; tris = []; cur = None
tex = {}
for l in open(path):
    f = l.split()
    if not f: continue
    if f[0] == 'v': V.append(tuple(float(x) for x in f[1:4]))
    elif f[0] == 'vt': VT.append((float(f[1]), float(f[2])))
    elif f[0] == 'usemtl': cur = f[1]
    elif f[0] == 'f':
        ids = [tuple(int(x) - 1 for x in p.split('/')[:2]) for p in f[1:4]]
        tris.append((cur, ids))
def cross(a, b): return (a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0])
def norm(a): return math.sqrt(sum(x*x for x in a))
bad = collections.defaultdict(list); total = collections.Counter()
for t, ids in tris:
    p = [V[i] for i, _ in ids]; uv = [VT[j] for _, j in ids]
    e1 = [p[1][k]-p[0][k] for k in range(3)]; e2 = [p[2][k]-p[0][k] for k in range(3)]
    area3 = norm(cross(e1, e2)) / 2
    if area3 < 1e-3: continue
    a = (uv[1][0]-uv[0][0], uv[1][1]-uv[0][1]); b = (uv[2][0]-uv[0][0], uv[2][1]-uv[0][1])
    areauv = abs(a[0]*b[1]-a[1]*b[0]) / 2
    total[t] += 1
    # texel density: uv area per world area; degenerate when the triangle has world size but (almost) no UV extent in one direction
    du = max(u for u, v in uv) - min(u for u, v in uv); dv = max(v for u, v in uv) - min(v for u, v in uv)
    if areauv < 1e-6 * area3 or min(du, dv) < 1e-4 and max(du, dv) > 1e-3:
        bad[t].append((area3, p, uv))
print('triangles', len(tris), 'textures', len(total), 'suspicious textures', len(bad))
for t, l in sorted(bad.items(), key=lambda kv: -sum(x[0] for x in kv[1]))[:top]:
    xs = [q[k] for _, p, _ in l for q in p for k in (0,)]; ys = [q[1] for _, p, _ in l for q in p]; zs = [q[2] for _, p, _ in l for q in p]
    print('%s: %d of %d triangles degenerate, world box x %.0f..%.0f y %.0f..%.0f z %.0f..%.0f, example uv %s' % (t, len(l), total[t], min(xs), max(xs), min(ys), max(ys), min(zs), max(zs), [tuple(round(c, 3) for c in q) for q in l[0][2]]))
