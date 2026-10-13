#include "o05_types.h"

typedef struct { u8 pad0[0x10]; u8 b10; } O05Wd;
typedef struct { void *f0; void *f4; O05Wd *f8; s32 fC; s32 f10; } O05M84;
extern O05M84 *D_800E5784;
void *func_00252FFC(s32 n);
void *func_0041A300(s32 a, s32 b);
void *func_0040ECB0(void *a, s32 b);
void *func_00419ED4(s32 a, s32 b);

s32 func_auto_00437718(void *w) {
    D_800E5784 = func_00252FFC(0x14);
    D_800E5784->f0 = func_0041A300(0x3C6, 0x3C7);
    D_800E5784->f4 = func_00419ED4(0x3C9, 0x6E);
    D_800E5784->f8 = func_0040ECB0(w, 0x3C8);
    D_800E5784->f8->b10 = 0xF;
    D_800E5784->fC = 3;
    D_800E5784->f10 = -1;
    return 0;
}
