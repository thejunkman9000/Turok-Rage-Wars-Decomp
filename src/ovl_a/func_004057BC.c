#include "o01_types.h"

s32 func_004057BC(u8 *p, s32 n) {
    do {
        if (*p++ == 0x7E) {
            return 1;
        }
    } while (--n != -1);
    return 0;
}
