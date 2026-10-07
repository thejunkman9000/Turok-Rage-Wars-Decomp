#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);

void func_0025BF28(SndVoices *p, SndMgr * owner) {
    SndVoice *w = p->v;
    SndVoice *v = p->v;
    SndMgr *m;
    s32 i;
    for (i = 0; i < 17; i++) {
        if (v->unk8 != -1 && p->owner->unk102 != i && v->unkB4 == owner) {
            m = v->mgr;
            v->unkAC = 1;
            v->unk50 = 0;
            if (v->unk10 != m->unk104) {
                alSndpSetSound(m->player, m->snd[w->idx]);
                if (alSndpGetState(m->player) != 0) {
                    alSndpStop(m->player);
                }
                v->unk4 = -1;
            }
        }
        v++;
        w++;
    }
}
