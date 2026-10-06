#include "dbglink_types.h"

s32 dbgLinkCmdReadBlock(void) {
    u32 addr;
    u8 b;
    u32 len;
    u8 b2;
    u32 *p;
    u32 *q;
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
                    q = &len;
                    dbgLinkRecvByte(&b2);
                    if (D_8014D3E8 == 0) {
                        v = b2 << 8;
                        dbgLinkRecvByte(&b2);
                        if (D_8014D3E8 == 0) {
                            v |= b2;
                            v <<= 8;
                            dbgLinkRecvByte(&b2);
                            if (D_8014D3E8 == 0) {
                                v |= b2;
                                v <<= 8;
                                dbgLinkRecvByte(&b2);
                                if (D_8014D3E8 == 0) {
                                    v |= b2;
                                    *q = v;
                                    dbgLinkSendBlock((u8 *)addr, len);
                                    ret = D_8014D3E8 == 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
