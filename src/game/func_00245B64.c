#include "b10_types.h"

extern B10Ctl *D_800E2830;

void func_00245B64(void) {
    B10Ctl *p = D_800E2830;
    if (p->f44 == 0) {
        void (*fn)(void) = p->fn10;
        if (fn) {
            p->fn10 = 0;
            fn();
        }
        D_800E2830->f44 = 1;
    }
}
