#include "b16_types.h"

void func_002734EC(B16Mtx *m, f32 sx, f32 sy, f32 sz) {
    m->m[0][0] *= sx;
    m->m[0][1] *= sx;
    m->m[0][2] *= sx;
    m->m[1][0] *= sy;
    m->m[1][1] *= sy;
    m->m[1][2] *= sy;
    m->m[2][0] *= sz;
    m->m[2][1] *= sz;
    m->m[2][2] *= sz;
}
