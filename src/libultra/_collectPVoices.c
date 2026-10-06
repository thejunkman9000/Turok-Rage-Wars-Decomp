#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

void _collectPVoices(ALSynth *drvr) {
    ALLink *dl;
    while ((dl = drvr->pLameList.next) != 0) {
        alUnlink(dl);
        alLink(dl, &drvr->pFreeList);
    }
}
