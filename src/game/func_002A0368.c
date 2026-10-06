#include "b23_types.h"

void func_0029D6A8(Mtx4f *m, void *rot);

void func_002A0368(Mtx4f *m, Vec3f *scale, void *rot, Vec3f *trans) {
    func_0029D6A8(m, rot);
    m->m[0][0] = m->m[0][0] * scale->x;
    m->m[0][1] = m->m[0][1] * scale->x;
    m->m[0][2] = m->m[0][2] * scale->x;
    m->m[1][0] = m->m[1][0] * scale->y;
    m->m[1][1] = m->m[1][1] * scale->y;
    m->m[1][2] = m->m[1][2] * scale->y;
    m->m[2][0] = m->m[2][0] * scale->z;
    m->m[2][1] = m->m[2][1] * scale->z;
    m->m[2][2] = m->m[2][2] * scale->z;
    m->m[3][0] = m->m[3][0] + trans->x;
    m->m[3][1] = m->m[3][1] + trans->y;
    m->m[3][2] = m->m[3][2] + trans->z;
}
