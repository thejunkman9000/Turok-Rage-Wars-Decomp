#include "libaudio.h"

void alUnlink(ALLink *ln);
void alLink(ALLink *ln, ALLink *to);

void _freePVoice(ALSynth *drvr, ALPVoice *pvoice) {
    alUnlink(&pvoice->node);
    alLink(&pvoice->node, &drvr->pLameList);
}
