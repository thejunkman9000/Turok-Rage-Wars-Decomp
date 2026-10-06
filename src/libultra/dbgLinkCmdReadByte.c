#include "dbglink_types.h"

s32 dbgLinkCmdReadByte(void) {
    u32 addr;
    u8 b;
    u32 *p;
    u32 v;
    s32 ret = 0;
    p = &addr;
    dbgLinkRecvByte(&b);
    if (D_8014D3E8 == 0) {
        v = b << 8;
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 == 0) {
            v |= b;
            v <<= 8;
            dbgLinkRecvByte(&b);
            if (D_8014D3E8 == 0) {
                v |= b;
                v <<= 8;
                dbgLinkRecvByte(&b);
                if (D_8014D3E8 == 0) {
                    v |= b;
                    *p = v;
                    dbgLinkSendByte(*(u8 *)addr);
                    ret = D_8014D3E8 == 0;
                }
            }
        }
    }
    return ret;
}
