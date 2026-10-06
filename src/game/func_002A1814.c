#include "b23_types.h"
s32 func_002A1814(u8 *a, u8 *b, s32 n) {
    u8 *end = a + n;
    if (n >= 4 && ((u32)a & 3) == 0 && ((u32)b & 3) == 0) {
        end -= 4;
        while (a <= end) {
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
