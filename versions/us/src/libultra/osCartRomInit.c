#include "common.h"

extern OSPiHandle CartRomHandle;

OSPiHandle *osCartRomInit(void) {
    u32 piConfig;
    u32 saveMask;

    piConfig = 0;

    if (CartRomHandle.baseAddress != 0xB0000000) {
        CartRomHandle.type = 0;
        CartRomHandle.baseAddress = 0xB0000000;
        osPiRawReadIo(0, &piConfig);
        CartRomHandle.latency = piConfig & 0xFF;
        CartRomHandle.pulse = (piConfig >> 8) & 0xFF;
        CartRomHandle.pageSize = (piConfig >> 16) & 0xF;
        CartRomHandle.relDuration = (piConfig >> 20) & 0xF;
        CartRomHandle.domain = 0;
        CartRomHandle.speed = 0;
        memset(&CartRomHandle.transferInfo, 0, sizeof(__OSTranxInfo));
        saveMask = __osDisableInt();
        CartRomHandle.next = __osPiTable;
        __osPiTable = &CartRomHandle;
        __osRestoreInt(saveMask);
    }

    return &CartRomHandle;
}
