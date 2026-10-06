#include "synth_types.h"

void __assert(const char *expr, const char *file, s32 line);

s32 __sndpTimeAtPitch(s32 time, f32 pitch) {
    f64 ratio;
    if (pitch == 0.0f) {
        __assert("EX", "audio/sndplayer.c", 0x11D);
    }
    ratio = (f32)time / pitch;
    return (ratio > 2147483647.0) ? 0x7FFFFFFF : (s32)ratio;
}
