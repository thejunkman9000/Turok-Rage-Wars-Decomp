#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
f32 func_0029EE48(f32);
f32 func_0029ED18(f32);
f32 func_0029D044(f32, f32);
void func_0029C6E0(Vec3f *v)
{
    f32 sx, cx, sy, cy, sz, cz, t, a, c, e1, e2;
    f32 r1, u, w, p, q, x1, y1, s;
    func_0029CBB0(v->x, &sx, &cx);
    func_0029CBB0(v->y, &sy, &cy);
    func_0029CBB0(v->z, &sz, &cz);
    t = -sy * cz;
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    a = func_0029EE48(-t);
    c = func_0029ED18(a);
    if (9.99999975e-05f < c || c < -9.99999975e-05f) {
        p = sy * sz;
        u = sz;
        r1 = cx * p;
        q = sx * cy;
        w = cy;
        x1 = r1 + q;
        y1 = -sx * p + w * cx;
        s = w * cz;
        e1 = func_0029D044(x1, y1);
        e2 = func_0029D044(u, s);
    } else {
        e1 = func_0029D044(-cz * sx, cz * cx);
        e2 = 0.0f;
    }
    v->x = e1;
    v->y = a;
    v->z = e2;
}

