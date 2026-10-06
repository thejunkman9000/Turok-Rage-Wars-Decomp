#include "common.h"

void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) {
    register u32 saveMask;
    u32 tmp;

    thread->id = id;
    thread->priority = pri;
    thread->next = NULL;
    thread->queue = NULL;
    thread->context.pc = (u32)entry;
    thread->context.a0 = (u64)arg;
    thread->context.sp = (u64)sp - 16;
    thread->context.ra = (u64)__osCleanupThread;
    tmp = 0x003FFF01;
    thread->context.sr = 65283;
    thread->context.rcp = (tmp & 0x3F0000) >> 16;
    thread->context.fpcsr = (u32)0x01000800;
    thread->fp = 0;
    thread->state = OS_STATE_STOPPED;
    thread->flags = 0;

    saveMask = __osDisableInt();
    thread->tlnext = __osActiveQueue;
    __osActiveQueue = thread;
    __osRestoreInt(saveMask);
}
