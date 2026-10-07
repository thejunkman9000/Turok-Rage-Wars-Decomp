#include "b13_types.h"

s32 func_0025C19C(SndVoices *p, s32 tag);
s32 func_00259AD8(SndQueue *q, s32 tag);

s32 func_00258614(SndMgr *m, s32 tag) {
    SndMgr_Lock(m);
    if (func_0025C19C(&m->pool, tag) != 0) {
        SndMgr_Unlock(m);
        return 1;
    }
    if (func_00259AD8(&m->q, tag) != 0) {
        SndMgr_Unlock(m);
        return 1;
    }
    SndMgr_Unlock(m);
    return 0;
}
