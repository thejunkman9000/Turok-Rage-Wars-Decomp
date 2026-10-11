#include "common.h"

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (!__osPiDevMgr.initialized) {
        osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
        osCreateMesgQueue(&__osPiEventQueue, __osPiEventBuf, 1);

        if (!__osPiAccessQueueEnabled) {
            __osPiCreateAccessQueue();
        }

        osSetEventMesg(8, &__osPiEventQueue, (OSMesg)0x22222222);

        oldPri = -1;
        myPri = osGetThreadPri(NULL);
        if (myPri < pri) {
            oldPri = myPri;
            osSetThreadPri(NULL, pri);
        }

        savedMask = __osDisableInt();

        __osPiDevMgr.initialized = TRUE;
        __osPiDevMgr.acsQueue = &__osPiAccessQueue;
        __osPiDevMgr.dma_func = osPiRawStartDma;
        __osPiDevMgr.edma_func = osEPiRawStartDma;
        __osPiDevMgr.evtQueue = &__osPiEventQueue;
        __osPiDevMgr.thread = &__osPiThread;
        __osPiDevMgr.cmdQueue = cmdQ;

        osCreateThread(&__osPiThread, 0, __osDevMgrMain, &__osPiDevMgr, &__osPiThreadStack[4096], pri);
        osStartThread(&__osPiThread);

        __osRestoreInt(savedMask);

        if (oldPri != -1) {
            osSetThreadPri(NULL, oldPri);
        }
    }
}
