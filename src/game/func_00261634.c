#include "b14_types.h"
u32 func_00261634(u32 x) {
    u32 count = 0;
    u32 last = 0;
    u32 i;
    for (i = 0; i < 32; i++) {
        if (x & (1 << i)) {
            count++;
            last = i;
        }
    }
    if (count >= 2) {
        return last + 1;
    }
    return last;
}
