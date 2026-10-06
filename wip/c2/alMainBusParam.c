#include "libaudio.h"

s32 alMainBusParam(void *filter, s32 paramID, void *param) {
    ALBus *f = (ALBus *)filter;
    ALFilter **s = f->sources;
    if (paramID == 2) {
        s[f->sourceCount++] = (ALFilter *)param;
    }
    return 0;
}
