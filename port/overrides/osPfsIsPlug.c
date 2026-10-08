#include "common.h"
/* port: no pak plugged on any controller */
s32 osPfsIsPlug(OSMesgQueue *queue, u8 *pattern) {
    *pattern = 0;
    return 0;
}
