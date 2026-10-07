#include "o03_types.h"
typedef struct Q2Pl { s16 f0; s16 f2; s16 f4; u8 pad6[4]; s16 fA; u8 padC[0x78 - 0xC]; u8 f78; u8 pad79[0x91 - 0x79]; u8 f91; u8 pad92[4]; } Q2Pl;
typedef struct Q2Cfg { u8 pad0[0x24]; s8 s24; s8 s25; u8 pad26[0xD0 - 0x26]; Q2Pl pl[8]; } Q2Cfg;
extern Q2Pl D_80146398[];
extern Q2Cfg D_801462C8[];
extern u8 D_801462EC;
typedef struct Q2G { u8 pad0[0x14]; f32 f14; } Q2G;
extern Q2G D_801468A0[];
extern u8 D_80102B4A[];
extern u8 D_80102B26[];
extern u8 D_80102B6C[];
extern u8 D_80102B74[];
s32 func_00426454(void);
s32 func_00265670(void *b, s32 i);
void func_002656A8(void *b, s32 i, s32 v);
void func_004245C0(s32 p, s32 *out) {
    s32 n, i, j, met, t;
    f32 y;
    s32 *w;
    Q2Pl *e;
    n = 0;
    out[0] = -1;
    out[1] = -1;
    if (func_00426454() == 0) {
        return;
    }
    e = &D_80146398[p];
    if (e->f78 != 1) {
        return;
    }
    if (e->f91 != 0) {
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (func_00265670(D_80102B4A + p * 0x190, i) == 0 && D_80102B26[i + p * 0x190] >= 2) {
            func_002656A8(D_80102B4A + p * 0x190, i, 1);
            if (n < 2) {
                out[n] = i;
                n++;
            }
        }
    }
#define BASE (D_80102B4A + p * 0x190)
#define AWARD(k) func_002656A8(BASE, k, 1); if (n < 2) { out[n] = k; n++; }
    if (func_00265670(BASE, 0x24) == 0) {
        met = 0;
        if ((u32)(D_801462EC - 1) < 5 && e->f4 >= 15) {
            met = 1;
        } else if (D_801468A0->f14 >= 0.0f && e->f4 >= 15) {
            y = D_801468A0->f14 * 0.06666667f;
            t = (s32)(y * 0.016666668f);
            if ((f32)((s8 *)D_801468A0)[-0x5B4] - (f32)t <= 5.0f) {
                met = 1;
            }
        }
        if (met == 1) {
            AWARD(0x24)
        }
    }
    if (func_00265670(BASE, 0x25) == 0) {
        met = 0;
        if ((u32)(D_801462EC - 1) < 10 && e->f4 >= 0x19) {
            met = 1;
        } else if (D_801468A0->f14 >= 0.0f && e->f4 >= 0x19) {
            y = D_801468A0->f14 * 0.06666667f;
            t = (s32)(y * 0.016666668f);
            if ((f32)((s8 *)D_801468A0)[-0x5B4] - (f32)t <= 10.0f) {
                met = 1;
            }
        }
        if (met == 1) {
            AWARD(0x25)
        }
    }
    if (func_00265670(BASE, 0x26) == 0 && e->f4 == 0 && D_801462C8->s24 >= 10 && D_801462C8->s25 >= 20) {
        AWARD(0x26)
    }
    if (func_00265670(BASE, 0x27) == 0 && e->f0 >= 5) {
        AWARD(0x27)
    }
    if (func_00265670(BASE, 0x28) == 0 && D_801462C8->s25 >= 20) {
        t = e->f4;
        met = 1;
        for (i = 0; i < 4; i++) {
            if (met != 1) break;
            if (p != i) {
                if (D_801462C8->pl[i].f78 != 1 || D_801462C8->pl[i].f91 != 0 || D_801462C8->pl[i].f4 - t < 10) {
                    met = 0;
                }
            }
        }
        if (met == 1) {
            AWARD(0x28)
        }
    }
    if (func_00265670(BASE, 0x29) == 0 && *(s32 *)(D_80102B6C + p * 0x190) >= 0x3E9) {
        AWARD(0x29)
    }
    if (func_00265670(BASE, 0x2A) == 0 && *(s32 *)(D_80102B74 + p * 0x190) >= 0x3E9) {
        AWARD(0x2A)
    }
    if (func_00265670(BASE, 0x2B) == 0 && e->fA >= 10 && D_801462C8->s24 >= 10 && D_801462C8->s25 >= 20) {
        AWARD(0x2B)
    }
    if (func_00265670(BASE, 0x2C) == 0 && e->f2 == 0 && D_801462C8->s24 >= 10 && D_801462C8->s25 >= 20) {
        func_002656A8(BASE, 0x2C, 1);
        if (n < 2) {
            out[n] = 0x2C;
        }
    }
}
