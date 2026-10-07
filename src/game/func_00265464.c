#include "b14_types.h"

s32 func_00265464(u8 *a, u8 *b, s32 n) {
    u8 *end = a + n;
    if (n >= 4 && !((u32)a & 3) && !((u32)b & 3)) {
        end -= 4;
        while (!(end < a)) {
            if (*(u32 *)a != *(u32 *)b) {
                a -= 4;
                b -= 4;
                break;
            }
            a += 4;
            b += 4;
        }
        end += 4;
    }
    while (a < end) {
        if (*a != *b) {
            if (*a < *b) {
                return -1;
            }
            return 1;
        }
        a++;
        b++;
    }
    return 0;
}

