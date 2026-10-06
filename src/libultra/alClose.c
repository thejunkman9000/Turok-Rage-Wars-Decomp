#include "libaudio.h"

void alSynDelete(ALSynth *drvr);

void alClose(ALGlobals *glob) {
    if (alGlobalsp != 0) {
        alSynDelete(&glob->drvr);
        alGlobalsp = 0;
    }
}
