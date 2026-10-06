#include "common.h"

void osViSetYScale(f32 value) {
    u32 saveMask = __osDisableInt();

    __osViNext->y.factor = value;
    __osViNext->state |= 4;
    __osRestoreInt(saveMask);
}
