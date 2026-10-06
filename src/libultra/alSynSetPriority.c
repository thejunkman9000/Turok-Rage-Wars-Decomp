#include "libaudio.h"

void alSynSetPriority(ALSynth *drvr, ALVoice *voice, s16 priority) {
    voice->priority = priority;
}
