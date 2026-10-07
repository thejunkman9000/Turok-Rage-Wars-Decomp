#include "b04_types.h"
extern f32 D_800C7468, D_800C746C, D_800C7470;
extern s32 D_800D7E10, D_8013B29C, D_801462C8;
extern u8 D_801462E5;
extern u8 D_8011FE88[];
typedef struct { u8 pad0[0x98]; s32 unk98; u8 pad9C[4]; s32 unkA0; s32 unkA4; } B04GF2;
extern B04GF2 D_801468A0[];
typedef struct { u8 pad0[0x80]; s8 unk80; u8 pad81[0x12]; u8 unk93; } B04St3;
#define W(o, off) (*(s32 *)((u8 *)(o) + (off)))
#define F(o, off) (*(f32 *)((u8 *)(o) + (off)))
#define U16(o, off) (*(u16 *)((u8 *)(o) + (off)))
#define S16(o, off) (*(s16 *)((u8 *)(o) + (off)))
#define STATS(o) (*(B04St3 **)((u8 *)(o) + 0x5D8))
s32 func_00245774();
s32 func_0022C450(void *);
u32 func_0022ABF0(void *);
void func_0021B1E4(void *, s32, s32, s32);
void func_0021B468(void *, s32, s32, s32);
void func_002227D0(void *, void *, s32);
s16 func_00229BE0(void *, s32);
void func_0022B10C(void *, s32);
s32 func_00274544();
s32 func_0025E4F4(s16);
void func_0025DE74(s16, s32, s32, s32, void *, s32);
void func_00237E70(u8 *, s32, s32);
void func_00239184(s32, s32, s32);
typedef struct { f32 x, y, z; } B04V3;
void func_0028CE70(u8 *, s32, s32, B04V3, f32, f32);
void func_0021BFBC(void *p, s32 a1, s32 dmg, s32 a3, s32 a4) {
    s32 v, cur, s0, s2, a2, a0, s3, s0b, t, s4, s5, v5;
    f32 fv, fv2;
    B04V3 zv;
    s16 snd;
    s2 = dmg;
    cur = W(p, 0x5E4);
    if (func_00245774() == 0 && func_0022C450(p) == 0 && D_8013B29C == 0
        && (!(D_801462C8 & 1) || a4 == 0x20) && U16(p, 0x650) >= 2U) {
        if (W(p, 0x80C) != 0)
            s2 = s2 / 5;
        if (!(F(p, 0x670) > 0.0f) || a4 == 0x20) {
            s5 = W(p, 0x5E4) == 0;
            if (W(p, 0x122C) & 0x100) {
                s0 = W(p, 0x5E4) - s2;
                if (s0 < 0)
                    s0 = 0;
                v = func_0022ABF0(p);
                a2 = 0;
                for (a0 = 2; a0 < 5; a0++) {
                    v = v - v / 2;
                    if (v < W(p, 0x5E4) && s0 < v && s0 > 0) {
                        a2 = 1;
                        break;
                    }
                }
                if (a2 != 0)
                    func_0021B1E4(p, W(p, 0x5EC), 0, 1);
            }
            if (D_801468A0->unk98 != 0 && STATS(p)->unk80 == 0xB && D_801468A0->unkA0 > 0) {
                t = D_801468A0->unkA0 - (s2 >> 8);
                D_801468A0->unkA0 = t;
                if (t <= 0) {
                    D_801468A0->unkA0 = 0;
                    switch (STATS(p)->unk93) {
                    case 0:
                        D_801468A0->unkA4 = 0x4B;
                        break;
                    case 1:
                        D_801468A0->unkA4 = 0x3C;
                        break;
                    case 2:
                        D_801468A0->unkA4 = 0x3C;
                        break;
                    }
                    func_002227D0(p, p, 0x2D);
                }
                s2 = 0;
            }
            if (W(p, 0x5E4) != 0)
                W(p, 0x13C8) = (W(p, 0x5E4) - s2) < -0x1DFF;
            t = W(p, 0x5E4) - s2;
            if (t < 0)
                t = 0;
            W(p, 0x5E4) = t;
            t = func_00274544();
            if ((t / 2) * 2 == t - 1) {
                if (W(p, 0x5E4) > 0) {
                    snd = func_00229BE0(p, 0x138D);
                    if (func_0025E4F4(snd) == 0)
                        func_0025DE74(snd, W(p, 0x8), W(p, 0xC), W(p, 0x10), (u8 *)p + 8, -1);
                }
            }
            s4 = W(p, 0x5E4) == 0;
            W(p, 0x174) = W(p, 0x5E4);
            W(p, 0x45C) = W(p, 0x5E4);
            if (s4 != 0) {
                s0b = 0xFF;
                if (s5 == 0)
                    func_0021B468(p, a1, a3, a4);
                s3 = 0xC;
            } else {
                s0b = ((s2 >> 8) * 0xFF) / 20;
                if (s0b >= 0x100 || (s0b < 0x80 && 0)) {}
                {
                    s32 lt = s0b < 0x100;
                    if (lt == 0 || (v5 = 0x80, (s0b < 0x80) == 0)) {
                        v5 = 0xFF;
                        if (lt != 0)
                            v5 = s0b;
                    }
                    s0b = v5;
                }
                s3 = 0x1E;
                v5 = s2 >> 8;
                if (W(p, 0x5DC) != 0) {
                    if (cur >= 0xF01 && W(p, 0x5E4) < 0xF01 && D_801462E5 == 0) {
                        func_00237E70(&D_801462E5 - 0x125D, W(p, 0x5DC), D_800D7E10);
                        v5 = s2 >> 8;
                    }
                }
                if (v5 != 0) {
                    fv = (f32)v5 * D_800C7468;
                    fv2 = fv;
                    if (D_800C746C < fv)
                        fv2 = D_800C746C;
                    zv.x = 0;
                    zv.y = 0;
                    zv.z = 0;
                    func_0028CE70(D_8011FE88, W(p, 0x698) + 0x140, 0x11, zv, D_800C7470, fv2);
                }
            }
            if (s4 == 0 && S16(p, 0x650) != 0x12) {
                if (W(p, 0x5DC) != 0) {
                    v5 = s2 * 0x10;
                    if (W(p, 0x16D4) == 0)
                        func_00239184(W(p, 0x5DC), s0b & 0xFF, s3);
                    v = s2 * 0x10 - s2;
                    if (v >= 0x65)
                        v = 0x64;
                    func_0022B10C(p, v & 0xFFFF);
                }
            }
        }
    }
}
