#include "b10_types.h"

extern B10Ctl *D_800E2830;
extern f32 D_800C88C0;
s32 func_00245774(void);
s32 func_00245754(void);

void func_002456FC(void) {
    if (func_00245774()) {
        if (func_00245754()) {
            B10Ctl *p = D_800E2830;
            if (p->f60 == 0) {
                p->f60 = 1;
                p->f64 = D_800C88C0;
            }
        }
    }
}
