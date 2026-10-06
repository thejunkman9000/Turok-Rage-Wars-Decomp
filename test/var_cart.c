#include "common.h"
extern OSPiHandle CartRomHandle;

#define TAIL \
    memset(&CartRomHandle.transferInfo, 0, sizeof(__OSTranxInfo)); \
    saveMask = __osDisableInt(); \
    CartRomHandle.next = __osPiTable; \
    __osPiTable = &CartRomHandle; \
    __osRestoreInt(saveMask);

OSPiHandle *v1(void) {
    u32 piConfig; u32 saveMask; u32 latency, pulse, pageSize, relDuration;
    piConfig = 0;
    if (CartRomHandle.baseAddress != 0xB0000000) {
        CartRomHandle.type = 0;
        CartRomHandle.baseAddress = 0xB0000000;
        osPiRawReadIo(0, &piConfig);
        latency = piConfig & 0xFF;
        pulse = (piConfig >> 8) & 0xFF;
        pageSize = (piConfig >> 16) & 0xF;
        relDuration = (piConfig >> 20) & 0xF;
        CartRomHandle.domain = 0;
        CartRomHandle.speed = 0;
        CartRomHandle.latency = latency;
        CartRomHandle.pulse = pulse;
        CartRomHandle.pageSize = pageSize;
        CartRomHandle.relDuration = relDuration;
        TAIL
    }
    return &CartRomHandle;
}

OSPiHandle *v2(void) {
    u32 piConfig; u32 saveMask;
    piConfig = 0;
    if (CartRomHandle.baseAddress != 0xB0000000) {
        CartRomHandle.type = 0;
        CartRomHandle.baseAddress = 0xB0000000;
        osPiRawReadIo(0, &piConfig);
        CartRomHandle.domain = 0;
        CartRomHandle.speed = 0;
        CartRomHandle.latency = piConfig & 0xFF;
        CartRomHandle.pulse = (piConfig >> 8) & 0xFF;
        CartRomHandle.pageSize = (piConfig >> 16) & 0xF;
        CartRomHandle.relDuration = (piConfig >> 20) & 0xF;
        TAIL
    }
    return &CartRomHandle;
}

OSPiHandle *v3(void) {
    u32 piConfig; u32 saveMask;
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
        TAIL
    }
    return &CartRomHandle;
}

OSPiHandle *v4(void) {
    u32 piConfig; u32 saveMask;
    piConfig = 0;
    if (CartRomHandle.baseAddress != 0xB0000000) {
        CartRomHandle.type = 0;
        CartRomHandle.baseAddress = 0xB0000000;
        osPiRawReadIo(0, &piConfig);
        CartRomHandle.domain = 0;
        CartRomHandle.speed = 0;
        CartRomHandle.latency = (u8)piConfig;
        CartRomHandle.pulse = (u8)(piConfig >> 8);
        CartRomHandle.pageSize = (piConfig >> 16) & 0xF;
        CartRomHandle.relDuration = (piConfig >> 20) & 0xF;
        TAIL
    }
    return &CartRomHandle;
}
