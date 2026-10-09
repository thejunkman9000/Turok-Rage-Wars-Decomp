#include "b23_types.h"

extern void (*D_800D2BA4)(void);
/* port: trampoline - the MIPS code passes a0..a3 and v0 straight through; the void decomp dropped them. */
u32 func_002A1F60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return ((u32 (*)(u32, u32, u32, u32))D_800D2BA4)(a0, a1, a2, a3);
}
