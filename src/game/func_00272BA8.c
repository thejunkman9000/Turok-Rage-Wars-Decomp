#include "b16_types.h"

void func_00272BA8(B16Mtx *m, Vec3f *v, Vec3f *dst) {
    dst->x = m->m[0][0] * v->x + m->m[1][0] * v->y + m->m[2][0] * v->z;
    dst->y = m->m[0][1] * v->x + m->m[1][1] * v->y + m->m[2][1] * v->z;
    dst->z = m->m[0][2] * v->x + m->m[1][2] * v->y + m->m[2][2] * v->z;
}
