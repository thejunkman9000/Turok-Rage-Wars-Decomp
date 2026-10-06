#include "libaudio.h"

s32 alSndpGetState(ALSndPlayer *sndp) {
    return sndp->sndState[sndp->target].state;
}
