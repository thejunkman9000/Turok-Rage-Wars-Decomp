#include "dbglink_types.h"

s32 dbgPortWaitRegMask(u16 *reg, u8 mask, u8 want, s32 cnt) {
    s32 ret = 0;
    s32 outer = D_800D3650;
    s32 c = cnt;
    for (;;) {
        while (osPiGetStatus() & 3) {
        }
        if ((mask & ((u8 *)reg)[1]) == want) {
            ret = 1;
            goto done;
        }
        if (c-- == 0) {
            outer--;
            c = cnt;
        }
        if (outer <= 0) break;
    }
    D_8014D3E8 = 1;
done:
    return ret;
}
