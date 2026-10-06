#include "b23_types.h"

extern s32 D_800D2B88;
extern void (*D_800D2B90)(char *buf, s32 a, s32 b);
extern char D_8014D0D0[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);

s32 func_002A1B8C(s32 a, s32 b, char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);

    D_800D2B88 = func_00414D4C(D_8014D0D0, fmt, ap);
    D_800D2B90(D_8014D0D0, a, b);
    return D_800D2B88;
}
