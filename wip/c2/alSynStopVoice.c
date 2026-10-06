#include "libaudio.h"

ALParam *__allocParam(void);

void alSynStopVoice(ALSynth *drvr, ALVoice *voice) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0xF;
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
