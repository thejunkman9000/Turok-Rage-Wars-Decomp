#include "b16_types.h"

void func_00273618(B16Mtx *m, f32 sx, f32 sy, f32 sz) {
    m->m[0][0] *= sx;
    m->m[1][0] *= sx;
    m->m[2][0] *= sx;
    m->m[3][0] *= sx;
    m->m[0][1] *= sy;
    m->m[1][1] *= sy;
    m->m[2][1] *= sy;
    m->m[3][1] *= sy;
    m->m[0][2] *= sz;
    m->m[1][2] *= sz;
    m->m[2][2] *= sz;
    m->m[3][2] *= sz;
}
