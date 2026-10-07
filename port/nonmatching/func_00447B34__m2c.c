#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_00447B34(s32 arg0, u8 *arg1) {
    M2C_UNK sp0;
    s8 sp4;
    s8 sp5;
    s32 var_v1;
    u32 temp_v0;
    u8 *var_a2;

    var_a2 = (u8 *)0x80154110;
    var_v1 = 0;
    if (arg0 > 0) {
        do {
            var_v1 += 1;
            var_a2 += 1;
        } while (var_v1 < arg0);
    }
    sp0 = M2C_UNALIGNED32(M2C_FIELD(var_a2, M2C_UNK *, 0));
    sp4 = M2C_FIELD(var_a2, s8 *, 4);
    sp5 = M2C_FIELD(var_a2, s8 *, 5);
    temp_v0 = (u32) (sp1 & 0xC0) >> 4;
    M2C_FIELD(arg1, s8 *, 3) = (s8) temp_v0;
    if (temp_v0 == 0) {
        M2C_FIELD(arg1, s16 *, 0) = (s16) (sp3 | ((u8) sp4 << 8));
        M2C_FIELD(arg1, u8 *, 2) = (u8) sp5;
    }
}
