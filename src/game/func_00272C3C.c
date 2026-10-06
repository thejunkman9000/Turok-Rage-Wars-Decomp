#include "p3_types.h"

void func_00272C3C(P3Mtx *m, P3Vec3 *v, P3Vec3 *out) {
    out->x = m->m[0][0] * v->x + m->m[0][1] * v->y + m->m[0][2] * v->z;
    out->y = m->m[1][0] * v->x + m->m[1][1] * v->y + m->m[1][2] * v->z;
    out->z = m->m[2][0] * v->x + m->m[2][1] * v->y + m->m[2][2] * v->z;
}
