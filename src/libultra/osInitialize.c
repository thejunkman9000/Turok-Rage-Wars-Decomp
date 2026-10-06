#include "common.h"

void osInitialize(void) {
    u32 pifdata;
    u32 clock = 0;

    __osInitialized = 1;

    __osSetSR(__osGetSR() | 0x20000000);
    __osSetFpcCsr(0x01000800);

    while (__osSiRawReadIo(0x1FC007FC, &pifdata) != 0) {
    }
    while (__osSiRawWriteIo(0x1FC007FC, pifdata | 8) != 0) {
    }

    *(__osExceptionVector *)0x80000000 = *(__osExceptionVector *)__osExceptionPreamble;
    *(__osExceptionVector *)0x80000080 = *(__osExceptionVector *)__osExceptionPreamble;
    *(__osExceptionVector *)0x80000100 = *(__osExceptionVector *)__osExceptionPreamble;
    *(__osExceptionVector *)0x80000180 = *(__osExceptionVector *)__osExceptionPreamble;

    osWritebackDCache((void *)0x80000000, 0x190);
    osInvalICache((void *)0x80000000, 0x190);

    osMapMainTLB();

    osPiRawReadIo(4, &clock);
    clock &= ~0xF;
    if (clock != 0) {
        osClockRate = clock;
    } else {
        osClockRate = 62500000;
    }
    osClockRate = osClockRate * 3 / 4;

    if (OS_RESET_TYPE == 0) {
        memset(osAppNMIBuffer, 0, 0x40);
    }

    if (OS_TV_TYPE == 0) {
        osViClock = 0x02F5B2D2;
    } else if (OS_TV_TYPE == 2) {
        osViClock = 0x02E6025C;
    } else {
        osViClock = 0x02E6D354;
    }
}
