#include "common.h"

s32 __osPfsSelectBank(OSPfs *pfs);

s32 __osClearPage(OSPfs *pfs, int page, u8 *data, u8 bank) {
    s32 ret;
    s32 i;
    pfs->activebank = bank;
    ret = __osPfsSelectBank(pfs);
    if (ret == 0) {
        for (i = 0; i < 8; i++) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, page * 8 + i, data, 0);
            if (ret != 0) {
                break;
            }
        }
        pfs->activebank = 0;
        ret = __osPfsSelectBank(pfs);
    }
    return ret;
}
