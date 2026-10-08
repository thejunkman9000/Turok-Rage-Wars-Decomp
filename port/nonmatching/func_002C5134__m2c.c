#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s16 func_002C5134(f32 arg0) {
    f32 var_f0;
    f32 var_f12;
    s32 var_condition_bit;

    if (arg0 >= 0.0f) {
        var_f12 = arg0 + *(f32 *)0x800CCF38;
        var_f0 = *(f32 *)0x800CCF3C;
        var_condition_bit = var_f0 < var_f12;
    } else {
        var_f12 = arg0 - *(f32 *)0x800CCF40;
        var_f0 = *(f32 *)0x800CCF44;
        var_condition_bit = var_f12 < var_f0;
    }
    if (var_condition_bit) {
        var_f12 = var_f0;
    }
    return (s16) (s32) var_f12;
}
