#include "o05_types.h"

typedef struct { u8 pad0[0x10]; u8 b10; } O05Wd;
typedef struct { void *f0; void *f4; O05Wd *f8; s32 fC; s32 f10; s32 f14; } O05M80;
extern O05M80 *D_800E5780;
extern u8 D_80102B7E[];
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
s32 func_00265670(void *p, s32 a);
void *func_0040ECB0(void *a, s32 b);
void func_0040E9D0(void *a, s32 b);
void *func_00419ED4(s32 a, s32 b);

s32 func_auto_00437310(void *w) {
    D_800E5780 = func_00252FFC(0x18);
    D_800E5780->f0 = func_0041A300(0x134, 0x135);
    D_800E5780->f14 = 0;
    if (func_00265670(D_80102B7E, 0) == 0) {
        func_0040E9D0(func_0040ECB0(w, 0x138), 1);
    }
    D_800E5780->f4 = func_00419ED4(0x137, 0x6E);
    D_800E5780->f8 = func_0040ECB0(w, 0x136);
    D_800E5780->f8->b10 = 0xF;
    D_800E5780->fC = 3;
    D_800E5780->f10 = -1;
    return 0;
}
