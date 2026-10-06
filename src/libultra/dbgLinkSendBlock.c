#include "dbglink_types.h"

s32 dbgLinkSendBlock(u8 *buf, s32 len) {
    s32 ret = 0;
    dbgPortWaitModemBit6_i(1);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetLineFormat_i(1);
    dbgPortSetFifoRxReset_i(1);
    dbgPortSetIntRxData_i(1);
    dbgPortWriteReg_i(&D_B2000014, 0);
    while (len-- != 0) {
        dbgPortWaitTxEmpty_i(1);
        if (D_8014D3E8 != 0) goto end;
        dbgPortWriteReg_i(&D_B2000020, *buf++);
    }
    dbgPortWaitTxEmpty_i(1);
    if (D_8014D3E8 != 0) goto end;
    dbgPortWaitModemBit6_i(0);
    if (D_8014D3E8 == 0) ret = 1;
end:
    dbgPortSetIntRxData_i(0);
    dbgPortSetFifoRxReset_i(0);
    dbgPortSetLineFormat_i(0);
    return ret;
}
