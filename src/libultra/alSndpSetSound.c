#include "libaudio.h"

void alSndpSetSound(ALSndPlayer *sndp, s16 sndId) {
    sndp->target = sndId;
}
