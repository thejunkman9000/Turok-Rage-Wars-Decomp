#include "b16_types.h"
void func_00272A80(B16Mtx *m, Vec3f *v, Vec3f *dst) {
    f32 w;
    f32 inv;
    dst->x = m->m[0][0] * v->x + m->m[1][0] * v->y + m->m[2][0] * v->z + m->m[3][0];
    dst->y = m->m[0][1] * v->x + m->m[1][1] * v->y + m->m[2][1] * v->z + m->m[3][1];
    dst->z = m->m[0][2] * v->x + m->m[1][2] * v->y + m->m[2][2] * v->z + m->m[3][2];
    w = m->m[0][3] * v->x + m->m[1][3] * v->y + m->m[2][3] * v->z + m->m[3][3];
    if (w != 0.0f) {
        inv = 1.0f / w;
        dst->x *= inv;
        dst->y *= inv;
        dst->z *= inv;
    }
}
