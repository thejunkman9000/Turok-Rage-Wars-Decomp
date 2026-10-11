#include "common.h"

s32 osContStartReadData(OSMesgQueue *mq) {
    s32 ret;

    __osSiGetAccess();

    if (__osContLastCmd != 1) {
        __osPackReadData();
        __osSiRawStartDma(OS_WRITE, &__osContBuffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }

    ret = __osSiRawStartDma(OS_READ, &__osContBuffer);
    __osContLastCmd = 1;
    __osSiRelAccess();

    return ret;
}
