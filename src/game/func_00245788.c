#include "b10_types.h"

extern B10Ctl *D_800E2830;

s32 func_00245788(void) {
    B10Ctl *p = D_800E2830;
    s32 r = 0;
    if (p->f38) {
        if (p->f1C >= p->f30 && p->f1C <= p->f34) {
            r = 1;
        }
    }
    return r;
}