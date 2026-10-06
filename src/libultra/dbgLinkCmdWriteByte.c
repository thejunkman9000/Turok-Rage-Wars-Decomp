#include "dbglink_types.h"

s32 dbgLinkCmdWriteByte(void) {
    u32 addr;
    u8 b;
    u8 b2;
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
                    dbgLinkRecvByte(&b2);
                    if (D_8014D3E8 == 0) {
                        *(u8 *)addr = b2;
                        ret = 1;
                    }
                }
            }
        }
    }
    return ret;
}
