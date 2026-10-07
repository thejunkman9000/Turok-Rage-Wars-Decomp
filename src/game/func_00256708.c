#include "b12_types.h"

void func_00256708(P3Lock *l) {
    u32 mask;
    u32 m2;
    if (l->count) {
        mask = __osDisableInt();
        if (++l->count != 1) {
            __osRestoreInt(mask);
            osRecvMesg(&l->q, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
        m2 = __osDisableInt();
        if (--l->count != 0) {
            __osRestoreInt(m2);
            osSendMesg(&l->q, 0, 1);
        } else {
            __osRestoreInt(m2);
        }
    }
}
