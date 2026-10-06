#include "common.h"

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern);
void __osPfsRequestData(u8 cmd);
void __osPfsGetInitData(u8 *pattern, OSContStatus *status);

s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern) {
    s32 ret = 0;
    OSMesg dummy;
    u8 bitpattern;
    OSContStatus data[4];
    s32 channel;
    u8 bits = 0;
    s32 crcErrorCount = 3;

    __osSiGetAccess();
    do {
        __osPfsRequestData(0);
        ret = __osSiRawStartDma(1, &__osPfsPifRam);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, &__osPfsPifRam);
        osRecvMesg(queue, &dummy, 1);
        __osPfsGetInitData(&bitpattern, data);
        for (channel = 0; channel < __osContNumControllers; channel++) {
            if (!(data[channel].status & 4)) {
                crcErrorCount--;
                break;
            }
        }
        if (channel == __osContNumControllers) {
            crcErrorCount = 0;
        }
    } while (crcErrorCount > 0);
    for (channel = 0; channel < __osContNumControllers; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1)) {
            bits |= 1 << channel;
        }
    }
    __osSiRelAccess();
    *pattern = bits;
    return ret;
}
