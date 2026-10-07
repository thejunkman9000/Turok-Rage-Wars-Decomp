#include "b06_types.h"

void func_002231B0(Plr *a, Plr *b, u8 *c);
void func_002238BC(Plr *a, Plr *b, u8 *c);
void func_00218464(u8 *p);
void func_0025DE74(s16 a, f32 x, f32 y, f32 z, s32 d, s32 e);
void func_002227D0(Plr *a, Plr *b, s32 c);
f32 func_002745D4(f32 x);
f32 sinf(f32 x);
extern s32 D_800CE47C;
extern u8 D_800CE850[];
extern s16 D_800CE872;
extern u8 D_800CE874[];
extern f32 D_800D2988;

void func_00224F38(Plr *a, Plr *b) {
    s32 v;
    s32 k;
    f32 K;
    f32 f;
    f32 t;
    if (a->unk6C8 == 0.0f) {
        a->unk650 = 0xB;
    } else {
        a->unk650 = 0xC;
    }
    func_002231B0(a, b, D_800CE874);
    a->unk730 = 2.0f * sinf(a->unk658 * 0.06981318f) * 0.017453294f;
    a->unk734 = 2.0f * sinf(a->unk658 * 0.087266475f) * 0.017453294f;
    a->unk738 = 2.0f * sinf(a->unk658 * 0.104719765f) * 0.017453294f;
    func_002238BC(a, b, D_800CE850);
    if (!(b->flags38 & 0x1000) && 2.0f < a->unk658) {
        func_00218464(a->unk938);
        b->unk20 = 0;
        func_0025DE74(0x2DE, b->pos.x, b->pos.y, b->pos.z, 0, -1);
        a->unk840 = 0;
        if (b->flags38 & 3) {
            func_002227D0(a, b, 2);
        } else {
            func_002227D0(a, b, 0xA);
        }
    }
    v = 0;
    if (a->unk86C == 0x1144) {
        v = a->unk10E == 0;
    }
    if (a->unkE4 == D_800CE47C) {
        k = 0x8A2;
    } else {
        if (v != 0) {
            goto skip;
        }
        f = a->unk6C0;
        if (1.024f <= f) {
            k = 0x8A2;
        } else {
            k = 0x8A7;
            if (!(f <= -1.024f)) {
                k = 0x14;
            }
        }
    }
    a->unk86C = k;
skip:
    t = a->unk11C4 + D_800D2988;
    a->unk11C4 = t;
    if (5.12f < a->unk6C8 && 45.0f < t) {
        a->unk11C4 = func_002745D4(15.0f);
        func_0025DE74(D_800CE872, b->pos.x, b->pos.y, b->pos.z, 0, -1);
        func_0025DE74(0x2E0, b->pos.x, b->pos.y, b->pos.z, 0, -1);
    }
}
