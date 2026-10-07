#include "b13_types.h"

void func_0025BB5C(SndVoices *p) {
    s32 i;
    SndVoice *v = p->v;
    for (i = 16; i >= 0; i--) {
        v->unk50 = 0;
        v++;
    }
}
