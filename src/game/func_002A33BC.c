#include "b23_types.h"

extern s32 D_800D2C9C;

void func_002A33BC(s32 v) {
    if (v == 1) {
        D_800D2C9C = v;
        return;
    }
    D_800D2C9C = 0;
}
