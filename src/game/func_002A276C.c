#include "b23_types.h"

extern s32 D_800D2BD0;
extern s32 D_800D2BD4[];

void func_00254784(s32 a);

void func_002A276C(void) {
    if (D_800D2BD0 != 0) {
        func_00254784(D_800D2BD4[0]);
        func_00254784(D_800D2BD4[1]);
        D_800D2BD4[0] = 0;
        D_800D2BD4[1] = 0;
        D_800D2BD0 = 0;
    }
}
