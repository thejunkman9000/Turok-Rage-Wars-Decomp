#include "dbglink_types.h"

extern u32 osSetIntMask(u32 mask);
extern void osWritebackDCacheAll(void);

s32 dbgLinkCmdExec(void) {
    u32 addr;
    u8 b;
    u32 *p;
    u32 v;
    void (*fn)(void);
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
                    fn = (void (*)(void))addr;
                    if (fn != 0) {
                        osSetIntMask(1);
                        osWritebackDCacheAll();
                        osInvalICache((void *)0x80000000, 0x800000);
                        fn();
                    }
                    ret = 1;
                }
            }
        }
    }
    return ret;
}
