#include "b16_types.h"

/* HACK: register pins reproduce the ROM allocation (mask a2, b a3, a t0, temps v0/v1) */
void func_00270980(B16Mtx4 dst, B16MtxFx *m) {
    register u32 mk asm("$6") = 0xFFFF0000;
    register u32 a asm("$8");
    register u32 b asm("$7");
    register u32 e asm("$2");
    register u32 s asm("$3");
    a = m->i[0];
    b = m->f[0];
    e = a & mk;
    s = b >> 16;
    e |= s;
    dst[0][0] = (s32)e * (1.0f / 65536.0f);
    e = a << 16;
    s = b & 0xFFFF;
    e |= s;
    dst[0][1] = (s32)e * (1.0f / 65536.0f);
    a = m->i[1];
    e = a | *(u16 *)&m->f[1];
    dst[0][2] = (s32)e * (1.0f / 65536.0f);
    dst[0][3] = 0.0f;
    a = m->i[2];
    b = m->f[2];
    e = a & mk;
    s = b >> 16;
    e |= s;
    dst[1][0] = (s32)e * (1.0f / 65536.0f);
    e = a << 16;
    s = b & 0xFFFF;
    e |= s;
    dst[1][1] = (s32)e * (1.0f / 65536.0f);
    a = m->i[3];
    e = a | *(u16 *)&m->f[3];
    dst[1][2] = (s32)e * (1.0f / 65536.0f);
    dst[1][3] = 0.0f;
    a = m->i[4];
    b = m->f[4];
    e = a & mk;
    s = b >> 16;
    e |= s;
    dst[2][0] = (s32)e * (1.0f / 65536.0f);
    e = a << 16;
    s = b & 0xFFFF;
    e |= s;
    dst[2][1] = (s32)e * (1.0f / 65536.0f);
    a = m->i[5];
    e = a | *(u16 *)&m->f[5];
    dst[2][2] = (s32)e * (1.0f / 65536.0f);
    dst[2][3] = 0.0f;
    a = m->i[6];
    b = m->f[6];
    e = a & mk;
    s = b >> 16;
    e |= s;
    dst[3][0] = (s32)e * (1.0f / 65536.0f);
    e = a << 16;
    s = b & 0xFFFF;
    e |= s;
    dst[3][1] = (s32)e * (1.0f / 65536.0f);
    a = m->i[7];
    {
        u32 e7 = (a & mk) | *(u16 *)&m->f[7];
        dst[3][2] = (s32)e7 * (1.0f / 65536.0f);
    }
    dst[3][3] = 1.0f;
}