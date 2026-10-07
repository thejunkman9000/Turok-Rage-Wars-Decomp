#include "q01_types.h"
typedef struct Q01Sub { u8 pad0[4]; s8 unk4; } Q01Sub;
typedef struct Q01Plr { u8 pad0[0x5DC]; u8 *unk5DC; u8 pad5E0[0x5EC-0x5E0]; s32 unk5EC; } Q01Plr;
typedef struct Q01Obj { u8 pad0[0x1C]; Q01Plr *unk1C; Q01Sub *unk20; void *unk24; } Q01Obj;
extern s32 D_80153788;
extern s32 D_80153760;
extern s32 D_8015377C;
extern s32 D_80153758;
extern s32 D_8015375C;
extern s32 D_800E28C8;
extern s32 D_8013B2C8;
extern s32 D_8014ADA0;
extern s32 D_80153764;
extern u8 D_8011FE88[];
extern u8 D_8011FAC0[];
extern u8 D_8014561C[];
extern u8 D_0044F100[];
extern u8 D_00450BD0[];
extern u8 D_0044F124[];
extern u8 D_0044F0DC[];
void func_00264268(Q01Sub *a);
void func_00264808(Q01Sub *a, s32 b);
void func_002647A8(s32 a);
s32 func_002645A0(s32 a);
void func_00404E28(s32 a);
s32 func_00404F04(s32 a);
void func_0044E178(u8 *a, s32 b, s32 c);
void func_0044EA24(u8 *a);
void func_004426E4(u8 *a, void *b, Q01Plr *c, Q01Sub *d, s32 e);

s32 func_00408E1C(s32 a0, Q01Obj *o) {
    s32 s0, s1, v;
    u8 *p;
    if (D_80153788 == 8) return 0;
    if (D_80153788 == 9 || D_80153788 == 5) {
        func_00264268(o->unk20);
        func_00264808(o->unk20, 1);
    }
    if (D_80153788 == 9) {
        if (D_80153760 != 0 && D_8015377C == 0 && D_80153758 == 0) {
            if (D_8015375C != 0) {
                s1 = D_800E28C8;
            } else {
                s1 = o->unk20->unk4;
            }
            func_002647A8(s1);
            func_0044E178(D_8011FE88, o->unk1C->unk5EC, 2);
            return 1;
        }
        func_0044EA24(D_8011FAC0);
        return 1;
    }
    if (D_8015375C != 0) {
        s1 = D_800E28C8;
    } else {
        s1 = o->unk20->unk4;
    }
    if (D_80153788 == 5) {
        func_002647A8(s1);
        func_0044E178(D_8011FE88, D_8013B2C8, 2);
    }
    if (D_8015375C != 0) {
        if (D_80153788 == 6) D_8014ADA0 = 1;
    }
    if (D_80153788 == 4 && D_80153760 != 0 && D_8015377C == 0) {
        func_00404E28(s1);
        s0 = func_00404F04(s1);
        v = func_002645A0(s1);
        if ((s0 == 0 || v != 0) && s0 != -2 && o->unk24 == (void *)1) {
            func_004426E4(D_8014561C, D_0044F100, o->unk1C, o->unk20, 0);
        } else {
            func_004426E4(D_8014561C, D_00450BD0, o->unk1C, o->unk20, 0);
        }
    } else if (D_80153788 == 3 && D_80153764 != 0) {
        func_00404E28(s1);
        s0 = func_00404F04(s1);
        v = func_002645A0(s1);
        if ((s0 == 0 || v != 0) && s0 != -2) {
            if (o->unk24 == (void *)1) {
                func_004426E4(D_8014561C, D_0044F124, o->unk1C, o->unk20, 0);
            }
        }
    } else {
        if (o->unk24 == (void *)1) o->unk24 = 0;
        if (o->unk24 != 0) {
            if (o->unk24 != D_0044F0DC && o->unk1C != 0) {
                p = o->unk1C->unk5DC + 0x554;
            } else {
                p = D_8014561C;
            }
            func_004426E4(p, o->unk24, o->unk1C, o->unk20, s1);
        }
    }
    return 1;
}
