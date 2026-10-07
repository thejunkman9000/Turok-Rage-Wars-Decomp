#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);

s32 func_0025C598(SndVoice *v) {
    SndMgr *m = v->mgr;
    alSndpSetSound(m->player, m->snd[v->idx]);
    return alSndpGetState(m->player);
}
