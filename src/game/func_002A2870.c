#include "b23_types.h"

extern s32 D_800D2C00;
extern s32 D_800D2C04;
extern s32 D_800D2C08;
extern s32 D_800D2C0C;

void func_002A2870(s32 a, s32 b, s32 c, s32 d) {
    D_800D2C00 = a;
    D_800D2C04 = b;
    D_800D2C08 = c;
    D_800D2C0C = d;
}
