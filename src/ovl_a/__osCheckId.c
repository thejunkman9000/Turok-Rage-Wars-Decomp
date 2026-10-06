#include "common.h"

s32 __osPfsSelectBank(OSPfs *pfs);

s32 __osCheckId(OSPfs *pfs) {
    s32 k;
    u8 temp[32];
    s32 ret;
    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        if (ret == 2) {
            ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
            if (ret != 0) {
                return ret;
            }
        } else {
            return ret;
        }
    }
    for (k = 0; k < 32; k++) {
        if (pfs->id[k] != temp[k]) {
            return 2;
        }
    }
    return 0;
}
