#include "b23_types.h"
void func_002A166C(s32 val, char *buf) {
    s32 n, v, i, j, len;
    char t;
    n = val;
    v = n;
    if (v < 0) {
        n = -v;
    }
    i = 0;
    do {
        buf[i++] = n % 10 + '0';
        n /= 10;
    } while (n > 0);
    len = i;
    if (v < 0) {
        buf[i++] = '-';
        len = i;
    }
    j = len - 1;
    for (i = 0; i < j; i++, j--) {
        t = buf[i];
        buf[i] = buf[j];
        buf[j] = t;
    }
    buf[len] = 0;

}
