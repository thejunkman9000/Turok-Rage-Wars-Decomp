#include "libaudio.h"

void alSynNew(ALSynth *drvr, void *config);

void alInit(ALGlobals *glob, void *config) {
    if (alGlobalsp == 0) {
        alGlobalsp = glob;
        alSynNew(&glob->drvr, config);
    }
}
