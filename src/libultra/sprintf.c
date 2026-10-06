#include "common.h"

static char *proutSprintf(char *dst, const char *src, u32 count) {
    return (char *)memcpy(dst, src, count) + count;
}

s32 sprintf(char *dst, const char *fmt, ...) {
    s32 ret;
    va_list args;

    args = (va_list)__builtin_next_arg(fmt);
    ret = _Printf(proutSprintf, dst, fmt, args);
    if (ret >= 0) {
        dst[ret] = '\0';
    }
    return ret;
}
