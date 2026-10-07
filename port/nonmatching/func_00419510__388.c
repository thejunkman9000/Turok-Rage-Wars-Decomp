#include "o03_types.h"
extern s32 D_800E32F0;
s32 func_00413688();
void func_002A1724(void *d, void *s, s32 n);
typedef struct O3TexB {
    /* 0x00 */ u8 pad0[8];
    /* 0x08 */ s16 w;
    /* 0x0A */ s16 h;
    /* 0x0C */ u8 padC[0xC];
    /* 0x18 */ u8 *data;
} O3TexB;
void func_00419510(O3TexB *t) {
    s32 fmt;
    s32 n;
    s32 row;
    s32 k;
    u8 *s0;
    u8 *s1;
    u32 a, b;
    if (D_800E32F0 != 0 && t->w != 0 && t->h != 0) {
        fmt = func_00413688();
        n = 0;
        switch (fmt) {
        case 8:
            n = t->w / 8;
            break;
        case 4:
            n = t->w / 16;
            break;
        case 0x10:
            n = t->w / 4;
            break;
        }
        row = 0;
        s1 = t->data;
        s0 = s1;
        if (t->h > 0) {
            do {
                if ((row & 1) != 0) {
                    for (k = 0; k < n; k++) {
                        a = *(u32 *)s1;
                        s1 += 4;
                        b = *(u32 *)s1;
                        s1 += 4;
                        *(u32 *)s0 = b;
                        s0 += 4;
                        *(u32 *)s0 = a;
                        s0 += 4;
                    }
                } else {
                    if (s1 != s0) {
                        func_002A1724(s0, s1, n * 8);
                    }
                    s0 += n * 8;
                    s1 += n * 8;
                }
                row++;
            } while (row < t->h);
        }
    }
}
