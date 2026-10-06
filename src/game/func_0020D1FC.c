#include "b02_types.h"

void func_0020D1FC(B2Mgr *m) {
    s32 i;
    s32 v = -1;

    for (i = 63; i >= 0; i--) {
        m->slots[i] = v;
    }
}
