#include "dbglink_types.h"

s32 dbgLinkRecvByte(u8 *out) {
    s32 ret = 0;
    dbgPortSetLineFormat_i(2);
    dbgPortSetParityEnable_i(1);
    D_8014D3E8 = 0;
    dbgPortWaitDataReady_i(1);
    if (D_8014D3E8 != 0) goto end;
    *out = dbgPortReadData_i();
    dbgPortSetParityEnable_i(0);
    dbgPortWaitDataReady_i(0);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetLineFormat_i(0);
    ret = 1;
end:
    return ret;
}
