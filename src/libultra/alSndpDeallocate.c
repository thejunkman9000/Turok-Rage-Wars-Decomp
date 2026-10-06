#include "libaudio.h"

void alSndpDeallocate(ALSndPlayer *sndp, s16 track) {
    ALSoundState *update = (ALSoundState *)(track * sizeof(ALSoundState) + (s32)sndp->sndState);
    if (update->state == AL_STOPPED) {
        update->sound = 0;
        if (sndp->target == track) {
            sndp->target = -1;
        }
    }
}
