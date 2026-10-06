#include "dbglink_types.h"

s32 dbgHostFwrite(u8 *buf, u32 size, u32 count, u32 handle) {
    u8 ack;
    s32 cnt = 100;
    D_8014D3E8 = 0;
    D_800D3650 = 100;
    dbgPortSetIntLineStatus_i(1);
    dbgPortWaitOverrun_i(1);
    if (D_8014D3E8 != 0) goto end;
    if (dbgLinkHandshake_i() == 0) goto end;
    dbgLinkSendByte(0x83);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(handle);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendWord_i(size * count);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendBlock(buf, size * count);
    do {
        D_8014D3E8 = 0;
        dbgLinkRecvByte(&ack);
    } while (cnt-- > 0 && D_8014D3E8 != 0);
    if (D_8014D3E8 != 0) goto end;
    dbgPortSetIntLineStatus_i(0);
    dbgPortWaitOverrun_i(0);
end:
    dbgPortSetIntLineStatus_i(0);
    D_800D3650 = 1;
    return count;
}
