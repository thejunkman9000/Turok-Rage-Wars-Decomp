#include "b16_types.h"

void func_0027317C(B16Mtx *m, Vec3f *d, f32 h) {
    f32 t, vx, vz;
    m->m[0][0] = m->m[2][2] = m->m[3][3] = 1.0f;
    m->m[0][1] = m->m[0][2] = m->m[0][3] = m->m[1][3] = m->m[2][0] = m->m[2][1] =
        m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
    t = 1.0f / d->y;
    vx = d->x * t;
    vz = d->z * t;
    m->m[3][1] = h;
    m->m[1][1] = 0.0f;
    m->m[1][0] = -vx;
    m->m[1][2] = -vz;
    m->m[3][0] = h * vx;
    m->m[3][2] = h * vz;
}
