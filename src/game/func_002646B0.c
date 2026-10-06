#include "b14_types.h"
typedef struct { u8 b[4]; } Q4;
extern Q4 D_8010FBE0[];
s32 func_002646B0(void) {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 4; i++) {
        if (((D_8010FBE0[i].b[3] >> 3) ^ 1) & 1) {
            n++;
        }
    }
    return n;
}
