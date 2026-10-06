#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

s32 _allocatePVoice(ALSynth *drvr, ALPVoice **pvoice, s16 priority) {
    ALLink *dl;
    ALPVoice *pv;
    s32 stolen = 0;
    if (((dl = drvr->pLameList.next) != 0) || ((dl = drvr->pFreeList.next) != 0)) {
        *pvoice = (ALPVoice *)dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);
    } else {
        for (dl = drvr->pAllocList.next; dl != 0; dl = dl->next) {
            pv = (ALPVoice *)dl;
            if (pv->vvoice->priority <= priority && pv->offset == 0) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = 1;
            }
        }
    }
    return stolen;
}
