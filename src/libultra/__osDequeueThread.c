#include "common.h"

void __osDequeueThread(OSThread **queue, OSThread *thread) {
    register OSThread **pred;
    register OSThread *succ;

    pred = queue;
    succ = *pred;

    while (succ != NULL) {
        if (succ == thread) {
            *pred = thread->next;
            return;
        }
        pred = &succ->next;
        succ = *pred;
    }
}
