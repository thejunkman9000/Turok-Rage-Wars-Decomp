#include "b12_types.h"

u32 func_002554E0(u32 n) {
    s32 bits = 0;
    s32 hi = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (n & (1 << i)) {
            bits++;
            hi = i;
        }
    }
    if (bits != 1) {
        hi++;
    }
    return 1 << hi;
}
