#include "common.h"

extern s32 D_800D2AF8;
extern s32 D_8014AEB8[];

void func_00295A60(void) {
    if (D_800D2AF8++ >= 3) {
        D_8014AEB8[1] += 5;
        D_800D2AF8 = 0;
        D_8014AEB8[3] = 1;
        D_8014AEB8[1] %= D_8014AEB8[0];
    }
}
