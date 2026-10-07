#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002BDB70(s32 arg0, s32 arg1, u8 *arg2) {
    s8 sp10;
    s8 sp11;
    s8 sp12;
    s8 sp13;
    s16 sp14;
    M2C_UNK sp30;
    s8 sp36;
    s32 var_a0;
    s32 var_a0_3;
    s8 *temp_v0;
    s8 *var_a0_2;
    s8 *var_s2;
    s8 *var_v1;
    u8 *var_s3;

    var_s3 = arg2;
    var_s2 = (s8 *)0x80154110;
    M2C_FIELD((s8 *)0x80154110, s32 *, 0x3C) = 1;
    sp11 = 0x23;
    sp10 = 0xFF;
    sp12 = 1;
    sp13 = 3;
    var_a0 = 0;
    sp14 = (__osContAddressCrc(arg1 & 0xFFFF) & 0xFF) | (arg1 << 5);
    sp36 = 0xFF;
    do {
        temp_v0 = &(&sp10)[var_a0];
        var_a0 += 1;
        M2C_FIELD(temp_v0, u8 *, 6) = (u8) *var_s3;
        var_s3 += 1;
    } while (var_a0 < 0x20);
    var_a0_2 = (s8 *)0x80154110;
    if (arg0 != 0) {
        var_a0_3 = 0;
        if (arg0 > 0) {
            do {
                *var_s2 = 0;
                var_a0_3 += 1;
                var_s2 += 1;
            } while (var_a0_3 < arg0);
        }
        var_a0_2 = var_s2;
    }
    var_v1 = &sp10;
    if ((s32) var_s2 & 3) {
        do {
            M2C_FIELD(var_a0_2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1, s8 *, 0));
            M2C_FIELD(var_a0_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1, M2C_UNK *, 4));
            M2C_FIELD(var_a0_2, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_v1, M2C_UNK *, 8));
            M2C_FIELD(var_a0_2, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_v1, M2C_UNK *, 0xC));
            var_v1 += 0x10;
            var_a0_2 += 0x10;
        } while (var_v1 != &sp30);
    } else {
        do {
            M2C_FIELD(var_a0_2, s32 *, 0) = (s32) M2C_FIELD(var_v1, s32 *, 0);
            M2C_FIELD(var_a0_2, s32 *, 4) = (s32) M2C_FIELD(var_v1, s32 *, 4);
            M2C_FIELD(var_a0_2, s32 *, 8) = (s32) M2C_FIELD(var_v1, s32 *, 8);
            M2C_FIELD(var_a0_2, s32 *, 0xC) = (s32) M2C_FIELD(var_v1, s32 *, 0xC);
            var_v1 += 0x10;
            var_a0_2 += 0x10;
        } while (var_v1 != &sp30);
    }
    M2C_FIELD(var_a0_2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1, s8 *, 0));
    M2C_FIELD(var_a0_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1, M2C_UNK *, 4));
    M2C_FIELD(var_s2, s8 *, 0x28) = 0xFE;
}
