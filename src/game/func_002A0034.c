#include "b23_types.h"

void func_002A0034(Mtx4f *m, Vec3f *a, Vec3f *b, Vec3f *c) {
    m->m[0][0] = a->x;
    m->m[1][0] = a->y;
    m->m[2][0] = a->z;
    m->m[0][1] = b->x;
    m->m[1][1] = b->y;
    m->m[2][1] = b->z;
    m->m[0][2] = c->x;
    m->m[1][2] = c->y;
    m->m[2][2] = c->z;
}
