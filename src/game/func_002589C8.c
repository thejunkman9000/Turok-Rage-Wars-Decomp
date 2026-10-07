#include "b13_types.h"

void func_0025C028(SndVoices *p, s32 tag);
void func_00259A70(SndQueue *q, s32 tag);

void func_002589C8(SndMgr *m, s32 tag) {
    SndMgr_Lock(m);
    func_0025C028(&m->pool, tag);
    func_00259A70(&m->q, tag);
    SndMgr_Unlock(m);
}
