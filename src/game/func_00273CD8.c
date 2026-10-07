#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_00273CD8(B16Mtx *m, f32 ang) {
    f32 s = sinf(ang);
    f32 c = cosf(ang);
    f32 x;
    x = m->m[0][0];
    m->m[0][0] = x * c + m->m[0][1] * -s;
    m->m[0][1] = x * s + m->m[0][1] * c;
    x = m->m[1][0];
    m->m[1][0] = x * c + m->m[1][1] * -s;
    m->m[1][1] = x * s + m->m[1][1] * c;
    x = m->m[2][0];
    m->m[2][0] = x * c + m->m[2][1] * -s;
    m->m[2][1] = x * s + m->m[2][1] * c;
    x = m->m[3][0];
    m->m[3][0] = x * c + m->m[3][1] * -s;
    m->m[3][1] = x * s + m->m[3][1] * c;
}
