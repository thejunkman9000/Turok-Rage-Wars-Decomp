#include "b14_types.h"
typedef struct { u8 b[4]; } Q4;
extern Q4 D_8010FBE0[];
s32 func_0026466C(void) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((D_8010FBE0[i].b[3] >> 3) ^ 1) & 1) {
            return 1;
        }
    }
    return 0;
}
