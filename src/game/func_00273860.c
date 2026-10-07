#include "p3_types.h"

void func_00273860(P3Mtx *m, f32 ang) {
    f32 s = sinf(ang);
    f32 c = cosf(ang);
    f32 y;
    y = m->m[1][0];
    m->m[1][0] = c * y + s * m->m[2][0];
    m->m[2][0] = -s * y + c * m->m[2][0];
    y = m->m[1][1];
    m->m[1][1] = c * y + s * m->m[2][1];
    m->m[2][1] = -s * y + c * m->m[2][1];
    y = m->m[1][2];
    m->m[1][2] = c * y + s * m->m[2][2];
    m->m[2][2] = -s * y + c * m->m[2][2];
}