#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
void func_0029F6E8(Vec3f *d, Vec3f *v, f32 ang)
{
    Vec3f t;
    f32 s, c;
    func_0029CBB0(ang, &s, &c);
    t.x = c * v->x - s * v->y;
    t.y = c * v->y + s * v->x;
    t.z = v->z;
    *d = t;
}
