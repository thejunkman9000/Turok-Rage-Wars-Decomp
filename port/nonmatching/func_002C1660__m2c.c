#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_002C1660(s32 arg6, s32 arg8, s32 arg9, s32 arg10, s32 arg11) {
    s32 temp_s2_2;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_v0;
    s64 temp_ra;
    s64 temp_s1;
    s64 temp_s2;
    s64 temp_sp;
    s64 var_s0;
    u16 temp_a0;
    u32 temp_v1_3;
    u8 *temp_a1;
    u8 *temp_s0;
    u8 *temp_s1_2;
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v1_4;

    temp_v0 = __osPopThread(0x800D9298);
    *(u8 **)0x800D92A0 = temp_v0;
    M2C_FIELD(temp_v0, s16 *, 0x10) = 4;
    M2C_ERROR(/* mtc0 $k1, $12 */);
    temp_s1 = M2C_FIELD(temp_v0, s64 *, 0xA0);
    temp_s2 = M2C_FIELD(temp_v0, s64 *, 0xA8);
    temp_sp = M2C_FIELD(temp_v0, s64 *, 0xF0);
    temp_ra = M2C_FIELD(temp_v0, s64 *, 0x100);
    M2C_ERROR(/* mtc0 $k1, $14 */);
    if ((M2C_FIELD(temp_v0, s32 *, 0x18) != 0) && (((u32) M2C_FIELD(temp_v0, u32 *, 0x118) >> 0x10) & 0x400)) {

    }
    *(s32 *)0xA430000C = (s32) *(0x800CCCC0 + ((M2C_FIELD(temp_v0, s32 *, 0x128) & ((u32) *(s32 *)0x800D9288 >> 0x10)) * 2));
    M2C_ERROR(/* unknown instruction: eret */);
    var_s0 = 0x20;
    if (osDestroyThread(0, M2C_FIELD(temp_v0, s64 *, 0x40), M2C_FIELD(temp_v0, s64 *, 0x48), M2C_FIELD(temp_v0, s64 *, 0x50)) != 0) {
        var_s0 = temp_s1;
    }
    temp_v1 = *(u8 **)0x8014EA44;
    arg11 = (s32) temp_ra;
    arg10 = (s32) temp_s2;
    arg9 = (s32) temp_s1;
    arg8 = (s32) var_s0;
    temp_s1_2 = temp_v1 + 0x14;
    arg6 = *(s32 *)0xA4600010;
    temp_a0 = M2C_FIELD(temp_v1, u16 *, 0x1A);
    temp_s0 = temp_s1_2 + ((temp_a0 * 0x24) + 0x18);
    if (arg6 & 1) {
        M2C_FIELD(temp_s0, s32 *, 0) = 0x1D;
        *(u32 *)0x800D9288 = (u32) (*(s32 *)0x800D9288 & ~0x800);
        __osLeoResume(0x800D9288U, (u8 *)0xA4600010);
        return 1;
    }
    arg6 = *(s32 *)0xA4600010;
    if (arg6 & 3) {
        do {
            arg6 = *(s32 *)0xA4600010;
        } while (arg6 & 3);
    }
    temp_s2_2 = *(s32 *)0xA5000508;
    if (temp_s2_2 & 0x02000000) {
        arg6 = *(s32 *)0xA4600010;
        if (arg6 & 3) {
            do {
                arg6 = *(s32 *)0xA4600010;
            } while (arg6 & 3);
        }
        M2C_FIELD(temp_s0, s32 *, 0) = 0;
        *(s32 *)0xA5000510 = M2C_FIELD(temp_s1_2, s32 *, 0x10) | 0x01000000;
        return 0;
    }
    temp_v1_2 = M2C_FIELD(temp_v1, s32 *, 0x14);
    if (temp_v1_2 != 2) {
        if (temp_s2_2 & 0x08000000) {
            arg6 = *(s32 *)0xA4600010;
            if (arg6 & 3) {
                do {
                    arg6 = *(s32 *)0xA4600010;
                } while (arg6 & 3);
            }
            M2C_FIELD(temp_s0, s32 *, 0) = 0x16;
            __osLeoResume(temp_a0, (u8 *)0xA4600010, 2);
            *(s32 *)0xA4600010 = 2;
            *(u32 *)0x800D9288 = (u32) (*(s32 *)0x800D9288 | 0x100401);
            return 1;
        }
        if (temp_v1_2 == 1) {
            if (!(temp_s2_2 & 0x40000000)) {
                var_v0 = 0x18;
                if ((M2C_FIELD(temp_s1_2, s32 *, 8) + 1) == (M2C_FIELD(temp_s1_2, u16 *, 4) * 0x55)) {
                    *(s32 *)0xA4600010 = 2;
                    M2C_FIELD(temp_s0, s32 *, 0) = 0;
                    *(u32 *)0x800D9288 = (u32) (*(s32 *)0x800D9288 | 0x100401);
                    __osLeoResume(0xA4600010U, (u8 *)0x100401, 2);
                    return 1;
                }
                goto block_59;
            }
            M2C_FIELD(temp_s0, s32 *, 4) = (s32) (M2C_FIELD(temp_s0, s32 *, 4) + M2C_FIELD(temp_s0, s32 *, 0xC));
            M2C_FIELD(temp_s1_2, s32 *, 8) = (s32) (M2C_FIELD(temp_s1_2, s32 *, 8) + 1);
            arg4 = M2C_FIELD(temp_s0, s32 *, 0xC);
            osEPiRawStartDma(*(s32 *)0x8014EA44, 1, 0x05000400, M2C_FIELD(temp_s0, s32 *, 4));
            return 1;
        }
        var_v0 = 4;
        if (temp_v1_2 == 0) {
            if (M2C_FIELD(temp_s1_2, u16 *, 4) == 3) {
                if ((M2C_FIELD(temp_s0, u32 *, 0x10) + 0x11) < M2C_FIELD(temp_s1_2, s32 *, 8)) {
                    M2C_FIELD(temp_s0, s32 *, 0) = 0;
                    goto block_60;
                }
                if (!(temp_s2_2 & 0x40000000)) {
                    var_v0 = 0x17;
                    goto block_59;
                }
                goto block_33;
            }
            M2C_FIELD(temp_s0, s32 *, 4) = (s32) (M2C_FIELD(temp_s0, s32 *, 4) + M2C_FIELD(temp_s0, s32 *, 0xC));
block_33:
            var_a0 = *(s32 *)0xA5000510;
            if (((var_a0 & 0x600000) == 0x600000) || (var_a0 & 0x02000000)) {
                temp_v1_3 = M2C_FIELD(temp_s0, u32 *, 0x10);
                if (temp_v1_3 >= 4U) {
                    var_v0 = 0x17;
                    if (M2C_FIELD(temp_s1_2, u16 *, 4) == 3) {
                        if (M2C_FIELD(temp_s1_2, s32 *, 8) >= 0x53) {
                            M2C_FIELD(temp_s0, s32 *, 0) = 0x17;
                            goto block_60;
                        }
                        goto block_40;
                    }
                    goto block_59;
                }
                M2C_FIELD((temp_s0 + (temp_v1_3 * 4)), s32 *, 0x14) = (s32) (M2C_FIELD(temp_s1_2, s32 *, 8) + 1);
block_40:
                M2C_FIELD(temp_s0, u32 *, 0x10) = (u32) (M2C_FIELD(temp_s0, u32 *, 0x10) + 1);
                goto block_41;
            }
block_41:
            if (temp_s2_2 & 0x10000000) {
                if ((M2C_FIELD(temp_s1_2, s32 *, 8) + 1) != 0x58) {
                    M2C_FIELD(temp_s0, s32 *, 0) = 0x18;
                    __osLeoAbnormalResume(var_a0, 0xA4600010, 2);
                }
                if ((s32) M2C_FIELD(temp_s1_2, u16 *, 4) == 0x20000) {
                    M2C_FIELD(temp_s1_2, s16 *, 6) = 1;
                    M2C_FIELD(temp_s1_2, s32 *, 8) = -1;
                    M2C_FIELD(temp_s1_2, s32 *, 0x40) = (s32) (M2C_FIELD(temp_s1_2, s32 *, 0x40) - M2C_FIELD(temp_s1_2, s32 *, 0x48));
                    M2C_FIELD(temp_s0, s32 *, 0) = 0x16;
                } else {
                    *(s32 *)0xA4600010 = 2;
                    M2C_FIELD(temp_v1, s32 *, 0x14) = 2;
                    M2C_FIELD(temp_s0, s32 *, 0) = 0;
                    *(u32 *)0x800D9288 = (u32) (*(s32 *)0x800D9288 | 0x100401);
                }
                arg4 = M2C_FIELD(temp_s0, s32 *, 0xC) * 4;
                osEPiRawStartDma(*(s32 *)0x8014EA44, 0, 0x05000000, M2C_FIELD(temp_s0, s32 *, 8));
                return 1;
            }
            if ((M2C_FIELD(temp_s1_2, s32 *, 8) == -1) && ((s32) M2C_FIELD(temp_s1_2, u16 *, 4) == 0x20001)) {
                temp_a1 = temp_s1_2 + 0x18;
                if (M2C_FIELD(temp_s1_2, s32 *, 0x28) == 0) {
                    temp_v1_4 = M2C_FIELD(temp_a1, u8 **, 8);
                    var_a0 = M2C_FIELD(temp_v1_4, s32 *, 8);
                    if ((M2C_FIELD(temp_v1_4, s32 *, 0) | M2C_FIELD(temp_v1_4, s32 *, 4) | var_a0 | M2C_FIELD(temp_v1_4, s32 *, 0xC)) != 0) {
                        M2C_FIELD(temp_s1_2, s32 *, 0x18) = 0x18;
                        goto block_60;
                    }
                }
                M2C_FIELD(temp_s1_2, s32 *, 0x18) = 0;
                __osLeoResume((u16) var_a0, temp_a1, 2);
                goto block_54;
            }
block_54:
            temp_v1_5 = M2C_FIELD(temp_s1_2, s32 *, 8) + 1;
            M2C_FIELD(temp_s1_2, s32 *, 8) = temp_v1_5;
            if (temp_s2_2 & 0x40000000) {
                if (temp_v1_5 >= 0x55) {
                    var_v0 = 0x18;
                    goto block_59;
                }
                arg4 = M2C_FIELD(temp_s0, s32 *, 0xC);
                osEPiRawStartDma(*(s32 *)0x8014EA44, 0, 0x05000400, M2C_FIELD(temp_s0, s32 *, 4));
                M2C_FIELD(temp_s0, s32 *, 0) = 0;
                return 1;
            }
            var_v0 = 0x18;
            if (temp_v1_5 < 0x55) {
                goto block_59;
            }
            goto block_61;
        }
block_59:
        M2C_FIELD(temp_s0, s32 *, 0) = var_v0;
block_60:
        __osLeoAbnormalResume();
block_61:
        /* Duplicate return node #62. Try simplifying control flow for better match */
        return 1;
    }
    return 1;
}
