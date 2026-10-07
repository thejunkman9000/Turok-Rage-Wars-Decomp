#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
f32 func_0029EE48(f32);
f32 func_0029ED18(f32);
f32 func_0029D044(f32, f32);
void func_0029C3C0(Vec3f *v)
{
    f32 x1, y1, x2, y2, p, q, sx, cx, sy, cy, sz, cz, t, a, c, e1, e2, ytmp;
    func_0029CBB0(v->x, &sx, &cx);
    func_0029CBB0(v->y, &sy, &cy);
    func_0029CBB0(v->z, &sz, &cz);
    t = cx * sz * sy - sx * cz;
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    a = func_0029EE48(-t);
    c = func_0029ED18(a);
    if (9.99999975e-05f < c || c < -9.99999975e-05f) {
        x1 = cx * cy;
        p = cx * cz;
        q = sx * sz;
        ytmp = p * sy + q;
        y2 = cy * sz;
        y1 = ytmp;
        x2 = q * sy + p;
        e1 = func_0029D044(y1, x1);
        e2 = func_0029D044(y2, x2);
    } else {
        e1 = 0.0f;
        e2 = func_0029D044(-sy, cy * cz);
    }
    v->x = a;
    v->y = e1;
    v->z = e2;
}

