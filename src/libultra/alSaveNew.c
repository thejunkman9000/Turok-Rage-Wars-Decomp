#include "libaudio.h"

void alFilterNew(ALFilter *f, void *handler, void *setParam, s32 type);
void *alSavePull(void);
s32 alSaveParam(void *filter, s32 paramID, void *param);

void alSaveNew(ALSave *f) {
    alFilterNew(&f->filter, alSavePull, alSaveParam, 3);
    f->dramout = 0;
    f->first = 1;
}
