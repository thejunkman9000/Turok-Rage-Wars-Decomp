#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_002BCAF0(s8 arg0) {
    s8 sp0;
    s8 sp1;
    s8 sp2;
    s8 sp3;
    s8 sp4;
    s8 sp5;
    s8 sp6;
    s8 sp7;
    s32 *var_v0;
    s32 var_a1;
    s32 var_a1_2;
    s8 *var_a2;

    var_a1 = 0xE;
    var_v0 = (s32 *)0x8014D4A8;
    do {
        *var_v0 = 0;
        var_a1 -= 1;
        var_v0 -= 4;
    } while (var_a1 >= 0);
    var_a2 = (s8 *)0x8014D470;
    var_a1_2 = 0;
    M2C_FIELD((s8 *)0x8014D470, s32 *, 0x3C) = 1;
    sp0 = 0xFF;
    sp1 = 1;
    sp2 = 3;
    sp3 = arg0;
    sp4 = 0xFF;
    sp5 = 0xFF;
    sp6 = 0xFF;
    sp7 = 0xFF;
    if (*(u8 *)0x8014D46C != 0) {
        do {
            M2C_FIELD(var_a2, s8 *, 0) = M2C_UNALIGNED32(sp0);
            M2C_FIELD(var_a2, M2C_UNK *, 4) = M2C_UNALIGNED32(sp4);
            var_a1_2 += 1;
            var_a2 += 8;
        } while (var_a1_2 < (s32) *(u8 *)0x8014D46C);
    }
    *var_a2 = 0xFE;
}
