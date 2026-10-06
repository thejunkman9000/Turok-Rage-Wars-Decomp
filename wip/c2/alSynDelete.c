#include "libaudio.h"

void alSynDelete(ALSynth *drvr) {
    drvr->head = 0;
}
