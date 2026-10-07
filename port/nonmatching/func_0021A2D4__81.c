#include "b04_types.h"
extern f32 D_800C73D4, D_800C73D8, D_800C73DC, D_800C73E0;
extern s32 D_800CE478, D_800CE47C, D_800D297C, D_801468F4;
extern s32 D_800D15E0;
extern s32 D_800D15E4[];
extern f32 D_800D15F0, D_800D15F4;
typedef struct { u8 pad0[0x54]; s32 unk54; u8 pad58[0x1B]; u8 unk73; } B04GF3;
extern B04GF3 D_801468A0[];
typedef struct { u8 pad0[0x60F]; s32 unk60F; } B04Gx;
extern u8 D_801462E5;
extern B04Gx D_801462E5x[];
typedef struct { u8 pad0[0xE]; u8 unkE; } B04Df;
typedef struct { u8 pad0[0x4]; u16 unk4; } B04Wd4;
extern B04Wd4 *D_800D052C[];
typedef struct { u8 pad0[0x8F]; u8 unk8F; } B04Sx;
typedef struct { u8 pad0[0x551]; u8 unk551; } B04Cx;
#define W(o, off) (*(s32 *)((u8 *)(o) + (off)))
#define F(o, off) (*(f32 *)((u8 *)(o) + (off)))
#define U8(o, off) (*(u8 *)((u8 *)(o) + (off)))
#define S16(o, off) (*(s16 *)((u8 *)(o) + (off)))
#define U16(o, off) (*(u16 *)((u8 *)(o) + (off)))
#define P(o, off, T) (*(T *)((u8 *)(o) + (off)))
typedef struct { u8 pad0[1]; u8 unk1; u8 pad2; s8 unk3; u8 pad4[0xB0]; s32 unkB4; u8 padB8[0x2C]; } B04Obj9;
void func_00228F94(void *, void *);
s32 func_0024BFC4(void *, s32);
void func_002536F4(s32, s32);
void func_0026B6A0(s32, void *, s32, s32, void *, s32, s32);
void func_0026D4F0(s32, void *, s32, s32, void *, s32, s32, s32, s32, s32, s32);
void func_0026DA4C(s32, s32, s32, void *, s32, s32);
void func_0021A2D4(void *o, s32 a1x, void *a2) {
    void *own = P(o, 0x1D8, void *);
    s32 s2, a1, k, v;
    f32 fv;
    if (F(own, 0x11D8) > 0.0f) {
        s2 = 1;
        if (W(own, 0x122C) & 0x8000)
            s2 = 0;
        else
            W(own, 0x122C) = W(own, 0x122C) | 0x8000;
        D_800D15E4[0] = 0;
        D_800D15E0 = 3;
        if (W(own, 0x122C) & 0x4000) {
            D_800D15E4[2] = 0;
            *(f32 *)&D_800D15E4[1] = D_800C73D4;
        } else {
            D_800D15E4[1] = 0;
            *(f32 *)&D_800D15E4[2] = D_800C73D8;
        }
        if (W(own, 0x1450) != 0)
            fv = D_800C73DC;
        else
            fv = (f32)U8(P(own, 0x5DC, void *), 0x551);
        D_800D15F0 = fv;
        D_800D15F4 = D_800C73E0;
        if (D_801468A0->unk54 != 0 && U8(P(own, 0x5D8, void *), 0x8F) != 0)
            U8(o, 1) = D_801468A0->unk73;
        else
            U8(o, 1) = U8(P(o, 0x18, void *), 0xE);
        func_0026B6A0(W(a2, 0xC), own, W(o, 0xB4), 1, (u8 *)o + (D_800D297C * 0x18 + 0x140), 0, *(s8 *)((u8 *)o + 3));
        D_800D15E0 = 0;
        if (s2 != 0)
            W(own, 0x122C) = W(own, 0x122C) & 0xFFFF7FFF;
        k = W(own, 0x5E0);
        if ((u32)(k - 0x11) >= 2U && k != 0xF
            && (U8(P(own, 0x5D8, void *), 0x8F) == 0 || D_801468F4 == 0)
            && W(own, 0x5E4) != 0 && U16(own, 0xE4) != D_800CE47C && !(W(own, 0x122C) & 0x20)) {
            s16 w = S16(own, 0x62E);
            u16 u = D_800D052C[w]->unk4;
            a1 = u - 0x4B3;
            if (w >= 0x10)
                a1 = u - 0x4B5;
            goto blk52;
        }
    } else if (D_801462E5 == 0
               || (((U8(P(own, 0x5D8, void *), 0x8F) == 0 || D_801462E5x->unk60F == 0 || W(own, 0x5E4) != 0)
                    && (D_801462E5 == 0 || (W(own, 0x13C8) == 0 && U16(own, 0xE4) != D_800CE478) || W(own, 0x5E4) != 0)))) {
        if (W(own, 0x122C) & 0x20) {
            func_00228F94(o, a2);
        } else {
            if (D_801468A0->unk54 != 0 && U8(P(own, 0x5D8, void *), 0x8F) != 0)
                U8(o, 1) = D_801468A0->unk73;
            else
                U8(o, 1) = U8(P(o, 0x18, void *), 0xE);
            func_0026B6A0(W(a2, 0xC), own, W(o, 0xB4), 1, (u8 *)o + (D_800D297C * 0x18 + 0x140), 0, *(s8 *)((u8 *)o + 3));
            if (F(own, 0x1240) > 0.0f)
                func_0026D4F0(W(a2, 0xC), own, W(o, 0xB4), 1, (u8 *)o + (D_800D297C * 0x18 + 0x140), 0, *(s8 *)((u8 *)o + 3),
                              U8(own, 0x123C), U8(own, 0x123D), U8(own, 0x123E), (s32)F(own, 0x1240) & 0xFF);
        }
        k = W(own, 0x5E0);
        if ((u32)(k - 0x11) >= 2U && k != 0xF
            && (U8(P(own, 0x5D8, void *), 0x8F) == 0 || D_801468F4 == 0)
            && W(own, 0x5E4) != 0 && U16(own, 0xE4) != D_800CE47C && !(W(own, 0x122C) & 0x20)) {
            s16 w = S16(own, 0x62E);
            a1 = D_800D052C[w]->unk4 - 0x4B3;
            if (w >= 0x10)
                a1 -= 2;
blk52:
            if (a1 >= 0) {
                v = func_0024BFC4(o, a1);
                if (v != 0) {
                    func_0026DA4C(v, W(o, 0xB4), 1, (u8 *)o + (D_800D297C * 0x18 + 0x140), 0, *(s8 *)((u8 *)o + 3));
                    func_002536F4(0, v);
                }
            }
        }
    }
}
