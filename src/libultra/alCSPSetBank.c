#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPSetBank(ALCSPlayer *seqp, void *b) {
    ALEvent evt;
    evt.type = AL_SEQP_BANK_EVT;
    evt.msg.spbank.bank = b;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
