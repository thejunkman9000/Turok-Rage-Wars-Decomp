#include "b12_types.h"

extern s32 D_800D0910;

s32 func_00250B98(void) {
    if (++D_800D0910 == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    return D_800D0910;
}
