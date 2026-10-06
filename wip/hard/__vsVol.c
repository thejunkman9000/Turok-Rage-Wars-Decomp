#include "libaudio.h"

s16 __vsVol(ALVoiceState *vs, ALSeqPlayer *seqp) {
    u32 t1;
    u32 t2;
    t1 = (vs->tremelo * vs->velocity * vs->envGain) >> 6;
    t2 = (vs->sound->sampleVolume * seqp->vol * seqp->chanState[vs->channel].vol) >> 14;
    return (t1 * t2) << 1 >> 16;
}
