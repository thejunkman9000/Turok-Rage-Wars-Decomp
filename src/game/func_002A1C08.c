#include "b23_types.h"
extern s32 D_800D2B88;
s32 func_00414D4C(char *buf, char *fmt, va_list ap);
void func_002A1C08(char *buf, char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);
    D_800D2B88 = func_00414D4C(buf, fmt, ap);
}

