#include "o06_types.h"
extern s32 func_0044252C(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern u8 D_801462E1[];
s32 func_00445CE8(s32 a, s32 b) {
    s32 v = D_801462E1[0];
    v = func_0044252C(b, v, 8, 0, 0xFF, 0);
    if (v == 0xF7) v = 0xF8;
    D_801462E1[0] = v;
    return 0;
}
