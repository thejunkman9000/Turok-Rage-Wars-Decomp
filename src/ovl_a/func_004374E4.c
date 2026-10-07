#include "o05_types.h"

typedef struct { void *f0; void *f4; void *f8; s32 fC; s32 f10; s32 f14; } O05M80;
typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
extern O05M80 *D_800E5780;
extern u8 D_80102B7E[];
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
s32 func_00265670(void *p, s32 a);
O05Obj10 *func_0040ECB0(void *cfg, s32 id);
void func_0040E9D0(void *w, s32 a);
void *func_00419ED4(s32 a, s32 b);

s32 func_004374E4(void *cfg) {
    D_800E5780 = func_00252FFC(0x18);
    D_800E5780->f0 = func_0041A300(0x136, 0x137);
    D_800E5780->f14 = 0;
    if (func_00265670(D_80102B7E, 0) == 0) {
        func_0040E9D0(func_0040ECB0(cfg, 0x13A), 1);
    }
    D_800E5780->f4 = func_00419ED4(0x139, 0x6E);
    D_800E5780->f8 = func_0040ECB0(cfg, 0x138);
    ((O05Obj10 *)D_800E5780->f8)->b10 = 0xF;
    D_800E5780->fC = 3;
    D_800E5780->f10 = -1;
    return 0;
}
