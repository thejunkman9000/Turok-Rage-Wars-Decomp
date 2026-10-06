#include "common.h"

void osDestroyThread(OSThread *thread) {
    register s32 saveMask;
    register OSThread *pred;
    register OSThread *succ;

    saveMask = __osDisableInt();

    if (thread == NULL) {
        thread = __osRunningThread;
    } else if (thread->state != OS_STATE_STOPPED) {
        __osDequeueThread(thread->queue, thread);
    }

    if (__osActiveQueue == thread) {
        __osActiveQueue = __osActiveQueue->tlnext;
    } else {
        pred = __osActiveQueue;
        succ = pred->tlnext;
        while (succ != NULL) {
            if (succ == thread) {
                pred->tlnext = thread->tlnext;
                break;
            } else {
                pred = succ;
                succ = pred->tlnext;
            }
        }
    }

    if (thread == __osRunningThread) {
        __osDispatchThread();
    }

    __osRestoreInt(saveMask);
}
