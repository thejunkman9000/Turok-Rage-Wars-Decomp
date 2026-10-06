#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpPlay(ALSndPlayer *sndp) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    if (s[sndp->target].state == AL_STOPPED) {
        evt.type = AL_SNDP_PLAY_EVT;
        evt.msg.sndp.state = &s[sndp->target];
        alEvtqPostEvent(&sndp->evtq, &evt, 0);
    }
}
