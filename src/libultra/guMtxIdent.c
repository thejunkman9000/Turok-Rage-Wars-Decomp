#include "common.h"

/* guMtxIdentF and guMtxF2L are inlined into guMtxIdent in the original object. */
static inline void identF(f32 mf[4][4]) {
    int r, c;

    for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
            if (r == c) {
                mf[r][c] = 1.0f;
            } else {
                mf[r][c] = 0.0f;
            }
        }
    }
}

static inline void f2l(f32 mf[4][4], Mtx *m) {
    int r, c;
    s32 tmp1;
    s32 tmp2;
    s32 *m1 = &m->m[0][0];
    s32 *m2 = &m->m[2][0];

    for (r = 0; r < 4; r++) {
        for (c = 0; c < 2; c++) {
            tmp1 = mf[r][2 * c] * 65536.0f;
            tmp2 = mf[r][2 * c + 1] * 65536.0f;
            *m1++ = (tmp1 & 0xFFFF0000) | ((tmp2 >> 0x10) & 0xFFFF);
            *m2++ = ((tmp1 << 0x10) & 0xFFFF0000) | (tmp2 & 0xFFFF);
        }
    }
}

void guMtxIdent(Mtx *m) {
    f32 mf[4][4];

    identF(mf);
    f2l(mf, m);
}
