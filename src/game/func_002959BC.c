#include "common.h"

extern s32 D_800D2AF4;
extern s32 D_8014AEB8[];

void func_002959BC(void) {
    s32 *p;
    s32 r;
    if (D_800D2AF4++ >= 3) {
        p = &D_8014AEB8[1];
        p[0] -= 5;
        p[0] = (p[0] + p[-1]) % p[-1];
        p[0] = (f32)p[0] < 0.0f ? -p[0] : p[0];
        p[2] = 1;
        D_800D2AF4 = 0;
    }
}
