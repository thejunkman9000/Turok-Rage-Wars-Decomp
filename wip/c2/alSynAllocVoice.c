#include "libaudio.h"

ALParam *__allocParam(void);
s32 _allocatePVoice(ALSynth *drvr, ALPVoice **pvoice, s16 priority);

s32 alSynAllocVoice(ALSynth *drvr, ALVoice *voice, ALVoiceConfig *vc) {
    ALParam *update;
    ALPVoice *pvoice = 0;
    s32 stolen;
    ALFilter *f;
    voice->priority = vc->priority;
    voice->unityPitch = vc->unityPitch;
    voice->table = 0;
    voice->fxBus = vc->fxBus;
    voice->state = 0;
    voice->pvoice = 0;
    stolen = _allocatePVoice(drvr, &pvoice, vc->priority);
    if (pvoice != 0) {
        f = pvoice->channelKnob;
        if (stolen != 0) {
            pvoice->offset = 0x200;
            pvoice->vvoice->pvoice = 0;
            update = __allocParam();
            update->delta = drvr->paramSamples;
            update->type = 0xB;
            update->data.i = 0;
            update->data2 = pvoice->offset - 0x40;
            f->setParam(f, 3, update);
            update = __allocParam();
            if (update != 0) {
                update->delta = drvr->paramSamples + pvoice->offset;
                update->type = 0xF;
                update->next = 0;
                f->setParam(f, 3, update);
            }
        } else {
            pvoice->offset = 0;
        }
        pvoice->vvoice = voice;
        voice->pvoice = pvoice;
    }
    return pvoice != 0;
}
