#include "common.h"

extern s32 D_800D2AE4;
extern s32 D_8014AEB8[];

void func_002957EC(void) {
    if (D_800D2AE4++ >= 3) {
        D_8014AEB8[1]--;
        D_8014AEB8[3] = 1;
        D_8014AEB8[1] = (D_8014AEB8[1] + D_8014AEB8[0]) % D_8014AEB8[0];
        D_8014AEB8[1] = (f32)D_8014AEB8[1] < 0.0f ? -D_8014AEB8[1] : D_8014AEB8[1];
        D_800D2AE4 = 0;
    }
}
