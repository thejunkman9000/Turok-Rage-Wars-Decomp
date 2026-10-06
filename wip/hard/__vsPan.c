#include "libaudio.h"

u8 __vsPan(ALVoiceState *vs, ALSeqPlayer *seqp) {
    s32 tmp;
    tmp = vs->sound->samplePan - 64 + seqp->chanState[vs->channel].pan;
    if (tmp < 0) {
        tmp = 0;
    }
    if (tmp > 127) {
        tmp = 127;
    }
    return tmp;
}
