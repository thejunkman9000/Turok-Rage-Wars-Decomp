#include "b16_types.h"

s32 *func_0028FD94(s32 *node, s32 idx);
void func_00253F2C(s32 a, s32 b);

void func_0026E1F8(s32 **p) {
    s32 *n;
    s32 *c;
    s32 i;
    s32 count;
    n = func_0028FD94(*p, 2);
    count = n[0];
    for (i = 0; i < count; i++) {
        c = func_0028FD94(func_0028FD94(n, i), 0);
        if (c[2] != 0) {
            func_00253F2C(0, c[2]);
        }
    }
}
