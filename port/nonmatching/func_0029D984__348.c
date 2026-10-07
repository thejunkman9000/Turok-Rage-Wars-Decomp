

#include "b22_types.h"
void func_0029CBB0(f32, f32 *, f32 *);
void func_0029D984(B22Mtx *m, Vec3f *a)
{
    f32 sx, cx, sy, cy, sz, cz;
    f32 t1, t2;
    func_0029CBB0(a->x, &sx, &cx);
    func_0029CBB0(a->y, &sy, &cy);
    func_0029CBB0(a->z, &sz, &cz);
    t1 = sx * sz;
    t2 = sx * cz;
    m->m[0][0] = cy * cz + sy * t1;
    m->m[1][0] = sy * t2 - sz * cy;
    m->m[2][0] = cx * sy;
    m->m[0][1] = cx * sz;
    m->m[1][1] = cx * cz;
    m->m[0][2] = cy * t1 - sy * cz;
    m->m[2][2] = cx * cy;
    m->m[1][2] = sy * sz + t2 * cy;
    m->m[2][1] = -sx;
    m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
}


