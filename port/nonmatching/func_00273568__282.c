#include "b16_types.h"

void func_00273568(B16Mtx *dst, B16Mtx *src, f32 sx, f32 sy, f32 sz) {
    dst->m[0][0] = src->m[0][0] * sx;
    do {
    dst->m[0][1] = src->m[0][1] * sx;
    dst->m[0][2] = src->m[0][2] * sx;
    dst->m[1][0] = src->m[1][0] * sy;
    dst->m[1][1] = src->m[1][1] * sy;
    dst->m[1][2] = src->m[1][2] * sy;
    dst->m[2][0] = src->m[2][0] * sz;
    dst->m[2][1] = src->m[2][1] * sz;
    dst->m[2][2] = src->m[2][2] * sz;
    dst->m[3][0] = src->m[3][0];
    dst->m[3][1] = src->m[3][1];
    dst->m[3][2] = src->m[3][2];
    dst->m[0][3] = dst->m[1][3] = dst->m[2][3] = 0.0f;
    dst->m[3][3] = 1.0f;
    } while (0);
}