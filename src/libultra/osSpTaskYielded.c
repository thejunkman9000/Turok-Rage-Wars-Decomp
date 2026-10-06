#include "common.h"

s32 osSpTaskYielded(OSTask *task) {
    u32 status;
    s32 result;

    status = __osSpGetStatus();

    result = status >> 8; /* SIGNAL1: the RSP yielded */
    result &= 1;

    if (status & SPSTATUS_SIGNAL0_SET) {
        task->t.flags |= result;
        task->t.flags &= ~OS_TASK_DP_WAIT;
    }

    return result;
}
