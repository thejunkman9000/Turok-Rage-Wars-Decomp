#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
void alSndpSetPan(void *p, s32 pan);

void func_0025C544(SndVoice *v, s32 pan) {
    SndMgr *m = v->mgr;
    alSndpSetSound(m->player, m->snd[v->idx]);
    alSndpSetPan(m->player, pan & 0xFF);
}
