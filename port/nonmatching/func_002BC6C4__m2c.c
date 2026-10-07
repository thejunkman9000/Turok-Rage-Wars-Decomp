#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_002BC6C4(u16 *arg0) {
    M2C_UNK sp0;
    u16 sp4;
    s32 var_v1;
    u16 *var_a1;
    u32 temp_v0;
    u8 *var_a0;
    u8 *var_a2;

    var_a1 = arg0;
    var_a2 = (u8 *)0x8014D470;
    var_v1 = 0;
    if (*(u8 *)0x8014D46C != 0) {
        var_a0 = arg0 + 3;
        do {
            sp0 = M2C_UNALIGNED32(M2C_FIELD(var_a2, M2C_UNK *, 0));
            sp4 = M2C_UNALIGNED32(M2C_FIELD(var_a2, M2C_UNK *, 4));
            temp_v0 = (u32) (sp2 & 0xC0) >> 4;
            M2C_FIELD(var_a0, s8 *, 1) = (s8) temp_v0;
            if (temp_v0 == 0) {
                *var_a1 = sp4;
                M2C_FIELD(var_a0, u8 *, -1) = sp6;
                M2C_FIELD(var_a0, u8 *, 0) = sp7;
            }
            var_v1 += 1;
            var_a2 += 8;
            var_a0 += 6;
            var_a1 += 6;
        } while (var_v1 < (s32) *(u8 *)0x8014D46C);
    }
}
