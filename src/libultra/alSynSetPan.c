#include "libaudio.h"

ALParam *__allocParam(void);

void alSynSetPan(ALSynth *drvr, ALVoice *voice, u8 pan) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0xC;
            update->data.i = pan;
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
