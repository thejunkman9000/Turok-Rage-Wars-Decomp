#include "b13_types.h"

s32 func_0025BA6C(SndVoices *p, s32 tag) {
    s32 i;
    SndVoice *v = p->v;
    for (i = 0; i < 16; i++) {
        if (v->unk8 != -1 && p->owner->unk102 != i && v->tag == tag) {
            return 1;
        }
        v++;
    }
    return 0;
}
