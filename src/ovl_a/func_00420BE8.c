#include "o03_types.h"
extern O3Pj *D_800E42D0;
void func_00420214();
void func_0025DF54(s32 a);
s32 func_00420BE8(s32 a0, s32 a1, u32 a2, s32 a3) {
    s32 idx = a2 & 0xFFFF;
    O3Pj *e;
    if ((a2 >> 16) == 3 && a3 == 0) {
        e = &D_800E42D0[idx];
        if (e->state == 1 && e->f10 != -1) {
            func_00420214(idx, e);
            func_0025DF54(0xE7C);
        }
    }
    return 0;
}
