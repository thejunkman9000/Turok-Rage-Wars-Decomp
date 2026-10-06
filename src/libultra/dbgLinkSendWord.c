#include "dbglink_types.h"

s32 dbgLinkSendWord(u32 v) {
    s32 ret = 0;
    dbgLinkSendByte(v >> 24);
    if (D_8014D3E8 == 0) {
        dbgLinkSendByte((v >> 16) & 0xFF);
        if (D_8014D3E8 == 0) {
            dbgLinkSendByte((v >> 8) & 0xFF);
            if (D_8014D3E8 == 0) {
                dbgLinkSendByte(v & 0xFF);
                ret = D_8014D3E8 == 0;
            }
        }
    }
    return ret;
}
