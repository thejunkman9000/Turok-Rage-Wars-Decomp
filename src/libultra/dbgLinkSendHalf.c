#include "dbglink_types.h"

s32 dbgLinkSendHalf(u16 v) {
    s32 ret = 0;
    dbgLinkSendByte((v >> 8) & 0xFF);
    if (D_8014D3E8 == 0) {
        dbgLinkSendByte(v & 0xFF);
        ret = D_8014D3E8 == 0;
    }
    return ret;
}
