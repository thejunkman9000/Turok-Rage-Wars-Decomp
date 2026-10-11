#include "common.h"

extern OSPiHandle DriveRomHandle;
extern OSPiHandle *__osDiskHandle;

OSPiHandle *osDriveRomInit(void) {
    u32 saveMask;

    DriveRomHandle.type = 2;
    DriveRomHandle.baseAddress = 0xA5000000;
    DriveRomHandle.latency = 3;
    DriveRomHandle.pulse = 6;
    DriveRomHandle.pageSize = 6;
    DriveRomHandle.relDuration = 2;
    DriveRomHandle.domain = 1;
    IO_WRITE(PI_BSD_DOM2_LAT_REG, 3);
    IO_WRITE(PI_BSD_DOM2_LWD_REG, 6);
    IO_WRITE(PI_BSD_DOM2_PGS_REG, 6);
    IO_WRITE(PI_BSD_DOM2_RLS_REG, 2);
    DriveRomHandle.speed = 0;
    memset(&DriveRomHandle.transferInfo, 0, sizeof(__OSTranxInfo));
    saveMask = __osDisableInt();
    DriveRomHandle.next = __osPiTable;
    __osPiTable = &DriveRomHandle;
    __osDiskHandle = &DriveRomHandle;
    __osRestoreInt(saveMask);

    return &DriveRomHandle;
}
