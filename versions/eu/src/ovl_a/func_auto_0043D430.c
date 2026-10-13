#include "common.h"
typedef struct { u8 pad[0x2D8]; u32 f2D8; } Q4G2B;
typedef struct { u8 pad[0xC]; Q4G2B *f0C; } Q4G2A;
extern u32 D_auto_8015220C;
extern u8 D_auto_80152225;
extern s32 D_auto_8015DDA4;

void func_auto_0043D430(Q4G2A *a) {
    s32 i;
    s32 n;
    u32 flags;
    u32 m;
    i = 0;
    n = 0;
    flags = D_auto_8015220C;
    do {
        switch (i) {
        default:
        case 0: m = 0x10000; break;
        case 1: m = 0x20000; break;
        case 2: m = 0x40000; break;
        case 3: m = 0x80000; break;
        case 4: m = 0x100000; break;
        case 5: m = 0x200000; break;
        case 6: m = 0x800000; break;
        case 7: m = 0x400000; break;
        case 8: m = 0x1000000; break;
        case 9: m = 0x2000000; break;
        case 10: m = 0x4000000; break;
        }
        if (D_auto_8015220C & m) goto found;
        i++;
        if (i >= 11) i = 0;
        else if (i < 0) i = 10;
        n++;
    } while (n < 11);
    i = -1;
found:
    D_auto_8015DDA4 = i;
    if (i != -1) {
        a->f0C->f2D8 |= 0x1800000;
    } else {
        a->f0C->f2D8 &= 0xFE7FFFFF;
    }
    if (D_auto_80152225 != 0) {
        a->f0C->f2D8 &= 0xFE7FFFFF;
    }
}
