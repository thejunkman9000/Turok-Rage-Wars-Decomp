#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPSetSeq(ALCSPlayer *seqp, void *seq) {
    ALEvent evt;
    evt.type = AL_SEQP_SEQ_EVT;
    evt.msg.spseq.seq = seq;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
