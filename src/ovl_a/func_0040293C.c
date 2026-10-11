#include "o01_types.h"

typedef struct O01Dl { u32 w0; u32 w1; } O01Dl;
typedef struct O01CtxG {
    /* 0x00 */ u8 pad0[0x1C];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ u8 pad20[0x10];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ u8 pad38[0x6C];
    /* 0xA4 */ f32 unkA4;
} O01CtxG;
extern O01CtxG *D_800E2830;
extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern const f32 D_800E0C3C;
extern const f32 D_800E0C40;
extern const f32 D_800E0C44;
extern const f32 D_800E0C48;
extern const f32 D_800E0C4C;
extern const f32 D_800E0C50;
extern O01Dl *D_80110634;
s32 func_0026925C(s32 a);
s32 func_00268CE0(s32 a);
void func_00401D74(s32 a);

#define GFX(a, b) { O01Dl *_g = D_80110634++; _g->w0 = (a); _g->w1 = (b); }
#define MAXF(a, b) ((a) >= (b) ? (a) : (b))
#define MAXI(a, b) ((a) > (b) ? (a) : (b))

void func_0040293C(void) {
    f32 fs;
    f32 k;
    f32 q;
    s32 sh;
    fs = ((f32)D_800E28D4 - (f32)D_800E28D0 / D_800E2830->unkA4) * D_800E0C40;
    q = D_800E0C44;
    k = D_800E0C3C;
    if (D_800E2830->unk1C < D_800E2830->unk30) {
        k = D_800E2830->unk30 - D_800E2830->unk1C;
        k = k / q;
        if (D_800E0C48 < k) {
            k = D_800E0C48;
        }
        k = D_800E0C48 - k;
    }
    if (D_800E2830->unk1C > D_800E2830->unk34) {
        k = D_800E2830->unk1C - D_800E2830->unk34;
        k = k / q;
        if (D_800E0C4C < k) {
            k = D_800E0C4C;
        }
        k = D_800E0C4C - k;
    }
    fs = fs * k;
    GFX(0xE7000000, 0)
    GFX(0xE3000A01, 0)
    func_0026925C(0x13);
    func_00268CE0(0x19);
    GFX(0xFA00FFFF, 0xFF)
    GFX(0xF6000000 | ((MAXI(D_800E28D0, 0) & 0x3FF) << 14) | ((MAXI((s32)fs, 0) & 0x3FF) << 2), 0)
    GFX(0xF6000000 | ((MAXI(D_800E28D0, 0) & 0x3FF) << 14) | ((MAXI(D_800E28D4, 0) & 0x3FF) << 2), ({ f32 _y = (f32)D_800E28D4 - fs; if (!(0.0f <= _y)) _y = 0.0f; (((u32)_y) & 0x3FF) << 2; }))
    sh = (s32)fs;
    func_00401D74(sh);
}
