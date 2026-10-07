#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_002BC7A0(s8 arg0, s16 arg1, s32 arg2) {
    s16 var_a1;
    s8 var_a0;
    u8 *temp_a2;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_a2 = arg2 - 0x2B94;
    *(s32 *)0x8014D4AC = M2C_ERROR(/* Read from unset register $v1 */);
    arg0 = M2C_ERROR(/* Read from unset register $v1 */);
    arg0 = M2C_ERROR(/* Read from unset register $v1 */);
    arg1 = M2C_ERROR(/* Read from unset register $v0 */);
    arg1 = -1;
    (s8) arg1 = -1;
    if (*temp_a2 != 0) {
        do {
            M2C_FIELD(var_a1, M2C_UNK *, 0) = M2C_UNALIGNED32(arg0);
            M2C_FIELD(var_a1, M2C_UNK *, 4) = M2C_UNALIGNED32(arg1);
            var_a0 += 1;
            var_a1 += 8;
        } while (var_a0 < (s32) *temp_a2);
    }
    *var_a1 = 0xFE;
}
