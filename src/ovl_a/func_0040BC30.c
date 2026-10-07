#include "o02_types.h"
typedef struct { s32 w[7]; } O02Vi;
typedef struct { s32 w[5]; } O02Vi20;
extern s32 D_800E28D8;
extern u8 D_800E28DB;
extern u8 D_80146848;
extern s32 D_801450C0;
extern s32 D_80000300;
extern O02Vi D_800E28F8[];
extern O02Vi D_800E2984[];
extern O02Vi20 D_800E2A10[];
extern s32 D_800E28E8;
extern s32 D_800D15C0, D_800D15C4, D_800D15C8, D_800D15CC;
extern s32 D_800E28D0, D_800E28D4;
s32 func_00265370(void);
void func_0040C504(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void osViSetSpecialFeatures(u32 f);
void func_0040BC30(void) {
    O02Vi *e = 0;
    s32 *new_var;
    O02Vi20 t;
    D_801450C0 = 2;
    if (D_800E28D8 == -1) {
        if (func_00265370() != 0x400000) {
            D_800E28D8 = 1;
        } else {
            D_800E28D8 = 0;
        }
        D_80146848 = D_800E28DB;
    }
    switch (D_80000300) {
    case 1:
        e = &D_800E28F8[D_800E28D8];
        break;
    case 0:
    case 2:
        e = &D_800E2984[D_800E28D8];
        break;
    }
    if (e != 0) {
        t = D_800E2A10[D_800E28D8];
        D_800E28E8 = t.w[0];
        D_800D15C0 = t.w[1];
        D_800D15C4 = t.w[2];
        D_800D15C8 = t.w[3];
        new_var = e->w;
        D_800D15CC = t.w[4];
        D_800E28D0 = new_var[0];
        D_800E28D4 = e->w[1];
        func_0040C504(new_var[0], new_var[1], new_var[2], new_var[3], new_var[4], new_var[5]);
        osViSetSpecialFeatures(D_800E28E8 ? 0x40 : 0x80);
        osViSetSpecialFeatures(0x20);
        osViSetSpecialFeatures(2);
    }
}
