#include "b14_types.h"
typedef struct { u8 b[4]; } Q4;
extern Q4 D_8010FBE0[];
s32 func_002646F4(s32 n) {
    s32 i;
    s32 c = 0;
    for (i = 0; i < 4; i++) {
        if (((D_8010FBE0[i].b[3] >> 3) ^ 1) & 1) {
            c++;
        }
        if (c - 1 == n) {
            return i;
        }
    }
    return -1;
}
