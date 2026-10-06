#include "dbglink_types.h"

s32 dbgLinkRecvBlock(u8 *buf, s32 len, u32 *sum) {
    s32 ret = 0;
    u32 acc = 0;
    u8 b;
    dbgPortSetIntModemStatus_i(1);
    dbgPortSetLineFormat_i(0);
    dbgPortSetFifoRxReset_i(1);
    dbgPortWriteReg_i(&D_B2000018, 0);
    while (len-- != 0) {
        dbgPortWaitTxEmpty_i(1);
        if (D_8014D3E8 != 0) goto end;
        b = dbgPortReadReg_i(&D_B2000020);
        *buf++ = b;
        acc = (acc << 1) | (acc >> 31);
        acc += b;
    }
    *sum = acc;
    ret = 1;
end:
    dbgPortSetFifoRxReset_i(0);
    dbgPortSetIntModemStatus_i(0);
    dbgPortSetLineFormat_i(0);
    return ret;
}
