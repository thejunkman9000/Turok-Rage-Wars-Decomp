#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpSetFXMix(ALSndPlayer *sndp, u8 mix) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    evt.type = AL_SNDP_FX_EVT;
    evt.msg.sndfx.state = &s[sndp->target];
    evt.msg.sndfx.fxmix = mix;
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
