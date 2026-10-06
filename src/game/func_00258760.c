#include "p3_types.h"

void func_00258760(P3LockOwner *o) {
    P3Lock *l = &o->lock;
    u32 mask = __osDisableInt();
    if (++l->count != 1) {
        __osRestoreInt(mask);
        osRecvMesg(&l->q, NULL, OS_MESG_BLOCK);
    } else {
        __osRestoreInt(mask);
    }
}
