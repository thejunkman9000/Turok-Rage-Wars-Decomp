#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002C4B9C(s32 arg0, s32 arg1) {
    M2C_UNK sp18;
    M2C_UNK32 *temp_v1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f4;
    f32 temp_f4_2;
    f32 temp_f4_3;
    f32 temp_f4_4;
    f32 temp_f5;
    f32 temp_f5_2;
    f32 temp_f5_3;
    f32 temp_f6;
    f32 temp_f7;
    f32 temp_f8;
    f32 var_f0;
    f32 var_f4;
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v0_6;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_a1_3;
    s16 var_a3;
    s32 temp_a0;
    s32 temp_a0_5;
    s32 temp_v0_3;
    s32 temp_v0_5;
    u8 *temp_a0_2;
    u8 *temp_a0_3;
    u8 *temp_a0_4;
    u8 *temp_v1_2;

    if (*(s16 *)0x800D94F0 == 0) {
        mdctInitTwiddles();
        *(u8 **)0x80151AC0 = mdctFftInit(0x80);
        *(s16 *)0x800D94F0 = 1;
    }
    temp_f20 = *(f32 *)0x800CCF28;
    adecDequantize((M2C_UNK32 (*)[]) &sp418[0], arg1 + 0x18);
    var_a1 = 0;
    do {
        temp_a0 = var_a1 * 8;
        temp_a0_2 = temp_a0 + &sp18;
        temp_v1 = &(&sp418[0])[0xFF - (var_a1 * 2)];
        temp_f0 = *(temp_a0 + &sp418[0]);
        temp_v0 = var_a1 + 1;
        var_a1 = temp_v0;
        M2C_FIELD(temp_a0_2, f32 *, 0) = temp_f0;
        M2C_FIELD(temp_a0_2, M2C_UNK32 *, 4) = (M2C_UNK32) *temp_v1;
    } while (temp_v0 < 0x80);
    var_a1_2 = 0;
    do {
        temp_a0_3 = (var_a1_2 * 8) + &sp18;
        temp_v0_3 = var_a1_2 * 4;
        temp_f2 = M2C_FIELD(temp_a0_3, f32 *, 0);
        temp_f5 = *(0x801510C0 + temp_v0_3);
        temp_f4 = temp_f2 * temp_f5;
        temp_f1 = M2C_FIELD(temp_a0_3, f32 *, 4);
        temp_f0_2 = *(0x801512C0 + temp_v0_3);
        temp_f3 = temp_f1 * temp_f0_2;
        temp_f2_2 = temp_f2 * temp_f0_2;
        temp_f1_2 = temp_f1 * temp_f5;
        temp_v0_2 = var_a1_2 + 1;
        var_a1_2 = temp_v0_2;
        M2C_FIELD(temp_a0_3, f32 *, 0) = (f32) (temp_f4 - temp_f3);
        M2C_FIELD(temp_a0_3, f32 *, 4) = (f32) (temp_f2_2 + temp_f1_2);
    } while (temp_v0_2 < 0x80);
    temp_v1_2 = *(s32 *)0x80151AC0;
    mdctFft(&sp18, M2C_FIELD(temp_v1_2, s32 *, 0xC), -1, M2C_FIELD(temp_v1_2, s32 *, 0), M2C_FIELD(temp_v1_2, s32 *, 4), M2C_FIELD(temp_v1_2, s32 *, 8));
    var_a1_3 = 0;
    do {
        temp_a0_4 = (var_a1_3 * 8) + &sp18;
        temp_v0_5 = var_a1_3 * 4;
        temp_f2_3 = M2C_FIELD(temp_a0_4, f32 *, 0);
        temp_f5_2 = *(0x801514C0 + temp_v0_5);
        temp_f4_2 = temp_f2_3 * temp_f5_2;
        temp_f1_3 = M2C_FIELD(temp_a0_4, f32 *, 4);
        temp_f0_3 = *(0x801516C0 + temp_v0_5);
        temp_f3_2 = temp_f1_3 * temp_f0_3;
        temp_f2_4 = temp_f2_3 * temp_f0_3;
        temp_f1_4 = temp_f1_3 * temp_f5_2;
        temp_v0_4 = var_a1_3 + 1;
        var_a1_3 = temp_v0_4;
        M2C_FIELD(temp_a0_4, f32 *, 0) = (f32) (temp_f4_2 - temp_f3_2);
        M2C_FIELD(temp_a0_4, f32 *, 4) = (f32) (temp_f2_4 + temp_f1_4);
    } while (temp_v0_4 < 0x80);
    var_a3 = 0;
    temp_f8 = *(f32 *)0x800CCF2C;
    temp_f7 = *(f32 *)0x800CCF30;
    temp_f6 = *(f32 *)0x800CCF34;
    do {
        temp_a0_5 = var_a3 * 4;
        temp_f4_3 = *(0x801518C0 + temp_a0_5);
        temp_f5_3 = *(0x801510C0 + temp_a0_5);
        temp_f3_3 = *(&sp18 + ((var_a3 * 8) | 4));
        temp_f0_4 = *(0x801512C0 + temp_a0_5);
        temp_f1_5 = temp_f20 * ((temp_f4_3 * temp_f5_3) + (temp_f3_3 * temp_f0_4));
        *(0x801518C0 + temp_a0_5) = (f32) *(&sp18 + (var_a3 * 8));
        if (temp_f1_5 >= 0.0f) {
            var_f0 = temp_f1_5 + temp_f8;
            if (temp_f7 < var_f0) {
                var_f0 = temp_f7;
            }
        } else {
            var_f0 = temp_f1_5 - temp_f8;
            if (var_f0 < temp_f6) {
                var_f0 = temp_f6;
            }
        }
        temp_f4_4 = temp_f20 * ((temp_f4_3 * temp_f0_4) - (temp_f3_3 * temp_f5_3));
        *(((s32) (var_a3 << 0x10) >> 0xE) + arg0) = (s16) (s32) var_f0;
        if (temp_f4_4 >= 0.0f) {
            var_f4 = temp_f4_4 + temp_f8;
            if (temp_f7 < var_f4) {
                var_f4 = temp_f7;
            }
        } else {
            var_f4 = temp_f4_4 - temp_f8;
            if (var_f4 < temp_f6) {
                var_f4 = temp_f6;
            }
        }
        *(((0xFF - ((s32) (var_a3 << 0x10) >> 0xF)) * 2) + arg0) = (s16) (s32) var_f4;
        temp_v0_6 = var_a3 + 1;
        var_a3 = temp_v0_6;
    } while (temp_v0_6 < 0x80);
}
