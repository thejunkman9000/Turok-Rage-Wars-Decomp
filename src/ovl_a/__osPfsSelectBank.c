#include "common.h"

s32 __osPfsSelectBank(OSPfs *pfs) {
    u8 temp[32];
    s32 k;
    for (k = 0; k < 32; k++) {
        temp[k] = pfs->activebank;
    }
    return __osContRamWrite(pfs->queue, pfs->channel, 0x400, temp, 0);
}
