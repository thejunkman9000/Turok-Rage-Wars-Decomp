#include "o01_types.h"

extern u8 D_800E285C[];

void func_00405648(u8 *src, u8 *dst, s32 n) {
    s32 i;
    s32 seen;
    for (i = 0; i < n; i++) {
        dst[i] = 0;
    }
    seen = 0;
    for (i = 0; i < n; i++) {
        if (src[i] < 0x42) {
            if (src[i] == 0 && seen == 0) {
                dst[i] = 0x20;
            } else {
                dst[i] = D_800E285C[src[i]];
                seen = 1;
            }
        } else {
            dst[i] = 0x7E;
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (dst[i] != 0x20 && dst[i] != 0) {
            break;
        }
        dst[i] = 0;
    }
    dst[n - 1] = 0;
}
