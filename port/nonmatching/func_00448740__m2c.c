#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_00448740(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 sp18;
    u8 sp20;
    u8 sp138;
    u16 sp13A;
    s32 *var_s3;
    s32 temp_a2;
    s32 temp_v0;
    s32 temp_v0_4;
    s32 temp_v0_7;
    s32 var_a3;
    s32 var_s1;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    u16 temp_v0_2;
    u16 temp_v0_5;
    u8 temp_v0_3;
    u8 temp_v0_6;
    u8 temp_v1;

    if (arg1 < M2C_FIELD(arg0, s32 *, 0x50)) {
        var_v0 = 5;
        if (arg1 >= 0) {
            if (arg4 > 0) {
                var_v0 = 5;
                if (!(arg4 & 0x1F)) {
                    if (arg3 >= 0) {
                        var_v0 = 5;
                        if (!(arg3 & 0x1F)) {
                            var_v0 = 5;
                            if (M2C_FIELD(arg0, s32 *, 0) & 1) {
                                var_v1 = 2;
                                if (__osCheckId(arg0) == 2) {
                                    goto block_8;
                                }
                                if ((M2C_FIELD(arg0, u8 *, 0x65) == 0) || (M2C_FIELD(arg0, u8 *, 0x65) = 0U, var_v0 = __osPfsSelectBank(arg0), (var_v0 == 0))) {
                                    var_v0 = __osContRamRead(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), (M2C_FIELD(arg0, u16 *, 0x5E) + arg1) & 0xFFFF, &sp18);
                                    if (var_v0 == 0) {
                                        var_v0 = 5;
                                        if (sp1C != 0) {
                                            if (sp18 == 0) {
                                                goto block_14;
                                            }
                                            if (((s32) sp1E < M2C_FIELD(arg0, s32 *, 0x60)) || ((u8) sp1E >= (u8) M2C_FIELD(arg0, u8 *, 0x64)) || (unksp1F == 0) || (unksp1F & 0x80)) {
                                                var_v0 = 5;
                                                if (sp1E != 1) {
                                                    return 3;
                                                }
                                                /* Duplicate return node #65. Try simplifying control flow for better match */
                                                return var_v0;
                                            }
                                            if (!(arg2 & 0xFF) && !(sp20 & 2)) {
                                                return 6;
                                            }
                                            var_a3 = arg3;
                                            sp138 = 0xFF;
                                            if (var_a3 < 0) {
                                                var_a3 += 0x1F;
                                            }
                                            var_s1 = var_a3 >> 5;
                                            sp13A = sp1E;
                                            var_v0_2 = arg4;
                                            if (var_s1 >= 8) {
loop_28:
                                                temp_v1 = M2C_FIELD(&sp13A, u8 *, 0);
                                                if (((temp_v1 == sp138) || (sp138 = temp_v1, temp_v0 = __osPfsRWInode(arg0, (u16 (*)[]) &sp38[0], 0, temp_v1 & 0xFF), var_v1 = temp_v0, (temp_v0 == 0))) && ((temp_v0_2 = (&sp38[0])[M2C_FIELD(&sp13A, u8 *, 1)], M2C_FIELD(&sp13A, u16 *, 0) = temp_v0_2, (((temp_v0_2 & 0xFFFF) < M2C_FIELD(arg0, s32 *, 0x60)) != 0)) || ((u8) M2C_FIELD(&sp13A, u8 *, 0) >= (u8) M2C_FIELD(arg0, u8 *, 0x64)) || (temp_v0_3 = M2C_FIELD(&sp13A, u8 *, 1), (temp_v0_3 == 0)) || (var_v1 = 0, (temp_v0_3 & 0x80)))) {
                                                    var_v1 = 3;
                                                    if (M2C_FIELD(&sp13A, u16 *, 0) == 1) {
                                                        var_v1 = 5;
                                                    }
                                                }
                                                var_s1 -= 8;
                                                if (var_v1 == 0) {
                                                    var_v0_2 = arg4;
                                                    if (var_s1 < 8) {
                                                        goto block_38;
                                                    }
                                                    goto loop_28;
                                                }
                                                goto block_8;
                                            }
block_38:
                                            if (var_v0_2 < 0) {
                                                var_v0_2 += 0x1F;
                                            }
                                            var_s4 = var_v0_2 >> 5;
                                            var_s3 = arg5;
                                            var_v1_2 = arg2 & 0xFF;
                                            if (var_s4 > 0) {
loop_42:
                                                if (var_s1 == 8) {
                                                    if ((((u8) sp13A == sp138) || (sp138 = (u8) sp13A, temp_v0_4 = __osPfsRWInode(arg0, (u16 (*)[]) &sp38[0], 0, (u8) sp13A & 0xFF), var_v1 = temp_v0_4, (temp_v0_4 == 0))) && ((temp_v0_5 = (&sp38[0])[M2C_FIELD(&sp13A, u8 *, 1)], M2C_FIELD(&sp13A, u16 *, 0) = temp_v0_5, (((temp_v0_5 & 0xFFFF) < M2C_FIELD(arg0, s32 *, 0x60)) != 0)) || ((u8) M2C_FIELD(&sp13A, u8 *, 0) >= (u8) M2C_FIELD(arg0, u8 *, 0x64)) || (temp_v0_6 = M2C_FIELD(&sp13A, u8 *, 1), (temp_v0_6 == 0)) || (var_v1 = 0, (temp_v0_6 & 0x80)))) {
                                                        var_v1 = 3;
                                                        if (M2C_FIELD(&sp13A, u16 *, 0) == 1) {
                                                            var_v1 = 5;
                                                        }
                                                    }
                                                    var_s1 = 0;
                                                    if (var_v1 == 0) {
                                                        goto block_52;
                                                    }
                                                    goto block_8;
                                                }
block_52:
                                                if ((M2C_FIELD(arg0, u8 *, 0x65) == (u8) sp13A) || (M2C_FIELD(arg0, u8 *, 0x65) = (u8) sp13A, temp_v0_7 = __osPfsSelectBank(arg0), var_v0 = temp_v0_7, (temp_v0_7 == 0))) {
                                                    temp_a2 = ((unksp13B * 8) + var_s1) & 0xFFFF;
                                                    if (!(arg2 & 0xFF)) {
                                                        var_v1 = __osContRamRead(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), temp_a2, var_s3);
                                                    } else {
                                                        var_v1 = __osContRamWrite(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), temp_a2, var_s3, 0);
                                                    }
                                                    var_s3 += 0x20;
                                                    if (var_v1 == 0) {
                                                        var_s4 -= 1;
                                                        var_s1 += 1;
                                                        if (var_s4 <= 0) {
                                                            var_v1_2 = arg2 & 0xFF;
                                                            goto block_60;
                                                        }
                                                        goto loop_42;
                                                    }
block_8:
                                                    return var_v1;
                                                }
                                                /* Duplicate return node #65. Try simplifying control flow for better match */
                                                return var_v0;
                                            }
block_60:
                                            var_v0 = 0;
                                            if (var_v1_2 == 1) {
                                                var_v0 = 0;
                                                if (!(sp20 & 2)) {
                                                    sp20 |= 2;
                                                    M2C_FIELD(arg0, u8 *, 0x65) = 0U;
                                                    var_v0 = __osPfsSelectBank(arg0);
                                                    if (var_v0 == 0) {
                                                        var_v0 = __osContRamWrite(M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8), (M2C_FIELD(arg0, u16 *, 0x5E) + arg1) & 0xFFFF, &sp18, 0);
                                                        if (var_v0 == 0) {
                                                            var_v0 = 0;
                                                        }
                                                    }
                                                }
                                            }
                                            /* Duplicate return node #65. Try simplifying control flow for better match */
                                            return var_v0;
                                        }
                                    }
                                }
                                /* Duplicate return node #65. Try simplifying control flow for better match */
                                return var_v0;
                            }
                        }
                        /* Duplicate return node #65. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    goto block_14;
                }
                /* Duplicate return node #65. Try simplifying control flow for better match */
                return var_v0;
            }
            goto block_14;
        }
        return var_v0;
    }
block_14:
    return 5;
}
