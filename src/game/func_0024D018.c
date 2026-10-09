#include "b11_types.h"
#include "b16_types.h"

extern f32 D_800C8CA0;

void func_0024D018(B16Mtx *m, B16Vec4 *q, f32 *pos) {
    f32 x = q->x;
    f32 y = q->y;
    f32 z = q->z;
    f32 w = q->w;
    f32 xx = x * x;
    f32 yy = y * y;
    f32 zz = z * z;
    f32 ww = w * w;
    m->m[0][0] = ww + xx - yy - zz;
    m->m[0][1] = 2.0f * x * y + 2.0f * w * z;
    m->m[0][2] = 2.0f * x * z - 2.0f * w * y;
    m->m[1][0] = 2.0f * x * y - 2.0f * w * z;
    m->m[1][1] = ww - xx + yy - zz;
    m->m[1][2] = 2.0f * y * z + 2.0f * w * x;
    m->m[2][0] = 2.0f * x * z + 2.0f * w * y;
    m->m[2][1] = 2.0f * y * z - 2.0f * w * x;
    m->m[2][2] = ww - xx - yy + zz;
    m->m[3][0] = pos[0];
    m->m[3][1] = pos[1];
    m->m[3][2] = pos[2];
    m->m[0][3] = 0.0f;
    m->m[3][3] = D_800C8CA0;
    m->m[1][3] = 0.0f;
    m->m[2][3] = 0.0f;
}
