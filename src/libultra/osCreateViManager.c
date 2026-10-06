#include "common.h"

static static void viMgrMain(void *arg);

void osCreateViManager(OSPri pri) {
    u32 savedMask;
    OSPri oldPri;
    OSPri myPri;

    if (__osViDevMgr.initialized) {
        return;
    }

    __osTimerServicesInit();
    osCreateMesgQueue(&__osViEventQueue, __osViEventBuf, 5);

    __osViRetraceMsg.hdr.type = 13;
    __osViRetraceMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    __osViRetraceMsg.hdr.retQueue = NULL;

    __osViCounterMsg.hdr.type = 14;
    __osViCounterMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    __osViCounterMsg.hdr.retQueue = NULL;

    osSetEventMesg(OS_EVENT_VI, &__osViEventQueue, &__osViRetraceMsg);
    osSetEventMesg(OS_EVENT_COUNTER, &__osViEventQueue, &__osViCounterMsg);

    oldPri = -1;
    myPri = osGetThreadPri(NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    savedMask = __osDisableInt();

    __osViDevMgr.initialized = TRUE;
    __osViDevMgr.thread = &__osViThread;
    __osViDevMgr.cmdQueue = &__osViEventQueue;
    __osViDevMgr.evtQueue = &__osViEventQueue;
    __osViDevMgr.acsQueue = NULL;
    __osViDevMgr.dma_func = NULL;
    __osViDevMgr.edma_func = NULL;

    osCreateThread(&__osViThread, 0, viMgrMain, &__osViDevMgr, &__osViThreadStack[4096], pri);
    __osViInit();
    osStartThread(&__osViThread);

    __osRestoreInt(savedMask);

    if (oldPri != -1) {
        osSetThreadPri(NULL, oldPri);
    }
}

static void viMgrMain(void *arg) {
    OSMgrArgs *dm;
    OSIoMesg *mesg;
    OSViContext *vc;
    u32 first;
    u32 count;
    u32 now;

    first = 0;
    mesg = NULL;

    vc = __osViGetCurrentContext();
    __osViRetraceCount = vc->retraceCount;
    if (__osViRetraceCount == 0) {
        __osViRetraceCount = 1;
    }
    dm = arg;

    while (TRUE) {
        osRecvMesg(dm->evtQueue, (OSMesg *)&mesg, OS_MESG_BLOCK);

        switch (mesg->hdr.type) {
        case 13:
            __osViSwapContext();
            __osViRetraceCount--;
            if (__osViRetraceCount == 0) {
                vc = __osViGetCurrentContext();
                if (vc->mq != NULL) {
                    osSendMesg(vc->mq, vc->msg, OS_MESG_NOBLOCK);
                }
                __osViRetraceCount = vc->retraceCount;
            }
            __osViIntrCount++;
            if (first) {
                count = osGetCount();
                _osCurrentTime = count;
                first = 0;
            }
            count = __osBaseCounter;
            now = osGetCount();
            __osBaseCounter = now;
            count = now - count;
            _osCurrentTime = _osCurrentTime + count;
            break;
        case 14:
            __osTimerInterrupt();
            break;
        }
    }
}
