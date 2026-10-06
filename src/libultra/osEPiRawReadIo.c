#include "common.h"

s32 osEPiRawReadIo(OSPiHandle *pihandle, u32 devAddr, u32 *data) {
    register u32 stat;
    register u32 domain;
    OSPiHandle *cHandle;

    if (data == NULL) {
        __assert("EX", "io/epirawread.c", 43);
    }

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

    *data = IO_READ(pihandle->baseAddress | devAddr);

    return 0;
}
