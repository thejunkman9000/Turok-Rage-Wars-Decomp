#include "b13_types.h"

void alSndpPlay(void *p);

void func_0025C5DC(SndVoice *v) {
    alSndpPlay(v->mgr->player);
}
