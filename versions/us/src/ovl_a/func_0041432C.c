#include "o02_types.h"
extern char D_80153D60[];
extern char D_800E10F0[];
extern char D_800E1100[];
s32 func_002A1C08(char *buf, char *fmt, ...);
s32 func_00414D4C(char *buf, char *fmt, va_list ap);
s32 func_0041432C(char *name, s32 val, char *fmt, ...) {
    if (fmt) {
        va_list ap = (char *)__builtin_next_arg(fmt);
        s32 n;
        if (name) {
            n = func_002A1C08(D_80153D60, D_800E10F0, name, val);
        } else {
            n = func_002A1C08(D_80153D60, D_800E10F0, D_800E1100, val);
        }
        func_00414D4C(D_80153D60 + n, fmt, ap);
    }
    return 1;
}
