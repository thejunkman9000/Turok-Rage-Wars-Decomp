#include "b16_types.h"
void func_0026EE90(B16Mtx4 m, f32 *src, f32 *dst) {
    f32 bmin[4];
    f32 bmax[4];
    f32 omin[4];
    f32 omax[4];
    s32 i, j;
    f32 a, e, f;

    bmin[0] = src[0];
    bmin[1] = src[1];
    bmin[2] = src[2];
    bmax[0] = src[3];
    bmax[1] = src[4];
    bmax[2] = src[5];
    omin[0] = omax[0] = m[3][0];
    omin[1] = omax[1] = m[3][1];
    omin[2] = omax[2] = m[3][2];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a = m[j][i];
            e = a * bmin[j];
            f = a * bmax[j];
            if (e < f) {
                omin[i] += e;
                omax[i] += f;
            } else {
                omin[i] += f;
                omax[i] += e;
            }
        }
    }
    dst[0] = omin[0];
    dst[1] = omin[1];
    dst[2] = omin[2];
    dst[3] = omax[0];
    dst[4] = omax[1];
    dst[5] = omax[2];
}
