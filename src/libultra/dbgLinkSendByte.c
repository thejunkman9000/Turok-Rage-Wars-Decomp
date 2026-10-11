#include "dbglink_types.h"

s32 dbgLinkSendByte(u8 b) {
    s32 ret = 0;
    u8 data;
    dbgPortSetLineFormat_i(3);
    D_8014D3E0 = b;
    data = b;
    while (osPiGetStatus() & 3) {
    }
    D_B2000000 = data;
    dbgPortSetIntRxData_i(1);
    dbgPortSetParityEnable_i(1);
    dbgPortWaitDataReady_i(1);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetParityEnable_i(0);
    dbgPortWaitDataReady_i(0);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetIntRxData_i(0);
    dbgPortSetLineFormat_i(0);
    ret = 1;
end:
    return ret;
}
