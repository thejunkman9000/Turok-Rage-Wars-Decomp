#include "s1009_types.h"
extern s32 func_002646B0(void *a);
s32 func_0043ECE8(void *a, S10Menu *m) {
    if (func_002646B0(a) < 2) {
        m->fC->flags &= ~0x1000000;
        if (m->state == 2) m->state = 1;
    } else {
        m->fC->flags |= 0x1000000;
    }
    return 0;
}
