#include "synth_types.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);
s32 alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
void _handleEvent(ALSndPlayer *sndp, ALEvent *event);

s32 _sndpVoiceHandler(void *node) {
    ALSndPlayer *sndp = (ALSndPlayer *)node;
    ALEvent evt;
    do {
        switch (sndp->nextEvent.type) {
        case AL_SNDP_API_EVT:
            evt.type = AL_SNDP_API_EVT;
            alEvtqPostEvent(&sndp->evtq, &evt, sndp->frameTime);
            break;
        default:
            _handleEvent(sndp, &sndp->nextEvent);
            break;
        }
        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
    } while (sndp->nextDelta == 0);
    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}
