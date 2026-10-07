#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002BD7C0(s32 arg0, s32 arg1) {
    s8 sp10;
    s8 sp11;
    s8 sp12;
    s8 sp13;
    s16 sp14;
    M2C_UNK sp2F;
    M2C_UNK sp30;
    s8 sp36;
    M2C_UNK *var_a0;
    s32 var_v1;
    s32 var_v1_2;
    s8 *var_a0_2;
    s8 *var_s2;
    s8 *var_v1_3;

    var_s2 = (s8 *)0x80154110;
    M2C_FIELD((s8 *)0x80154110, s32 *, 0x3C) = 1;
    sp11 = 3;
    sp12 = 0x21;
    sp10 = 0xFF;
    sp13 = 2;
    var_v1 = 0x1F;
    var_a0 = &sp2F;
    sp14 = (__osContAddressCrc(arg1 & 0xFFFF) & 0xFF) | (arg1 << 5);
    sp36 = 0xFF;
    do {
        M2C_FIELD(var_a0, s8 *, 6) = 0xFF;
        var_v1 -= 1;
        var_a0 -= 1;
    } while (var_v1 >= 0);
    if (arg0 != 0) {
        var_v1_2 = 0;
        if (arg0 > 0) {
            do {
                *var_s2 = 0;
                var_v1_2 += 1;
                var_s2 += 1;
            } while (var_v1_2 < arg0);
        }
    }
    var_a0_2 = var_s2;
    var_v1_3 = &sp10;
    if ((s32) var_s2 & 3) {
        do {
            M2C_FIELD(var_a0_2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, s8 *, 0));
            M2C_FIELD(var_a0_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 4));
            M2C_FIELD(var_a0_2, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 8));
            M2C_FIELD(var_a0_2, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 0xC));
            var_v1_3 += 0x10;
            var_a0_2 += 0x10;
        } while (var_v1_3 != &sp30);
    } else {
        do {
            M2C_FIELD(var_a0_2, s32 *, 0) = (s32) M2C_FIELD(var_v1_3, s32 *, 0);
            M2C_FIELD(var_a0_2, s32 *, 4) = (s32) M2C_FIELD(var_v1_3, s32 *, 4);
            M2C_FIELD(var_a0_2, s32 *, 8) = (s32) M2C_FIELD(var_v1_3, s32 *, 8);
            M2C_FIELD(var_a0_2, s32 *, 0xC) = (s32) M2C_FIELD(var_v1_3, s32 *, 0xC);
            var_v1_3 += 0x10;
            var_a0_2 += 0x10;
        } while (var_v1_3 != &sp30);
    }
    M2C_FIELD(var_a0_2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, s8 *, 0));
    M2C_FIELD(var_a0_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 4));
    M2C_FIELD(var_s2, s8 *, 0x28) = 0xFE;
}
