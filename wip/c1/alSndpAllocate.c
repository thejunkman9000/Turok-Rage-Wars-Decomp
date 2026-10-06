#include "libaudio.h"

s16 alSndpAllocate(ALSndPlayer *sndp, ALSound *sound) {
    ALSoundState *state = sndp->sndState;
    s16 i;
    for (i = 0; i < sndp->maxSounds; i++) {
        if (state[i].sound == 0) {
            state[i].sound = sound;
            state[i].priority = 5;
            state[i].state = AL_STOPPED;
            state[i].pitch = 1.0f;
            state[i].pan = 64;
            state[i].fxMix = 0;
            state[i].vol = (sound->sampleVolume * 0x7FFF) / 127;
            return i;
        }
    }
    return -1;
}
