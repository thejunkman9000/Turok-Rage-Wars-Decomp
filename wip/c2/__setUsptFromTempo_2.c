#include "libaudio.h"

void __setUsptFromTempo_2(ALCSPlayer *seqp, f32 tempo) {
    if (seqp->target != 0) {
        seqp->uspt = (s32)(tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 488;
    }
}
