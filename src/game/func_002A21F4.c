#include "b23_types.h"

extern s32 D_800D2BB4[];

s32 func_002A21F4(s32 a0, s32 n, s32 keep) {
    if (keep == 0) {
        D_800D2BB4[0] = 0;
    }
    D_800D2BB4[0] += n;
    return 0;
}
