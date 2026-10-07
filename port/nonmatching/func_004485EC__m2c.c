#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_004485EC(s8 arg0) {
    s8 sp0;
    s8 sp1;
    s8 sp2;
    s8 sp3;
    s8 sp4;
    s8 sp5;
    s8 sp6;
    s8 sp7;
    s32 var_a2;
    s8 *var_a3;

    var_a3 = (s8 *)0x80154110;
    var_a2 = 0;
    *(s8 *)0x8014D4B0 = arg0;
    M2C_FIELD((s8 *)0x80154110, s32 *, 0x3C) = 1;
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
            M2C_FIELD(var_a3, s8 *, 0) = M2C_UNALIGNED32(sp0);
            M2C_FIELD(var_a3, M2C_UNK *, 4) = M2C_UNALIGNED32(sp4);
            var_a2 += 1;
            var_a3 += 8;
        } while (var_a2 < (s32) *(u8 *)0x8014D46C);
    }
    *var_a3 = 0xFE;
}
