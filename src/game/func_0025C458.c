#include "p3_types.h"

void alSndpSetSound(void *sndp, s16 id);
void alSndpSetVol(void *sndp, s16 vol);

void func_0025C458(P3Snd *s, s32 vol) {
    P3SndBank *b = s->bank;
    alSndpSetSound(b->sndp, b->snd[s->idx]);
    alSndpSetVol(b->sndp, (s16)((f32)vol * s->volScale));
}
