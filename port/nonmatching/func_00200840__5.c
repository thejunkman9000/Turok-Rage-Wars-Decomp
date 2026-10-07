#include "b01_types.h"

u32 func_002005A0(u32 *addr);

/* read one byte from a big-endian word (PI bus read of the aligned word) */
u32 func_00200840(u32 addr) {
    u32 w = func_002005A0((u32 *)(addr & ~3));
    return (w >> ((~addr & 3) * 8)) & 0xFF;
}
