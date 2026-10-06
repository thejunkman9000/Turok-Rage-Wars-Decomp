#include "dbglink_types.h"

s32 dbgLinkCmdWriteWord(void) {
    u32 addr;
    u8 b;
    u32 val;
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
                    q = &val;
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
                                    ret = 1;
                                    *(u32 *)addr = val;
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
