#include "o01_types.h"

extern u8 D_800E285C[];
s32 func_002A15A0(s32 c);

void func_0040570C(u8 *src, u8 *dst, s32 n) {
    s32 i;
    s32 j;
    for (i = 0; i < n; i++) {
        src[i] = func_002A15A0(src[i]);
        for (j = 0; j < 0x42; j++) {
            if (src[i] == D_800E285C[j]) {
                dst[i] = j;
                break;
            }
        }
        if (j == 0x42) {
            dst[i] = 0;
        }
    }
}
