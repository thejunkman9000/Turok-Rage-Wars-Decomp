#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);

s32 func_0025B940(SndVoices *p, s16 tag, s16 key) {
    s32 i;
    s16 j;
    SndVoice *v = p->v;
    SndVoice *s;
    SndMgr *m;
    j = 0;
    for (i = 0; i < 16; i++) {
        if (v->unk8 != -1 && p->owner->unk102 != i && v->tag == tag && (v->unkA4 & 0x40) != 0 && v->unk3A == key) {
            SND_VOICE_AT(s, p, j);
            m = s->mgr;
            s->unkAC = 1;
            s->unk50 = 0;
            if (s->unk10 != m->unk104) {
                alSndpSetSound(m->player, m->snd[s->idx]);
                if (alSndpGetState(m->player) != 0) {
                    alSndpStop(m->player);
                }
                s->unk4 = -1;
            }
            return j;
        }
        j = j + 1;
        v++;
    }
    return -1;
}
