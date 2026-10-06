#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void *alAdpcmPull(void);
s32 alLoadParam(void *filter, s32 paramID, void *param);

void alLoadNew(ALLoadFilter *f, void *(*dma)(void *), ALHeap *hp) {
    alFilterNew(&f->filter, alAdpcmPull, alLoadParam, 0);
    f->state = alHeapDBAlloc(0, 0, hp, 1, 0x20);
    f->lstate = alHeapDBAlloc(0, 0, hp, 1, 0x20);
    f->dma = dma(f->dmaState);
    f->lastsam = 0;
    f->first = 1;
    f->memin = 0;
}
