#include "libaudio.h"

s32 _timeToSamplesNoRound_2(ALSynth *synth, s32 micros) {
    f32 tmp = ((f32)micros * (f32)synth->outputRate) * 0.000001f + 0.5f;
    return (s32)tmp;
}
