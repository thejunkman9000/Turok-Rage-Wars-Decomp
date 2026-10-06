#include "common.h"

s32 osDpSetNextBuffer(void *bufPtr, u64 size) {
    if (__osDpDeviceBusy()) {
        return -1;
    }

    IO_WRITE(DPC_STATUS_REG, 1);
    do {
    } while (IO_READ(DPC_STATUS_REG) & 1);

    IO_WRITE(DPC_START_REG, osVirtualToPhysical(bufPtr));
    IO_WRITE(DPC_END_REG, osVirtualToPhysical(bufPtr) + (u32)size);
    return 0;
}
