#include "libaudio.h"

ALParam *__allocParam(void);

void alSynSetFXMix(ALSynth *drvr, ALVoice *voice, u8 fxmix) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0x10;
            @@d@@
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
