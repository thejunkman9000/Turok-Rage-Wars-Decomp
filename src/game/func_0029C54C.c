
#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
f32 func_0029EE48(f32);
f32 func_0029ED18(f32);
f32 func_0029D044(f32, f32);
void func_0029C54C(Vec3f *v)
{
    f32 sx, cx, sy, cy, sz, cz, t, a, c, e1, e2;
    f32 p, s, x1, y1, u, w, w2;
    func_0029CBB0(v->x, &sx, &cx);
    func_0029CBB0(v->y, &sy, &cy);
    func_0029CBB0(v->z, &sz, &cz);
    t = cy * sz;
    if (1.0f < t) {
        t = 1.0f;
    }
    if (t < -1.0f) {
        t = -1.0f;
    }
    a = func_0029EE48(t);
    c = func_0029ED18(a);
    if (9.99999975e-05f < c || c < -9.99999975e-05f) {
        u = sy;
        p = u * sz;
        w = cx * p;
        x1 = sx * cz - w;
        s = cy * cz;
        y1 = sx * p + cx * cz;
        e1 = func_0029D044(x1, y1);
        e2 = func_0029D044(u, s);
    } else {
        w2 = sx * sy * cz;
        e1 = func_0029D044(sx * cy, cx * sz - w2);
        e2 = 0.0f;
    }
    v->x = e1;
    v->y = e2;
    v->z = a;
}


