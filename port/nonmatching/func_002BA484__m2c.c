#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
f64 func_002BA484(f64 arg0, s32 arg2) {
    f64 var_f12;

    var_f12 = arg0;
    if (arg2 != 0) {
        var_f12 *= (f64) (1 << arg2);
    }
    return var_f12;
}
