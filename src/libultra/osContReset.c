#include "common.h"

s32 osContReset(OSMesgQueue *mq, OSContStatus *data) {
    s32 ret;
    u8 pattern;

    __osSiGetAccess();

    if (__osContLastCmd != 0xFF) {
        __osPackResetData();
        __osSiRawStartDma(OS_WRITE, &__osContBuffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osSiRawStartDma(OS_READ, &__osContBuffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osPackRequestData(0xFF);
        __osSiRawStartDma(OS_WRITE, &__osContBuffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
        __osContLastCmd = 0xFF;
    }

    ret = __osSiRawStartDma(OS_READ, &__osContBuffer);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    __osContGetInitData(&pattern, data);
    __osSiRelAccess();

    return ret;
}
