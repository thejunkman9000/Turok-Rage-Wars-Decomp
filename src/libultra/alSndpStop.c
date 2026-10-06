#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpStop(ALSndPlayer *sndp) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    evt.type = AL_SNDP_STOP_EVT;
    evt.msg.sndp.state = &s[sndp->target];
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
