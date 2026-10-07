#include "common.h"

static inline u32 m03_f2u(f32 x) {
    return (u32)x;
}

void func_0024CC20(f32 *f, u32 *m) {
    u32 *ai = m;
    u32 *af = m + 8;
    u32 e1;
    u32 e2;
    e1 = (u32)f[0];
    e2 = (u32)f[1];
    *ai++ = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af++ = (e1 << 16) | (e2 & 0xFFFF);
    e1 = (u32)f[2];
    *ai++ = e1 & 0xFFFF0000;
    *af++ = e1 << 16;
    e1 = (u32)f[4];
    e2 = (u32)f[5];
    *ai++ = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af++ = (e1 << 16) | (e2 & 0xFFFF);
    e1 = (u32)f[6];
    *ai++ = e1 & 0xFFFF0000;
    *af++ = e1 << 16;
    e1 = (u32)f[8];
    e2 = (u32)f[9];
    *ai++ = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af++ = (e1 << 16) | (e2 & 0xFFFF);
    e1 = (u32)f[10];
    *ai++ = e1 & 0xFFFF0000;
    *af++ = e1 << 16;
    e1 = (u32)f[12];
    e2 = (u32)f[13];
    *ai++ = (e1 & 0xFFFF0000) | (e2 >> 16);
    *af++ = (e1 << 16) | (e2 & 0xFFFF);
    e1 = (u32)f[14];
    *ai++ = (e1 & 0xFFFF0000) | 1;
    *af++ = e1 << 16;
}
