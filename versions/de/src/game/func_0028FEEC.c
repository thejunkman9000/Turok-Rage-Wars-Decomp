#include "common.h"
void *memcpy(void *dst, const void *src, u32 n);
void func_0028FEEC(s32 *src, u8 *dst, s32 flag) {
    u8 *data;
    u8 *p;
    s32 i;
    s32 j;
    s32 w;
    s32 h;
    s32 n;
    data = (u8 *)src + 8;
    memcpy(dst, src, 8);
    p = dst + 8;
    h = src[1];
    w = src[0];
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            *p++ = data[i + j * h];
        }
    }
    n = h * w;
    if (flag != 0) {
        memcpy(src, dst, n + 8);
    }
}
