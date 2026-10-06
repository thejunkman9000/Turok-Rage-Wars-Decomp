#include "dbglink_types.h"

extern u32 D_800D3640;
extern u32 D_800D3644;
extern u32 D_800D3648;

s32 dbgLinkCmdLoadProgram(void) {
    u32 size;
    u8 b;
    u32 cksum;
    u8 b2;
    u32 sum;
    u32 *p;
    u32 *q;
    u32 v;
    s32 ret = 0;
    u8 *dst = (u8 *)0x80100000;
    p = &size;
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
                    q = &cksum;
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
                                    dbgLinkRecvBlock(dst, size, &sum);
                                    if (D_8014D3E8 == 0) {
                                        if (cksum == sum) {
                                            D_800D3640 = 1;
                                            D_800D3644 = (u32)dst;
                                            ret = 1;
                                            D_800D3648 = size;
                                        }
                                    }
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
