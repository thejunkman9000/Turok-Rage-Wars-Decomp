#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
f32 func_002BB630(f32 arg0) {
    f64 temp_f0;
    f64 temp_f12;
    f64 temp_f12_2;
    f64 temp_f2;
    f64 var_f0;
    s32 temp_f3;

    if (((M2C_BITWISE(s32, arg0) >> 0x16) & 0x1FF) < 0x136) {
        temp_f12 = (f64) fabsf(arg0);
        temp_f2 = (second half of f64) + *(f64 *)0x800CCAA8;
        if (!(*(f64 *)0x800CCAB0 <= temp_f2)) {
            var_f0 = temp_f2 - (second half of f64);
        } else {
            var_f0 = temp_f2 + (second half of f64);
        }
        temp_f3 = (s32) var_f0;
        temp_f12_2 = (temp_f12 - (second half of f64)) - (((f64) temp_f3 - *(f64 *)0x800CCAB8) * *(f64 *)0x800CCA98);
        temp_f0 = temp_f12_2 + (temp_f12_2 * (temp_f12_2 * temp_f12_2) * ((second half of f64) + M2C_FIELD((u8 *)0x800CCA60, f64 *, 8)));
        if (!(temp_f3 & 1)) {
            return (f32) temp_f0;
        }
        return -(f32) temp_f0;
    }
    return *(f32 *)0x800CCAA0;
}
