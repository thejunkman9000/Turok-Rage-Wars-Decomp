#include "b16_types.h"

f32 sinf(f32 x);
f32 cosf(f32 x);

void func_00272EAC(B16Mtx *m, f32 rx, f32 ry, f32 rz) {
    f32 sx = sinf(rx);
    f32 cx = cosf(rx);
    f32 sy = sinf(ry);
    f32 cy = cosf(ry);
    f32 sz = sinf(rz);
    f32 cz = cosf(rz);
    m->m[0][0] = cy * cz;
    m->m[0][1] = cy * sz;
    m->m[0][2] = -sy;
    m->m[1][0] = sx * sy * cz - cx * sz;
    m->m[1][1] = sx * sy * sz + cx * cz;
    m->m[1][2] = sx * cy;
    m->m[2][0] = cx * sy * cz + sx * sz;
    m->m[2][1] = cx * sy * sz - sx * cz;
    m->m[2][2] = cx * cy;
    m->m[0][3] = m->m[1][3] = m->m[2][3] = m->m[3][0] = m->m[3][1] = m->m[3][2] = 0.0f;
    m->m[3][3] = 1.0f;
}
