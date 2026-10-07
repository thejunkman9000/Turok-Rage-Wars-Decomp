#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
f32 func_002BA358(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f1;
    f32 var_f2;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;

    var_a1 = arg1 >> 3;
    var_v1 = 0;
    if (var_a1 == 0) {
        return arg0;
    }
    var_f2 = *(f32 *)0x800CC95C;
    var_f1 = ((f32) (arg2 << 0x10) + (f32) (arg3 & 0xFFFF)) * *(f32 *)0x800CC958;
    var_v0 = var_a1 & 1;
loop_3:
    var_a1 = var_a1 >> 1;
    if (var_v0 != 0) {
        var_f2 *= var_f1;
    }
    var_v1 += 1;
    if (var_a1 != 0) {
        var_f1 *= var_f1;
        var_v0 = var_a1 & 1;
        if (var_v1 < 0x20) {
            goto loop_3;
        }
    }
    return arg0 * var_f2;
}
