#include "common.h"

void __osContGetInitData(u8 *pattern, OSContStatus *status) {
    OSContPackedRequest *pkt;
    OSContPackedRequest buf;
    s32 i;
    u8 bits;

    bits = 0;
    pkt = &__osContBuffer[0].request;

    for (i = 0; i < __osContNumControllers; i++, pkt++, status++) {
        buf = *(OSContPackedRequest *)pkt;
        status->errno = (buf.unk02 & 0xC0) >> 4;
        if (status->errno == 0) {
            status->type = buf.unk05 << 8 | buf.unk04;
            status->status = buf.unk06;
            bits |= 1 << i;
        }
    }

    *pattern = bits;
}
