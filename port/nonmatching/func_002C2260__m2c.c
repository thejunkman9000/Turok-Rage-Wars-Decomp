#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_002C2260(s32 arg0) {
    s32 var_t2;
    u32 temp_t3;

    temp_t3 = *(u32 *)0x800D9288;
    var_t2 = *(s32 *)0xA430000C;
    if (var_t2 != 0) {
        var_t2 |= ((temp_t3 >> 0x10) ^ -1) & 0x3F;
    }
    *(s32 *)0xA430000C = (s32) M2C_FIELD((((u32) (arg0 & 0x3F0000 & temp_t3) >> 0xF) + 0x800D0000), u16 *, -0x3340);
    M2C_ERROR(/* mtc0 $t4, $12 */);
    return (M2C_ERROR(/* mfc0 $12 */) & 0xFF01) | ((temp_t3 ^ -1) & 0xFF00) | (var_t2 << 0x10);
}
