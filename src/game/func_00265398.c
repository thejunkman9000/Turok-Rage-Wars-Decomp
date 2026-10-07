#include "b14_types.h"
void func_00265398(u8 *dst, u8 *src, s32 n) {
    u8 *d;
    u8 *s;
    if (n != 0) {
        if (((u32)src | (u32)dst | n) & 3) {
            d = dst;
            s = src;
            if (dst < src) {
                do {
                    *d++ = *s++;
                } while (--n != 0);
            } else {
                d += n - 1;
                s += n - 1;
                do {
                    *d-- = *s--;
                } while (--n != 0);
            }
        } else {
            n >>= 2;
            if (dst < src) {
                do {
                    *(u32 *)dst = *(u32 *)src;
                    src += 4;
                    dst += 4;
                } while (--n != 0);
            } else {
                dst += n * 4 - 4;
                src += n * 4 - 4;
                do {
                    *(u32 *)dst = *(u32 *)src;
                    src -= 4;
                    dst -= 4;
                } while (--n != 0);
            }
        }
    }
}
