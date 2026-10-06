#include "common.h"

s32 osSetTimer(OSTimer *timer, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg) {
    OSTime time;

    timer->remaining = countdown;
    timer->next = NULL;
    timer->prev = NULL;
    timer->interval = interval;

    if (countdown == 0) {
        timer->remaining = interval;
    }

    timer->mq = mq;
    timer->msg = msg;

    time = __osInsertTimer(timer);

    if (__osTimerList->next == timer) {
        __osSetTimerIntr(time);
    }

    return 0;
}
