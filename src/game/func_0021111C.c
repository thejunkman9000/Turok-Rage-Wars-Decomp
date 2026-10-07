#include "b02_types.h"

typedef struct G21Ctl { u8 pad[0x1F0]; f32 fb[8]; } G21Ctl;
#define CTL_FB(c) (((G21Ctl *)(c))->fb)
#define ACT_5D4(a) (*(s32 *)((u8 *)(a) + 0x5D4))

extern f32 D_800C7100;
extern f32 D_800C7104;
extern f32 D_800C7108;
extern f32 D_800C710C;
extern f32 D_800C7110;
extern f32 D_800C7114;
extern f32 D_800C7118;
extern f32 D_800C711C;
extern s32 D_800D297C;
extern u8 D_8013B364[];

void func_00211020(B2Ctl *ctl);
s32 func_002099B4(B2Ctl *ctl, B2Actor *t);
f32 func_0027272C(Vec3f *a, Vec3f *b);
f32 func_00209BE0(B2Ctl *ctl);
s32 func_00274544();
void func_00209308(B2Ctl *ctl, Vec3f *p, f32 a, f32 f);
f32 func_00209DAC(B2Ctl *ctl);
s32 func_00210EFC(f32 a);
void func_00210964(B2Actor *a, s32 idx);
void func_00209E80(B2Ctl *ctl);
void func_00208410(B2Ctl *ctl);
void func_00208AAC(B2Ctl *ctl);
s32 func_0020D1CC(u8 *mgr, s32 a, s32 b);
void func_00209874(B2Ctl *ctl, s32 state);

void func_0021111C(B2Actor *actor) {
    B2Ctl *ctl;
    B2Actor *t;
    s32 s2;
    s32 v;
    s32 r;
    u32 fa, fb;
    s32 nb;
    s32 idx;
    f32 fs0;

    ctl = (B2Ctl *)actor->owner->brain;
    func_00211020(ctl);
    if (ctl->target != NULL) {
        if (!(ctl->unk318 & 3)) {
            ctl->unk31C = func_002099B4(ctl, ctl->target);
        }
        ctl->unk318 = ctl->unk318 + 1;
        t = ctl->target->owner;
        fa = ctl->owner->flags38 & 0x3000;
        fb = t->flags38 & 0x3000;
        nb = fb != 0;
        if (fa && !nb) {
            func_00209874(ctl, 12);
            return;
        }
        s2 = ((B2Ctl *)t->brain)->unk4;
        if (ctl->unk31C != 0) {
            if (func_0027272C(&t->pos, &ctl->owner->pos) < D_800C7100) {
                ctl->unk230 = 3;
                func_00209874(ctl, 7);
                return;
            }
            fs0 = func_00209BE0(ctl) * D_800C7104;
            v = ctl->unk2D8 - 1;
            ctl->unk2D8 = v;
            if (v <= 0) {
                ctl->unk2D8 = func_00274544() % 4 + 12;
                ctl->unk2DC = func_00274544() % 2;
                r = func_00274544();
                if (r / 2 * 2 == r - 1) {
                    ctl->unk2DC = 2;
                }
            }
            func_00209308(ctl, &t->pos, 2.0f, func_00209DAC(ctl));
            if (ctl->unk2DC == 0) {
                idx = func_00210EFC((ctl->owner->unk6C - D_800C7108) - D_800C710C);
                if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                    func_00210964(ctl->owner, idx);
                }
                if (CTL_FB(ctl)[idx] < D_800C7110) {
                    goto b23;
                }
                ctl->owner->unk6A4 = -fs0;
            } else if (ctl->unk2DC == 1) {
                idx = func_00210EFC((ctl->owner->unk6C - D_800C7114) + D_800C7118);
                if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                    func_00210964(ctl->owner, idx);
                }
                if (CTL_FB(ctl)[idx] < D_800C711C) {
b23:
                    ctl->owner->unk6A4 = 0.0f;
                    ctl->unk2DC = 2;
                } else {
                    ctl->owner->unk6A4 = fs0;
                }
            } else {
                ctl->owner->unk6A4 = 0.0f;
            }
            ctl->q[0] = -1;
            func_00209E80(ctl);
        } else {
            ctl->unkC = s2;
            func_00208410(ctl);
            func_00208AAC(ctl);
        }
        if (s2 != ctl->unk10) {
            ctl->unk10 = s2;
            if (func_0020D1CC(D_8013B364, ctl->unk4, s2) == 0) {
                func_00209874(ctl, 1);
            }
        }
    }
}
