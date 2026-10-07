#include "b13_types.h"

void func_0025BF28(SndVoices *p, s32 tag);
void func_00259A0C(SndQueue *q, s32 tag);

void func_002588F4(SndMgr *m, s32 tag) {
    SndMgr_Lock(m);
    func_0025BF28(&m->pool, tag);
    func_00259A0C(&m->q, tag);
    SndMgr_Unlock(m);
}
