#include "b23_types.h"

extern s32 D_800D2BB0[];

void func_00254784(s32 a);

void func_002A2114(void) {
    if (D_800D2BB0[0] != 0) {
        func_00254784(D_800D2BB0[0]);
    }
    D_800D2BB0[0] = 0;
    D_800D2BB0[3] = 0;
    D_800D2BB0[4] = 0;
}
