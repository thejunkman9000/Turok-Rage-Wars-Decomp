#include "b13_types.h"



void alSndpDeallocate(void *p, s32 id);

void func_0025C67C(SndVoice *v) {
    SndMgr *m = v->mgr;
    SndCore *c = (SndCore *)((u8 *)m + 0x7C);
    alSndpDeallocate(m->player, c->snd[v->idx]);
    c->snd[v->idx] = -1;
    v->unk38 = 0;
    v->unkC = -1;
    v->unk8 = -1;
    v->tag = -1;
    v->unk3A = -1;
    v->unkB4 = (SndMgr *)-1;
}
