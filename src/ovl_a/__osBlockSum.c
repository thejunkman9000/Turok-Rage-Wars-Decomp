#include "common.h"

s32 __osPfsSelectBank(OSPfs *pfs);
u16 __osSumcalc(u8 *ptr, int length);

s32 __osBlockSum(OSPfs *pfs, u8 page, u16 *sum, u8 bank) {
    s32 ret;
    s32 i;
    u8 temp[32];
    pfs->activebank = bank;
    ret = __osPfsSelectBank(pfs);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < 8; i++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, page * 8 + i, temp);
        if (ret != 0) {
            pfs->activebank = 0;
            __osPfsSelectBank(pfs);
            return ret;
        }
        *sum += __osSumcalc(temp, 32);
    }
    pfs->activebank = 0;
    return __osPfsSelectBank(pfs);
}
