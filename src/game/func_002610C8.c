#include "b14_types.h"
void func_002610C8(s32 *p, s32 n) {
    s32 i;
    p[0] = n;
    p[1] = (n * 4 + 15) & ~7;
    for (i = 1; i <= n; i++) {
        p[i + 1] = 0xDEADBEEF;
    }
}
