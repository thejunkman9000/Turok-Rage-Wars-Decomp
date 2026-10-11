#include "common.h"

void osContGetReadData(OSContPad *pad) {
    OSContPackedRead *pkt;
    OSContPackedRead buf;
    s32 i;

    pkt = &__osContBuffer[0].read;

    for (i = 0; i < __osContNumControllers; i++, pkt++, pad++) {
        buf = *pkt;
        pad->errno = (buf.unk02 & 0xC0) >> 4;
        if (pad->errno == 0) {
            pad->button = buf.button;
            pad->stick_x = buf.rawStickX;
            pad->stick_y = buf.rawStickY;
        }
    }
}
