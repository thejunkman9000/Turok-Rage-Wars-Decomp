#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
f64 func_002BA3D0(f64 arg0, s32 *arg2) {
    f64 var_f1;
    f64 var_f1_2;
    f64 var_f1_3;

    *arg2 = 0;
    if (arg0 == *(f64 *)0x800CC960) {
        return arg0;
    }
    var_f1_2 = fabs(arg0);
    if ((second half of f64) <= var_f1_2) {
        do {
            var_f1_2 *= *(f64 *)0x800CC970;
            *arg2 += 1;
        } while ((second half of f64) <= var_f1_2);
    }
    var_f1_3 = second half of f64;
    if ((second half of f64) < *(f64 *)0x800CC978) {
        do {
            var_f1_3 *= 2.0;
            *arg2 -= 1;
        } while (var_f1_3 < (second half of f64));
    }
    var_f1 = second half of f64;
    if (!(*(f64 *)0x800CC980 < arg0)) {
        var_f1 = -(second half of f64);
    }
    return var_f1;
}
