#include "common.h"
#include "D:/Projects/TurokRageWars/port/m2c_macros.h"
typedef s32 M2C_UNKTYPE;
void func_002C2320(void) {
    s32 var_t1;

    var_t1 = 0x1E;
    M2C_ERROR(/* mtc0 $t2, $10 */);
    M2C_ERROR(/* mtc0 $zero, $2 */);
    M2C_ERROR(/* mtc0 $zero, $3 */);
    do {
        M2C_ERROR(/* mtc0 $t1, $0 */);
        M2C_ERROR(/* unknown instruction: tlbwi */);
        var_t1 -= 1;
    } while (var_t1 >= 0);
    M2C_ERROR(/* mtc0 $t0, $10 */);
}
