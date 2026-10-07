#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_00273B08(B16Mtx *m, f32 ang) {
    f32 s = sinf(ang);
    f32 c = cosf(ang);
    f32 x;
    x = m->m[0][0];
    m->m[0][0] = x * c + m->m[0][2] * s;
    m->m[0][2] = x * -s + m->m[0][2] * c;
    x = m->m[1][0];
    m->m[1][0] = x * c + m->m[1][2] * s;
    m->m[1][2] = x * -s + m->m[1][2] * c;
    x = m->m[2][0];
    m->m[2][0] = x * c + m->m[2][2] * s;
    m->m[2][2] = x * -s + m->m[2][2] * c;
    x = m->m[3][0];
    m->m[3][0] = x * c + m->m[3][2] * s;
    m->m[3][2] = x * -s + m->m[3][2] * c;
}
