#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void *alResamplePull(void);
s32 alResampleParam(void *filter, s32 paramID, void *param);

void alResampleNew(ALResampler *f, ALHeap *hp) {
    alFilterNew(&f->filter, alResamplePull, alResampleParam, 1);
    f->state = alHeapDBAlloc(0, 0, hp, 1, 0x20);
    f->delta = 0;
    f->first = 1;
    f->motion = 0;
    f->upitch = 0;
    f->ctrlList = 0;
    f->ctrlTail = 0;
    f->ratio = 1.0f;
}
