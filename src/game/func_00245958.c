#include "b10_types.h"

extern B10Ctl *D_800E2830;

s32 func_00245958(void) {
    B10Ctl *p = D_800E2830;
    if (p->f38 == 0) {
        return 0;
    }
    return p->fA8;
}