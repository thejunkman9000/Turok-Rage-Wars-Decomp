#include "common.h"

void __osPfsRequestOneChannel(int channel);
void __osPfsGetOneChannelData(int channel, OSContStatus *data);

s32 __osPfsGetStatus(OSMesgQueue *queue, int channel) {
    s32 ret;
    s32 res;
    OSMesg dummy;
    OSContStatus data;
    __osPfsRequestOneChannel(channel);
    __osSiRawStartDma(1, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, 1);
    ret = __osSiRawStartDma(0, &__osPfsPifRam);
    osRecvMesg(queue, &dummy, 1);
    __osPfsGetOneChannelData(channel, &data);
    @@body@@
}
