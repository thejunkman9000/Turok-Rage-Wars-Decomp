#include "common.h"

s32 osPiRawReadIo(u32 devAddr, u32 *data) {
    register u32 stat;

    if (data == NULL) {
        __assert("EX", "io/pirawread.c", 61);
    }

    stat = IO_READ(PI_STATUS_REG);
    while (stat & (PI_STATUS_BUSY | PI_STATUS_IOBUSY)) {
        stat = IO_READ(PI_STATUS_REG);
    }

    *data = IO_READ(OS_ROM_BASE | devAddr);

    return 0;
}
