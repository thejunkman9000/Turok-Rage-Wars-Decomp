#include "dbglink_types.h"

s32 dbgLinkCmdCallHook(void) {
    u32 arg = 0;
    u8 b;
    u32 *p;
    u32 v;
    u32 res = 0;
    p = &arg;
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
                    if (D_800D364C != 0) res = D_800D364C(arg);
                    dbgLinkSendByte(res >> 24);
                    if (D_8014D3E8 == 0) {
                        dbgLinkSendByte((res >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            dbgLinkSendByte((res >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                dbgLinkSendByte(res & 0xFF);
                            }
                        }
                    }
                    if (D_8014D3E8 == 0) return 1;
                }
            }
        }
    }
    return 0;
}
