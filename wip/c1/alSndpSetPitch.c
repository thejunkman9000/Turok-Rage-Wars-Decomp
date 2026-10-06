#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpSetPitch(ALSndPlayer *sndp, f32 pitch) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    evt.type = AL_SNDP_PITCH_EVT;
    evt.msg.sndpitch.state = &s[sndp->target];
    evt.msg.sndpitch.pitch = pitch;
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
