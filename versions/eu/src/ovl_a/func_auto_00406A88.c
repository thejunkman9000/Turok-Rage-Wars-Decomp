#include "q01_types.h"
extern u8 D_auto_80152789;
typedef struct Q01Sub { u8 pad0[0xB0]; s32 unkB0; } Q01Sub;
typedef struct Q01Obj { u8 pad0[0x1C]; s32 unk1C; Q01Sub *unk20; } Q01Obj;
extern s32 D_80153750;
extern s32 D_8015376C;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_800E28C4;
extern s32 D_80153784;
extern s32 D_8015375C;
extern s32 D_8014AD9C;
extern s32 D_800E28CC;
extern s32 D_8014AD94;
extern s32 D_800E28C8;
extern s32 D_80146D60;
extern s32 D_80146D6C;
extern s32 D_auto_800E25A4[];
extern s32 D_auto_800E25B4[];
extern s32 D_8011FECC;
extern u8 D_8014561C[];
extern u8 D_8011FAC0[];
extern u8 D_auto_0044FD8C[];
extern u8 D_auto_0044FD44[];
extern u8 D_auto_00450014[];
extern u8 D_0044F148[];
extern u8 D_auto_004501A0[];
extern u8 D_auto_0045017C[];
s32 func_0026466C();
void func_0029324C(u8 *a);
s32 func_002A137C(u8 *a, s32 b);
void func_00404E28(s32 a);
s32 func_00404F04(s32 a);
s32 func_004050CC(s32 a, s32 *b);
s32 func_00405160(s32 a, s32 *b);
void func_00405338(s32 a, s32 b, s32 *c);
s32 func_00405598(s32 a);
void func_00405648(s32 a, u8 *b, s32 c);
s32 func_004057EC(s32 a);
void func_auto_00405F58(Q01Obj *o);
s32 func_auto_004068CC(Q01Obj *o, s32 a, s32 *b, s32 *c);
void func_004426E4(u8 *a, u8 *b, s32 c, Q01Sub *d, u8 *e);

#define ERRSITE D_80153784 = 1; D_8014AD9C = 0; func_004426E4(D_8014561C, D_auto_0044FD44, arg0->unk1C, arg0->unk20, 0); D_8014AD94 = 0; D_800E28CC = 1;
void func_auto_00406A88(Q01Obj *arg0) {
    u8 buf[16];
    s32 sp28, sp2C, sp30, sp34, sp38, sp3C;
    s32 s0, s1, s2, s3, v0, r, r2, m1;
    u8 *a1; u8 *a0;
    D_80153750 = 0;
    D_8015376C = 1;
    D_80153760 = 0;
    D_8015377C = 0;
    D_800E28C4 = 0;
    D_80153784 = 0;
    D_8015375C = 1;
    if (func_0026466C() == 0) {
        D_80153784 = 1;
        D_8014AD9C = 0;
        func_004426E4(D_8014561C, D_auto_0044FD8C, arg0->unk1C, arg0->unk20, 0);
        D_800E28CC = 1;
        D_8014AD94 = 0;
        return;
    }
    s0 = 0;
    if (D_800E28C8 == -1) {
        s1 = 0;
        do {
            func_00404E28(s0);
            if (func_00404F04(s0) != -2) break;
            s0++;
            if (s0 >= 4) s0 = 0;
            s1++;
        } while (s1 < 4);
        if (s1 == 4) s0 = -1;
        D_800E28C8 = s0;
        if (s0 == -1) {
            ERRSITE
            return;
        }
    }
    if (func_00405598(D_800E28C8) != 0) goto blk59;
    func_0029324C(D_8011FAC0);
    if ((arg0->unk20->unkB0 & 0x1000) && D_800E28CC == 0) {
        D_80146D60 = 1;
        D_800E28CC = 1;
    }
    D_800E28CC = 1;
    if (D_80146D6C != 0 || D_80146D60 != 0) {
        func_00404E28(D_800E28C8);
        if (func_00404F04(D_800E28C8) != -2) goto fin;
        ERRSITE
        return;
    }
    s3 = 0;
    s2 = s3;
    sp2C = -1;
    sp28 = D_800E28C8;
    do {
        if (D_800E28C8 != -1) {
            s3 = func_auto_004068CC(arg0, D_800E28C8, &sp28, &sp2C);
            if (s3 != 0) { s0 = 0; goto found; }
        }
        s0 = 0;
        if (D_800E28C8 != -1) {
            s0 = D_800E28C8 + 1;
            if (s0 >= 4) s0 = 0;
        }
        s1 = 0;
        do {
            func_00404E28(s0);
            if (func_00404F04(s0) != -2) break;
            s0++;
            if (s0 >= 4) s0 = 0;
            s1++;
        } while (s1 < 4);
        if (s1 == 4) s0 = -1;
        D_800E28C8 = s0;
        s2++;
    } while (s2 < 4);
    s0 = 0;
    if (s3 == 0) {
        D_800E28C8 = sp28;
        func_00404E28(sp28);
        if (func_00404F04(D_800E28C8) == -2) {
            ERRSITE
            return;
        }
    }
found:
    s2 = D_800E28C8;
    s1 = D_auto_800E25A4[D_auto_80152789];
    do {
        func_00405338(s2, s0, &sp30);
        func_00405648(sp30, buf, 0x10);
        if (func_002A137C(buf, s1) == 0) { s3 = 1; goto L2; }
        s0++;
    } while (s0 < 0x10);
    s3 = 0;
L2:
    s0 = 0;
    s2 = D_800E28C8;
    s1 = D_auto_800E25B4[D_auto_80152789];
    do {
        func_00405338(s2, s0, &sp34);
        func_00405648(sp34, buf, 0x10);
        if (func_002A137C(buf, s1) == 0) { v0 = 1; goto L3; }
        s0++;
    } while (s0 < 0x10);
    v0 = 0;
L3:
    if (s3 != 0) goto fin;
    if (v0 != 0) goto fin;
    if (func_00405160(D_800E28C8, &sp38) != 0) goto blk59;
    s0 = func_004050CC(D_800E28C8, &sp3C);
    if (s0 != 0) goto blk59;
    m1 = func_004057EC(D_8011FECC + 0x610);
    r2 = func_004057EC(0x18);
    if (sp3C == 0 || sp38 < r2) goto L56;
    if (sp38 < m1) {
        D_80153784 = 1;
        D_80146D60 = 1;
        func_004426E4(D_8014561C, D_auto_004501A0, arg0->unk1C, arg0->unk20, D_0044F148);
        goto after;
    }
    if (sp38 < r2) goto L56;
    goto after;
L56:
    D_80153784 = 1;
    D_80146D60 = 1;
    func_004426E4(D_8014561C, D_auto_0045017C, arg0->unk1C, arg0->unk20, D_0044F148);
after:
    if (s0 == 0) goto fin;
blk59:
    D_80153784 = 1;
    D_80146D60 = 1;
    func_004426E4(D_8014561C, D_auto_00450014, arg0->unk1C, arg0->unk20, D_0044F148);
fin:
    if (D_80153784 == 0) func_auto_00405F58(arg0);
    D_8014AD94 = 0;
    D_800E28CC = 1;
}
