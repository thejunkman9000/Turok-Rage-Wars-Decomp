#include "common.h"

s32 __osSpRawStartDma(s32 dir, u32 devAddr, void *dramAddr, u32 size) {
    if (devAddr & 7) {
        __assert("EX", "io/sprawdma.c", 58);
    }
    if ((u32)dramAddr & 7) {
        __assert("EX", "io/sprawdma.c", 59);
    }
    if (size & 7) {
        __assert("EX", "io/sprawdma.c", 60);
    }

    if (__osSpDeviceBusy()) {
        return -1;
    }

    IO_WRITE(SP_MEM_ADDR_REG, devAddr);
    IO_WRITE(SP_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));

    if (dir == OS_READ) {
        IO_WRITE(SP_WR_LEN_REG, size - 1);
    } else {
        IO_WRITE(SP_RD_LEN_REG, size - 1);
    }

    return 0;
}
