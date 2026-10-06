#include "libaudio.h"

void alSynAddPlayer(ALSynth *drvr, ALPlayer *client) {
    OSIntMask mask;
    mask = osSetIntMask(1);
    client->samplesLeft = drvr->curSamples;
    client->next = drvr->head;
    drvr->head = client;
    osSetIntMask(mask);
}
