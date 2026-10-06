#include "libaudio.h"

ALParam *__allocParam(void);
s32 _timeToSamplesNoRound(ALSynth *synth, s32 micros);

void alSynSetVol(ALSynth *drvr, ALVoice *voice, s16 vol, s32 time) {
    ALParam *update;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->type = 0xB;
            update->data.i = vol;
            update->d2.i = _timeToSamplesNoRound(drvr, time);
            update->next = 0;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
