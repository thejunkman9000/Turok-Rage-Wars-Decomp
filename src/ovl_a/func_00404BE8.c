#include "o01_types.h"

extern u8 D_800E285C[];
extern s32 D_801534F0[];
extern O01PadTab *D_800E2854;
extern s32 D_800E2850;
extern s32 D_800E2858;
extern u8 D_800E0CF0[];
s32 func_002A137C(char *a, char *b);
s32 *func_002533DC(s32 a, s32 b, s32 c, void *d);
void func_002538A8(s32 a);
void func_002537D8(s32 a, s32 b);
void *memset(void *p, s32 c, u32 n);

typedef struct O01Pp { u8 *p; s32 pad; } O01Pp;

static inline void O01ConvName(u8 *src, u8 *dst, s32 n) {
    s32 i;
    s32 seen;
    for (i = 0; i < n; i++) {
        dst[i] = 0;
    }
    seen = 0;
    for (i = 0; i < n; i++) {
        if (src[i] < 0x42) {
            if (src[i] == 0 && seen == 0) {
                dst[i] = 0x20;
            } else {
                dst[i] = D_800E285C[src[i]];
                seen = 1;
            }
        } else {
            dst[i] = 0x7E;
        }
    }
    for (i = n - 1; i >= 0; i--) {
        if (dst[i] != 0x20 && dst[i] != 0) {
            break;
        }
        dst[i] = 0;
    }
    dst[n - 1] = 0;
}

s32 func_00404BE8(char *name, s32 pad, s32 *outIdx) {
    u8 buf[16];
    O01Pp pp;
    s32 i = 0;
    do {
        if (D_801534F0[pad] == 3) {
            pp.p = D_800E2854[pad].ent[i].unkE;
        }
        O01ConvName(pp.p, buf, 16);
        if (func_002A137C((char *)buf, name) == 0) {
            if (outIdx != 0) {
                *outIdx = i;
            }
            return 1;
        }
        i++;
    } while (i < 16);
    return 0;
}

void func_00404D84(void) {
    s32 *h;
    u8 *p;
    h = func_002533DC(0, 0x810, 0x23, D_800E0CF0);
    p = (u8 *)*h;
    D_800E2858 = (s32)h;
    D_800E2854 = (O01PadTab *)p;
    memset(p, 0, 0x810);
    D_800E2850 = 1;
}

void func_00404DDC(void) {
    func_002538A8(0);
    if (D_800E2858 != 0) {
        func_002537D8(0, D_800E2858);
        D_800E2858 = 0;
        D_800E2854 = 0;
    }
    D_800E2850 = 0;
}
