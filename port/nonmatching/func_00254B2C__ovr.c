#include "b12_types.h"
#include <stdio.h>

extern u8 D_801051A0[];
u32 func_002559D4(void *heap, u32 size);
u32 func_002558C0(void *heap, u32 size);
u32 func_002512C8(s32 a, s32 b, s32 c);

static int g_ab;
u32 func_00254B2C(s32 unused, u32 size, s32 flag, u32 flags) {
    u32 p;
    if (flag) {
        p = func_002559D4(D_801051A0, size);
    } else {
        p = func_002558C0(D_801051A0, size);
    }
    fprintf(stderr, "alloc size=%X flag=%d flags=%X -> %08X\n", size, flag, flags, p);
    { extern void port_bt(void); extern char *getenv(const char *); if (getenv("TUROK_ALLOCBT") && !flag && (size == 0x3360 || size == 0x70 || (size == 0x10 && getenv("TUROK_ALLOCBT")[0] == 0x31 && ++g_ab == 300))) { fprintf(stderr, "ALLOCBT size=%X", size); port_bt(); } }
    if (p == 0) {
        u32 r;
        u32 f = flags & 0x10;
        do {
            r = func_002512C8(0, 2, f == 0);
        } while (r != 0 && r < size);
        if (!(r < size)) {
            if (flag) {
                p = func_002559D4(D_801051A0, size);
            } else {
                p = func_002558C0(D_801051A0, size);
            }
        }
    }
    return p;
}
