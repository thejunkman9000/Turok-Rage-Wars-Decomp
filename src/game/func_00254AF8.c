#include "b12_types.h"

s32 func_002512C8(s32 a, s32 b, s32 c, s32 d);

s32 func_00254AF8(s32 unused, s32 a1, u32 flags, s32 a3) {
    s32 v = a1;
    if (flags & 0x10) {
        v = 0;
    }
    return func_002512C8(0, 2, v, a3);
}
