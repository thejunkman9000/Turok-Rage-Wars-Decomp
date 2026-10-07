#include "b23_types.h"

extern u8 D_800CAEF0[];
extern char D_8014D0D0[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);
s32 func_002A1F50(void *p, s32 size, s32 n, s32 fp);

s32 func_002A1C38(s32 fp, char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);
    u8 *p;
    u8 *seg;
    s32 n;
    s32 total;
    u8 c;

    func_00414D4C(D_8014D0D0, fmt, ap);
    p = seg = (u8 *)D_8014D0D0;
    total = n = 0;
    if (*seg != 0) {
        c = *p;
        do {
            if (*p == '\n') {
                if (n > 0) {
                    func_002A1F50(seg, 1, n, fp);
                    total += n;
                    n = 0;
                    seg = p;
                }
                func_002A1F50(D_800CAEF0, 1, 1, fp);
                total += 1;
            }
            p++;
            c = *p;
            n++;
        } while (c != 0);
    }
    if (n > 0) {
        func_002A1F50(seg, 1, n, fp);
        total += n;
    }
    return total;
}


