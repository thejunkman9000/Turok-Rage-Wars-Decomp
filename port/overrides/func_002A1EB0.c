#include "b23_types.h"

extern void (*D_800D2B98)(void);
/* port: trampoline - the MIPS code passes a0..a3 and v0 straight through (callers use it as
 * void func_002A1EB0(s32 h)); the void decomp dropped them. */
u32 func_002A1EB0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return ((u32 (*)(u32, u32, u32, u32))D_800D2B98)(a0, a1, a2, a3);
}
