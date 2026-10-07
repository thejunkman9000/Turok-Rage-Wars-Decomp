#include "b13_types.h"

void func_0025BE28(SndVoices *p, s32 tag);
void func_002599A8(SndQueue *q, s32 tag);

void func_00258820(SndMgr *m, s32 tag) {
    SndMgr_Lock(m);
    func_0025BE28(&m->pool, tag);
    func_002599A8(&m->q, tag);
    SndMgr_Unlock(m);
}
