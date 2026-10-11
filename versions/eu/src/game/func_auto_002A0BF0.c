#include "b23_types.h"
extern s32 D_auto_800CE4F8;
extern char D_auto_80156E50[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);

char *func_auto_002A0BF0(char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);

    D_auto_800CE4F8 = func_00414D4C(D_auto_80156E50, fmt, ap);
    return D_auto_80156E50;
}
