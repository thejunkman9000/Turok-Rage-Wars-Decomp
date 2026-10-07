#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_002BEDA0(s32 arg0, s32 arg1) {
    s32 *var_v1;
    s32 var_v0;

    if (arg1 & 3) {
        __assert(0x800CCBE0, 0x800CCBE4, 0x37);
    }
    var_v0 = -1;
    if (__osSiDeviceBusy() == 0) {
        if (arg0 == 1) {
            osWritebackDCache(arg1, 0x40);
        }
        *(s32 *)0xA4800000 = osVirtualToPhysical(arg1);
        if (arg0 != 0) {
            var_v1 = (s32 *)0xA4800010;
        } else {
            var_v1 = (s32 *)0xA4800004;
        }
        *var_v1 = 0x1FC007C0;
        var_v0 = 0;
        if (arg0 == 0) {
            osInvalDCache(arg1, 0x40);
            var_v0 = 0;
        }
    }
    return var_v0;
}
