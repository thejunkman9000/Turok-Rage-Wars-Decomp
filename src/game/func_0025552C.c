#include "b12_types.h"

extern u32 D_800D0930;
extern u32 D_800D0938;
extern B12Mgr D_80103F70;

void func_0025552C(void) {
    s32 max = 0;
    u32 i;
    s32 len;
    B12Bucket *p;
    for (i = 0; i < D_800D0930; i++) {
    }
    for (i = 0; i < D_800D0930; i++) {
        len = 0;
        for (p = &D_80103F70.buckets[i]; p; p = p->next) {
            len++;
        }
        if (len < max) {
            len = max;
        }
        max = len;
    }
    if (D_800D0938) {
        D_800D0938 = 0;
    }
}
