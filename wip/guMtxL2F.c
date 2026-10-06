#include "common.h"

void guMtxL2F(f32 mf[4][4], Mtx *m) {
    int r, c;
    u32 tmp1;
    u32 tmp2;
    u32 *m1;
    u32 *m2;
    s32 stmp1, stmp2;

    m1 = (u32 *)&m->m[0][0];
    m2 = (u32 *)&m->m[2][0];

    for (r = 0; r < 4; r++) {
        for (c = 0; c < 2; c++) {
            tmp1 = (*m1 & 0xFFFF0000) | ((*m2 >> 0x10) & 0xFFFF);
            tmp2 = ((*m1++ << 0x10) & 0xFFFF0000) | (*m2++ & 0xFFFF);
            stmp1 = *(s32 *)&tmp1;
            stmp2 = *(s32 *)&tmp2;
            mf[r][c * 2 + 0] = stmp1 / 65536.0f;
            mf[r][c * 2 + 1] = stmp2 / 65536.0f;
        }
    }
}
