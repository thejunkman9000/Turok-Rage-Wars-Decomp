#include "q01_types.h"
typedef struct Q01Sub { u8 pad0[4]; s8 unk4; } Q01Sub;
typedef struct Q01Arg { u8 pad0[0x1C]; s32 unk1C; Q01Sub *unk20; } Q01Arg;
typedef struct Q01Plr { u8 pad0[0x5DC]; u8 *unk5DC; u8 pad5E0[0x698-0x5E0]; s32 unk698; } Q01Plr;
extern s32 D_800E28B0;
extern s32 D_800E28B4;
extern s32 D_800E28B8;
extern s32 D_800E28BC;
extern s32 D_80153710;
extern s32 D_8015375C;
extern s32 D_8015377C;
extern s32 D_80153760;
extern s32 D_80153750;
extern s32 D_80153784;
extern s32 D_800E28C8;
extern s32 D_8014ADA0;
extern s32 D_80146D60;
extern s32 D_8014AD9C;
extern s32 D_80146D6C;
extern u8 D_8014561C[];
extern u8 D_80145040[];
extern u8 D_0044F148[];
extern u8 D_00450758[];
extern u8 D_00450BD0[];
extern u8 D_00451820[];
extern u8 D_00451844[];
extern u8 D_00451868[];
extern u8 D_0045188C[];
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
Q01Plr *func_0022A5B0(void *a, void *b);
void func_004426E4(void *a, void *b, s32 c, s32 d, s32 e);
s32 func_004085E0(s32 a0, Q01Arg *arg) {
    struct { s32 m; s32 pad; } mm;
    u8 *tbl;
    Q01Plr *plr;
    s32 sw;
    s32 rv;
    Q01Plr *u;
    if (D_800E28B0 != 0 || D_800E28B4 != 0) {
        func_002538A8(0);
    }
    if (D_800E28B0 != 0) {
        func_002537D8(0, D_800E28B0);
    }
    if (D_800E28B4 != 0) {
        func_002537D8(0, D_800E28B4);
    }
    D_800E28B0 = 0;
    D_800E28B4 = 0;
    D_800E28B8 = 0;
    D_800E28BC = 0;
    D_80153710 = 0;
    if (D_8015375C != 0) {
        mm.m = D_800E28C8;
    } else {
        mm.m = arg->unk20->unk4;
    }
    if (D_8015375C != 0) {
        D_8014ADA0 = 0;
        D_80146D60 = 0;
        D_8014AD9C = 1;
        D_80146D6C = 0;
        func_004426E4(D_8014561C, D_0044F148, 0, (s32)arg->unk20, 0);
        return 1;
    }
    if (D_8015377C != 0) {
        if (D_80153760 != 0) {
            D_80153784 = 1;
            plr = func_0022A5B0(D_80145040, arg->unk20);
            func_004426E4(plr->unk5DC + 0x554, D_00450758, (s32)plr, plr->unk698, mm.m);
            return 1;
        }
        if (D_80153750 != 0) {
            D_80153784 = 1;
            u = (Q01Plr *)arg->unk1C;
            sw = arg->unk20->unk4;
            mm.m = sw;
            plr = u;
            switch (sw) {
            case 0:
            default: tbl = D_00451820; break;
            case 1: tbl = D_00451844; break;
            case 2: tbl = D_00451868; break;
            case 3: tbl = D_0045188C; break;
            }
            func_004426E4(plr->unk5DC + 0x554, tbl, (s32)plr, plr->unk698, mm.m);
            return 1;
        }
        return 0;
    }
    plr = func_0022A5B0(D_80145040, arg->unk20);
    if (D_80153760 != 0) {
        D_80153784 = 1;
        func_004426E4(D_80145040 + 0x5DC, D_00450BD0, (s32)plr, plr->unk698, mm.m);
        return 1;
    }
    if (D_80153750 == 0) {
        return 0;
    } else {
        D_80153784 = 1;
        return 1;
    }
}
