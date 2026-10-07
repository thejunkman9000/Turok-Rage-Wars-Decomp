#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

u32 func_002BCEE4(u8 *arg0) {
    M2C_UNK sp10;
    M2C_UNK *var_v1_2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_v1;
    u32 var_s0_2;
    u32 var_v0;

    var_s0 = 0x80154110;
    var_v0 = 5;
    if (M2C_FIELD(((M2C_FIELD(arg0, s32 *, 8) * 4) + 0x800E0000), s32 *, -0x7C80) != 0) {
        __osSiGetAccess();
        *(s8 *)0x8014D4B0 = 3;
        __osSiRawStartDma(1, (M2C_FIELD(arg0, s32 *, 8) << 6) + 0x8014D4C0);
        osRecvMesg(M2C_FIELD(arg0, s32 *, 4), 0, 1);
        __osSiRawStartDma(0, 0x80154110);
        osRecvMesg(M2C_FIELD(arg0, s32 *, 4), 0, 1);
        temp_a0 = M2C_FIELD(arg0, s32 *, 8);
        var_a1 = 0x80154110;
        if (temp_a0 != 0) {
            var_v1 = 0;
            if (temp_a0 > 0) {
                do {
                    var_v1 += 1;
                    var_s0 += 1;
                } while (var_v1 < temp_a0);
                var_a1 = var_s0;
            }
        }
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
        var_s0_2 = (u32) (sp12 & 0xC0) >> 4;
        if ((var_s0_2 == 0) && ((__osContDataCrc(0x8014D5C0, (u8 *) var_a1) & 0xFF) != sp36)) {
            var_s0_2 = 4;
        }
        __osSiRelAccess();
        var_v0 = var_s0_2;
    }
    return var_v0;
}
