#include "b01_types.h"

void func_00200568(u32 addr, u32 val);
void func_00200C28(u32 addr, u32 val);

/* memcpy from RAM into a bus-addressed buffer: byte writes up to word alignment, word writes, byte tail */
void func_00200D18(u32 dst, u8 *src, u32 n) {
    while (n != 0 && (dst & 3) != 0) {
        func_00200C28(dst++, *src++);
        n--;
    }
    if (n >= 4) {
        do {
            func_00200568(dst, (src[0] << 24) | (src[1] << 16) | (src[2] << 8) | src[3]);
            dst += 4;
            n -= 4;
            src += 4;
        } while (n >= 4);
    }
    while (n != 0) {
        func_00200C28(dst++, *src++);
        n--;
    }
}
