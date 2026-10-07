#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_0043DEDC(u8 *arg0) {
    s32 var_s0;
    s32 var_s1;
    s8 var_s0_2;
    u8 *var_v0;

    var_s0 = 7;
    var_v0 = (u8 *)0x801466E2;
    do {
        M2C_FIELD(var_v0, s8 *, 0x148) = 0;
        var_s0 -= 1;
        var_v0 -= 0x96;
    } while (var_s0 >= 0);
    var_s0_2 = 0;
    var_s1 = 0x8010F328;
loop_3:
    if (func_0026439C(var_s1) == 0) {
        var_s0_2 += 1;
        var_s1 += 0x224;
        if (var_s0_2 < 4) {
            goto loop_3;
        }
    } else {
        M2C_FIELD((u8 *)0x80146302, s8 *, 0x78) = 1;
        M2C_FIELD((u8 *)0x80146302, s8 *, 0x7F) = var_s0_2;
        M2C_FIELD(arg0, s32 *, 0x20) = var_s1;
    }
    func_0025E3A4();
}
