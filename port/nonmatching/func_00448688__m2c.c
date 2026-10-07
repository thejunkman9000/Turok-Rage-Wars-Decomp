#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_00448688(s8 *arg0, s16 *arg1) {
    M2C_UNK sp0;
    u8 sp4;
    s16 *var_t0;
    s32 var_a2;
    s8 var_t1;
    u32 temp_v0;
    u8 *var_a1;
    u8 *var_a3;

    var_t0 = arg1;
    var_t1 = 0;
    var_a3 = (u8 *)0x80154110;
    var_a2 = 0;
    if (*(u8 *)0x8014D46C != 0) {
        var_a1 = arg1 + 2;
        do {
            sp0 = M2C_UNALIGNED32(M2C_FIELD(var_a3, M2C_UNK *, 0));
            sp4 = M2C_UNALIGNED32(M2C_FIELD(var_a3, M2C_UNK *, 4));
            temp_v0 = (u32) (sp2 & 0xC0) >> 4;
            M2C_FIELD(var_a1, s8 *, 1) = (s8) temp_v0;
            if (temp_v0 == 0) {
                *var_t0 = sp4 | (sp5 << 8);
                var_t1 |= 1 << var_a2;
                M2C_FIELD(var_a1, u8 *, 0) = sp6;
            }
            var_a2 += 1;
            var_a3 += 8;
            var_a1 += 4;
            var_t0 += 4;
        } while (var_a2 < (s32) *(u8 *)0x8014D46C);
    }
    *arg0 = var_t1;
}
