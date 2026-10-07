#include "b13_types.h"

s32 func_0025BDCC(SndVoices *p, s32 tag, SndMgr *owner) {
    s32 i;
    SndVoice *v = p->v;
    for (i = 0; i < 16; i++) {
        if (v->unk8 != -1 && p->owner->unk102 != i && v->tag == tag && v->unkB4 == owner) {
            return i;
        }
        v++;
    }
    return -1;
}
