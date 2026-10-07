#include "b05_types.h"

typedef struct B05Slot {
    /* 0x00 */ s32 unk0;
    u8 pad4[4];
    /* 0x08 */ s32 unk8;
    u8 padC[4];
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    u8 pad18[0x20];
    /* 0x38 */ s32 last;
} B05Slot;

typedef struct B05P18 {
    u8 pad0[0x5F4];
    s16 s5F4;
    s16 s5F6;
    s16 s5F8;
    u8 pad5FA[0x34];
    s16 s62E;
    u8 pad630[0x7FC];
    B05Slot slot[3];    /* 0xE2C */
    u8 padEE0[0x4D8];
    s32 u13B8;
    s32 u13BC;
    s32 u13C0;
} B05P18;

typedef struct B05A18 {
    u8 pad0[0x29C];
    f32 f29C;
    f32 f2A0;
    f32 f2A4;
    f32 f2A8;
} B05A18;

extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern f32 D_800C76B4;
extern f32 D_800C76B8;
extern f32 D_800C76BC;
extern f32 D_800C76C0;
extern f32 D_800C76C4;
extern f32 D_800C76C8;
extern f32 D_800C76CC;
extern f32 D_800C76D0;
extern f32 D_800C76D4;
extern f32 D_800C76D8;
extern f32 D_800C76DC;
extern f32 D_800C76E0;
extern f32 D_800C76E4;
extern f32 D_800C76E8;
extern u8 D_800CE4CC[];
extern u8 D_800CE4FC[];
extern u8 D_800CE53C[];
extern u8 D_800CE56C[];
extern u8 D_800CE5AC[];
extern u8 D_800CE5DC[];

s32 func_40C4F4();
s32 func_0022AB8C(B05P18 *);
void func_002A921C(s16, f32, f32, f32, f32, s32, s32, s32);
void func_002AB6FC(void *, u8 *);
void func_002ABC18(s32, s32, s16, s16, f32, f32, s32);

void func_0021EA30(B05P18 *p, B05A18 *a) {
    f32 s1f;
    f32 s1;
    f32 s2f;
    f32 s2;
    f32 s3;
    f32 s0;
    f32 s0f;

    s1f = a->f29C / (f32)D_800E28D0;
    s1 = a->f2A0 / (f32)D_800E28D4;
    if (func_40C4F4() == 0) {
        s2f = D_800C76B4;
        s2 = D_800C76B8;
    } else {
        s2f = D_800C76BC;
        s2 = D_800C76C0;
    }
    s3 = s1f * D_800C76C4;
    if (p->s5F4 != p->slot[0].last || p->u13B8 != 0) {
        if (func_40C4F4() == 0) {
            func_002AB6FC(&p->slot[0], D_800CE4CC);
        } else {
            func_002AB6FC(&p->slot[0], D_800CE4FC);
        }
        p->u13B8 = 0;
        p->slot[0].last = p->s5F4;
    }
    if (p->s5F6 != p->slot[1].last || p->u13BC != 0) {
        if (func_40C4F4() == 0) {
            func_002AB6FC(&p->slot[1], D_800CE53C);
        } else {
            func_002AB6FC(&p->slot[1], D_800CE56C);
        }
        p->u13BC = 0;
        p->slot[1].last = p->s5F6;
    }
    if (p->s5F8 != p->slot[2].last || p->u13C0 != 0) {
        if (func_40C4F4() == 0) {
            func_002AB6FC(&p->slot[2], D_800CE5AC);
        } else {
            func_002AB6FC(&p->slot[2], D_800CE5DC);
        }
        p->u13C0 = 0;
        p->slot[2].last = p->s5F8;
    }
    if (func_0022AB8C(p) != -1) {
        if (p->slot[0].unk0 != 0 && p->slot[0].unk8 != 0 && p->s62E < 0x12) {
            s0f = p->slot[0].f14 * s1 + a->f2A8 + a->f2A0;
            s0 = p->slot[0].f10 * s1f + a->f2A4 + s2;
            func_002ABC18(0xBEA, 0, (s32)(s0 - s3), (s32)(s0f - s1 * D_800C76C8), s1f, s1, 1);
            func_002A921C(p->s5F4, s0 - s1f * D_800C76CC, s0f - s1 * D_800C76D0, s1f * s2f, s1, 1, 0, 0);
        }
        if (p->slot[1].unk0 != 0 && p->slot[1].unk8 != 0 && p->s62E < 0x12) {
            s0 = p->slot[1].f10 * s1f + a->f2A4 + s2;
            s0f = p->slot[1].f14 * s1 + a->f2A8 + a->f2A0;
            func_002ABC18(0xBEB, 0, (s32)(s0 - s3), (s32)(s0f - s1 * D_800C76D4), s1f, s1, 1);
            func_002A921C(p->s5F6, s0 - s1f * D_800C76D8, s0f - s1 * D_800C76DC, s1f * s2f, s1, 1, 0, 0);
        }
        if (p->slot[2].unk0 != 0 && p->slot[2].unk8 != 0 && p->s62E < 0x12) {
            s0 = p->slot[2].f10 * s1f + a->f2A4 + s2;
            s0f = p->slot[2].f14 * s1 + a->f2A8 + a->f2A0;
            func_002ABC18(0xBEC, 0, (s32)(s0 - s3), (s32)(s0f - s1 * D_800C76E0), s1f, s1, 1);
            func_002A921C(p->s5F8, s0 - s1f * D_800C76E4, s0f - s1 * D_800C76E8, s1f * s2f, s1, 1, 0, 0);
        }
    }
}
