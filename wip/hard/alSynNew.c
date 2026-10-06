#include "libaudio.h"

void alLink(ALLink *ln, ALLink *to);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void alSaveNew(void *save);
void alMainBusNew(void *bus, void *ptr, s32 n);
void alAuxBusNew(void *bus, void *ptr, s32 n);
void alAuxBusParam(void *bus, s32 type, void *param);
void alMainBusParam(void *bus, s32 type, void *param);
void alSynAllocFX(ALSynth *drvr, s32 bus, ALSynConfig *c, ALHeap *hp);
void alLoadNew(void *filter, void *dma, ALHeap *hp);
void alLoadParam(void *filter, s32 type, void *param);
void alResampleNew(void *filter, ALHeap *hp);
void alResampleParam(void *filter, s32 type, void *param);
void alEnvmixerNew(void *filter, ALHeap *hp);
void alEnvmixerParam(void *filter, s32 type, void *param);
void alSaveParam(void *filter, s32 type, void *param);

void alSynNew(ALSynth *drvr, ALSynConfig *c) {
    s32 i;
    ALHeap *hp = (ALHeap *)c->heap;
    ALPVoice *pv;
    ALParam *paramPtr;
    void *save;
    drvr->head = 0;
    drvr->curSamples = 0;
    drvr->paramSamples = 0;
    drvr->numPVoices = c->maxPVoices;
    drvr->maxOutSamples = 0xA0;
    drvr->outputRate = c->outputRate;
    drvr->dma = c->dmaproc;
    save = alHeapDBAlloc(0, 0, hp, 1, 0x1C);
    alSaveNew(save);
    drvr->saveBus = save;
    drvr->mainBus = alHeapDBAlloc(0, 0, hp, 1, 0x4C);
    drvr->maxAuxBusses = 1;
    alMainBusNew(drvr->mainBus, alHeapDBAlloc(0, 0, hp, c->maxPVoices, 4), c->maxPVoices);
    drvr->auxBus = alHeapDBAlloc(0, 0, hp, 1, 0x20);
    alAuxBusNew(drvr->auxBus, alHeapDBAlloc(0, 0, hp, c->maxPVoices, 4), c->maxPVoices);
    if (c->fxType != 0) {
        alSynAllocFX(drvr, 0, c, hp);
    } else {
        alAuxBusParam(drvr->auxBus, 2, drvr->mainBus);
    }
    drvr->pFreeList.next = 0;
    drvr->pFreeList.prev = 0;
    drvr->pLameList.next = 0;
    drvr->pLameList.prev = 0;
    drvr->pAllocList.next = 0;
    drvr->pAllocList.prev = 0;
    pv = alHeapDBAlloc(0, 0, hp, c->maxPVoices, 0xDC);
    for (i = 0; i < c->maxPVoices; i++) {
        alLink(&pv->node, &drvr->pFreeList);
        pv->vvoice = 0;
        alLoadNew(pv->decoder, drvr->dma, hp);
        alLoadParam(pv->decoder, 1, 0);
        alResampleNew(pv->resampler, hp);
        alResampleParam(pv->resampler, 1, pv->decoder);
        alEnvmixerNew(pv->envmixer, hp);
        alEnvmixerParam(pv->envmixer, 1, pv->resampler);
        alMainBusParam(drvr->mainBus, 2, pv->envmixer);
        pv->channelKnob = (ALFilter *)pv->envmixer;
        pv++;
    }
    alSaveParam(save, 1, drvr->auxBus);
    paramPtr = alHeapDBAlloc(0, 0, hp, c->maxUpdates, 0x1C);
    drvr->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr->next = drvr->paramList;
        drvr->paramList = paramPtr;
        paramPtr++;
    }
    drvr->heap = hp;
}
