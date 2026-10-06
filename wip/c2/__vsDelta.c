#include "libaudio.h"

s32 __vsDelta(ALVoiceState *vs, s32 t) {
    s32 delta;
    delta = vs->envEndTime - t;
    if (delta >= 0) {
        return delta;
    }
    return 1000;
}
