#include "b16_types.h"

void func_002734B8(B16Mtx *m, f32 x, f32 y, f32 z) {
    m->m[3][0] += x;
    m->m[3][1] += y;
    m->m[3][2] += z;
}
