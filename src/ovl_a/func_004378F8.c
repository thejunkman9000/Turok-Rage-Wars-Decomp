#include "o05_types.h"

typedef struct { void *f0; void *f4; void *f8; s32 fC; s32 f10; } O05M84;
typedef struct { u8 pad[0x10]; u8 b10; } O05Obj10;
extern O05M84 *D_800E5784;
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
O05Obj10 *func_0040ECB0(void *cfg, s32 id);
void *func_00419ED4(s32 a, s32 b);

s32 func_004378F8(void *cfg) {
    D_800E5784 = func_00252FFC(0x14);
    D_800E5784->f0 = func_0041A300(0x3CC, 0x3CD);
    D_800E5784->f4 = func_00419ED4(0x3CF, 0x6E);
    D_800E5784->f8 = func_0040ECB0(cfg, 0x3CE);
    ((O05Obj10 *)D_800E5784->f8)->b10 = 0xF;
    D_800E5784->fC = 3;
    D_800E5784->f10 = -1;
    return 0;
}
