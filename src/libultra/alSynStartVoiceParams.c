#include "libaudio.h"

ALParam *__allocParam(void);
s32 _timeToSamplesNoRound(ALSynth *synth, s32 micros);

void alSynStartVoiceParams(ALSynth *drvr, ALVoice *voice, void *w, f32 pitch, s16 vol, u8 pan, u8 fxmix, s32 t) {
    ALParam *update;
    u8 fx = fxmix;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            if ((s8)fxmix < 0) {
                fx = -(s8)fxmix;
            }
            update->delta = drvr->paramSamples + voice->pvoice->offset;
            update->next = 0;
            update->type = 0xD;
            update->moredata = voice->unityPitch;
            update->d2.v.pan = pan;
            update->d2.v.vol = vol;
            update->d2.v.fxmix = fx;
            update->data.f = pitch;
            update->samples = _timeToSamplesNoRound(drvr, t);
            update->wave = w;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
