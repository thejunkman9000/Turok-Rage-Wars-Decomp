#include "b10_types.h"

extern B10Ctl *D_800E2830;
s32 func_4030E0(void);

s32 func_00245608(s32 id, void (*f1)(void), void (*f2)(void)) {
    s32 r = func_4030E0();
    if (D_800E2830->fE0 == id) {
        D_800E2830->fE4 = f1;
        D_800E2830->fE8 = f2;
    } else {
        if (f1) {
            f1();
        }
        if (f2) {
            f2();
        }
    }
    return r;
}
