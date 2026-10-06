#include "common.h"

void __osTimerServicesInit(void) {
    _osCurrentTime = 0;
    __osBaseCounter = 0;
    __osViIntrCount = 0;

    __osTimerList->prev = __osTimerList;
    __osTimerList->next = __osTimerList->prev;
    __osTimerList->remaining = 0;
    __osTimerList->interval = __osTimerList->remaining;
    __osTimerList->mq = NULL;
    __osTimerList->msg = NULL;
}
