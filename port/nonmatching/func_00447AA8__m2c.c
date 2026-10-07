#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_00447AA8(s32 arg0) {
    s8 sp0;
    s8 sp1;
    s8 sp2;
    s8 sp3;
    s8 sp4;
    s8 sp5;
    s32 var_a1;
    s8 *var_v1;

    var_v1 = (s8 *)0x80154110;
    var_a1 = 0;
    M2C_FIELD((s8 *)0x80154110, s32 *, 0x3C) = 1;
    sp0 = 1;
    sp1 = 3;
    *(s8 *)0x8014D4B0 = 0;
    sp2 = 0;
    sp3 = 0xFF;
    sp4 = -1;
    sp5 = -1;
    if (arg0 > 0) {
        do {
            *var_v1 = 0;
            var_a1 += 1;
            var_v1 += 1;
        } while (var_a1 < arg0);
    }
    M2C_FIELD(var_v1, s8 *, 0) = M2C_UNALIGNED32(sp0);
    M2C_FIELD(var_v1, s8 *, 4) = sp4;
    M2C_FIELD(var_v1, s8 *, 5) = sp5;
    M2C_FIELD(var_v1, s8 *, 6) = 0xFE;
}
