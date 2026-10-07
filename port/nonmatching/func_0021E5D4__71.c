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
extern f32 D_800C768C;
extern f32 D_800C7690;
extern f32 D_800C7694;
extern f32 D_800C7698;
extern f32 D_800C769C;
extern f32 D_800C76A0;
extern f32 D_800C76A4;
extern f32 D_800C76A8;
extern f32 D_800C76AC;
extern f32 D_800C76B0;

void func_0024BC84(Vec3f *, B05P14 *, Vec3f);
f32 func_0024D274(B05P14 *);
void *func_00268C1C(u8 *, u8 *);
void func_00268C7C(u8 *, void *);
void func_00271FA4(Vec3f *, Vec3f *, Vec3f *);
s32 func_00274544();

void func_0021E5D4(B05P14 *p) {
    Vec3f out;
    Vec3f off;
    B05Fx *fx;
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
        fx = p->fx67C;
        if (fx != NULL || (fx = func_00268C1C(D_8013B1A8, D_800CE410)) != NULL) {
            p->fx67C = fx;
            off.x = 0.0f;
            off.y = 0.0f;
            off.z = D_800C768C;
            func_0024BC84(&out, p, off);
            func_00271FA4(&out, &out, &p->pos);
            fx->unk16 = 1;
            fx->unk10 = (s32)out.x;
            fx->unk12 = (s32)(out.y + func_0024D274(p) * D_800C7690);
            fx->unkC = D_800C7694;
            fx->unk14 = (s32)out.z;
        }
        fx = p->fx680;
        if (fx != NULL || (fx = func_00268C1C(D_8013B1A8, D_800CE418)) != NULL) {
            p->fx680 = fx;
            off.x = 0.0f;
            off.y = 0.0f;
            off.z = D_800C7698;
            func_0024BC84(&out, p, off);
            func_00271FA4(&out, &out, &p->pos);
            fx->unk16 = 1;
            fx->unk10 = (s32)out.x;
            fx->unk12 = (s32)(out.y + func_0024D274(p) * D_800C769C);
            fx->unkC = D_800C76A0;
            fx->unk14 = (s32)out.z;
        }
        if (p->f678 < D_800C76A4) {
            vis = 1;
            if (p->f678 < D_800C76A8) {
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
        fx = p->fx684;
        if (fx != NULL || (fx = func_00268C1C(D_8013B1A8, D_800CE420)) != NULL) {
            p->fx684 = fx;
            off.x = 0.0f;
            off.y = 0.0f;
            off.z = 0.0f;
            func_0024BC84(&out, p, off);
            func_00271FA4(&out, &out, &p->pos);
            fx->unk16 = 1;
            fx->unk10 = (s32)out.x;
            fx->unk12 = (s32)(out.y + func_0024D274(p) * D_800C76AC);
            fx->unkC = D_800C76B0;
            fx->unk14 = (s32)out.z;
        }
        if ((p->flags6B0 & 0x20) && p->fx684 != NULL) {
            if (((B05Fx *)p->fx684)->unk8 != D_800CE420) {
                ((B05Fx *)p->fx684)->unk8 = D_800CE420;
            } else {
                ((B05Fx *)p->fx684)->unk8 = D_800CE428;
            }
        }
    }
}
