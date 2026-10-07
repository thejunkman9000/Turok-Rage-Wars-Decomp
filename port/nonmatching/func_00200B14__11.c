#include "b01_types.h"

u32 func_002005A0(u32 addr);
u32 func_00200800(u32 addr);

void func_00200AD8(u32 addr, u32 val) {
    s32 sh = (~addr & 3) * 8;
    u32 *p = (u32 *)(addr & ~3);
    *p = (*p & ~(0xFF << sh)) | ((val & 0xFF) << sh);
}

/* copy from a bus-addressed buffer into RAM: byte reads up to word alignment, word reads, byte tail */
void func_00200B14(u32 src, u32 dst, u32 n) {
    u32 w;
    while (n != 0 && (src & 3) != 0) {
        func_00200AD8(dst++, func_00200800(src++) & 0xFF);
        n--;
    }
    while (n >= 4) {
        w = func_002005A0(src);
        func_00200AD8(dst++, w >> 24);
        func_00200AD8(dst++, (w >> 16) & 0xFF);
        func_00200AD8(dst++, (w >> 8) & 0xFF);
        func_00200AD8(dst++, w & 0xFF);
        src += 4;
        n -= 4;
    }
    while (n != 0) {
        func_00200AD8(dst++, func_00200800(src++) & 0xFF);
        n--;
    }
}
