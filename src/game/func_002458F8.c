#include "p2_types.h"

extern Obj74 *D_800E2830;
s32 func_00245788(void);

s32 func_002458F8(void) {
    u32 v;

    if (func_00245788() == 0) {
        return 0;
    }
    v = D_800E2830->f74 & 2;
    return v != 0;
}