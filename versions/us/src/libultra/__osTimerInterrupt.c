#include "common.h"

void __osTimerInterrupt(void) {
    OSTimer *timer;
    u32 count;
    u32 elapsed;

    if (__osTimerList->next == __osTimerList) {
        return;
    }

    while (1) {
        timer = __osTimerList->next;

        if (timer == __osTimerList) {
            __osSetCompare(0);
            __osTimerCounter = 0;
            break;
        }

        count = osGetCount();
        elapsed = count - __osTimerCounter;
        __osTimerCounter = count;

        if (elapsed < timer->remaining) {
            timer->remaining -= elapsed;
            __osSetTimerIntr(timer->remaining);
            return;
        } else {
            timer->prev->next = timer->next;
            timer->next->prev = timer->prev;
            timer->next = NULL;
            timer->prev = NULL;

            if (timer->mq != NULL) {
                osSendMesg(timer->mq, timer->msg, OS_MESG_NOBLOCK);
            }

            if (timer->interval != 0) {
                timer->remaining = timer->interval;
                __osInsertTimer(timer);
            }
        }
    }
}
