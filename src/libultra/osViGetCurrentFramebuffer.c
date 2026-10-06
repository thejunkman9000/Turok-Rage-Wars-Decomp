#include "common.h"

void *osViGetCurrentFramebuffer(void) {
    u32 saveMask = __osDisableInt();
    void *framep = __osViCurr->buffer;

    __osRestoreInt(saveMask);
    return framep;
}
