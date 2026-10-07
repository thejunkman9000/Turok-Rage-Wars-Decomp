#include "o06_types.h"
s32 func_004467D8(u8 *a, u8 *b, s32 n) {
    u8 c = *a++; u8 d = *b++; n--;
    if (c == d && c != 0 && n == 0) return func_004467D8(a, b, n);
    return c == d;
}
