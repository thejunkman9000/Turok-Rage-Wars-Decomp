#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);

void func_0025C5FC(SndVoice *v) {
    SndMgr *m = v->mgr;
    v->unkAC = 1;
    v->unk50 = 0;
    if (v->unk10 != m->unk104) {
        alSndpSetSound(m->player, m->snd[v->idx]);
        if (alSndpGetState(m->player) != 0) {
            alSndpStop(m->player);
        }
        v->unk4 = -1;
    }
}
