#include "b16_types.h"

s32 *func_0028FD94(s32 *node, s32 idx);
s32 func_00296E04(s32 *p, s32 a);
void func_002536F4(s32 a, s32 b);

void func_0026E158(s32 **p) {
    s32 *n;
    s32 *c;
    s32 i;
    s32 count;
    s32 r;
    n = func_0028FD94(*p, 2);
    count = n[0];
    for (i = 0; i < count; i++) {
        c = func_0028FD94(func_0028FD94(n, i), 0);
        if (c[2] != 0) {
            r = func_00296E04(&c[2], -1);
            if (r != 0) {
                func_002536F4(0, r);
            }
        }
    }
}
