#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);

s32 func_0025B874(SndVoices *p, s16 idx) {
    SndVoice *v;
    SndMgr *m;
    SND_VOICE_AT(v, p, idx);
    m = v->mgr;
    alSndpSetSound(m->player, m->snd[v->idx]);
    return alSndpGetState(m->player);
}
