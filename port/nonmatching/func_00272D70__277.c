#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_00272D70(B16Mtx *m, f32 angle, f32 x, f32 y, f32 z) {
    f32 s = sinf(angle);
    f32 c = cosf(angle);
    f32 xy = x * y;
    f32 yz = y * z;
    f32 zx = z * x;
    f32 omc = 1.0f - c;
    xy *= omc;
    yz *= omc;
    zx *= omc;
    m->m[3][3] = 1.0f;
    m->m[0][0] = x * x + c * (1.0f - x * x);
    m->m[1][1] = y * y + c * (1.0f - y * y);
    m->m[2][2] = z * z + c * (1.0f - z * z);
    m->m[2][1] = yz - x * s;
    m->m[1][2] = yz + x * s;
    m->m[2][0] = zx + y * s;
    m->m[0][2] = zx - y * s;
    m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
    m->m[1][0] = xy - z * s;
    m->m[0][1] = xy + z * s;
}
