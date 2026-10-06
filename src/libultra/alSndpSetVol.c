#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alSndpSetVol(ALSndPlayer *sndp, s16 vol) {
    ALEvent evt;
    ALSoundState *s = sndp->sndState;
    evt.type = AL_SNDP_VOL_EVT;
    evt.msg.sndvol.state = &s[sndp->target];
    evt.msg.sndvol.vol = vol;
    alEvtqPostEvent(&sndp->evtq, &evt, 0);
}
