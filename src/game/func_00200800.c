#include "b01_types.h"

u32 func_002005A0(u32 *addr);

/* read one byte from a big-endian word (PI bus read of the aligned word) */
u32 func_00200800(u32 addr) {
    s32 sh = (~addr & 3) * 8;
    u32 w = func_002005A0((u32 *)(addr & ~3));
    return (w >> sh) & 0xFF;
}
