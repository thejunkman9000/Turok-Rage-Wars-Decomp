#include "dbglink_types.h"

s32 dbgHostFopen(u8 *name, u8 *mode) {
    u32 handle = 0;
    u8 b;
    u8 b2;
    u32 *p;
    u32 v;
    D_8014D3E8 = 0;
    D_800D3650 = 100;
    dbgPortSetIntLineStatus_i(1);
    dbgPortWaitOverrun_i(1);
    if (D_8014D3E8 != 0) goto end;
    if (dbgLinkHandshake_i() == 0) goto end;
    dbgLinkSendByte(0x80);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendString_i(name);
    if (D_8014D3E8 != 0) goto end;
    dbgLinkSendString_i(mode);
    if (D_8014D3E8 != 0) goto end;
    p = &handle;
    dbgLinkRecvByte(&b2);
    if (D_8014D3E8 != 0) goto end;
    v = b2 << 8;
    dbgLinkRecvByte(&b2);
    if (D_8014D3E8 != 0) goto end;
    v |= b2;
    v <<= 8;
    dbgLinkRecvByte(&b2);
    if (D_8014D3E8 != 0) goto end;
    v |= b2;
    v <<= 8;
    dbgLinkRecvByte(&b2);
    if (D_8014D3E8 != 0) goto end;
    v |= b2;
    *p = v;
    dbgPortSetIntLineStatus_i(0);
    dbgPortWaitOverrun_i(0);
end:
    dbgPortSetIntLineStatus_i(0);
    D_800D3650 = 1;
    return handle;
}
