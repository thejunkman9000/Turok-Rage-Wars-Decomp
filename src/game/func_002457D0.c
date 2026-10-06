#include "b10_types.h"

extern B10Ctl *D_800E2830;

s32 func_002457D0(void) {
    B10Ctl *p = D_800E2830;
    if (p->f38 == 0) {
        return 1;
    }
    return p->f1C > p->f34;
}