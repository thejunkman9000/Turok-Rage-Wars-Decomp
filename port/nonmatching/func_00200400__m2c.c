#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_002A81B0();

void func_00200400(u32 arg4, s32 arg5) {
    s32 var_a0;

    var_a0 = 0x1E;
    do {
        M2C_ERROR(/* mtc0 $a0, $0 */);
        M2C_ERROR(/* mtc0 $t1, $10 */);
        M2C_ERROR(/* mtc0 $zero, $2 */);
        M2C_ERROR(/* mtc0 $zero, $3 */);
        M2C_ERROR(/* unknown instruction: tlbwi */);
        M2C_ERROR(/* mtc0 $t0, $10 */);
        var_a0 -= 1;
    } while (var_a0 != 0);
    arg4 = 0x100000U;
    arg5 = 7;
    func_00000488(0x1F, 0x1FE000, 0x200000, 0);
    (M2C_UNK (*)(M2C_UNK))func_002A81B0(func_002A81B0);
    M2C_BREAK(1);
    M2C_ERROR(/* mtc0 $a0, $0 */);
    M2C_ERROR(/* mtc0 $a1, $5 */);
    M2C_ERROR(/* mtc0 $a2, $10 */);
    if (M2C_ERROR(/* Read from unset register $a3 */) != -1) {
        M2C_ERROR(/* mtc0 $t5, $2 */);
    } else {
        M2C_ERROR(/* mtc0 $t6, $2 */);
    }
    M2C_ERROR(/* mtc0 $t6, $3 */);
    if (arg4 != -1U) {
        M2C_ERROR(/* mtc0 $t5, $3 */);
    }
    M2C_ERROR(/* unknown instruction: tlbwi */);
    M2C_ERROR(/* mtc0 $t0, $10 */);
}
