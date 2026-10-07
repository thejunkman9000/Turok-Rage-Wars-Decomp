#include "b13_types.h"

void func_0025B610(SndVoices *p, s32 tag);
void func_00259938(SndQueue *q, s32 tag);
void func_0025D1DC(SndFx *obj);

void func_00258C2C(SndMgr *m, s32 tag) {
    SndMgr_Lock(m);
    func_0025B610(&m->pool, tag);
    func_00259938(&m->q, tag);
    m->unk2B9C = 0;
    SndMgr_Unlock(m);
    func_0025D1DC(&m->obj2BC0);
}
