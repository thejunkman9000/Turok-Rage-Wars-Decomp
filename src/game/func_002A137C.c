#include "b23_types.h"

s32 func_002A137C(u8 *a, u8 *b) {
    s32 d;

    while ((d = *a - *b) == 0 && *b != 0) {
        a++;
        b++;
    }
    return d;
}
