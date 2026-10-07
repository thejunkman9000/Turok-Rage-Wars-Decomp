#include "b16_types.h"

void func_002702EC(f32 *mf, B16MtxFx *m) {
    u32 *ai = m->i;
    u32 *af = m->f;
    u32 e1, e2;
    e1 = (u32)(mf[0] * 65536.0f);
    e2 = (u32)(mf[1] * 65536.0f);
    *ai = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af = (e1 << 16) | (e2 & 0xFFFF);
    ai++;
    af++;
    e1 = (u32)(mf[2] * 65536.0f);
    *ai = e1 & 0xFFFF0000;
    *af = e1 << 16;
    ai++;
    af++;
    e1 = (u32)(mf[4] * 65536.0f);
    e2 = (u32)(mf[5] * 65536.0f);
    *ai = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af = (e1 << 16) | (e2 & 0xFFFF);
    ai++;
    af++;
    e1 = (u32)(mf[6] * 65536.0f);
    *ai = e1 & 0xFFFF0000;
    *af = e1 << 16;
    ai++;
    af++;
    e1 = (u32)(mf[8] * 65536.0f);
    e2 = (u32)(mf[9] * 65536.0f);
    *ai = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af = (e1 << 16) | (e2 & 0xFFFF);
    ai++;
    af++;
    e1 = (u32)(mf[10] * 65536.0f);
    *ai = e1 & 0xFFFF0000;
    *af = e1 << 16;
    ai++;
    af++;
    e1 = (u32)(mf[12] * 65536.0f);
    e2 = (u32)(mf[13] * 65536.0f);
    *ai = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af = (e1 << 16) | (e2 & 0xFFFF);
    ai++;
    af++;
    e1 = (u32)(mf[14] * 65536.0f);
    *ai = (e1 & 0xFFFF0000) | 1;
    *af = e1 << 16;
}
