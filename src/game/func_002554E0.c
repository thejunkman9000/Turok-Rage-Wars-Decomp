#include "span_1000/code_80254CE4.h"
#include "types.h"
/* Rounds a value up to a power of two by locating its highest set bit and bumping it unless exactly one bit is set. Adapted from func_80261614_de, with a signed loop counter, an exactly-one-bit test, and 1 << bit returned instead of the bit index. */

s32 func_80255540_de(s32 arg0) {
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;

    var_a1 = 0;
    var_a2 = 0;
    var_v1 = 0;
    do {
        if (arg0 & (u32)(1 << var_v1)) {
            var_a1 += 1;
            var_a2 = var_v1;
        }
        var_v1 += 1;
    } while (var_v1 < 0x20);
    if (var_a1 != 1) {
        var_a2 += 1;
    }
    return 1 << var_a2;
}
