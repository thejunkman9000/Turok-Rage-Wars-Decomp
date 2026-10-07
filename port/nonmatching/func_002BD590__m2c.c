#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

u32 func_002BD590(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    M2C_UNK sp10;
    M2C_UNK sp16;
    M2C_UNK *var_v1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s1;
    s32 var_s3;
    s32 var_v1;
    s32 var_v1_3;
    u32 var_s0;
    u8 *var_s2;
    u8 temp_v0_3;

    var_s2 = arg3;
    var_s3 = 2;
    __osSiGetAccess();
    *(s8 *)0x8014D4B0 = 2;
    __osPackRamReadData(arg1, arg2 & 0xFFFF);
    __osSiRawStartDma(1, 0x80154110);
    osRecvMesg(arg0, 0, 1);
loop_1:
    __osSiRawStartDma(0, 0x80154110);
    osRecvMesg(arg0, 0, 1);
    var_s1 = 0x80154110;
    if (arg1 != 0) {
        var_v1 = 0;
        if (arg1 > 0) {
            do {
                var_v1 += 1;
                var_s1 += 1;
            } while (var_v1 < arg1);
        }
    }
    var_a1 = var_s1;
    var_v1_2 = &sp10;
    if (var_a1 & 3) {
        temp_v0 = var_a1 + 0x20;
        do {
            M2C_FIELD(var_v1_2, M2C_UNK *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 0));
            M2C_FIELD(var_v1_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 4));
            M2C_FIELD(var_v1_2, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 8));
            M2C_FIELD(var_v1_2, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 0xC));
            var_a1 += 0x10;
            var_v1_2 += 0x10;
        } while (var_a1 != temp_v0);
    } else {
        temp_v0_2 = var_a1 + 0x20;
        do {
            M2C_FIELD(var_v1_2, s32 *, 0) = (s32) M2C_FIELD(var_a1, s32 *, 0);
            M2C_FIELD(var_v1_2, s32 *, 4) = (s32) M2C_FIELD(var_a1, s32 *, 4);
            M2C_FIELD(var_v1_2, s32 *, 8) = (s32) M2C_FIELD(var_a1, s32 *, 8);
            M2C_FIELD(var_v1_2, s32 *, 0xC) = (s32) M2C_FIELD(var_a1, s32 *, 0xC);
            var_a1 += 0x10;
            var_v1_2 += 0x10;
        } while (var_a1 != temp_v0_2);
    }
    M2C_FIELD(var_v1_2, M2C_UNK *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 0));
    M2C_FIELD(var_v1_2, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_a1, M2C_UNK *, 4));
    var_s0 = (u32) (sp12 & 0xC0) >> 4;
    if (var_s0 != 0) {
        var_s0 = 1;
        goto block_19;
    }
    if ((__osContDataCrc(&sp16, (u8 *) var_a1) & 0xFF) != sp36) {
        var_s0 = __osPfsGetStatus(arg0, arg1);
        if (var_s0 == 0) {
            var_s0 = 4;
block_19:
            goto block_20;
        }
    } else {
        var_v1_3 = 0;
        do {
            temp_v0_3 = M2C_FIELD((&sp10 + var_v1_3), u8 *, 6);
            var_v1_3 += 1;
            *var_s2 = temp_v0_3;
            var_s2 += 1;
        } while (var_v1_3 < 0x20);
block_20:
        if (var_s0 == 4) {
            var_s3 -= 1;
            if (var_s3 >= 0) {
                goto loop_1;
            }
        }
    }
    __osSiRelAccess();
    return var_s0;
}
