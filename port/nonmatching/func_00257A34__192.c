#include "b13_types.h"

void func_002598D4(SndQueue *q, s32 tag);
void func_0025BABC(SndVoices *p, s16 idx);

s32 func_00257A34(SndMgr *m, s32 tag) {
    SndCore *c;
    s32 n = 0;
    s32 i;
    SndVoice *v;
    if (tag != -1) {
        SndMgr_Lock(m);
        func_002598D4(&m->q, tag);
        c = (SndCore *)((u8 *)m + 0x7C);
        for (i = 0; i < 17; i++) {
            if (m->pool.v[i].unk4 == tag) {
                n++;
                v = &m->pool.v[i];
                if (i == 16) {
                    v->unk4 = -1;
                    v->unk38 = 0;
                    v->unk3A = -1;
                    v->unkC = -1;
                    v->unk8 = -1;
                } else {
                    if (v->unkA0 > 0) {
                        v->unkA0 = 0;
                        v->unkA4 &= ~0x10;
                    }
                    if (c->snd[i] != -1) {
                        func_0025BABC(&m->pool, i);
                    }
                }
            }
        }
        SndMgr_Unlock(m);
    }
    return n;
}
