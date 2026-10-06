#include "common.h"

extern s32 D_800D2AE8;
extern s32 D_8014AEB8[];

void func_0029576C(void) {
    if (D_800D2AE8++ >= 3) {
        D_8014AEB8[1]++;
        D_800D2AE8 = 0;
        D_8014AEB8[3] = 1;
        D_8014AEB8[1] %= D_8014AEB8[0];
    }
}
