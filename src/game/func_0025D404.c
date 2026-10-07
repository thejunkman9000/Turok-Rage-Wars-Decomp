#include "b13_types.h"

void *func_00258D60(SndMgr *m);
void alSndpSetSound(void *p, s32 id);
void alSndpStop(void *p);

void func_0025D404(SndFx *fx) {
    void *p;
    if (fx->unk8 != 2 && fx->unk8 != 0) {
        fx->unk8 = 2;
        p = func_00258D60(fx->owner);
        alSndpSetSound(p, ((s16 *)&fx->sndId)[1]);
        alSndpStop(p);
    }
}
