#include "dbglink_types.h"

s32 dbgLinkCmdWriteHalf(void) {
    u32 addr;
    u8 b;
    u16 val;
    u8 b2;
    u32 *p;
    u16 *q;
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
                    q = &val;
                    dbgLinkRecvByte(&b2);
                    if (D_8014D3E8 == 0) {
                        h = b2 << 8;
                        dbgLinkRecvByte(&b2);
                        if (D_8014D3E8 == 0) {
                            h |= b2;
                            *q = h;
                            ret = 1;
                            *(u16 *)addr = val;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
