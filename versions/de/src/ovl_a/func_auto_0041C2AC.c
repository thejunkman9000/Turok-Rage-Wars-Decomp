#include "o03_types.h"
extern O3Pg *D_800E3518;
extern s32 D_800E28C8;
extern s32 D_80146D70;
extern u8 D_8011FAC0[];
void *func_00252FFC(s32 size);
void func_00286A78(void *p, s32 a, s32 b);
void func_00293318(void *p, s32 a, s32 b);
void func_002A338C(void);
void func_0040C4A8(s32 a);
void func_0040E958(s32 it, s32 on);
s32 func_0040ECB0(s32 p, s32 id);
s32 func_auto_0041C2AC(s32 parent) {
    D_800E3518 = func_00252FFC(0x2C);
    D_800E3518->parent = parent;
    D_800E3518->w1 = func_0040ECB0(parent, 0x3BE);
    func_0040E958(D_800E3518->w1, 1);
    D_800E3518->w2 = func_0040ECB0(parent, 0x3C3);
    func_0040E958(D_800E3518->w2, 0);
    D_800E3518->w3 = func_0040ECB0(parent, 0x3BD);
    func_0040E958(D_800E3518->w3, 0);
    D_800E3518->w4 = func_0040ECB0(parent, 0x3BF);
    func_0040E958(D_800E3518->w4, 0);
    D_800E3518->f14 = 0;
    D_800E3518->f18 = 0;
    func_0040C4A8(0);
    func_002A338C();
    D_800E28C8 = -1;
    D_80146D70 = 0;
    func_00293318(D_8011FAC0, 0, 0);
    func_00286A78(D_8011FAC0 + 0x3C8, 0, 0);
    D_800E3518->f1C = 0;
    return 0;
}
