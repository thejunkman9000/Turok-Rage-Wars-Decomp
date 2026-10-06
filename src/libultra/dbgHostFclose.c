#include "dbglink_types.h"

s32 dbgHostFclose(u32 handle) {
    D_8014D3E8 = 0;
    D_800D3650 = 100;
    dbgPortSetIntLineStatus_i(1);
    dbgPortWaitOverrun_i(1);
    if (D_8014D3E8 != 0) goto end;
    if (dbgLinkHandshake_i() == 0) goto end;
    dbgLinkSendByte(0x81);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(handle);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetIntLineStatus_i(0);
    dbgPortWaitOverrun_i(0);
end:
    dbgPortSetIntLineStatus_i(0);
    D_800D3650 = 1;
    return 0;
}
