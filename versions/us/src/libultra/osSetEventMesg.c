#include "common.h"

void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg) {
    register u32 saveMask;
    __OSEventState *es;

    saveMask = __osDisableInt();

    es = &__osEventStateTab[e];
    es->messageQueue = mq;
    es->message = msg;

    __osRestoreInt(saveMask);
}
