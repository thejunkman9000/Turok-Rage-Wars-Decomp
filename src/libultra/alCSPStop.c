#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPStop(ALCSPlayer *seqp) {
    ALEvent evt;
    evt.type = AL_SEQP_STOP_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
