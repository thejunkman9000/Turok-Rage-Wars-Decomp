#include "b23_types.h"

extern s32 D_800D2B88;
extern void (*D_800D2B8C)(char *);
extern char D_8014D0D0[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);

s32 func_002A1B20(char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);

    D_800D2B88 = func_00414D4C(D_8014D0D0, fmt, ap);
    if (D_800D2B8C != 0) {
        D_800D2B8C(D_8014D0D0);
    }
    return D_800D2B88;
}
