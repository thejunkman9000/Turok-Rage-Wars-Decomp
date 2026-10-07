#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
s32 func_002C2170(s32 arg0) {
    s32 var_v0;
    u32 temp_t3;

    M2C_ERROR(/* mtc0 $t1, $10 */);
    M2C_ERROR(/* unknown instruction: tlbp */);
    if (!(M2C_ERROR(/* mfc0 $0 */) & 0x80000000)) {
        M2C_ERROR(/* unknown instruction: tlbr */);
        temp_t3 = (u32) (M2C_ERROR(/* mfc0 $5 */) + 0x2000) >> 1;
        if (!(temp_t3 & arg0)) {
            var_v0 = M2C_ERROR(/* mfc0 $2 */);
        } else {
            var_v0 = M2C_ERROR(/* mfc0 $3 */);
        }
        if (var_v0 & 2) {
            M2C_ERROR(/* mtc0 $t0, $10 */);
            return ((var_v0 & 0x3FFFFFC0) << 6) + (arg0 & (temp_t3 - 1));
        }
        goto block_6;
    }
block_6:
    M2C_ERROR(/* mtc0 $t0, $10 */);
    return -1;
}
