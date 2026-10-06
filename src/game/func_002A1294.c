#include "b23_types.h"

u8 *func_002A1294(u8 *dst, u8 *src, s32 n) {
    u8 *r;
    u8 c;

    r = dst;
    if (n == 0) {
        goto end;
    }
copy:
    c = *src;
    src++;
    *dst = c;
    dst++;
    if (c == 0) {
        goto fill;
    }
    n--;
    if (n != 0) {
        goto copy;
    }
fill:
    if (n == 0) {
        goto end;
    }
    n--;
    if (n == 0) {
        goto end;
    }
zero:
    *dst = 0;
    n--;
    dst++;
    if (n != 0) {
        goto zero;
    }
end:
    return r;
}
