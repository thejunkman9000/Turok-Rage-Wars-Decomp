#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
void func_0029F654(Vec3f *d, Vec3f *v, f32 ang)
{
    Vec3f t;
    f32 s, c;
    func_0029CBB0(ang, &s, &c);
    t.x = c * v->x + s * v->z;
    t.y = v->y;
    t.z = c * v->z - s * v->x;
    *d = t;
}
