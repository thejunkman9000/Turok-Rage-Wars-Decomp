#include "dbglink_types.h"

s32 dbgHostFseek(u32 handle, u32 offset, u32 whence) {
    u32 res = 0;
    s32 cnt = 100;
    D_8014D3E8 = 0;
    D_800D3650 = 100;
    dbgPortSetIntLineStatus_i(1);
    dbgPortWaitOverrun_i(1);
    if (D_8014D3E8 != 0) goto end;
    if (dbgLinkHandshake_i() == 0) goto end;
    dbgLinkSendByte(0x84);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(handle);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(offset);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(whence);
    if (D_8014D3E8 != 0) goto end;
    do {
        D_8014D3E8 = 0;
        dbgLinkRecvWord_i(&res);
    } while (cnt-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetIntLineStatus_i(0);
    dbgPortWaitOverrun_i(0);
end:
    dbgPortSetIntLineStatus_i(0);
    D_800D3650 = 1;
    return res;
}
