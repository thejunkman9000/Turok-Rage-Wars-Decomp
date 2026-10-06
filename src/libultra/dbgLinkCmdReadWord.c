#include "dbglink_types.h"

s32 dbgLinkCmdReadWord(void) {
    u32 addr;
    u8 b;
    u32 *p;
    u32 v;
    u32 w;
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
                    w = *(u32 *)addr;
                    dbgLinkSendByte(w >> 24);
                    if (D_8014D3E8 == 0) {
                        dbgLinkSendByte((w >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            dbgLinkSendByte((w >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                dbgLinkSendByte(w & 0xFF);
                                ret = D_8014D3E8 == 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
