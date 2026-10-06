#include "common.h"

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern, OSContStatus *status);

void __osPfsGetInitData(u8 *pattern, OSContStatus *status) {
    OSContPackedRequest *pkt;
    OSContPackedRequest buf;
    s32 i;
    u8 bits;

    bits = 0;
    pkt = (OSContPackedRequest *)__osPfsPifRam.ramarray;

    for (i = 0; i < __osContNumControllers; i++, pkt++, status++) {
        buf = *pkt;
        status->errno = (buf.unk02 & 0xC0) >> 4;
        if (status->errno == 0) {
            status->type = buf.unk05 << 8 | buf.unk04;
            status->status = buf.unk06;
            bits |= 1 << i;
        }
    }

    *pattern = bits;
}
