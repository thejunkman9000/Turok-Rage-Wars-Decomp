#include "common.h"

OSTime osGetTime(void) {
    u32 elapsed;
    u32 count;
    OSTime time;
    register u32 saveMask;

    saveMask = __osDisableInt();
    count = osGetCount();
    elapsed = count - __osTimerCounter;
    time = _osCurrentTime;
    __osRestoreInt(saveMask);

    return time + elapsed;
}
