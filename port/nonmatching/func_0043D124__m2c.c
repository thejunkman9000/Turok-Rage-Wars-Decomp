#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_0043D124(u8 *arg0) {
    u32 temp_v1;

    temp_v1 = *(u32 *)0x80154030;
    if (temp_v1 < 0xCU) {
        M2C_FIELD(arg0, s32 *, 0x14) = (s32) *(0x44FB94 + (temp_v1 * 0x10));
    } else {
        M2C_FIELD(arg0, s32 *, 0x14) = 0x800D7E14;
    }
    return 0;
}
