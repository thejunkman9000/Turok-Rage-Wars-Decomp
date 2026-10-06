#include "b23_types.h"

/* NOTE: the ROM symbol func_002A1AC4 starts with 3 stray words (addu a0,s1,zero; addu a1,s0,zero;
   addiu v0,zero,2); this function proper starts at ROM +0xC (VRAM func_002A1AD0). */
extern s32 D_800D2B88;
extern char D_8014D0D0[];

s32 func_00414D4C(char *buf, char *fmt, va_list ap);

char *func_002A1AC4(char *fmt, ...) {
    va_list ap = (char *)__builtin_next_arg(fmt);

    D_800D2B88 = func_00414D4C(D_8014D0D0, fmt, ap);
    return D_8014D0D0;
}
