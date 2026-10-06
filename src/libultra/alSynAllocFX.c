#include "synth_types.h"

void alFxNew(void *fx, ALSynConfig *c, ALHeap *hp);
s32 alFxParam(void *filter, s32 paramID, void *param);
s32 alAuxBusParam(void *filter, s32 paramID, void *param);

void *alSynAllocFX(ALSynth *drvr, s16 bus, ALSynConfig *c, ALHeap *hp) {
    alFxNew(((ALSynFxBus *)drvr->mainBus)[bus].fx, c, hp);
    alFxParam(((ALSynFxBus *)drvr->mainBus)[bus].fx, 1, &((ALSynFxBus *)drvr->mainBus)[bus]);
    alAuxBusParam(drvr->auxBus, 2, ((ALSynFxBus *)drvr->mainBus)[bus].fx);
    return ((ALSynFxBus *)drvr->mainBus)[bus].fx;
}
