#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_002BD0A8(s32 arg0, u8 *arg1, s32 arg2) {
    M2C_UNK sp18;
    u8 sp37;
    s8 sp38;
    s16 sp3C;
    M2C_UNK sp58;
    s32 *var_v0_3;
    s32 *var_v1_2;
    s32 var_a0;
    s32 var_a0_10;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a0_8;
    s32 var_v0;
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v1;
    s8 *var_a0_9;
    s8 *var_a1;
    s8 *var_a2;
    s8 *var_s1;
    s8 *var_s2;
    s8 *var_v1_3;
    u8 *var_s3;
    u8 *var_s4;
    u8 *var_v0_2;
    u8 *var_v1;
    u8 *temp_v0_3;

    var_a0 = 0x1F;
    var_v1 = &sp37;
    M2C_FIELD(arg1, s32 *, 4) = arg0;
    M2C_FIELD(arg1, s32 *, 8) = arg2;
    M2C_FIELD(arg1, s32 *, 0) = 0;
    M2C_FIELD(arg1, s8 *, 0x65) = 0x80;
    do {
        *var_v1 = 0xFE;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp18, 0);
    if (var_v0 == 2) {
        var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp18, 0);
    }
    if (var_v0 == 0) {
        var_v0 = __osContRamRead(arg0, arg2, 0x400, &sp18);
        if (var_v0 == 2) {
            var_v0 = 4;
        }
        if (var_v0 == 0) {
            if (sp37 != 0xFE) {
                var_a0_2 = 0x1F;
                var_v0_2 = &sp37;
                do {
                    *var_v0_2 = 0x80;
                    var_a0_2 -= 1;
                    var_v0_2 -= 1;
                } while (var_a0_2 >= 0);
                var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp18, 0);
                if (var_v0 == 2) {
                    var_v0 = __osContRamWrite(arg0, arg2, 0x400, &sp18, 0);
                }
                if (var_v0 == 0) {
                    var_v0 = __osContRamRead(arg0, arg2, 0x400, &sp18);
                    if (var_v0 == 2) {
                        var_v0 = 4;
                    }
                    if (var_v0 == 0) {
                        if (sp37 != 0x80) {
                            goto block_18;
                        }
                        var_v0 = 0;
                        if (M2C_FIELD(((arg2 * 4) + 0x800E0000), s32 *, -0x7C80) == 0) {
                            var_a0_3 = 0;
                            do {
                                temp_v0 = var_a0_3 + 0x8014D5C0;
                                temp_v1 = var_a0_3 + 0x8014D6E0;
                                var_a0_3 += 1;
                                *temp_v0 = 1;
                                *temp_v1 = 0;
                            } while (var_a0_3 < 0x20);
                            var_s3 = (u8 *)0x8014D5C0;
                            var_s2 = (arg2 << 6) + 0x8014D4C0;
                            var_a0_4 = 0xE;
                            var_v0_3 = var_s2 + 0x38;
                            do {
                                *var_v0_3 = 0;
                                var_a0_4 -= 1;
                                var_v0_3 -= 4;
                            } while (var_a0_4 >= 0);
                            M2C_FIELD(var_s2, s32 *, 0x3C) = 1;
                            M2C_FIELD(&sp38, s8 *, 1) = 0x23;
                            M2C_FIELD(&sp38, s8 *, 0) = 0xFF;
                            M2C_FIELD(&sp38, s8 *, 2) = 1;
                            M2C_FIELD(&sp38, s8 *, 3) = 3;
                            var_a0_5 = 0;
                            sp3C = (__osContAddressCrc(0x600, var_s2, (s8 *)1, (s8 *)0x8014D5C0) & 0xFF) | (0x600 << 5);
                            M2C_FIELD(&sp38, s8 *, 0x26) = 0xFF;
                            do {
                                temp_v0_2 = &(&sp38)[var_a0_5];
                                var_a0_5 += 1;
                                M2C_FIELD(temp_v0_2, u8 *, 6) = (u8) *var_s3;
                                var_s3 += 1;
                            } while (var_a0_5 < 0x20);
                            var_a2 = var_s2;
                            if (arg2 != 0) {
                                var_a0_6 = 0;
                                if (arg2 > 0) {
                                    do {
                                        *var_s2 = 0;
                                        var_a0_6 += 1;
                                        var_s2 += 1;
                                    } while (var_a0_6 < arg2);
                                    var_a2 = var_s2;
                                }
                            }
                            var_a1 = &sp38;
                            if ((s32) var_s2 & 3) {
                                do {
                                    M2C_FIELD(var_a2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_a1, s8 *, 0));
                                    M2C_FIELD(var_a2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 4));
                                    M2C_FIELD(var_a2, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 8));
                                    M2C_FIELD(var_a2, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 0xC));
                                    var_a1 += 0x10;
                                    var_a2 += 0x10;
                                } while (var_a1 != &sp58);
                            } else {
                                do {
                                    M2C_FIELD(var_a2, s32 *, 0) = (s32) M2C_FIELD(var_a1, s32 *, 0);
                                    M2C_FIELD(var_a2, s32 *, 4) = (s32) M2C_FIELD(var_a1, s32 *, 4);
                                    M2C_FIELD(var_a2, s32 *, 8) = (s32) M2C_FIELD(var_a1, s32 *, 8);
                                    M2C_FIELD(var_a2, s32 *, 0xC) = (s32) M2C_FIELD(var_a1, s32 *, 0xC);
                                    var_a1 += 0x10;
                                    var_a2 += 0x10;
                                } while (var_a1 != &sp58);
                            }
                            var_s4 = (u8 *)0x8014D6E0;
                            var_s1 = (arg2 << 6) + 0x8014D5E0;
                            var_a0_7 = 0xE;
                            var_v1_2 = var_s1 + 0x38;
                            M2C_FIELD(var_a2, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_a1, s8 *, 0));
                            M2C_FIELD(var_a2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 4));
                            M2C_FIELD(var_s2, s8 *, 0x28) = 0xFE;
                            do {
                                *var_v1_2 = 0;
                                var_a0_7 -= 1;
                                var_v1_2 -= 4;
                            } while (var_a0_7 >= 0);
                            M2C_FIELD(var_s1, s32 *, 0x3C) = 1;
                            M2C_FIELD(&sp38, s8 *, 1) = 0x23;
                            M2C_FIELD(&sp38, s8 *, 0) = 0xFF;
                            M2C_FIELD(&sp38, s8 *, 2) = 1;
                            M2C_FIELD(&sp38, s8 *, 3) = 3;
                            var_a0_8 = 0;
                            sp3C = (__osContAddressCrc(0x600, var_a1, var_a2, var_s1) & 0xFF) | (0x600 << 5);
                            M2C_FIELD(&sp38, s8 *, 0x26) = 0xFF;
                            do {
                                temp_v0_3 = &sp38 + var_a0_8;
                                var_a0_8 += 1;
                                M2C_FIELD(temp_v0_3, u8 *, 6) = (u8) *var_s4;
                                var_s4 += 1;
                            } while (var_a0_8 < 0x20);
                            var_a0_9 = var_s1;
                            if (arg2 != 0) {
                                var_a0_10 = 0;
                                if (arg2 > 0) {
                                    do {
                                        *var_s1 = 0;
                                        var_a0_10 += 1;
                                        var_s1 += 1;
                                    } while (var_a0_10 < arg2);
                                }
                                var_a0_9 = var_s1;
                            }
                            var_v1_3 = &sp38;
                            if ((s32) var_s1 & 3) {
                                do {
                                    M2C_FIELD(var_a0_9, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, s8 *, 0));
                                    M2C_FIELD(var_a0_9, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 4));
                                    M2C_FIELD(var_a0_9, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 8));
                                    M2C_FIELD(var_a0_9, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 0xC));
                                    var_v1_3 += 0x10;
                                    var_a0_9 += 0x10;
                                } while (var_v1_3 != &sp58);
                            } else {
                                do {
                                    M2C_FIELD(var_a0_9, s32 *, 0) = (s32) M2C_FIELD(var_v1_3, s32 *, 0);
                                    M2C_FIELD(var_a0_9, s32 *, 4) = (s32) M2C_FIELD(var_v1_3, s32 *, 4);
                                    M2C_FIELD(var_a0_9, s32 *, 8) = (s32) M2C_FIELD(var_v1_3, s32 *, 8);
                                    M2C_FIELD(var_a0_9, s32 *, 0xC) = (s32) M2C_FIELD(var_v1_3, s32 *, 0xC);
                                    var_v1_3 += 0x10;
                                    var_a0_9 += 0x10;
                                } while (var_v1_3 != &sp58);
                            }
                            M2C_FIELD(var_a0_9, s8 *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, s8 *, 0));
                            M2C_FIELD(var_a0_9, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_3, M2C_UNK *, 4));
                            M2C_FIELD(var_s1, s8 *, 0x28) = 0xFE;
                            M2C_FIELD(((arg2 * 4) + 0x800E0000), s32 *, -0x7C80) = 1;
                            var_v0 = 0;
                        }
                        /* Duplicate return node #53. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    /* Duplicate return node #53. Try simplifying control flow for better match */
                    return var_v0;
                }
                /* Duplicate return node #53. Try simplifying control flow for better match */
                return var_v0;
            }
block_18:
            return 0xB;
        }
        /* Duplicate return node #53. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
