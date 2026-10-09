#include "o06_types.h"
extern s32 func_0044252C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern s32 func_0025E2E4(void);
extern void func_0025E2F4(s32 a);
extern u8 D_801462E0[];
s32 func_00445B98(s32 a, s32 b) {
    s32 v = D_801462E0[0];
    v = func_0044252C(b, v, 8, 0, 0xFF, 0);
    if (v == 0xF7) v = 0xF8;
    D_801462E0[0] = v;
    if (func_0025E2E4() <= 0) func_0025E2F4(1);
    return 0;
}
