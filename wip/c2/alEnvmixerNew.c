#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
void *alEnvmixerPull(void);
s32 alEnvmixerParam(void *filter, s32 paramID, void *param);

void alEnvmixerNew(ALEnvMixer *e, ALHeap *hp) {
    alFilterNew(&e->filter, alEnvmixerPull, alEnvmixerParam, 4);
    e->state = alHeapDBAlloc(0, 0, hp, 1, 0x50);
    e->first = 1;
    e->motion = 0;
    e->f1A = 1;
    e->f28 = 1;
    e->f2E = 1;
    e->f1C = 1;
    e->f1E = 1;
    e->f20 = 0;
    e->f22 = 0;
    e->f26 = 1;
    e->f24.a = 0;
    e->f24.b = 0;
    e->f30 = 0;
    e->f34 = 0;
    e->f18 = 0;
    e->f3C = 0;
    e->f40 = 0;
    e->f44 = 0;
}
