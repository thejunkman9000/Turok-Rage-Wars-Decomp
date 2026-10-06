#include "libaudio.h"

u8 __alCSeqNextDelta(ALCSeq *seq, s32 *pDeltaTicks);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void __CSPPostNextSeqEvent(ALCSPlayer *seqp) {
    ALEvent evt;
    s32 deltaTicks;
    if (seqp->state != 1) {
        return;
    }
    if (seqp->target == 0) {
        return;
    }
    if (__alCSeqNextDelta(seqp->target, &deltaTicks)) {
        evt.type = 0;
        alEvtqPostEvent(&seqp->evtq, &evt, deltaTicks * seqp->uspt);
    }
}
