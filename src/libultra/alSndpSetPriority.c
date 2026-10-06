#include "libaudio.h"

void alSndpSetPriority(ALSndPlayer *sndp, s16 sndId, u8 priority) {
    sndp->sndState[sndId].priority = priority;
}
