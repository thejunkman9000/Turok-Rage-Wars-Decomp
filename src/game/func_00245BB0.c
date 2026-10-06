#include "b10_types.h"

extern B10Ctl *D_800E2830;
void func_002537D8(s32 a, void *p);

void func_00245BB0(void) {
    if (D_800E2830->f48 == 0) {
        void (*fn)(void);
        if (D_800E2830->p0) {
            func_002537D8(0, D_800E2830->p0);
        }
        D_800E2830->p0 = 0;
        D_800E2830->f4 = 0;
        D_800E2830->f38 = 0;
        D_800E2830->f3C = 0;
        D_800E2830->f60 = 0;
        fn = D_800E2830->fn0C;
        if (fn) {
            D_800E2830->fn0C = 0;
            fn();
        }
        D_800E2830->f48 = 1;
    }
}
