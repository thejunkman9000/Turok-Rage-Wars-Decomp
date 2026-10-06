#include "libaudio.h"

ALParam *__allocParam(void);

void alSynSetFXMix(ALSynth *drvr, ALVoice *voice, u8 fxmix) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0x10;
            update->data.i = ((s8)fxmix < 0) ? -(s8)fxmix : (fxmix & 0xFF);
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
