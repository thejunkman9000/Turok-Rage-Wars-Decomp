/* port (passthru_fix.py): func_00211020 needs a1 a2 a3 - the MIPS code passed this function's own incoming registers on to the callee; the C decomp dropped them. */
#include "b02_types.h"

typedef struct G21Ctl { u8 pad[0x1F0]; f32 fb[8]; } G21Ctl;
#define CTL_FB(c) (((G21Ctl *)(c))->fb)
#define ACT_5D4(a) (*(s32 *)((u8 *)(a) + 0x5D4))
#define ACT_6A8(a) (*(f32 *)((u8 *)(a) + 0x6A8))
#define ACT_6B0(a) (*(u32 *)((u8 *)(a) + 0x6B0))
#define CTL_2E0(c) (*(s32 *)((u8 *)(c) + 0x2E0))
#define CTL_320(c) (*(s32 *)((u8 *)(c) + 0x320))

extern f32 D_800C7120;
extern f32 D_800C7124;
extern f32 D_800C7128;
extern f32 D_800C712C;
extern f32 D_800C7130;
extern f32 D_800C7134;
extern f32 D_800C7138;
extern f32 D_800C713C;
extern f32 D_800C7140;
extern f32 D_800C7144;
extern f32 D_800C7148;
extern f32 D_800C714C;
extern f32 D_800C7150;
extern f32 D_800C7154;
extern s32 D_800D297C;
extern u8 D_8013B364[];

void func_00211020(B2Ctl *ctl, u32, u32, u32);
s32 func_002099B4(B2Ctl *ctl, B2Actor *t);
f32 func_00209BE0(B2Ctl *ctl);
s32 func_00274544();
void func_00209308(B2Ctl *ctl, Vec3f *p, f32 a, f32 f);
f32 func_00209DAC(B2Ctl *ctl);
f32 func_0027272C(Vec3f *a, Vec3f *b);
s32 func_00210EFC(f32 a);
void func_00210964(B2Actor *a, s32 idx);
void func_00209E80(B2Ctl *ctl);
void func_00208410(B2Ctl *ctl);
void func_00208AAC(B2Ctl *ctl);
void func_0020FA10(B2Ctl *ctl);
u8 *func_0020C994(u8 *mgr, s32 id);
s32 func_0020D1CC(u8 *mgr, s32 a, s32 b);
void func_00209874(B2Ctl *ctl, s32 state);

void func_00211470(B2Actor *actor, u32 pt_a1, u32 pt_a2, u32 pt_a3) {
    B2Ctl *ctl;
    B2Actor *t;
    Vec3f *tp;
    s32 s2;
    s32 v;
    s32 idx;
    f32 fs0;
    f32 fs0f;
    f32 d;
    f32 dd;
    f32 nf;
    u32 fa, fb;
    s32 nb;
    u32 f6;
    u8 *mgr;

    ctl = (B2Ctl *)actor->owner->brain;
    func_00211020(ctl, pt_a1, pt_a2, pt_a3);
    mgr = D_8013B364;
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
        if (*(u16 *)(func_0020C994(mgr, s2) + 0xC) & 0x400) {
            ctl->target = NULL;
            func_0020FA10(ctl);
            return;
        }
        if (ctl->unk31C != 0) {
            fs0f = func_00209BE0(ctl);
            v = ctl->unk2D8 - 1;
            fs0 = fs0f * D_800C7120;
            ctl->unk2D8 = v;
            if (v <= 0) {
                ctl->unk2D8 = func_00274544() % 4 + 12;
                ctl->unk2DC = func_00274544() % 2;
                CTL_2E0(ctl) = func_00274544() % 250000 + 0x57E40;
            }
            tp = &t->pos;
            func_00209308(ctl, tp, 2.0f, func_00209DAC(ctl));
            d = func_0027272C(tp, &ctl->owner->pos);
            dd = d + D_800C7124;
            nf = (f32)CTL_2E0(ctl);
            if (dd < 0.0f) {
                if (nf < -dd) goto b19;
                goto b23;
            }
            if (nf < dd) {
b19:
                idx = func_00210EFC(ctl->owner->unk6C - D_800C7128);
                if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                    func_00210964(ctl->owner, idx);
                }
                if (CTL_FB(ctl)[idx] < D_800C712C) {
                    goto b31;
                }
                ACT_6A8(ctl->owner) = D_800C7130;
            } else {
b23:
                dd = d - D_800C7134;
                nf = (f32)CTL_2E0(ctl);
                if (dd < 0.0f) {
                    if (-dd < nf) goto b27;
                    goto b31;
                }
                if (dd < nf) {
b27:
                    idx = func_00210EFC(ctl->owner->unk6C);
                    if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                        func_00210964(ctl->owner, idx);
                    }
                    if (CTL_FB(ctl)[idx] < D_800C7138) {
                        goto b31;
                    }
                    ACT_6A8(ctl->owner) = D_800C713C;
                } else {
b31:
                    ACT_6A8(ctl->owner) = 0.0f;
                }
            }
            if (ctl->unk2DC == 0) {
                idx = func_00210EFC((ctl->owner->unk6C - D_800C7140) - D_800C7144);
                if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                    func_00210964(ctl->owner, idx);
                }
                if (CTL_FB(ctl)[idx] < D_800C7148) {
                    goto b41;
                }
                ctl->owner->unk6A4 = -fs0;
            } else if (ctl->unk2DC == 1) {
                idx = func_00210EFC((ctl->owner->unk6C - D_800C714C) + D_800C7150);
                if (ACT_5D4(ctl->owner) % 2 == D_800D297C) {
                    func_00210964(ctl->owner, idx);
                }
                if (CTL_FB(ctl)[idx] < D_800C7154) {
b41:
                    ctl->owner->unk6A4 = 0.0f;
                    ctl->unk2DC = 2;
                } else {
                    ctl->owner->unk6A4 = fs0;
                }
            } else {
                ctl->owner->unk6A4 = 0.0f;
            }
            ctl->q[0] = -1;
            if (--CTL_320(ctl) == 0 && (func_00274544() % 100 < (s32)fs0f)) {
                f6 = ACT_6B0(ctl->owner);
                ACT_6B0(ctl->owner) = f6 | 0x10;
            }
            if (CTL_320(ctl) < 0) {
                CTL_320(ctl) = (func_00274544() % 2 + 2) * 15;
            }
            func_00209E80(ctl);
        } else {
            ctl->unkC = s2;
            func_00208410(ctl);
            func_00208AAC(ctl);
        }
        if (s2 != ctl->unk10) {
            ctl->unk10 = s2;
            if (func_0020D1CC(mgr, ctl->unk4, s2) == 0) {
                func_00209874(ctl, 1);
            }
        }
    }
}
