#include "dbglink_types.h"

s32 dbgHostSendWord(u32 w) {
    D_8014D3E8 = 0;
    D_800D3650 = 100;
    dbgPortSetIntLineStatus_i(1);
    dbgPortWaitOverrun_i(1);
    if (D_8014D3E8 != 0) goto end;
    if (dbgLinkHandshake_i() == 0) goto end;
    dbgLinkSendByte(0xC0);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(w);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetIntLineStatus_i(0);
    dbgPortWaitOverrun_i(0);
end:
    dbgPortSetIntLineStatus_i(0);
    D_800D3650 = 1;
    return 0;
}
