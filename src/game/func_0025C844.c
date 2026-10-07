#include "b13_types.h"

void alSndpDeallocate(void *p, s32 id);

s32 func_0025C844(SndVoices *p, s16 idx) {
    SndVoice *v;
    SndMgr *m;
    SndCore *c;
    SND_VOICE_AT(v, p, idx);
    m = v->mgr;
    c = (SndCore *)((u8 *)m + 0x7C);
    alSndpDeallocate(m->player, c->snd[v->idx]);
    c->snd[v->idx] = -1;
    v->unk38 = 0;
    v->unkC = -1;
    v->unk8 = -1;
    v->tag = -1;
    v->unk3A = -1;
    v->unkB4 = (SndMgr *)-1;
    return 0;
}
