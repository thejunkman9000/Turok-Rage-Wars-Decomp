#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
f32 func_0029EE48(f32);
f32 func_0029ED18(f32);
f32 func_0029D044(f32, f32);
void func_0029C868(Vec3f *v)
{
    f32 sx, cx, sy, cy, sz, cz, t, a, c, e1, e2;
    f32 u, w, p, q, x1, y1, s;
    func_0029CBB0(v->x, &sx, &cx);
    func_0029CBB0(v->y, &sy, &cy);
    func_0029CBB0(v->z, &sz, &cz);
    t = cy * sx * sz - sy * cz;
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    a = func_0029EE48(-t);
    c = func_0029ED18(a);
    if (9.99999975e-05f < c || c < -9.99999975e-05f) {
        w = cy;
        u = cx;
        q = u * w;
        p = sy * sz;
        u = u * sz;
        w = w * cz;
        y1 = p + sx * w;
        w = w + p * sx;
        e1 = func_0029D044(y1, q);
        e2 = func_0029D044(u, w);
    } else {
        e1 = func_0029D044(sx, cx * cz);
        e2 = 0.0f;
    }
    v->x = e1;
    v->y = a;
    v->z = e2;
}
