#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;

void func_002B2870(s32 arg0, s32 arg1, s32 arg2, u8 arg4) {
    s32 temp_at_2;
    s32 var_t4;
    s32 var_t5;
    s32 var_t7;
    s8 *var_s1;
    s8 temp_t5;
    s8 var_t1;
    u32 var_t0;
    u32 var_t2;
    u32 var_t6;
    u8 *var_s1_2;
    u8 temp_at;
    u8 *var_s0;

    var_s0 = saved_reg_s0;
    rncInputBits();
    if ((M2C_ERROR(/* Read from unset register $t0 */) - 1) >= 0) {
        var_s1 = sp;
        do {
            rncInputBits();
            *var_s1 = M2C_ERROR(/* Read from unset register $t0 */);
            var_s1 += 1;
        } while (M2C_ERROR(/* Read from unset register $t2 */) != 0);
        var_t0 = M2C_ERROR(/* Read from unset register $a1 */);
        var_t1 = 1;
        var_t2 = 0;
        arg0 = M2C_ERROR(/* Read from unset register $t5 */);
        arg1 = M2C_ERROR(/* Read from unset register $t6 */);
        arg2 = M2C_ERROR(/* Read from unset register $t7 */);
        do {
            var_t4 = M2C_ERROR(/* Read from unset register $t3 */);
            var_s1_2 = &arg4;
loop_5:
            temp_at = *var_s1_2;
            var_s1_2 += 1;
            if (var_t1 == temp_at) {
                M2C_FIELD(var_s0, s16 *, 0) = (s16) ((1 << var_t1) - 1);
                var_t5 = (var_t2 >> 0x10) | (var_t2 << 0x10);
                var_t7 = var_t1 - 1;
                do {
                    temp_at_2 = var_t5 & M2C_ERROR(/* Read from unset register $a3 */);
                    var_t5 *= 2;
                    var_t6 = (u32) ((-1U >> 0x10) & M2C_ERROR(/* Read from unset register $t6 */)) >> 1;
                    if (temp_at_2 != 0) {
                        var_t6 |= M2C_ERROR(/* Read from unset register $a3 */);
                    }
                    var_t7 -= 1;
                } while (var_t7 != 0);
                M2C_FIELD(var_s0, s16 *, 2) = (s16) (var_t6 >> (0x10 - var_t1));
                var_s0 = var_s0 + 2 + 2;
                M2C_FIELD(var_s0, s8 *, 0x3C) = var_t1;
                temp_t5 = M2C_ERROR(/* Read from unset register $t3 */) - var_t4;
                M2C_FIELD(var_s0, s8 *, 0x3D) = temp_t5;
                M2C_FIELD(var_s0, s16 *, 0x3E) = (s16) ((1 << (temp_t5 - 1)) - 1);
                var_t2 += var_t0;
            }
            var_t4 -= 1;
            if (var_t4 != 0) {
                goto loop_5;
            }
            var_t0 = var_t0 >> 1;
            var_t1 += 1;
        } while (var_t1 != 0x11);
    }
}
