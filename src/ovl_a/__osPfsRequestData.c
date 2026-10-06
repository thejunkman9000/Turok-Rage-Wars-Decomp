#include "common.h"

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern, OSContStatus *status);

void __osPfsRequestData(u8 cmd) {
    OSContPackedRequest *pkt;
    OSContPackedRequest buf;
    s32 i;

    pkt = (OSContPackedRequest *)__osPfsPifRam.ramarray;
    __osContLastCmd = cmd;
    __osPfsPifRam.pifstatus = 1;

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
