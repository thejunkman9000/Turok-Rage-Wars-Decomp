#include "libaudio.h"

ALParam *__allocParam(void);

void alSynStopVoice(ALSynth *drvr, ALVoice *voice) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            @@st@@
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
