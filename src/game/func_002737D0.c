#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_002737D0(B16Mtx *m, f32 a) {
    f32 s = sinf(a);
    f32 c;
    m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] =
        m->m[2][1] = m->m[1][2] = m->m[2][0] = m->m[0][2] = 0.0f;
    m->m[3][3] = m->m[2][2] = 1.0f;
    c = cosf(a);
    m->m[1][1] = c;
    m->m[0][0] = c;
    m->m[1][0] = -s;
    m->m[0][1] = s;
}
