#include "b13_types.h"

void alCSPStop(void *p);

void func_0025DB78(SndSeq *s) {
    s->unk28 = -1;
    alCSPStop(s->csp);
}
