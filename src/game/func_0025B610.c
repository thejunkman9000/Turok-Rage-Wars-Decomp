#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);

void func_0025B610(SndVoices *p, s32 tag0) {
    register s32 tag asm("$23") = tag0;
    register s32 neg asm("$20");
    register s32 one asm("$21");
    SndVoice *v = p->v;
    SndVoice *w = p->v;
    SndMgr *m;
    s32 i;
    for (i = 0, neg = -1, one = 1; i < 16; i++) {
        do {
            if (v->unk8 != neg && p->owner->unk102 != i && (tag == neg || v->tag != tag)) {
                m = v->mgr;
                v->unkAC = one;
                v->unk50 = 0;
                if (v->unk10 != m->unk104) {
                    alSndpSetSound(m->player, m->snd[w->idx]);
                    if (alSndpGetState(m->player) != 0) {
                        alSndpStop(m->player);
                    }
                    v->unk4 = neg;
                }
            }
            v++;
            w++;
        } while (0);
    }
}