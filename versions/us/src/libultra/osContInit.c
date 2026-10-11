#include "common.h"

s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data) {
    OSMesg dummy;
    s32 ret = 0;
    OSTime t;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;

    if (__osContinitialized) {
        return 0;
    }
    __osContinitialized = 1;

    t = osGetTime();
    if (t < 23437500) {
        osCreateMesgQueue(&timerMesgQueue, &dummy, 1);
        osSetTimer(&mytimer, 23437500 - t, 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
    }

    __osContNumControllers = 4;
    __osPackRequestData(0);
    ret = __osSiRawStartDma(OS_WRITE, &__osContBuffer);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &__osContBuffer);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);
    __osContGetInitData(bitpattern, data);
    __osContLastCmd = 0;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&__osContMesgQueue, __osContMesgBuff, 1);

    return ret;
}
