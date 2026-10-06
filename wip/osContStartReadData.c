#include "common.h"

s32 osContStartReadData(OSMesgQueue *mq) {
    s32 ret = 0;
    s32 i;

    __osSiGetAccess();

    if (__osContLastCmd != 1) {
        __osPackReadData();
        ret = __osSiRawStartDma(OS_WRITE, __osContBuffer);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }

    for (i = 0; i < 0x10; i++) {
        *((u32 *)&__osContBuffer + i) = 255;
    }

    __osContPifStatus = 0;
    ret = __osSiRawStartDma(OS_READ, &__osContBuffer);
    __osContLastCmd = 1;
    __osSiRelAccess();

    return ret;
}
