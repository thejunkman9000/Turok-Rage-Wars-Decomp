#include "libaudio.h"

void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta);

void alCSPSetChlFXMix(ALCSPlayer *seqp, u8 chan, u8 fxmix) {
    ALEvent evt;
    evt.type = AL_SEQP_MIDI_EVT;
    evt.msg.midi.ticks = 0;
    evt.msg.midi.status = chan | 0xB0;
    evt.msg.midi.byte1 = 0x5B;
    evt.msg.midi.byte2 = fxmix;
    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
