#include "common.h"

void __osPfsRequestOneChannel(int channel);
void __osPfsGetOneChannelData(int channel, OSContStatus *data);

s32 __osPfsGetStatus(OSMesgQueue *queue, int channel) {
    s32 ret;
    OSMesg dummy;
    OSContStatus data;
    __osPfsRequestOneChannel(channel);
    __osSiRawStartDma(1, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, 1);
    ret = __osSiRawStartDma(0, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, 1);
    __osPfsGetOneChannelData(channel, &data);
    if ((data.status & 1) && (data.status & 2)) {
        return 2;
    }
    if (((*(u16 *)&data.status) & 0x1FF) != 0x100) {
        return 1;
    }
    if (data.status & 4) {
        return 4;
    }
    return ret;
}
