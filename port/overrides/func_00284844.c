#include "b19_types.h"
f32 func_002745D4(f32 a);
/* port: the MIPS code leaves x in $f12 for func_002745D4(f32), which reads it as its own argument;
 * the no-argument decomp call made the x86 callee read a garbage float. */
void func_00284844(f32 x) {
    if (x != 0.0f) func_002745D4(x);
}
