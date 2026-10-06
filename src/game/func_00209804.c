#include "b02_types.h"

void func_00209804(B2Ctl *ctl) {
    s32 i;
    s32 v = -1;

    for (i = 3; i >= 0; i--) {
        ctl->q[i] = v;
    }
}
