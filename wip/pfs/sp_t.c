#include "libaudio.h"

ALParam *__allocParam(void);
s32 _timeToSamplesNoRound(ALSynth *synth, s32 micros);

void alSynStartVoiceParams(ALSynth *drvr, ALVoice *voice, void *w, f32 pitch, s16 vol, u8 pan, u8 fxmix, s32 t) {
    ALParam *update;
    s32 fx = fxmix;
    if (voice->pvoice != 0) {
        update = __allocParam();
        if (update != 0) {
            if ((s8)fxmix < 0) {
                fx = -fx;
            }
            @@a@@
            @@b@@
            update->samples = _timeToSamplesNoRound(drvr, t);
            update->wave = w;
            voice->pvoice->channelKnob->setParam(voice->pvoice->channelKnob, 3, update);
        }
    }
}
