#include "b16_types.h"
void func_00273DDC(B16Mtx *m) {
    f32 t;
    t = m->m[1][0]; m->m[1][0] = m->m[2][0]; m->m[2][0] = t;
    t = m->m[1][1]; m->m[1][1] = m->m[2][1]; m->m[2][1] = t;
    t = m->m[1][2]; m->m[1][2] = m->m[2][2]; m->m[2][2] = t;
}
