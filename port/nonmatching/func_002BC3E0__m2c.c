#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_002BC3E0(void) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_a3;
    s32 var_v0;
    u32 var_a2;

    temp_f0 = (M2C_ERROR(/* Read from unset register $f2 */) / M2C_ERROR(/* Read from unset register $f0 */)) + M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), f32 *, -0x3488);
    temp_f1 = *(f32 *)0x800CCB7C;
    if (temp_f1 <= temp_f0) {
        var_a2 = (s32) (temp_f0 - temp_f1) | 0x80000000;
        var_v0 = var_a2 < 0x84U;
    } else {
        var_a2 = (u32) (s32) temp_f0;
        var_v0 = var_a2 < 0x84U;
    }
    if (var_v0 != 0) {
        return -1;
    }
    var_a3 = var_a2 / 66;
    if ((u32) (var_a3 & 0xFF) >= 0x11U) {
        var_a3 = 0x10;
    }
    *(s32 *)0xA4500010 = var_a2 - 1;
    *(s32 *)0xA4500014 = (var_a3 & 0xFF) - 1;
    *(s32 *)0xA4500008 = 1;
    return (s32) *(s32 *)0x800D9280 / (s32) var_a2;
}
