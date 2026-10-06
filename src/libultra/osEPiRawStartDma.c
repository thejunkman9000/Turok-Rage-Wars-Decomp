#include "common.h"

s32 osEPiRawStartDma(OSPiHandle *pihandle, s32 dir, u32 cart_addr, void *dram_addr, u32 size) {
    register u32 stat;
    register u32 domain;
    OSPiHandle *cHandle;

    stat = IO_READ(PI_STATUS_REG);
    while (stat & (PI_STATUS_BUSY | PI_STATUS_IOBUSY)) {
        stat = IO_READ(PI_STATUS_REG);
    }

    domain = pihandle->domain;
    if (__osCurrentHandle[domain] != pihandle) {
        cHandle = __osCurrentHandle[domain];
        if (domain == 0) {
            if (cHandle->latency != pihandle->latency) {
                IO_WRITE(PI_BSD_DOM1_LAT_REG, pihandle->latency);
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                IO_WRITE(PI_BSD_DOM1_PGS_REG, pihandle->pageSize);
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                IO_WRITE(PI_BSD_DOM1_RLS_REG, pihandle->relDuration);
            }
            if (cHandle->pulse != pihandle->pulse) {
                IO_WRITE(PI_BSD_DOM1_PWD_REG, pihandle->pulse);
            }
        } else {
            if (cHandle->latency != pihandle->latency) {
                IO_WRITE(PI_BSD_DOM2_LAT_REG, pihandle->latency);
            }
            if (cHandle->pageSize != pihandle->pageSize) {
                IO_WRITE(PI_BSD_DOM2_PGS_REG, pihandle->pageSize);
            }
            if (cHandle->relDuration != pihandle->relDuration) {
                IO_WRITE(PI_BSD_DOM2_RLS_REG, pihandle->relDuration);
            }
            if (cHandle->pulse != pihandle->pulse) {
                IO_WRITE(PI_BSD_DOM2_LWD_REG, pihandle->pulse);
            }
        }
        __osCurrentHandle[domain] = pihandle;
    }

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dram_addr));
    IO_WRITE(PI_CART_ADDR_REG, (pihandle->baseAddress | cart_addr) & 0x1FFFFFFF);

    switch (dir) {
        case 0:
            IO_WRITE(PI_WR_LEN_REG, size - 1);
            break;
        case 1:
            IO_WRITE(PI_RD_LEN_REG, size - 1);
            break;
        default:
            return -1;
    }

    return 0;
}
