#include "libaudio.h"

s32 alFxParam(void *filter, s32 paramID, void *param) {
    if (paramID == 1) {
        ((ALFilter *)filter)->source = (ALFilter *)param;
    }
    return 0;
}
