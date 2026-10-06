#include "b23_types.h"

extern s32 D_800D2B88;
extern char D_8014D0D0[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);

char *func_002A200C(char *fmt, va_list ap) {
    D_800D2B88 = func_00414D4C(D_8014D0D0, fmt, ap);
    return D_8014D0D0;
}
