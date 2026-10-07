#include "b23_types.h"
void func_002A166C(s32 n, char *s) {
    s32 i, j, sign, len;
    char c;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do { s[i++] = n % 10 + '0'; } while ((n /= 10) > 0);
    if (sign < 0) s[i++] = '-';
    len = i;
    for (i = 0, j = len - 1; i < j; i++, j--) { c = s[i]; s[i] = s[j]; s[j] = c; }
    s[len] = 0;
}

