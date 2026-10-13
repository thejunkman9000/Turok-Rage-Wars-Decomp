#include "o03_types.h"
extern O3Pg *D_800E3518;
extern s32 D_800E28CC;
extern s32 D_800E3514;
extern s32 D_80146D60;
extern s32 D_8014AD94;
void func_00299368(s32 a);
void func_0029A73C();
s32 func_0029AA08(void);
void func_auto_0040E8D8(s32 it, s32 on);
void func_auto_0041BE90();
void func_auto_0041C164();
void func_auto_0041C244();
void func_auto_00434FB4(s32 a);
s32 func_auto_0041C494(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3C4:
        func_auto_0040E8D8(D_800E3518->w2, 0);
        func_auto_0041BE90();
        break;
    case 0x3C5:
        func_auto_0041C164();
        break;
    case 0x3C2:
        func_auto_0041C244();
        break;
    case 0x3C1:
        D_80146D60 = 1;
        D_800E28CC = 1;
        D_8014AD94 = 0;
        D_800E3514 = 1;
        func_auto_00434FB4(6);
        func_00299368(0x13);
        break;
    }
    return 0;
}
