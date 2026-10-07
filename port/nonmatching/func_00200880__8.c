/* EXACT only with gcc 2.7.2 -O2 and 'game' assembler behaviour (bare j $31 keeps a nop slot).
   With gcc 2.8.1 -O2 -msplit-addresses only the return slot differs. */
#include "p1_types.h"
u8 func_00200800(u32 addr);
u32 func_002005A0(u32 addr);
void func_00200880(u32 addr, u8 *dst, u32 len) {
    u32 w;
    while (len != 0 && (addr & 3) != 0) {
        *dst++ = func_00200800(addr++);
        len--;
    }
    while (len >= 4) {
        w = func_002005A0(addr);
        *dst++ = w >> 24;
        *dst++ = w >> 16;
        *dst++ = w >> 8;
        *dst++ = w;
        addr += 4;
        len -= 4;
    }
    while (len != 0) {
        *dst++ = func_00200800(addr++);
        len--;
    }
}
