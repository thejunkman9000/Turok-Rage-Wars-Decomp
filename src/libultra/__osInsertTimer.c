#include "common.h"

u64 __osInsertTimer(OSTimer *timer) {
    OSTimer *cur;
    u64 remaining;
    s32 saveMask;

    saveMask = __osDisableInt();

    for (cur = __osTimerList->next, remaining = timer->remaining;
         cur != __osTimerList && remaining > cur->remaining;
         remaining -= cur->remaining, cur = cur->next) {
        ;
    }

    timer->remaining = remaining;

    if (cur != __osTimerList) {
        cur->remaining -= remaining;
    }

    timer->next = cur;
    timer->prev = cur->prev;
    cur->prev->next = timer;
    cur->prev = timer;

    __osRestoreInt(saveMask);
    return remaining;
}
