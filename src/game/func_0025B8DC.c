
#include "b13_types.h"

void alSndpPlay(void *p);

void func_0025B8DC(SndVoices *p, s32 idx) {
    SndVoice *v = &p->v[(s16)idx];
    alSndpPlay(v->mgr->player);
    p->v[(s16)idx].unkA4 |= 8;
}

