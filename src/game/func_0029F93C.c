
#include "b22_types.h"
void func_0029F93C(Vec3f *out, Vec3f *p, Vec3f *q, f32 nx, f32 ny, f32 nz, f32 d)
{
    Vec3f dir;
    f32 num, den, t;
    dir.x = q->x - p->x;
    dir.y = q->y - p->y;
    dir.z = q->z - p->z;
    num = nx * p->x + ny * p->y + nz * p->z;
    num = num + d;
    num = -num;
    den = nx * dir.x + ny * dir.y + nz * dir.z;
    if (den < 0.001f && den > -0.001f) {
        t = 0.5f;
    } else {
        t = num / den;
    }
    out->x = p->x + t * dir.x;
    out->y = p->y + t * dir.y;
    out->z = p->z + t * dir.z;
}


