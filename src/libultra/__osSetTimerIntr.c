#include "common.h"

void __osSetTimerIntr(u64 time) {
    u64 target;
    s32 saveMask = __osDisableInt();

    __osTimerCounter = osGetCount();
    target = __osTimerCounter + time;
    __osSetCompare(target);

    __osRestoreInt(saveMask);
}
