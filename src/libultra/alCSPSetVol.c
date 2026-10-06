#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPSetVol(ALCSPlayer *seqp, s16 vol) {
    ALEvent evt;
    evt.type = AL_SEQP_VOL_EVT;
    evt.msg.spvol.vol = vol;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
