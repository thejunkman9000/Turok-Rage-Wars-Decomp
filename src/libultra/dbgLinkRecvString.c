#include "dbglink_types.h"

s32 dbgLinkRecvString(u8 *buf, s32 max) {
    u8 b;
    s32 ret = 0;
    s32 i = 0;
    do {
        dbgLinkRecvByte(&b);
        if (D_8014D3E8 != 0) goto end;
        if (i < max) buf[i] = b;
        i++;
    } while (b != 0);
    ret = 1;
end:
    return ret;
}
