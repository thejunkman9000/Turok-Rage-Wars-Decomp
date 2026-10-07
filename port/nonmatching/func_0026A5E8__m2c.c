#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_0026A5E8(void) {
    f32 temp_f0;
    f32 temp_f1;
    s32 var_v0;
    u8 *temp_a1;

    temp_a1 = *(u8 **)0x80110634;
    temp_f1 = *(f32 *)0x800C9724;
    M2C_FIELD(temp_a1, s32 *, 0) = 0xFA000000;
    temp_f0 = *(f32 *)0x800D15F4;
    *(u8 **)0x80110634 = temp_a1 + 8;
    if (!(temp_f1 <= temp_f0)) {
        var_v0 = (s32) temp_f0 & 0xFF;
    } else {
        var_v0 = ((s32) (temp_f0 - temp_f1) | 0x80000000) & 0xFF;
    }
    M2C_FIELD(temp_a1, s32 *, 4) = (s32) ((M2C_FIELD(saved_reg_s1, u8 *, 0x10) << 0x18) | (M2C_FIELD(saved_reg_s1, u8 *, 0x11) << 0x10) | (M2C_FIELD(saved_reg_s1, u8 *, 0x12) << 8) | var_v0);
    func_00268CE0(0x11, temp_a1);
    func_002536F4(0, saved_reg_s4);
    func_0026AA6C();
}
