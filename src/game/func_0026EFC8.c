#include "b16_types.h"

void func_0026EFC8(B16Mtx *dst, B16Mtx *src) {
    f32 det;
    f32 inv;
    f32 t;
    f32 t2;
    f32 t3;

    det = src->m[0][0] * src->m[1][1] * src->m[2][2] - src->m[0][0] * src->m[2][1] * src->m[1][2] -
          src->m[1][0] * src->m[0][1] * src->m[2][2] + src->m[1][0] * src->m[2][1] * src->m[0][2] +
          src->m[2][0] * src->m[0][1] * src->m[1][2] - src->m[2][0] * src->m[1][1] * src->m[0][2];
    if (det == 0.0f) {
        dst->m[0][0] = src->m[0][0];
        dst->m[0][1] = src->m[0][1];
        dst->m[0][2] = src->m[0][2];
        dst->m[0][3] = src->m[0][3];
        dst->m[1][0] = src->m[1][0];
        dst->m[1][1] = src->m[1][1];
        dst->m[1][2] = src->m[1][2];
        dst->m[1][3] = src->m[1][3];
        dst->m[2][0] = src->m[2][0];
        dst->m[2][1] = src->m[2][1];
        dst->m[2][2] = src->m[2][2];
        dst->m[2][3] = src->m[2][3];
        dst->m[3][0] = src->m[3][0];
        dst->m[3][1] = src->m[3][1];
        dst->m[3][2] = src->m[3][2];
        dst->m[3][3] = src->m[3][3];
        return;
    }
    inv = 1.0f / det;
    dst->m[0][0] = (src->m[1][1] * src->m[2][2] - src->m[2][1] * src->m[1][2]) * inv;
    t = src->m[0][1] * src->m[2][2];
    dst->m[0][1] = (src->m[2][1] * src->m[0][2] - t) * inv;
    dst->m[0][2] = (src->m[0][1] * src->m[1][2] - src->m[1][1] * src->m[0][2]) * inv;
    dst->m[0][3] = 0.0f;
    dst->m[1][0] = (-src->m[1][0] * src->m[2][2] + src->m[2][0] * src->m[1][2]) * inv;
    dst->m[1][1] = (src->m[0][0] * src->m[2][2] - src->m[2][0] * src->m[0][2]) * inv;
    t2 = src->m[0][0] * src->m[1][2];
    dst->m[1][2] = (src->m[1][0] * src->m[0][2] - t2) * inv;
    dst->m[1][3] = 0.0f;
    dst->m[2][0] = -(-src->m[1][0] * src->m[2][1] + src->m[2][0] * src->m[1][1]) * inv;
    dst->m[2][1] = (-src->m[0][0] * src->m[2][1] + src->m[2][0] * src->m[0][1]) * inv;
    dst->m[2][2] = -(-src->m[0][0] * src->m[1][1] + src->m[1][0] * src->m[0][1]) * inv;
    dst->m[2][3] = 0.0f;
    dst->m[3][0] = (-src->m[1][0] * src->m[2][1] * src->m[3][2] + src->m[1][0] * src->m[2][2] * src->m[3][1] +
                    src->m[2][0] * src->m[1][1] * src->m[3][2] - src->m[2][0] * src->m[1][2] * src->m[3][1] -
                    src->m[3][0] * src->m[1][1] * src->m[2][2] + src->m[3][0] * src->m[2][1] * src->m[1][2]) * inv;
    dst->m[3][1] = (src->m[0][0] * src->m[2][1] * src->m[3][2] - src->m[0][0] * src->m[2][2] * src->m[3][1] -
                    src->m[2][0] * src->m[0][1] * src->m[3][2] + src->m[2][0] * src->m[0][2] * src->m[3][1] +
                    src->m[3][0] * src->m[0][1] * src->m[2][2] - src->m[3][0] * src->m[2][1] * src->m[0][2]) * inv;
    t3 = src->m[0][0] * src->m[1][1] * src->m[3][2] - src->m[0][0] * src->m[1][2] * src->m[3][1] -
         src->m[1][0] * src->m[0][1] * src->m[3][2] + src->m[1][0] * src->m[0][2] * src->m[3][1] +
         src->m[3][0] * src->m[0][1] * src->m[1][2];
    dst->m[3][2] = (src->m[3][0] * src->m[1][1] * src->m[0][2] - t3) * inv;
    dst->m[3][3] = 1.0f;
}
