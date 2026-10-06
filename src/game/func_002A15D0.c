#include "b23_types.h"
s32 func_002A15D0(u8 *s) {
    s32 n, c;
    u8 first;
    while (*s == ' ') {
        s++;
    }
    c = *s++;
    first = c;
    if (first == '-' || first == '+') {
        c = *s++;
    }
    n = 0;
    while ((u32)(c - '0') < 10) {
        n = c - '0' + n * 10;
        c = *s++;
    }
    if (first == '-') {
        return -n;
    }
    return n;

}
