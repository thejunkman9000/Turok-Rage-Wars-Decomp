#include "libaudio.h"

ALParam *__allocParam(void);
void _freePVoice(ALSynth *drvr, ALPVoice *pvoice);

void alSynFreeVoice(ALSynth *drvr, ALVoice *voice) {
    ALParam *update;
    if (voice->pvoice != 0) {
        if (voice->pvoice->offset != 0) {
            update = __allocParam();
            if (update != 0) {
                update->delta = drvr->paramSamples + voice->pvoice->offset;
                update->type = 0;
                update->data = (s32)voice->pvoice;
                voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
                voice->pvoice = 0;
            }
        } else {
            _freePVoice(drvr, voice->pvoice);
            voice->pvoice = 0;
        }
    }
}
