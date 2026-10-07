#include "b05_types.h"

typedef struct B05P14 {
    u8 pad0[0x8];
    /* 0x008 */ Vec3f pos;
    u8 pad14[0x664];
    /* 0x678 */ f32 f678;
    /* 0x67C */ void* fx67C;
    /* 0x680 */ void* fx680;
    /* 0x684 */ void* fx684;
    u8 pad688[0x28];
    /* 0x6B0 */ u32 flags6B0;
} B05P14;

typedef struct B05Fx { u8 pad0[8]; void *unk8; f32 unkC; s16 unk10; s16 unk12; s16 unk14; s16 unk16; } B05Fx;

extern s32 D_801462C8;
extern u8 D_8013B1A8[];
extern u8 D_800CE410[];
extern u8 D_800CE418[];
extern u8 D_800CE420[];
extern u8 D_800CE428[];

void func_0024BC84(Vec3f *, B05P14 *, Vec3f);
f32 func_0024D274(B05P14 *);
void *func_00268C1C(u8 *, u8 *);
void func_00268C7C(u8 *, void *);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
s32 func_00274544();

static inline void fxupd(B05P14 *p, void **slot, u8 *tab, f32 offz, f32 k1, f32 k2) {
    Vec3f off;
    Vec3f out;
    B05Fx *fx = *slot;
    if (fx != NULL || (fx = func_00268C1C(D_8013B1A8, tab)) != NULL) {
        *slot = fx;
        off.x = 0.0f;
        off.y = 0.0f;
        off.z = offz;
        func_0024BC84(&out, p, off);
        func_00271FA4(&out, &out, &p->pos);
        fx->unk16 = 1;
        fx->unk10 = (s32)out.x;
        fx->unk12 = (s32)(out.y + func_0024D274(p) * k1);
        fx->unk14 = (s32)out.z;
        fx->unkC = k2;
    }
}

void func_0021E5D4(B05P14 *p) {
    s16 vis;

    if (D_801462C8 & 0x4000) {
        p->f678 = 0.0f;
    } else {
        if (p->fx684 != NULL) {
            func_00268C7C(D_8013B1A8, p->fx684);
            p->fx684 = NULL;
        }
    }
    if (p->f678 != 0.0f) {
        fxupd(p, &p->fx67C, D_800CE410, 204.79999f, 0.5f, 1.0f);
        fxupd(p, &p->fx680, D_800CE418, 614.39996f, 0.5f, 1.0f);
        if (p->f678 < 70.0f) {
            vis = 1;
            if (p->f678 < 20.0f) {
                vis = ((func_00274544() % 100) < 0x32) ^ 1;
            } else if ((func_00274544() % 100) < 0xF) {
                vis = 0;
            }
            if (p->fx67C != NULL) {
                ((B05Fx *)p->fx67C)->unk16 = vis;
            }
            if (p->fx680 != NULL) {
                ((B05Fx *)p->fx680)->unk16 = vis;
            }
        }
    } else {
        if (p->fx67C != NULL) {
            func_00268C7C(D_8013B1A8, p->fx67C);
            p->fx67C = NULL;
        }
        if (p->fx680 != NULL) {
            func_00268C7C(D_8013B1A8, p->fx680);
            p->fx680 = NULL;
        }
    }
    if (D_801462C8 & 0x4000) {
        fxupd(p, &p->fx684, D_800CE420, 0.0f, 0.5f, 1.0f);
        if ((p->flags6B0 & 0x20) && p->fx684 != NULL) {
            if (((B05Fx *)p->fx684)->unk8 == D_800CE420) {
                ((B05Fx *)p->fx684)->unk8 = D_800CE428;
            } else {
                ((B05Fx *)p->fx684)->unk8 = D_800CE420;
            }
        }
    }
}
