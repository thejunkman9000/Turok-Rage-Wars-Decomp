#include "dbglink_types.h"

s32 dbgLinkHandshake(void) {
    u8 b;
    s32 ret = 0;
    dbgLinkSendByte(0x10);
    if (D_8014D3E8 == 0) {
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 == 0) {
            ret = b == 0x11;
        }
    }
    return ret;
}
