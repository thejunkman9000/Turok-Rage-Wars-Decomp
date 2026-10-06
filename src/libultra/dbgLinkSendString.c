#include "dbglink_types.h"

s32 dbgLinkSendString(u8 *s) {
    s32 ret = 0;
    u8 c;
    do {
        c = *s++;
        dbgLinkSendByte(c);
        if (D_8014D3E8 != 0) goto end;
    } while (c != 0);
    ret = 1;
end:
    return ret;
}
