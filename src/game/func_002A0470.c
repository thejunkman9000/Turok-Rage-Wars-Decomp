#include "b23_types.h"

void *func_002A0470(void *dst, void *src, s32 n) {
    u8 *d = (u8 *)dst;
    u8 *s = (u8 *)src;
    u32 k;

    if (n == 0 || dst == src) {
        return dst;
    }
    if (dst < src) {
        k = (u32)s;
        if ((k | (u32)dst) & 3) {
            if ((k ^ (u32)dst) & 3) {
                k = n;
            } else if (n < 4) {
                k = n;
            } else {
                k = 4 - (k & 3);
            }
            n -= k;
            do {
                *d++ = *s++;
            } while (--k != 0);
        }
        k = (u32)n >> 2;
        if (k != 0) {
            do {
                *(u32 *)d = *(u32 *)s;
                s += 4;
                d += 4;
            } while (--k != 0);
        }
        k = n & 3;
        if (k != 0) {
            do {
                *d++ = *s++;
            } while (--k != 0);
        }
    } else {
        s += n;
        d += n;
        k = (u32)s;
        if ((k | (u32)d) & 3) {
            if ((k ^ (u32)d) & 3) {
                k = n;
            } else if (n < 5) {
                k = n;
            } else {
                k = k & 3;
            }
            n -= k;
            do {
                *--d = *--s;
            } while (--k != 0);
        }
        k = (u32)n >> 2;
        if (k != 0) {
            do {
                s -= 4;
                d -= 4;
                *(u32 *)d = *(u32 *)s;
            } while (--k != 0);
        }
        k = n & 3;
        if (k != 0) {
            do {
                *--d = *--s;
            } while (--k != 0);
        }
    }
    return dst;
}
