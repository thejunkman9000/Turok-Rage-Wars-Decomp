#include "b10_types.h"

extern B10Ctl *D_800E2830;

s32 func_00243840(B10Vec *a, B10Vec *b) {
    s32 r = 1;
    if (a->y < b->y) {
        r = -1;
    }
    return r;
}