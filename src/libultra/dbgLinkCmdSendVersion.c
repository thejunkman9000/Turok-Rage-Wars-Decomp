#include "dbglink_types.h"

extern u32 strlen(const u8 *str);
extern u8 D_800CB480[];

s32 dbgLinkCmdSendVersion(void) {
    s32 ret = 0;
    u8 *str = D_800CB480;
    u32 len;
    u8 b;
    u32 *p;
    u32 v;
    u32 w;
    p = &len;
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
                    len = (len < strlen(str)) ? len : strlen(str);
                    w = len;
                    dbgLinkSendByte(w >> 24);
                    if (D_8014D3E8 == 0) {
                        dbgLinkSendByte((w >> 16) & 0xFF);
                        if (D_8014D3E8 == 0) {
                            dbgLinkSendByte((w >> 8) & 0xFF);
                            if (D_8014D3E8 == 0) {
                                dbgLinkSendByte(w & 0xFF);
                            }
                        }
                    }
                    dbgLinkSendBlock(str, len);
                    if (D_8014D3E8 == 0) ret = 1;
                }
            }
        }
    }
    return ret;
}
