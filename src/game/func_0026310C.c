/* Bit stream: reads n bits with func_00263174 (LSB first) and sign-extends the n-bit value.
   This is the whole manifest unit pad_063D0C (26 insns, right behind the 3-insn setter func_00263100).
   Upstream: func_802630EC_de. */
#include "s1008_types.h"

s32 func_00263174(B14BitRd *r, s32 n);

s32 func_0026310C(B14BitRd *r, s32 n) {
    s32 val;
    s32 i;
    s32 mask;
    val = func_00263174(r, n);
    mask = 1 << (n - 1);
    if (val & mask) {
        i = n;
        if (n < 0x20) {
            do {
                val |= 1 << i;
                i += 1;
            } while (i < 0x20);
        }
    }
    return val;
}
