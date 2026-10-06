#include "libaudio.h"

void __setUsptFromTempo(ALSeqPlayer *seqp, f32 tempo) {
    if (seqp->target != 0) {
        seqp->uspt = (s32)(tempo * seqp->target->qnpt);
    } else {
        seqp->uspt = 488;
    }
}
