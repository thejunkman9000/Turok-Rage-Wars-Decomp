#include "b23_types.h"
u8 *func_002A17DC(u8 *p, s32 c, s32 n) {
    while (n != 0) {
        if (*p == (u8)c) break;
        n--;
        p++;
    }
    return n != 0 ? p : 0;

}
