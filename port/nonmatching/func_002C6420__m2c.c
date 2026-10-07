#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
u32 func_002C6420(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 sp0;
    u32 sp4;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_t0;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t8;
    s32 temp_t8_2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_t5;
    s32 var_v0;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a2_3;
    u32 temp_lo;
    u32 temp_lo_2;
    u32 temp_lo_3;
    u32 temp_lo_4;
    u32 temp_lo_5;
    u32 temp_lo_6;
    u32 temp_t1;
    u32 temp_t2;
    u32 temp_t2_2;
    u32 temp_t2_3;
    u32 temp_t3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 var_a0_4;
    u32 var_a1;
    u32 var_a2;
    u32 var_a3;
    u32 var_t0;
    u32 var_t2;
    u32 var_t2_2;
    u32 var_t3;
    u32 var_t6;
    u32 var_t7;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_4;
    u32 var_v1_5;
    u32 var_v1_6;

    var_t0 = arg3;
    var_t3 = arg1;
    var_t2 = arg0;
    if (arg2 == 0) {
        if (var_t2 < var_t0) {
            if (var_t0 <= 0xFFFFU) {
                var_a0 = (var_t0 >= 0x100U) * 8;
            } else {
                var_a0 = 0x18;
                if (var_t0 <= 0xFFFFFFU) {
                    var_a0 = 0x10;
                }
            }
            var_t5 = 0x20 - (*(0x800CD250 + (arg3 >> var_a0)) + var_a0);
            if (var_t5 != 0) {
                var_t0 <<= var_t5;
                var_t2 = (var_t2 << var_t5) | (var_t3 >> (0x20 - var_t5));
                var_t3 <<= var_t5;
            }
        } else {
            var_v0 = var_t0 > 0xFFFFU;
            if (var_t0 == 0) {
                var_t0 = 1U / arg2;
                var_v0 = var_t0 > 0xFFFFU;
            }
            if (var_v0 == 0) {
                var_a0_2 = (var_t0 >= 0x100U) * 8;
            } else {
                var_a0_2 = 0x18;
                if (var_t0 <= 0xFFFFFFU) {
                    var_a0_2 = 0x10;
                }
            }
            var_t5 = 0x20 - (*(0x800CD250 + (var_t0 >> var_a0_2)) + var_a0_2);
            temp_t8 = 0x20 - var_t5;
            if (var_t5 == 0) {
                var_t2 -= var_t0;
            } else {
                var_t0 <<= var_t5;
                temp_a0 = var_t2 >> temp_t8;
                temp_t2 = (var_t2 << var_t5) | (var_t3 >> temp_t8);
                temp_a1 = var_t0 >> 0x10;
                temp_a2 = var_t0 & 0xFFFF;
                temp_lo = (temp_a0 / temp_a1) * temp_a2;
                var_v1 = ((temp_a0 % temp_a1) << 0x10) | (temp_t2 >> 0x10);
                var_t3 <<= var_t5;
                if (var_v1 < temp_lo) {
                    var_v1 += var_t0;
                    if ((var_v1 >= var_t0) && (var_v1 < temp_lo)) {
                        var_v1 += var_t0;
                    }
                }
                temp_v1 = var_v1 - temp_lo;
                temp_lo_2 = (temp_v1 / temp_a1) * temp_a2;
                var_v1_2 = ((temp_v1 % temp_a1) << 0x10) | (temp_t2 & 0xFFFF);
                if (var_v1_2 < temp_lo_2) {
                    var_v1_2 += var_t0;
                    var_t2 = var_v1_2 - temp_lo_2;
                    if (var_v1_2 >= var_t0) {
                        if (var_v1_2 < temp_lo_2) {
                            var_v1_2 += var_t0;
                        }
                        goto block_24;
                    }
                } else {
block_24:
                    var_t2 = var_v1_2 - temp_lo_2;
                }
            }
        }
        temp_a1_2 = var_t0 >> 0x10;
        temp_a2_2 = var_t0 & 0xFFFF;
        temp_lo_3 = (var_t2 / temp_a1_2) * temp_a2_2;
        var_v1_3 = ((var_t2 % temp_a1_2) << 0x10) | (var_t3 >> 0x10);
        if (var_v1_3 < temp_lo_3) {
            var_v1_3 += var_t0;
            if ((var_v1_3 >= var_t0) && (var_v1_3 < temp_lo_3)) {
                var_v1_3 += var_t0;
            }
        }
        temp_v1_2 = var_v1_3 - temp_lo_3;
        temp_lo_4 = (temp_v1_2 / temp_a1_2) * temp_a2_2;
        var_v1_4 = ((temp_v1_2 % temp_a1_2) << 0x10) | (var_t3 & 0xFFFF);
        if (var_v1_4 < temp_lo_4) {
            var_v1_4 += var_t0;
            if ((var_v1_4 >= var_t0) && (var_v1_4 < temp_lo_4)) {
                var_v1_4 += var_t0;
            }
        }
        if (sp != NULL) {
            var_t7 = (u32) (var_v1_4 - temp_lo_4) >> var_t5;
            var_t6 = 0;
            goto block_62;
        }
    } else if (var_t2 < arg2) {
        sp0 = var_t2;
        sp4 = arg1;
    } else {
        if (arg2 <= 0xFFFFU) {
            var_a0_3 = (arg2 >= 0x100U) * 8;
        } else {
            var_a0_3 = 0x18;
            if (arg2 <= 0xFFFFFFU) {
                var_a0_3 = 0x10;
            }
        }
        temp_t5 = 0x20 - (*(0x800CD250 + (arg2 >> var_a0_3)) + var_a0_3);
        temp_t8_2 = 0x20 - temp_t5;
        if (temp_t5 == 0) {
            temp_a0_2 = var_t3 - var_t0;
            if ((arg2 < var_t2) || (var_t3 >= var_t0)) {
                var_t2 = (var_t2 - arg2) - (var_t3 < temp_a0_2);
                var_t3 = temp_a0_2;
            }
            var_t7 = var_t3;
            if (sp != NULL) {
                var_t6 = var_t2;
                goto block_62;
            }
        } else {
            temp_t1 = (arg2 << temp_t5) | (var_t0 >> temp_t8_2);
            temp_t0 = var_t0 << temp_t5;
            temp_a0_3 = var_t2 >> temp_t8_2;
            temp_t2_2 = (var_t2 << temp_t5) | (var_t3 >> temp_t8_2);
            temp_a2_3 = temp_t1 >> 0x10;
            var_a3 = temp_a0_3 / temp_a2_3;
            temp_t4 = temp_t1 & 0xFFFF;
            temp_lo_5 = var_a3 * temp_t4;
            var_v1_5 = ((temp_a0_3 % temp_a2_3) << 0x10) | (temp_t2_2 >> 0x10);
            temp_t3 = var_t3 << temp_t5;
            if (var_v1_5 < temp_lo_5) {
                var_v1_5 += temp_t1;
                var_a3 -= 1;
                if ((var_v1_5 >= temp_t1) && (var_v1_5 < temp_lo_5)) {
                    var_a3 -= 1;
                    var_v1_5 += temp_t1;
                }
            }
            temp_v1_3 = var_v1_5 - temp_lo_5;
            var_a0_4 = temp_v1_3 / temp_a2_3;
            temp_lo_6 = var_a0_4 * temp_t4;
            var_v1_6 = ((temp_v1_3 % temp_a2_3) << 0x10) | (temp_t2_2 & 0xFFFF);
            if ((var_v1_6 < temp_lo_6) && (var_v1_6 += temp_t1, var_a0_4 -= 1, ((var_v1_6 < temp_t1) == 0))) {
                var_t2_2 = var_v1_6 - temp_lo_6;
                if (var_v1_6 < temp_lo_6) {
                    var_a0_4 -= 1;
                    var_v1_6 += temp_t1;
                    goto block_55;
                }
            } else {
block_55:
                var_t2_2 = var_v1_6 - temp_lo_6;
            }
            temp_v0 = (var_a3 << 0x10) | var_a0_4;
            var_a2 = MULTU_HI(temp_v0, temp_t0);
            var_a1 = temp_v0 * temp_t0;
            if ((var_t2_2 < var_a2) || ((var_a2 == var_t2_2) && (temp_t3 < var_a1))) {
                temp_a0_4 = var_a1 - temp_t0;
                var_a2 = (var_a2 - temp_t1) - (var_a1 < temp_a0_4);
                var_a1 = temp_a0_4;
            }
            temp_v1_4 = temp_t3 - var_a1;
            if (sp != NULL) {
                temp_t2_3 = (var_t2_2 - var_a2) - (temp_t3 < temp_v1_4);
                var_t7 = (temp_t2_3 << temp_t8_2) | (temp_v1_4 >> temp_t5);
                var_t6 = temp_t2_3 >> temp_t5;
block_62:
                M2C_FIELD(sp, u32 *, 0) = var_t6;
                M2C_FIELD(sp, u32 *, 4) = var_t7;
            }
        }
    }
    return sp0;
}
