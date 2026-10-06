#include "dbglink_types.h"

s32 dbgLinkRecvWord(u32 *out) {
    u8 b;
    u32 v;
    s32 ret = 0;
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
                    ret = 1;
                    *out = v;
                }
            }
        }
    }
    return ret;
}
