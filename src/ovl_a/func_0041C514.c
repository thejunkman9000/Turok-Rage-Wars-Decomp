#include "o03_types.h"
extern O3Pg *D_800E3518;
extern s32 D_800E28CC;
extern s32 D_800E3514;
extern s32 D_80146D60;
extern s32 D_8014AD94;
void func_00299368(s32 a);
void func_0029A73C();
s32 func_0029AA08(void);
void func_0040E958(s32 it, s32 on);
void func_0041BF10();
void func_0041C1E4();
void func_0041C2C4();
void func_00435190(s32 a);
s32 func_0041C514(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3CB:
        func_0040E958(D_800E3518->w2, 0);
        func_0041BF10();
        break;
    case 0x3CA:
        func_0041C1E4();
        break;
    case 0x3C7:
        func_0041C2C4();
        break;
    case 0x3C6:
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        D_800E3514 = 1;
        func_00435190(6);
        func_00299368(0x13);
        break;
    }
    return 0;
}
