#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
void alSndpSetPitch(void *p, f32 pitch);

void func_0025C4D4(SndVoice *v, f32 pitch) {
    SndMgr *m = v->mgr;
    alSndpSetSound(m->player, m->snd[v->idx]);
    alSndpSetPitch(m->player, pitch * v->unk34 * v->unkB8);
}
