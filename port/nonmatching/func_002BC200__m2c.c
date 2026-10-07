#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
f32 func_002BC200(f32 arg0) {
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_f4;
    s32 temp_v1;

    temp_v1 = (M2C_BITWISE(s32, arg0) >> 0x16) & 0x1FF;
    if (temp_v1 < 0xFF) {
        if (temp_v1 >= 0xE6) {
            return arg0 + ((second half of f64) * (f32) ((((second half of f64) + M2C_FIELD((u8 *)0x800CCB20, f64 *, 0x10)) * (f64) (arg0 * arg0)) + M2C_FIELD((u8 *)0x800CCB20, f64 *, 8)));
        }
        return arg0;
    }
    if (temp_v1 < 0x136) {
        temp_f2 = (f32) ((f64) arg0 * (second half of f64));
        if (temp_f2 >= 0.0f) {
            var_f0_2 = temp_f2 + *(f32 *)0x800CCB64;
        } else {
            var_f0_2 = temp_f2 - *(f32 *)0x800CCB68;
        }
        temp_f4 = (s32) var_f0_2;
        temp_f12 = (f32) ((f64) (f32) ((f64) arg0 - (second half of f64)) - ((f64) (f32) temp_f4 * *(f64 *)0x800CCB58));
        var_f0 = temp_f12 + (temp_f12 * (second half of f64) * (f32) ((second half of f64) + M2C_FIELD((u8 *)0x800CCB20, f64 *, 8)));
        if (temp_f4 & 1) {
            return -var_f0;
        }
        /* Duplicate return node #11. Try simplifying control flow for better match */
        return var_f0;
    }
    var_f0 = *(f32 *)0x800CCB60;
    return var_f0;
}
