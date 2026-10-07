#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

s32 func_004478B0(u8 *arg0, s32 *arg1) {
    s32 temp_s0;
    s32 var_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    u16 *var_v1;

    var_s2 = 0;
    if (!(M2C_FIELD(arg0, s32 *, 0) & 1)) {
        return 5;
    }
    var_v0 = 2;
    if (__osCheckId(arg0) != 2) {
        var_s1 = 0;
        if ((u8) M2C_FIELD(arg0, u8 *, 0x64) > 0U) {
loop_5:
            temp_s0 = var_s1 & 0xFF;
            var_v0 = __osPfsRWInode(arg0, (u16 (*)[]) &sp10[0], 0, temp_s0);
            if (var_v0 == 0) {
                var_v0_2 = 1;
                if (temp_s0 == 0) {
                    var_v0_2 = M2C_FIELD(arg0, s32 *, 0x60);
                }
                var_a0 = var_v0_2;
                if (var_a0 < 0x80) {
                    var_v1 = &(&sp10[0])[var_a0];
                    do {
                        if (*var_v1 == 3) {
                            var_s2 += 1;
                        }
                        var_a0 += 1;
                        var_v1 += 2;
                    } while (var_a0 < 0x80);
                }
                var_s1 += 1;
                if ((u32) (var_s1 & 0xFF) >= (u8) M2C_FIELD(arg0, u8 *, 0x64)) {
                    goto block_14;
                }
                goto loop_5;
            }
        } else {
block_14:
            *arg1 = var_s2 << 8;
            var_v0 = 0;
        }
    }
    return var_v0;
}
