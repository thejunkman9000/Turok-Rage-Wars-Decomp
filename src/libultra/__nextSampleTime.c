#include "libaudio.h"

s32 __nextSampleTime(ALSynth *drvr, ALPlayer **client) {
    ALPlayer *c;
    s32 delta = 0x7FFFFFFF;
    if (drvr->head == 0) {
        __assert("EX", "audio/synthesizer.c", 307);
    }
    *client = 0;
    for (c = drvr->head; c != 0; c = c->next) {
        if ((c->samplesLeft - drvr->curSamples) < delta) {
            *client = c;
            delta = c->samplesLeft - drvr->curSamples;
        }
    }
    return (*client)->samplesLeft;
}
