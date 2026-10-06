#include "common.h"

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag) {
    register u32 saveMask;
    register OSThread *thread;

    saveMask = __osDisableInt();

    while (!mq->validCount) {
        if (!flag) {
            __osRestoreInt(saveMask);
            return -1;
        }
        __osRunningThread->state = OS_STATE_WAITING;
        __osEnqueueAndYield(&mq->mtqueue);
    }

    if (msg != NULL) {
        *msg = *(mq->first + mq->msg);
    }

    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    if (mq->fullqueue->next != NULL) {
        thread = __osPopThread(&mq->fullqueue);
        osStartThread(thread);
    }

    __osRestoreInt(saveMask);
    return 0;
}
