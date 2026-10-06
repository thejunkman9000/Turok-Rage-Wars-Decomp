#include "libaudio.h"

ALParam *__allocParam(void);

void alSynSetPitch(ALSynth *drvr, ALVoice *voice, f32 pitch) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 7;
            update->data.f = pitch;
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
