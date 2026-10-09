/* port: C function-pointer call forwards the argument registers the MIPS code left live at the jalr (this function's own incoming a0..a3); see port/jalrscan.py. */
#include "b19_types.h"
void func_00285484(u8 *lo, u8 *hi, u32 size, s32 (*cmp)(), void (*swap)()) {
    u8 *p;
    u8 *max;
    while (lo < hi) {
        max = lo;
        for (p = lo + size; p <= hi; p += size) {
            if (cmp(p, max, size, cmp) > 0) max = p;
        }
        swap(max, hi);
        hi -= size;
    }
}
