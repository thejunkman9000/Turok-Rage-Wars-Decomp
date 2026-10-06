#include "b14_types.h"
s32 func_0026477C(s32 i);
extern s32 D_8010FBF0[];
s32 func_002645F0(s32 i) {
    s32 r;
    if (func_0026477C(i) != 0) {
        r = D_8010FBF0[i];
    } else {
        r = 0;
    }
    return r;
}
