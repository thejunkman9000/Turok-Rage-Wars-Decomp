#include "b05_types.h"

typedef struct B05Pl {
    u8 pad0[0x3];
    /* 0x003 */ s8 b3;
    u8 pad4[0x4];
    /* 0x008 */ Vec3f pos;
    /* 0x014 */ void* p14;
    /* 0x018 */ void* def;
    u8 pad1C[0x4];
    /* 0x020 */ f32 f20;
    u8 pad24[0x14];
    /* 0x038 */ u32 flags38;
    u8 pad3C[0x4];
    /* 0x040 */ f32 f40;
    u8 pad44[0x18];
    /* 0x05C */ s32 q5C;
    /* 0x060 */ s32 q60;
    /* 0x064 */ s32 q64;
    /* 0x068 */ s32 q68;
    /* 0x06C */ f32 ang;
    u8 pad70[0x90];
    /* 0x100 */ u32 flags100;
    u8 pad104[0x4];
    /* 0x108 */ s16 s108;
    u8 pad10A[0x4];
    /* 0x10E */ s8 b10E;
    u8 pad10F[0xC9];
    /* 0x1D8 */ void* owner;
    u8 pad1DC[0x114];
    /* 0x2F0 */ Vec3f v2F0;
    /* 0x2FC */ void* p2FC;
    u8 pad300[0x28];
    /* 0x328 */ f32 f328;
    u8 pad32C[0x18];
    /* 0x344 */ s32 q344;
    /* 0x348 */ s32 q348;
    /* 0x34C */ s32 q34C;
    /* 0x350 */ s32 q350;
    /* 0x354 */ f32 f354;
    u8 pad358[0x12C];
    /* 0x484 */ void* p484;
    u8 pad488[0x38];
    /* 0x4C0 */ void* p4C0;
    u8 pad4C4[0x10C];
    /* 0x5D0 */ s32 unk5D0;
    u8 pad5D4[0x4];
    /* 0x5D8 */ void* stats;
    /* 0x5DC */ void* pawn;
    u8 pad5E0[0x4];
    /* 0x5E4 */ s32 hp;
    u8 pad5E8[0x2];
    /* 0x5EA */ s16 s5EA;
    /* 0x5EC */ s32 u5EC;
    /* 0x5F0 */ s32 u5F0;
    /* 0x5F4 */ s16 s5F4;
    /* 0x5F6 */ u16 s5F6;
    /* 0x5F8 */ s16 s5F8;
    u8 pad5FA[0x8];
    /* 0x602 */ s8 arr602;
    u8 pad603[0x2B];
    /* 0x62E */ s16 s62E;
    u8 pad630[0x20];
    /* 0x650 */ u16 state;
    u8 pad652[0x2];
    /* 0x654 */ u16 prevState;
    u8 pad656[0x2];
    /* 0x658 */ f32 f658;
    /* 0x65C */ s32 u65C;
    u8 pad660[0x4];
    /* 0x664 */ u32 flags664;
    u8 pad668[0x4];
    /* 0x66C */ f32 f66C;
    /* 0x670 */ f32 f670;
    u8 pad674[0x4];
    /* 0x678 */ f32 f678;
    u8 pad67C[0x1C];
    /* 0x698 */ void* p698;
    u8 pad69C[0x10];
    /* 0x6AC */ u32 flags6AC;
    /* 0x6B0 */ u32 flags6B0;
    /* 0x6B4 */ u32 flags6B4;
    /* 0x6B8 */ u32 flags6B8;
    /* 0x6BC */ u32 flags6BC;
    /* 0x6C0 */ f32 f6C0;
    /* 0x6C4 */ f32 f6C4;
    /* 0x6C8 */ f32 f6C8;
    /* 0x6CC */ f32 f6CC;
    /* 0x6D0 */ s32 u6D0;
    u8 pad6D4[0x10];
    /* 0x6E4 */ f32 f6E4;
    /* 0x6E8 */ Vec3f v6E8;
    /* 0x6F4 */ f32 f6F4;
    /* 0x6F8 */ Vec3f v6F8;
    /* 0x704 */ f32 f704;
    u8 pad708[0x10];
    /* 0x718 */ f32 f718;
    /* 0x71C */ s32 u71C;
    /* 0x720 */ f32 f720;
    u8 pad724[0x4];
    /* 0x728 */ f32 f728;
    u8 pad72C[0x2C];
    /* 0x758 */ f32 f758;
    /* 0x75C */ f32 f75C;
    u8 pad760[0x10];
    /* 0x770 */ s16 s770;
    u8 pad772[0x2];
    /* 0x774 */ Vec3f v774;
    /* 0x780 */ f32 f780;
    /* 0x784 */ f32 f784;
    u8 pad788[0x60];
    /* 0x7E8 */ s32 u7E8;
    /* 0x7EC */ f32 f7EC;
    /* 0x7F0 */ f32 f7F0;
    u8 pad7F4[0x60];
    /* 0x854 */ f32 f854;
    u8 pad858[0x14];
    /* 0x86C */ s32 st;
    /* 0x870 */ s32 st870;
    u8 pad874[0xC4];
    /* 0x938 */ s32 u938;
    u8 pad93C[0x37C];
    /* 0xCB8 */ s32 uCB8;
    u8 padCBC[0x51C];
    /* 0x11D8 */ f32 f11D8;
    /* 0x11DC */ f32 f11DC;
    /* 0x11E0 */ f32 f11E0;
    u8 pad11E4[0x8];
    /* 0x11EC */ f32 f11EC;
    u8 pad11F0[0x3C];
    /* 0x122C */ u32 flags122C;
    /* 0x1230 */ f32 f1230;
    /* 0x1234 */ f32 f1234;
    /* 0x1238 */ s32 u1238;
    u8 pad123C[0x4];
    /* 0x1240 */ f32 f1240;
    /* 0x1244 */ f32 f1244;
    u8 pad1248[0xA4];
    /* 0x12EC */ s32 u12EC;
    u8 pad12F0[0xC4];
    /* 0x13B4 */ void* tab13B4;
    u8 pad13B8[0x1C];
    /* 0x13D4 */ s32 u13D4;
    u8 pad13D8[0x78];
    /* 0x1450 */ s32 u1450;
    /* 0x1454 */ void* p1454;
    u8 pad1458[0x27C];
    /* 0x16D4 */ s32 u16D4;
    /* 0x16D8 */ u16 u16D8;
} B05Pl;

#define FLD(T, p, off) (*(T *)((u8 *)(p) + (off)))

typedef struct B05Blk38 { s32 w[14]; } B05Blk38;

typedef struct B05Act {
    u8 pad0[8];
    Vec3f pos;
    u8 *p14;
    u8 pad18[8];
    f32 f20;
    u8 pad24[0x14];
    u32 flags38;
    u8 pad3C[4];
    f32 f40;
    u8 pad44[0x18];
    s32 q5C;
    s32 q60;
    s32 q64;
    s32 q68;
    f32 ang;
    u8 pad70[0x90];
    u32 flags100;
    u8 pad104[4];
    s16 s108;
    u8 pad10A[4];
    s8 b10E;
} B05Act;

typedef struct B05Quat { f32 x, y, z, w; } B05Quat;
typedef struct B05Row20 { u8 pad0[4]; s32 unk4; s32 unk8; s16 unkC; u8 padE[2]; } B05Row20;

extern f32 D_800C78C4;
extern f32 D_800C78C8;
extern f32 D_800C78CC;
extern f32 D_800C78D0;
extern f32 D_800C78D4;
extern f32 D_800C78D8;
extern f32 D_800C78DC;
extern f32 D_800C78E0;
extern f32 D_800C78E4;
extern f32 D_800C78E8;
extern f32 D_800C78EC;
extern f32 D_800C78F0;
extern f32 D_800C78F4;
extern f32 D_800C78F8;
extern f32 D_800C78FC;
extern f32 D_800C7900;
extern f32 D_800C7904;
extern f32 D_800C7908;
extern f32 D_800C790C;
extern f32 D_800C7910;
extern f32 D_800C7914;
extern f32 D_800C7918;
extern f32 D_800C791C;
extern f32 D_800C7920;
extern f32 D_800C7924;
extern f32 D_800C7928;
extern f32 D_800C792C;
extern f32 D_800C7930;
extern f32 D_800C7934;
extern s32 D_800CE430[];
extern s32 D_800CE47C;
extern u8 D_800CE8C8[];
extern u8 D_800CED30[];
extern B05Row20 *D_800D052C[];
extern f32 D_800D2988;
extern u8 *D_80103FCC;
extern u8 D_801040F0[];
extern u8 *D_801041F0;
extern void *D_8010428C;
extern s32 D_801042EC;
extern u8 D_8011FE88[];
extern f32 D_8013B184;
extern s32 D_8013B2C8;
extern u8 D_8013B364[];
extern s32 D_8013B4E8;
extern s32 D_801450B8;
extern s32 D_80146290;
extern u8 D_801462C8[];
extern u8 D_801462E5;
extern u8 D_801468A0[];
extern s32 D_801468F4;
extern s32 D_80146918;
extern s32 D_8014694C;

s32 func_44DE70(u8 *, s32, s32, f32 *, s32);
f32 sqrtf_(f32, void *) __asm__("sqrtf");
void func_00208158(void *);
void func_0020AF9C(u8 *, void *);
void func_00213CF8(void *, void *);
void func_00216488(f32 *, s32, s32, s32, s32, s32);
void func_00217F4C(void *, void *, void *);
void func_00218B84(void *, void *, void *);
void func_00219480(void *, void *);
void func_00219A40(void *, void *, f32 *);
void func_0021B1E4(void *, s32, s32, s32);
void func_0021E5D4(void *, void *);
void func_00220D20(void *);
void func_002227D0(void *, void *, s32);
void func_002228E4(void *, void *, void *);
void func_00222E80(void *, void *);
void func_00222FBC(void *, void *, s32 *);
void func_00229294(void *);
u16 func_0022ACA8(void *, s32, s32);
void func_0022B5B0(void *);
void func_0022B8D0(void *);
void func_0022BD84(void *, void *, void *);
void func_0022C070(void *, void *);
void func_0022C6D4(void *, void *);
s32 func_0022C750(void *, void *);
void func_0022C87C(void *, void *, s32 *);
s32 func_00243A80(void *, f32, f32, f32, s32 *);
s32 func_0024490C(void *, f32, f32, f32, Vec3f, u8 *, f32, f32, f32, f32);
s32 func_00245788();
void func_00245D20(void *, void *, void *, s32);
void func_00246674(void *);
s32 func_002469F8(void *, s32, s32);
void func_00246E34(void *);
void func_00246FF4(void *);
s32 func_0024B690(void *, s32, s32);
void func_0024B6E4(void *, s32, s32);
f32 func_0024D274(void *);
void func_0024D388(void *);
f32 func_0024E410(void *);
f32 func_0024E454(void *);
s32 func_0024E61C(void *);
void *func_0024E7CC(void *);
void func_0025470C(s32);
void func_0025DE74(s32, f32, f32, f32, s32);
void func_0025E438(s32);
void func_0025E460(f32);
f32 func_002745D4(f32, void *, s32);
void func_002748E0(f32 *, f32, f32);
f32 func_002752CC(void *, f32, f32);
f32 func_00275E44(void *, f32, f32);
void func_00278DE8(u8 *, s32, void *);
void func_00278E74(void *, s32, void *);
void func_0028A258(u8 *, void *, f32 *, void *);
void func_0028B250(u8 *, void *, s32, s32);
s32 func_0029EB58(s32);
void func_002A75D0(void *, void *);
void func_002ADA44(void *, u8 *);

void func_00220EB0(B05Pl *p) {
    f32 sp30[3];
    B05Blk38 sp40;
    f32 sp78[3];
    f32 sp88[6];
    f32 spA0[6];
    f32 *pA0;
    f32 spB8;
    f32 spBC;
    s32 spC0, spC4, spC8, spCC;
    u8 *cfg;
    u8 *gm;
    f32 fs3;
    f32 fvA, fvB, fvC, fvD, fvE, fvF, fvG, fvH, fvI, fvJ, fvK, fvL, fvM, fvN, fvO;
    f32 tA, tB, tC, tD;
    s32 a0;
    B05Act *a;
    f32 fs2, fs2f, fs0, fs0f, fs1, fs1f, fa0, fv0, fv1, fv1b, fv0b, fv5, fv6, t, fa, fb, fs0d;
    s32 s0, r, t0, a0s, s1b, v2, s4, a2, a1, v8, v1x, s1d, v13, v14b, t7, v5x, t8, t4b, v6b, v1y;
    u32 t9;
    u16 t3, t9b;
    u8 *s1, *s0p, *s6, *s7, *v5, *v6, *s1c, *s6b, *s1p, *a0p, *v14, *v7, *v4p, *s0b;
    s32 *s5;
    void (*cb)(void *, void *);

    a = (B05Act *)p;
    spC0 = 0;
    fs3 = D_800D2988;
    spC4 = 0;
    if (p->flags122C & 0x2000) {
        fvA = fs3 * D_800C78C4;
        goto L6;
    }
    if (p->flags122C & 0x80) {
        fvA = fs3 * D_800C78C8;
        goto L6;
    }
    if (p->f11E0 > 0.0f) {
        fvA = fs3 * p->f11E0;
L6:
        D_800D2988 = fvA;
    }
    spC8 = p->unk5D0 == 2;
    if (func_00245788() != 0) {
        spC8 = 1;
    }
    cfg = D_801462C8;
    if (FLD(u8, cfg, 0x1D) != 0) {
        spC8 = 1;
    }
    func_0020AF9C(D_8013B364, p);
    if (p->u1450 != 0) {
        func_00208158(p->p1454);
    }
    if (FLD(u8, cfg, 0x1D) != 0) {
        func_0025470C(8);
    }
    a0 = 0;
    p->owner = p;
    p->p4C0 = p;
    if ((p->flags38 & 0x1000) && FLD(u8, cfg, 0x1D) == 0) {
        a0 = FLD(s32, cfg, -0xCAC) == 0;
    }
    func_0025E438(a0);
    if (D_801462E5 == 0) {
        if ((D_80146290 == 0 || !(p->flags6AC & 0x20)) && (p->flags6B0 & 0x800)) {
            if (p->u13D4 != 0) {
                p->u13D4 = 0;
            } else {
                p->u13D4 = 1;
            }
        }
        if (D_801462E5 == 0 && (p->uCB8 == 0 || p->u938 == 0) &&
            (D_80146290 == 0 || !(p->flags6AC & 0x20)) && (p->flags6B0 & 0x200)) {
            B05Row20 *r = D_800D052C[p->s770];
            s16 tt = r->unkC;
            if (tt != -1 && *(s8 *)((u8 *)p + 0x602 + tt * 2) != 0) {
                p->s770 = (u16)r->unkC;
            }
        }
    }
    func_00220D20(p);
    func_00229294(p);
    func_0022B5B0(p);
    func_0022B8D0(p);
    p->flags100 = p->flags100 & 0xFFFDFFFF;
    if (spC8 != 0 && p->f11D8 <= 0.0f) {
        func_00246E34(p);
    }
    if (p->state >= 2U) {
        func_00213CF8(p, (u8 *)p + 0x170);
    }
    gm = D_801468A0;
    if (FLD(s32, gm, 0x54) != 0 && FLD(s32, gm, 0x68) == 0 && FLD(u8, p->stats, 0x8F) == 1) {
        spC0 |= 0x2000;
        spC4 |= 0x400000;
    }
    if (D_80146918 != 0 && FLD(u8, p->stats, 0x8F) == 1) {
        spC0 |= 0x2000;
    }
    if (p->f704 > 0.0f) {
        fvB = p->f704 - D_800D2988;
        if (fvB < 0.0f) {
            fvB = 0.0f;
        }
        p->f704 = fvB;
    }
    if (p->f670 > 0.0f) {
        fvC = p->f670 - D_800D2988;
        if (fvC < 0.0f) {
            fvC = 0.0f;
        }
        p->f670 = fvC;
    }
    sp40 = *(B05Blk38 *)((u8 *)p + 0x688);
    fs2 = D_800D2988;
    while (0.0f < fs2) {
        fs2 = 0.0f;
        pA0 = spA0;
        fs2f = D_800C78CC;
        spCC = 0x1B614;
        {
            p->prevState = p->state;
            p->u65C = p->flags664;
            s1 = a->p14;
            func_002228E4(p, a, func_0024E7CC(a));
            if (D_801462E5 == 0) {
                s0p = &a->pos;
                if (s1 != NULL && s0p != NULL && (FLD(u16, s1, 2) & 0x40)) {
                    fs0 = func_002752CC(s1, a->pos.x, FLD(f32, s0p, 8));
                    tA = (f32)(s32)(fs0 - func_00275E44(s1, a->pos.x, FLD(f32, s0p, 8)));
                    if (tA < D_800C78D0) {
                        fa0 = D_800C78D8 - tA * D_800C78D4;
                    } else {
                        fa0 = 0.0f;
                    }
                } else {
                    fa0 = 0.0f;
                }
                func_0025E460(fa0);
            }
            p->f66C = D_800D2988 * p->f784;
            func_0022C070(p, a);
            fv0 = p->f6C0;
            fa0 = p->f6C4;
            fv1 = sqrtf_(fv0 * fv0 + fa0 * fa0, 0);
            p->f6C8 = fv1;
            p->f75C = p->f75C + fv1 * D_800C78DC;
            p->f758 = p->f758 + fv1 * D_800C78E0;
            p->v6E8 = a->pos;
            p->f658 = p->f658 + D_800D2988;
            r = func_0024E61C(a);
            if (r != 0 && p->u6D0 == 0 && p->f6CC < D_800C78E4) {
                func_00246674(a);
            }
            p->u6D0 = r;
            p->f6CC = a->f20;
            if (r == 0 && (s16)p->state != 0xF && !(a->flags38 & 0x2000)) {
                p->f6E4 = p->f6E4 + D_800D2988;
            } else {
                p->f6E4 = 0.0f;
            }
            if (p->state >= 2U && p->hp != 0) {
                func_00222E80(p, a);
                func_0022C6D4(p, a);
                if (func_0022C750(p, a) == 0) {
                    if (p->f728 != 0.0f && !(a->flags38 & 0x100)) {
                        if ((f32)func_0029EB58((s32)p->f728) < D_800C78E8) {
                            a->ang = a->ang + p->f728;
                        }
                        p->f728 = 0.0f;
                    }
                }
                fs0 = 0.0f;
                if (D_800D052C[p->s62E]->unk8 <= 0 || p->u7E8 == 0 ||
                    (D_801468F4 != 0 && FLD(u8, p->stats, 0x8F) != 0)) {
                    p->u7E8 = 0;
                    t0 = FLD(s32, p, 0x878 + 0xB4);
                    if (t0 != 0 && t0 != 3) {
                        FLD(s32, p, 0x878 + 0xB4) = 3;
                    }
                }
                if (p->hp != 0 && p->u7E8 != 0) {
                    fs0 = D_800C78EC;
                    p->u7E8 = 1;
                }
                p->f7F0 = fs0;
                func_00219480((u8 *)p + 0x878, p);
                func_002748E0(&p->f7EC, fs0, 0.5f);
                if (fs0 == 0.0f && p->f7EC < D_800C78F0) {
                    p->f7EC = 0.0f;
                }
            }
            if (func_00245788(p) == 0 || (u32)(p->state - 0x16) < 0xC) {
                cb = FLD(void *, p->tab13B4, (s16)p->state * 0x18 + 4);
                if (cb != NULL) {
                    cb(p, a);
                }
            }
            v5 = func_0024E7CC(a);
            if (v5 != NULL) {
                func_00245D20(p, v5, &p->v6E8, 1);
                if ((FLD(u32, v5, 0x44) & 0x4000) && p->hp > 0) {
                    func_002227D0(p, a, 0x20);
                    func_00216488(pA0, 0, 0x3E700, 0x41CCCCCC, 0x80, 0);
                    func_00219A40(p, (u8 *)a + 0x170, pA0);
                }
                if (FLD(u32, v5, 0x44) & 0x80000) {
                    p->f854 = p->f854 - D_800D2988;
                    if (p->f854 <= 0.0f) {
                        if (p->hp > 0) {
                            func_00216488(pA0, 0, FLD(u16, v5, 0x50) << 8, 0x41CCCCCC, 0x80, 0);
                            func_00219A40(p, (u8 *)a + 0x170, pA0);
                        }
                        p->f854 = FLD(f32, v5, 0x28);
                    }
                    p->u12EC = 0;
                }
            }
            a0s = (s16)p->state;
            s1b = (a->flags38 & 0xC0000) != 0;
            s5 = FLD(s32 *, p->tab13B4, a0s * 0x18 + 8);
            if (p->u71C != 0) {
                s1b = 1;
                if (a0s != 4) {
                    func_002227D0(p, a, 4);
                }
            }
            fvD = 0.0f;
            if (s1b != 0) {
                fvD = D_800C78F4;
            }
            spB8 = p->f718;
            func_002748E0(&spB8, fvD, 0.25f);
            fv1 = spB8 - p->f718;
            if (fv1 < 0.0f) {
                if (-fv1 < fs2f) {
                    goto L120;
                }
            } else if (fv1 < fs2f) {
L120:
                fv1 = 0.0f;
            }
            tB = p->f718 + fv1;
            fv1b = D_800C78F8 - tB;
            p->f718 = tB;
            if (D_800C78FC <= fv1b && fv1b <= D_800C7900) {
                v2 = *s5 | 0x80;
            } else {
                v2 = *s5 & ~0x80;
            }
            *s5 = v2;
            fvE = 0.0f;
            if ((u32)(p->state - 9) < 4U) {
                fvE = D_800C7904;
            }
            spBC = p->f720;
            func_002748E0(&spBC, fvE, 0.25f);
            fv0b = spBC - p->f720;
            if (fv0b < 0.0f) {
                if (-fv0b < fs2f) {
                    goto L131;
                }
            } else if (fv0b < fs2f) {
L131:
                fv0b = 0.0f;
            }
            tC = p->f720 + fv0b;
            p->f720 = tC;
            fs1f = FLD(f32, p->def, 0xF4) - p->f780 - p->f718 - tC - p->f6F4;
            if (fs1f > 0.0f) {
                fs1 = func_0024E454(a);
                func_0024D388(a);
                fs0f = func_0024D274(a);
                fs0 = func_0024E410(a);
                spA0[0] = a->pos.x;
                spA0[1] = a->pos.y + fs1f;
                spA0[2] = a->pos.z;
                if (func_0024490C(a, a->pos.x, a->pos.y, a->pos.z, *(Vec3f *)spA0, D_801040F0, fs1, fs0f, fs0, fs0) != 0) {
                    tD = FLD(f32, D_80103FCC, 0xE8) - a->pos.y;
                    fv6 = p->v6E8.y - (fs1f - tD);
                    fs1f = tD;
                    p->v6E8.y = fv6;
                }
            }
            p->f6F4 = p->f6F4 + fs1f;
            func_0022BD84(p, a, v5);
            if (p->f678 > 0.0f) {
                p->f678 = p->f678 - D_800D2988;
                if (p->f678 < 0.0f) {
                    p->f678 = 0.0f;
                }
            }
            func_0021E5D4(p, a);
            s6 = a->p14;
            sp30[0] = a->pos.x;
            sp30[1] = a->pos.y;
            sp30[2] = a->pos.z;
            s7 = func_0024E7CC(a);
            if (p->s5EA != 0) {
                p->flags100 = p->flags100 | 0x10000;
                if (p->f11D8 > 0.0f) {
                    p->v6E8 = a->pos;
                }
                s4 = func_00243A80(p, p->v6E8.x, p->v6E8.y, p->v6E8.z, s5);
                p->flags100 = p->flags100 & 0xFFFEFFFF;
            } else {
                s4 = 0;
            }
            s1c = a->p14;
            v6 = func_0024E7CC(a);
            if (s7 != v6) {
                func_00278E74(s6, spC0 | 2, p);
                func_00278E74(s1c, spC0 | 1, p);
                if (v6 != NULL && (FLD(u32, v6, 0x44) & 0x80000)) {
                    p->f854 = FLD(f32, v6, 0x28);
                }
            }
            func_0028A258(D_8011FE88, p, sp30, &a->pos);
            if (s4 != 0) {
                if (D_801041F0 != NULL && *D_801041F0 == 1) {
                    func_00278DE8(D_801041F0, spC4 | 2, p);
                }
                if (D_8010428C != NULL) {
                    func_00278E74(D_8010428C, spC0 | 4, p);
                }
                func_00222FBC(p, a, s5);
                func_0022C87C(p, a, s5);
                if (D_801042EC == 2 && (u32)(p->state - 5) < 2U) {
                    if (a->f20 > 0.0f) {
                        a->f20 = 0.0f;
                    }
                    p->state = 6;
                    p->f6C4 = p->f6C4 * fs2f;
                    p->f6C0 = p->f6C0 * fs2f;
                }
            }
            if (D_801041F0 != NULL && *D_801041F0 == 3) {
                func_002ADA44(p, D_801041F0);
            }
            if (s7 != NULL && v6 != NULL) {
                if (FLD(u32, v6, 0x44) & 0x04000000) {
                    t3 = FLD(u16, v6, 0x4C);
                    if (t3 != p->u5EC) {
                        p->u5EC = t3;
                    }
                }
                if (FLD(u32, v6, 0x44) & 0x08000000) {
                    p->u5EC = FLD(u16, v6, 0x4C);
                    p->u5F0 = FLD(u16, v6, 0x4C);
                    D_8013B2C8 = FLD(u16, v6, 0x4C);
                }
            }
            s0 = 0;
            if (D_8013B4E8 > 0) {
                s6b = spCC + D_8011FE88;
                s1p = D_8011FE88;
L170:
                a0p = FLD(u8 *, s1p, 0x1B620);
                if (a0p != NULL && (v14 = FLD(u8 *, a0p, 0x18), ((FLD(u32, v14, 4) & 4) == 0)) && v14 != NULL &&
                    (sp78[0] = a->pos.x - FLD(f32, a0p, 8), sp78[1] = a->pos.y - FLD(f32, a0p, 0xC), sp78[2] = a->pos.z - FLD(f32, a0p, 0x10),
                     ((f32)(s32)sqrtf_(sp78[0] * sp78[0] + sp78[1] * sp78[1] + sp78[2] * sp78[2], a0p) < FLD(f32, v14, 0x18)))) {
                    if (func_44DE70(D_8011FE88, -1, FLD(s32, v14, 0x20), sp88, 1) != 0) {
                        FLD(f32, D_8011FE88, 0x1B614) = a->pos.x - sp88[0];
                        FLD(f32, D_8011FE88, 0x1B618) = a->pos.y - sp88[1];
                        FLD(f32, D_8011FE88, 0x1B61C) = a->pos.z - sp88[2];
                    } else {
                        FLD(f32, s6b, 0) = sp78[0];
                        FLD(f32, s6b, 4) = sp78[1];
                        FLD(f32, s6b, 8) = sp78[2];
                    }
                    func_0025DE74(0x230, a->pos.x, a->pos.y, a->pos.z, -1);
                    func_0021B1E4(p, FLD(s32, v14, 0x20), 0, 0);
                } else {
                    s0 += 1;
                    s1p += 4;
                    if (s0 < FLD(s32, D_8011FE88, 0x1B660)) {
                        goto L170;
                    }
                }
            }
            p->flags6B0 = 0;
            p->flags6B4 = 0;
            p->flags6B8 = 0;
            p->flags6BC = 0;
        }
    }
    *(B05Blk38 *)((u8 *)p + 0x688) = sp40;
    fvF = p->f11E0;
    D_800D2988 = fs3;
    if (fvF != 0.0f) {
        fvF = fvF - fs3 * D_800C7908;
        if (fvF < 0.0f) {
            fvF = 0.0f;
        }
        p->f11E0 = fvF;
    }
    v7 = func_0024E7CC(a);
    if (v7 != NULL && (FLD(u32, v7, 0x44) & 0x4000)) {
        a->f20 = 0.0f;
    } else if (a->pos.y < D_8013B184 - D_800C790C) {
        func_0021B1E4(p, p->u5EC, 0, 0);
    }
    if (func_0024E61C(a) != 0) {
        p->v6F8 = a->pos;
    }
    if (spC8 != 0) {
        a2 = 0x66;
        if (D_801462E5 != 0) {
            if (D_801468F4 != 0 && FLD(u8, p->stats, 0x8F) != 0) {
                a2 = D_800CE47C;
            } else {
                a2 = D_800CE430[FLD(s16, p->def, 0xC)];
                p->b3 = FLD(u8, p->stats, 0x81);
            }
        }
        func_0028B250(D_8011FE88, p, a2, p->st);
        a1 = p->st;
        if (p->st870 != a1) {
            if (func_0024B690(p, a1, 0) == 0) {
                if (func_00245788(p) != 0) {
                    func_0024B690(p, 0x1B58, 0);
                }
            }
        }
        v8 = func_002469F8(p, p->st, -1);
        a1 = func_002469F8(p, p->st, v8);
        v1x = a1;
        if (v8 < a1) {
            a1 = v8;
        }
        s1d = v1x;
        if (s1d < v8) {
            s1d = v8;
        }
        if (a->b10E != 0) {
            if (a->s108 == a1) {
                if (func_002745D4(D_800C7910, p, a1) < D_800C7914) {
                    a1 = s1d;
                    goto L212;
                }
            } else {
L212:
                func_0024B6E4(p, a1, 0);
                a->b10E = 0;
            }
        }
        if (spC8 == 0) {
            goto L214;
        }
    } else {
L214:
        func_00246FF4(p);
    }
    p->v2F0 = a->pos;
    p->p2FC = a->p14;
    p->f328 = a->f40;
    p->f354 = a->ang;
    p->q344 = a->q5C;
    p->q348 = a->q60;
    p->q34C = a->q64;
    p->q350 = a->q68;
    p->v774 = a->pos;
    if ((FLD(u32, D_801462C8, 0) & 8) || (FLD(s32, D_801462C8, 0x670) != 0 && FLD(u8, p->stats, 0x94) != 0)) {
        p->s5F4 = func_0022ACA8(p, 0, 0);
        p->s5F6 = func_0022ACA8(p, 1, 0);
        p->s5F8 = func_0022ACA8(p, 2, 0);
    }
    v13 = 0x15;
    if (FLD(u32, D_801462C8, 0) & 4) {
        v4p = (u8 *)p + 0x2A;
        do {
            FLD(s16, v4p, 0x602) = 1;
            v13 -= 1;
            v4p -= 2;
        } while (v13 >= 0);
    }
    if (p->pawn != NULL) {
        FLD(s32, p->pawn, 0x120) = p->u16D4;
        FLD(u16, p->pawn, 0x126) = p->u16D8;
    }
    t9 = p->u16D8;
    if (t9 != 0) {
        v14b = (t9 * 2) / 3;
        if (v14b < 5) {
            v14b = 5;
        }
        if ((s32)t9 < v14b) {
            p->u16D8 = 0;
        } else {
            p->u16D8 = t9 - v14b;
        }
    }
    s0b = (u8 *)p + 0x458;
    func_00217F4C((u8 *)p + 0x938, p, s0b);
    func_00218B84((u8 *)p + 0xCCC, p, s0b);
    if (p->s62E == 0) {
        p->tab13B4 = D_800CED30;
    } else {
        p->tab13B4 = D_800CE8C8;
    }
    func_002A75D0((u8 *)p + 0xD40, p);
    if (p->f11D8 > 0.0f) {
        fvG = p->f11D8 - D_800D2988;
        p->f11D8 = fvG;
        if (fvG <= 0.0f) {
            p->flags100 = p->flags100 | 0x01000000;
        }
    }
    if (p->f11DC > 0.0f) {
        fvH = p->f11DC - fs3;
        p->f11DC = fvH;
        if (fvH <= 0.0f) {
            p->f11DC = 0.0f;
            p->flags122C = p->flags122C & ~0x2000;
        }
    }
    if (p->f11EC > 0.0f) {
        fvI = p->f11EC - D_800D2988;
        if (!(fvI >= 0.0f)) {
            fvI = 0.0f;
        }
        p->f11EC = fvI;
    }
    FLD(f32, p->p698, 8) = a->pos.x;
    FLD(f32, p->p698, 0xC) = a->pos.y;
    FLD(f32, p->p698, 0x10) = a->pos.z;
    if (p->u1450 == 0 || (t0 = 0x17, D_8014694C != 0)) {
        t0 = 0;
        if (D_801450B8 != 1) {
            t0 = 0x17;
        }
    }
    func_0028B250(D_8011FE88, (u8 *)p + 0x2E8, D_800D052C[p->s62E]->unk4 + t0, FLD(s32, p->p484, 0x10));
    if (!(p->flags100 & 0x400)) {
        p->st870 = p->st;
    }
    t7 = p->flags122C;
    v5x = t7 & 0x2000;
    if (t7 & 0x4000) {
        if (p->f11D8 <= 0.0f) {
            p->flags122C = t7 & ~0x4000;
        }
        v5x = p->flags122C & 0x2000;
    }
    if (v5x != 0) {
        if (p->f11DC <= 0.0f) {
            p->flags122C = p->flags122C & ~0x2000;
        }
    }
    t8 = p->flags122C;
    if (!(t8 & 0x10020) && t8 != 0) {
        fvJ = p->f1230 - D_800D2988;
        p->f1230 = fvJ;
        if (fvJ <= 0.0f) {
            p->f1240 = 0.0f;
            p->u1238 = -1;
            p->f1230 = 0.0f;
            p->f1234 = 0.0f;
            p->flags122C = t8 & 0xFFFF6000;
            return;
        }
        fvK = p->f1240 - p->f1244;
        if (fvK < 0.0f) {
            fvK = 0.0f;
        }
        p->f1240 = fvK;
        return;
    }
    if (t8 & 0x10000) {
        fa = p->f1230;
        fb = fa - D_800C7918;
        p->f1230 = fb;
        if (fa < 0.0f) {
            fb = 0.0f;
        } else {
            p->f1230 = fb - D_800C7918;
        }
        t9b = p->s5F6;
        p->f1230 = fb;
        t4b = t9b - 1;
        p->s5F6 = t4b;
        if (!(t9b & 0x8000)) {
            p->s5F6 = t9b - 2;
            v6b = t4b;
        } else {
            v6b = 0;
        }
        p->s5F6 = v6b;
        if (((v6b << 16) == 0) || p->f1230 == 0.0f) {
            v1y = 0xFFFE7BFF;
            goto L293;
        }
    } else if (t8 & 0x20) {
        if (p->u1238 == -1) {
            p->f1230 = 0.0f;
            p->u1238 = 0;
            p->f1234 = D_800C791C;
        }
        switch (p->u1238) {
        case 0:
            fvL = p->f1230 + D_800D2988;
            p->f1230 = fvL;
            if (D_800C7920 < fvL || fvL < 0.0f) {
                p->f1234 = -p->f1234;
            }
            if (D_800C7924 < p->f1230) {
                p->f1230 = 0.0f;
                p->u1238 = 1;
                p->f1234 = D_800C7928;
                return;
            }
            break;
        case 1:
            fvM = p->f1230 + D_800D2988;
            p->f1230 = fvM;
            if (D_800C792C < fvM) {
                p->u1238 = 2;
L289:
                p->f1230 = 0.0f;
                return;
            }
            break;
        case 2:
            fvN = p->f1230 + D_800D2988;
            p->f1230 = fvN;
            if (D_800C7930 <= fvN) {
                p->u1238 = 3;
                goto L289;
            }
            break;
        case 3:
            fvO = p->f1230 + p->f1234;
            p->f1230 = fvO;
            if (D_800C7934 < fvO) {
                v1y = -0x21;
                p->u1238 = -1;
L293:
                p->f1230 = 0.0f;
                p->flags122C = p->flags122C & v1y;
            }
            break;
        }
    }
}
