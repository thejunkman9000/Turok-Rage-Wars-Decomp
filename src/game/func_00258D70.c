#include "b13_types.h"

s32 func_00258D70(SndMgr *m, s32 tag) {
    s32 n = 0;
    s32 i;
    SndMgr_Lock(m);
    for (i = 0; i < 17; i++) {
        if (m->pool.v[i].unk4 == tag) {
            n++;
        }
    }
    SndMgr_Unlock(m);
    return n;
}
