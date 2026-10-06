#include "libaudio.h"

ALParam *__allocParam(void);

void alSynStartVoice(ALSynth *drvr, ALVoice *voice, void *w) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0xE;
            update->data.p = w;
            update->next = 0;
            update->moredata = voice->unityPitch;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
