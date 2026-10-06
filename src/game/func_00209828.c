#include "b02_types.h"

s32 func_00209828(B2Ctl *ctl) {
    s32 i;

    for (i = 1; i < 4; i++) {
        ctl->q[i - 1] = ctl->q[i];
    }
    ctl->q[3] = -1;
    return ctl->q[0] != -1;
}
