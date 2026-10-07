#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_00273A34(B16Mtx *m, f32 a) {
    f32 s = sinf(a);
    f32 c = cosf(a);
    f32 x;
    x = m->m[0][0];
    m->m[0][0] = c * x + -s * m->m[2][0];
    m->m[2][0] = s * x + c * m->m[2][0];
    x = m->m[0][1];
    m->m[0][1] = c * x + -s * m->m[2][1];
    m->m[2][1] = s * x + c * m->m[2][1];
    x = m->m[0][2];
    m->m[0][2] = c * x + -s * m->m[2][2];
    m->m[2][2] = s * x + c * m->m[2][2];
}
