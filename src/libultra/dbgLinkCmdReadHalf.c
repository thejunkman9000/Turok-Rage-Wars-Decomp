#include "dbglink_types.h"

s32 dbgLinkCmdReadHalf(void) {
    u32 addr;
    u8 b;
    u32 *p;
    u32 v;
    u16 h;
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
                    h = *(u16 *)addr;
                    dbgLinkSendByte(h >> 8);
                    if (D_8014D3E8 == 0) {
                        dbgLinkSendByte(h & 0xFF);
                        ret = D_8014D3E8 == 0;
                    }
                }
            }
        }
    }
    return ret;
}
