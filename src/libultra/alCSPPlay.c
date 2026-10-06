#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPPlay(ALCSPlayer *seqp) {
    ALEvent evt;
    evt.type = AL_SEQP_PLAY_EVT;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
