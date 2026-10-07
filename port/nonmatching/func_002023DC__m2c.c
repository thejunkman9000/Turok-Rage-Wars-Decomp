#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_002023DC(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_a2;
    s32 temp_a3;
    s32 var_a0;
    u8 *var_a1;

    var_a0 = 0x1F;
    var_a1 = (u8 *)0x800F7660;
    do {
        M2C_ERROR(/* mtc0 $a0, $0 */);
        var_a0 -= 1;
        M2C_ERROR(/* unknown instruction: tlbr */);
        M2C_FIELD(var_a1, s32 *, 0) = (s32) M2C_ERROR(/* mfc0 $5 */);
        M2C_FIELD(var_a1, s32 *, 4) = (s32) M2C_ERROR(/* mfc0 $10 */);
        temp_a2 = M2C_ERROR(/* mfc0 $2 */);
        temp_a3 = M2C_ERROR(/* mfc0 $3 */);
        M2C_FIELD(var_a1, s32 *, 8) = temp_a2;
        M2C_FIELD(var_a1, s32 *, 0xC) = temp_a3;
        var_a1 -= 0x10;
    } while (var_a0 >= 0);
    M2C_ERROR(/* mtc0 $v0, $10 */);
    arg0 = var_a0;
    arg1 = var_a1;
    arg2 = temp_a2;
    arg3 = temp_a3;
    return M2C_ERROR(/* mfc0 $10 */);
}
