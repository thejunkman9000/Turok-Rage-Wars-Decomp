#include "b23_types.h"

s32 func_002A13AC(u8 *a, u8 *b, s32 n) {
    if (n == 0) {
        return 0;
    }
    n--;
    while (n != 0 && *a != 0 && *a == *b) {
        n--;
        a++;
        b++;
    }
    return *a - *b;
}
