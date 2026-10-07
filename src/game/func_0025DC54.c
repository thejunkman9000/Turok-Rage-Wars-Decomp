#include "b13_types.h"

extern f32 D_800C9110;

void alCSPSetVol(void *p, s16 vol);

void func_0025DC54(SndSeq *s, f32 vol) {
    alCSPSetVol(s->csp, vol * D_800C9110);
    s->vol = vol;
}
