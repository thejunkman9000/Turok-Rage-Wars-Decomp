#include "common.h"

void __osPackReadData(void) {
    OSContPackedRead *pkt;
    OSContPackedRead buf;
    s32 i;

    pkt = &__osContBuffer[0].read;

    for (i = 0; i < 15; i++) {
        *((u32 *)&__osContBuffer + i) = 0;
    }

    __osContPifStatus = 1;

    buf.unk00 = 255;
    buf.unk01 = 1;
    buf.unk02 = 4;
    buf.unk03 = 1;
    buf.button = 65535;
    buf.rawStickX = -1;
    buf.rawStickY = -1;

    for (i = 0; i < __osContNumControllers; i++) {
        *pkt++ = buf;
    }

    pkt->unk00 = 254;
}
