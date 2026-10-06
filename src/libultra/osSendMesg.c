#include "common.h"

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    register u32 saveMask;
    register s32 index;
    register OSThread *thread;

    saveMask = __osDisableInt();

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            __osRunningThread->state = OS_STATE_WAITING;
            __osEnqueueAndYield(&mq->fullqueue);
        } else {
            __osRestoreInt(saveMask);
            return -1;
        }
    }

    index = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[index] = msg;
    mq->validCount++;

    if (mq->mtqueue->next != NULL) {
        thread = __osPopThread(&mq->mtqueue);
        osStartThread(thread);
    }

    __osRestoreInt(saveMask);
    return 0;
}
