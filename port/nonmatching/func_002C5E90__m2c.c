#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_002C5E90(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a2;
    s32 temp_a2_3;
    s32 temp_a2_6;
    s32 temp_a2_8;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t1;
    s32 var_a2;
    s32 var_a2_3;
    s32 var_t0;
    s32 var_t2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a2_2;
    u32 temp_a2_4;
    u32 temp_a2_5;
    u32 temp_a2_7;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 temp_hi;
    u32 temp_lo;
    u32 temp_lo_2;
    u32 temp_lo_3;
    u32 temp_lo_4;
    u32 temp_lo_5;
    u32 temp_lo_6;
    u32 temp_lo_7;
    u32 temp_lo_8;
    u32 temp_t0_3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u32 temp_v1_6;
    u32 temp_v1_7;
    u32 temp_v1_8;
    u32 var_a0;
    u32 var_a0_2;
    u32 var_a2_2;
    u32 var_a2_4;
    u32 var_t0_2;
    u32 var_t1;
    u32 var_t2_2;
    u32 var_t3;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_4;
    u32 var_v1_5;
    u32 var_v1_6;

    var_a0 = arg0;
    var_t1 = arg3;
    var_t3 = arg1;
    if (arg2 == 0) {
        if (var_a0 < var_t1) {
            if (var_t1 <= 0xFFFFU) {
                var_t0 = (var_t1 >= 0x100U) * 8;
            } else {
                var_t0 = 0x18;
                if (var_t1 <= 0xFFFFFFU) {
                    var_t0 = 0x10;
                }
            }
            temp_a2 = 0x20 - (*(0x800CD150 + (arg3 >> var_t0)) + var_t0);
            if (temp_a2 != 0) {
                var_t1 <<= temp_a2;
                var_a0 = (var_a0 << temp_a2) | (var_t3 >> (0x20 - temp_a2));
                var_t3 <<= temp_a2;
            }
            temp_a2_2 = var_t1 >> 0x10;
            temp_t0 = var_t1 & 0xFFFF;
            temp_lo = (var_a0 / temp_a2_2) * temp_t0;
            var_v1 = ((var_a0 % temp_a2_2) << 0x10) | (var_t3 >> 0x10);
            if (var_v1 < temp_lo) {
                var_v1 += var_t1;
                if ((var_v1 >= var_t1) && (var_v1 < temp_lo)) {
                    var_v1 += var_t1;
                }
            }
            temp_v1 = var_v1 - temp_lo;
            temp_lo_2 = (temp_v1 / temp_a2_2) * temp_t0;
            temp_v1_2 = ((temp_v1 % temp_a2_2) << 0x10) | (var_t3 & 0xFFFF);
            temp_v1_3 = temp_v1_2 + var_t1;
            if ((temp_v1_2 < temp_lo_2) && (temp_v1_3 >= var_t1) && (temp_v1_3 < temp_lo_2)) {

            }
            goto block_67;
        }
        var_v0 = var_t1 > 0xFFFFU;
        if (var_t1 == 0) {
            var_t1 = 1U / arg2;
            var_v0 = var_t1 > 0xFFFFU;
        }
        if (var_v0 == 0) {
            var_a2 = (var_t1 >= 0x100U) * 8;
        } else {
            var_a2 = 0x18;
            if (var_t1 <= 0xFFFFFFU) {
                var_a2 = 0x10;
            }
        }
        temp_a2_3 = 0x20 - (*(0x800CD150 + (var_t1 >> var_a2)) + var_a2);
        temp_a1 = 0x20 - temp_a2_3;
        if (temp_a2_3 == 0) {
            var_a0_2 = var_a0 - var_t1;
            var_t2 = 1;
        } else {
            var_t1 <<= temp_a2_3;
            temp_a3 = var_a0 >> temp_a1;
            temp_a0 = (var_a0 << temp_a2_3) | (var_t3 >> temp_a1);
            var_t3 <<= temp_a2_3;
            temp_a2_4 = var_t1 >> 0x10;
            var_t0_2 = temp_a3 / temp_a2_4;
            temp_a1_2 = var_t1 & 0xFFFF;
            temp_lo_3 = var_t0_2 * temp_a1_2;
            var_v1_2 = ((temp_a3 % temp_a2_4) << 0x10) | (temp_a0 >> 0x10);
            if (var_v1_2 < temp_lo_3) {
                var_v1_2 += var_t1;
                var_t0_2 -= 1;
                if ((var_v1_2 >= var_t1) && (var_v1_2 < temp_lo_3)) {
                    var_t0_2 -= 1;
                    var_v1_2 += var_t1;
                }
            }
            temp_v1_4 = var_v1_2 - temp_lo_3;
            var_a2_2 = temp_v1_4 / temp_a2_4;
            temp_lo_4 = var_a2_2 * temp_a1_2;
            var_v1_3 = ((temp_v1_4 % temp_a2_4) << 0x10) | (temp_a0 & 0xFFFF);
            var_v0_2 = var_t0_2 << 0x10;
            if (var_v1_3 < temp_lo_4) {
                var_v1_3 += var_t1;
                var_a2_2 -= 1;
                if (var_v1_3 >= var_t1) {
                    var_v0_2 = var_t0_2 << 0x10;
                    if (var_v1_3 < temp_lo_4) {
                        var_a2_2 -= 1;
                        var_v1_3 += var_t1;
                        goto block_33;
                    }
                } else {
block_33:
                    var_v0_2 = var_t0_2 << 0x10;
                }
            }
            var_t2 = var_v0_2 | var_a2_2;
            var_a0_2 = var_v1_3 - temp_lo_4;
        }
        temp_a2_5 = var_t1 >> 0x10;
        temp_t0_2 = var_t1 & 0xFFFF;
        temp_lo_5 = (var_a0_2 / temp_a2_5) * temp_t0_2;
        var_v1_4 = ((var_a0_2 % temp_a2_5) << 0x10) | (var_t3 >> 0x10);
        if (var_v1_4 < temp_lo_5) {
            var_v1_4 += var_t1;
            if ((var_v1_4 >= var_t1) && (var_v1_4 < temp_lo_5)) {
                var_v1_4 += var_t1;
            }
        }
        temp_v1_5 = var_v1_4 - temp_lo_5;
        temp_lo_6 = (temp_v1_5 / temp_a2_5) * temp_t0_2;
        temp_v1_6 = ((temp_v1_5 % temp_a2_5) << 0x10) | (var_t3 & 0xFFFF);
        temp_v1_7 = temp_v1_6 + var_t1;
        if ((temp_v1_6 < temp_lo_6) && (temp_v1_7 >= var_t1) && (temp_v1_7 < temp_lo_6)) {

        }
    } else {
        if (var_a0 < arg2) {
            goto block_67;
        }
        if (arg2 <= 0xFFFFU) {
            var_a2_3 = (arg2 >= 0x100U) * 8;
        } else {
            var_a2_3 = 0x18;
            if (arg2 <= 0xFFFFFFU) {
                var_a2_3 = 0x10;
            }
        }
        temp_a2_6 = 0x20 - (*(0x800CD150 + (arg2 >> var_a2_3)) + var_a2_3);
        temp_a1_3 = 0x20 - temp_a2_6;
        if (temp_a2_6 == 0) {
            if ((arg2 >= var_a0) && (var_t3 >= var_t1)) {

            }
            goto block_67;
        }
        temp_t0_3 = (arg2 << temp_a2_6) | (var_t1 >> temp_a1_3);
        temp_t1 = var_t1 << temp_a2_6;
        temp_a3_2 = var_a0 >> temp_a1_3;
        temp_a0_2 = (var_a0 << temp_a2_6) | (var_t3 >> temp_a1_3);
        temp_a2_7 = temp_t0_3 >> 0x10;
        var_t2_2 = temp_a3_2 / temp_a2_7;
        temp_a1_4 = temp_t0_3 & 0xFFFF;
        temp_lo_7 = var_t2_2 * temp_a1_4;
        var_v1_5 = ((temp_a3_2 % temp_a2_7) << 0x10) | (temp_a0_2 >> 0x10);
        if (var_v1_5 < temp_lo_7) {
            var_v1_5 += temp_t0_3;
            var_t2_2 -= 1;
            if ((var_v1_5 >= temp_t0_3) && (var_v1_5 < temp_lo_7)) {
                var_t2_2 -= 1;
                var_v1_5 += temp_t0_3;
            }
        }
        temp_v1_8 = var_v1_5 - temp_lo_7;
        var_a2_4 = temp_v1_8 / temp_a2_7;
        temp_lo_8 = var_a2_4 * temp_a1_4;
        var_v1_6 = ((temp_v1_8 % temp_a2_7) << 0x10) | (temp_a0_2 & 0xFFFF);
        var_v0_3 = var_t2_2 << 0x10;
        if (var_v1_6 < temp_lo_8) {
            var_v1_6 += temp_t0_3;
            var_a2_4 -= 1;
            if (var_v1_6 >= temp_t0_3) {
                var_v0_3 = var_t2_2 << 0x10;
                if (var_v1_6 < temp_lo_8) {
                    var_a2_4 -= 1;
                    var_v1_6 += temp_t0_3;
                    goto block_62;
                }
            } else {
block_62:
                var_v0_3 = var_t2_2 << 0x10;
            }
        }
        temp_a2_8 = var_v0_3 | var_a2_4;
        temp_a0_3 = var_v1_6 - temp_lo_8;
        temp_hi = MULTU_HI(temp_a2_8, temp_t1);
        if (temp_a0_3 >= temp_hi) {
            var_t2 = 0;
            if (temp_hi == temp_a0_3) {
                if ((u32) (var_t3 << temp_a2_6) < (u32) (temp_a2_8 * temp_t1)) {
                    goto block_66;
                }
            }
        } else {
block_66:
block_67:
            var_t2 = 0;
        }
    }
    return var_t2;
}
