#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpSetPan(ALSndPlayer *sndp, u8 pan) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    evt.type = AL_SNDP_PAN_EVT;
    evt.msg.sndpan.pan = pan;
    evt.msg.sndpan.state = &s[sndp->target];
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
