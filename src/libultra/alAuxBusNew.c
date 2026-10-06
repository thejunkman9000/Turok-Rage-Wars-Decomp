#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alAuxBusPull(void);
s32 alAuxBusParam(void *filter, s32 paramID, void *param);

void alAuxBusNew(ALBus *m, void *sources, s32 maxSources) {
    alFilterNew(&m->filter, alAuxBusPull, alAuxBusParam, 7);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = sources;
}
