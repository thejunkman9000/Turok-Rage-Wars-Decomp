#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s16 func_002BA038(f64 arg0, f64 arg1, s32 arg4, s16 *arg5) {
    s32 sp40;
    f64 temp_f14;
    f64 temp_f1;
    f64 temp_f1_2;
    f64 temp_f1_3;
    f64 var_f12;
    f64 var_f14;
    f64 var_f1;
    f64 var_f1_2;
    f64 var_f1_3;
    s32 var_a0;
    s32 var_v0_2;
    u8 *var_v0;
    u8 *var_v1;

    var_f12 = arg0;
    var_f14 = arg1;
    if (arg4 == 0) {
        if (var_f12 <= var_f14) {
            *arg5 = 0xFFFF;
            return 0x7FFF;
        }
        *arg5 = 0;
        return 0;
    }
    temp_f1_2 = *(f64 *)0x800CC8F0;
    if (var_f14 < temp_f1_2) {
        var_f14 = temp_f1_2;
    }
    if (var_f12 <= *(f64 *)0x800CC8F8) {
        var_f12 = second half of f64;
    }
    var_v1 = sp;
    var_v0 = (u8 *)0x800CC8A8;
    do {
        M2C_FIELD(var_v1, s32 *, 0) = (s32) M2C_FIELD(var_v0, s32 *, 0);
        M2C_FIELD(var_v1, s32 *, 4) = (s32) M2C_FIELD(var_v0, s32 *, 4);
        M2C_FIELD(var_v1, s32 *, 8) = (s32) M2C_FIELD(var_v0, s32 *, 8);
        M2C_FIELD(var_v1, s32 *, 0xC) = (s32) M2C_FIELD(var_v0, s32 *, 0xC);
        var_v0 += 0x10;
        var_v1 += 0x10;
    } while (var_v0 != (u8 *)0x800CC8E8);
    temp_f14 = var_f14 / var_f12;
    var_a0 = (s32) (second half of f64);
    sp40 = 0;
    if (temp_f14 == *(f64 *)0x800CC908) {

    } else {
        var_f1 = fabs(temp_f14);
        if ((second half of f64) <= var_f1) {
            do {
                var_f1 *= *(f64 *)0x800CC918;
                sp40 += 1;
            } while ((second half of f64) <= var_f1);
        }
        var_f1_2 = second half of f64;
        if ((second half of f64) < *(f64 *)0x800CC920) {
            do {
                var_f1_2 *= 2.0;
                sp40 -= 1;
            } while (var_f1_2 < (second half of f64));
        }
        if (!(*(f64 *)0x800CC928 < temp_f14)) {

        }
    }
    var_f1_3 = second half of f64;
    if (var_a0 != 0) {
        var_v0_2 = var_a0 & 1;
        do {
            var_a0 = var_a0 >> 1;
            if (var_v0_2 != 0) {

            }
            var_f1_3 = second half of f64;
            var_v0_2 = var_a0 & 1;
        } while (var_a0 != 0);
    }
    temp_f1_3 = var_f1_3 * var_f1_3;
    temp_f1 = temp_f1_3 * temp_f1_3;
    *arg5 = (s16) (s32) ((second half of f64) * *(f64 *)0x800CC950);
    return (s16) (s32) (temp_f1 * temp_f1);
}
