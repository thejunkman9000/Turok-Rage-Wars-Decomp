#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

u32 func_002BD950(s32 arg0, s32 arg1, s32 arg2, M2C_UNK arg3, s32 arg4) {
    M2C_UNK sp10;
    M2C_UNK *var_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s2;
    s32 var_v1;
    s32 var_v1_2;
    u32 temp_v1;
    u32 var_s0;
    u32 var_v0;

    var_s2 = 2;
    if ((arg4 == 1) || (temp_v1 = arg2 & 0xFFFF, ((temp_v1 < 7U) == 0)) || (var_v0 = 0, (temp_v1 == 0))) {
        __osSiGetAccess();
        *(s8 *)0x8014D4B0 = 3;
        __osPackRamWriteData(arg1, arg2 & 0xFFFF, arg3);
        __osSiRawStartDma(1, 0x80154110);
        osRecvMesg(arg0, 0, 1);
loop_4:
        __osSiRawStartDma(0, 0x80154110);
        osRecvMesg(arg0, 0, 1);
        var_a1 = 0x80154110;
        if (arg1 != 0) {
            var_v1 = 0;
            if (arg1 > 0) {
                do {
                    var_v1 += 1;
                    var_a1 += 1;
                } while (var_v1 < arg1);
            }
        }
        var_v1_2 = var_a1;
        var_a0 = &sp10;
        if (var_v1_2 & 3) {
            temp_v0 = var_v1_2 + 0x20;
            do {
                M2C_FIELD(var_a0, M2C_UNK *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 0));
                M2C_FIELD(var_a0, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 4));
                M2C_FIELD(var_a0, M2C_UNK *, 8) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 8));
                M2C_FIELD(var_a0, M2C_UNK *, 0xC) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 0xC));
                var_v1_2 += 0x10;
                var_a0 += 0x10;
            } while (var_v1_2 != temp_v0);
        } else {
            temp_v0_2 = var_v1_2 + 0x20;
            do {
                M2C_FIELD(var_a0, s32 *, 0) = (s32) M2C_FIELD(var_v1_2, s32 *, 0);
                M2C_FIELD(var_a0, s32 *, 4) = (s32) M2C_FIELD(var_v1_2, s32 *, 4);
                M2C_FIELD(var_a0, s32 *, 8) = (s32) M2C_FIELD(var_v1_2, s32 *, 8);
                M2C_FIELD(var_a0, s32 *, 0xC) = (s32) M2C_FIELD(var_v1_2, s32 *, 0xC);
                var_v1_2 += 0x10;
                var_a0 += 0x10;
            } while (var_v1_2 != temp_v0_2);
        }
        M2C_FIELD(var_a0, M2C_UNK *, 0) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 0));
        M2C_FIELD(var_a0, M2C_UNK *, 4) = M2C_UNALIGNED32(M2C_FIELD(var_v1_2, M2C_UNK *, 4));
        var_s0 = (u32) (sp12 & 0xC0) >> 4;
        if (var_s0 != 0) {
            var_s0 = 1;
            goto block_19;
        }
        if ((__osContDataCrc(arg3, var_a1) & 0xFF) != sp36) {
            var_s0 = __osPfsGetStatus(arg0, arg1);
            if (var_s0 == 0) {
                var_s0 = 4;
                goto block_19;
            }
        } else {
block_19:
            if (var_s0 == 4) {
                var_s2 -= 1;
                if (var_s2 >= 0) {
                    goto loop_4;
                }
            }
        }
        __osSiRelAccess();
        var_v0 = var_s0;
    }
    return var_v0;
}
