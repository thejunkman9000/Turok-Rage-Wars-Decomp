#include "common.h"

void osYieldThread(void) {
    u32 saveMask = __osDisableInt();

    __osRunningThread->state = 2;
    __osEnqueueAndYield(&__osRunQueue);
    __osRestoreInt(saveMask);
}
