

#include "b14_types.h"
#undef memcpy
void memcpy();

void *func_00261110(s32 *p, void *src, s32 size) {
    s32 n; s32 i; s32 k; u8 *dst; s32 *q; s32 *r;
    n = p[0];
    for (i = 0; i <= n; i++) {
        if (p[i + 1] == 0xDEADBEEF) {
            break;
        }
    }
    i--;
    k = i + 1;
    q = p + k;
    r = p + i;
    q[1] = r[1] + size;
    dst = (u8 *)p + r[1];
    if (src != NULL) {
        memcpy(dst, src, size);
    }
    return dst;
}

