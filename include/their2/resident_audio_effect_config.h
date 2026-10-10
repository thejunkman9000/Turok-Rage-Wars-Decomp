#ifndef RESIDENT_AUDIO_EFFECT_CONFIG_H
#define RESIDENT_AUDIO_EFFECT_CONFIG_H
#include "types.h"

/* On-ROM effect parameters consumed by 802B3F10. Each delay record uses
 * eight words; coefficients are narrowed to s16 in the runtime filter. */
typedef struct ResidentAudioDelayParameters {
    s32 input;
    s32 output;
    s32 feedback;
    s32 feedforward;
    s32 gain;
    s32 chorusRate;
    s32 chorusDepth;
    s32 lowpass;
} ResidentAudioDelayParameters;
#endif
