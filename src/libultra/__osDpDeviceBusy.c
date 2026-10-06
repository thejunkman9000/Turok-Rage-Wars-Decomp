#include "common.h"

s32 __osDpDeviceBusy(void) {
    u32 stat = IO_READ(DPC_STATUS_REG);

    if (stat & 0x100) {
        return TRUE;
    }
    return FALSE;
}
