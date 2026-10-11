#include "common.h"

void __osPackRequestData(u8 cmd) {
    OSContPackedRequest *pkt;
    OSContPackedRequest buf;
    s32 i;

    for (i = 0; i < 15; i++) {
        __osContPifRam.ramarray[i] = 0;
    }

    __osContPifRam.pifstatus = 1;

    pkt = (OSContPackedRequest *)__osContPifRam.ramarray;

    buf.unk00 = 255;
    buf.unk01 = 1;
    buf.unk02 = 3;
    buf.unk03 = cmd;
    buf.unk04 = 255;
    buf.unk05 = 255;
    buf.unk06 = 255;
    buf.unk07 = 255;

    for (i = 0; i < __osContNumControllers; i++) {
        *pkt++ = buf;
    }

    pkt->unk00 = 254;
}
