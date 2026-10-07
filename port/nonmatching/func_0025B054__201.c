#include "b13_types.h"

void alSndpSetSound(void *p, s32 id);
s32 alSndpGetState(void *p);
void alSndpStop(void *p);

s32 func_0025B054(SndVoices *p, s32 a, s32 b, s16 pri, s32 c) {
    SndMgr *m = p->owner;
    SndCore *core = (SndCore *)((u8 *)m + 0x7C);
    s32 i;
    s32 best = pri;
    s32 bestIdx = -1;
    s32 lim = best;
    SndVoice *v = p->v;
    SndVoice *s;
    SndMgr *m2;
    for (i = 0; i < 16; i++) {
        if (core->snd[i] == -1) {
            return (s16)i;
        }
        if (v->unk38 < lim) {
            if (!(best < v->unk38) && v->unk38 != 100) {
                best = v->unk38;
                bestIdx = i;
            }
        }
        v++;
    }
    if (bestIdx == -1) {
        return -1;
    }
    if (core->snd[bestIdx] != -1) {
        SND_VOICE_AT(s, p, (s16)bestIdx);
        m2 = s->mgr;
        s->unkAC = 1;
        s->unk50 = 0;
        if (s->unk10 != m2->unk104) {
            alSndpSetSound(m2->player, m2->snd[s->idx]);
            if (alSndpGetState(m2->player) != 0) {
                alSndpStop(m2->player);
            }
            s->unk4 = -1;
        }
        return p->v[15].unkC0 == -1 ? 16 : -1;
    }
    {
        SndNode *h = (SndNode *)m->q.active.link.next;
        if ((SndLink *)h == &m->q.active.link) {
            return (s16)bestIdx;
        }
        if (!(pri < h->body.unk38)) {
            return (s16)bestIdx;
        }
        return -1;
    }
}
