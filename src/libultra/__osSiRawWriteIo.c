#include "common.h"

s32 __osSiRawWriteIo(u32 devAddr, u32 data) {
    if (devAddr & 3) {
        __assert("EX", "io/sirawwrite.c", 52);
    }

    if (__osSiDeviceBusy()) {
        return -1;
    }

    HW_REG(devAddr, u32) = data;
    return 0;
}
