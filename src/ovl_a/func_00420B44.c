#include "o03_types.h"
extern O3Pj *D_800E42D0;
s32 func_00420B44(void) {
    s32 i, n;
    n = 0;
    for (i = 0; i < 4; i++) {
        if ((u32)(D_800E42D0[i].state - 1) < 2) {
            n++;
        }
    }
    return n;
}
