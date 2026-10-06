#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alMainBusPull(void);
s32 alMainBusParam(void *filter, s32 paramID, void *param);

void alMainBusNew(ALBus *m, void *sources, s32 maxSources) {
    alFilterNew(&m->filter, alMainBusPull, alMainBusParam, 6);
    m->sourceCount = 0;
    m->maxSources = maxSources;
    m->sources = sources;
}
