#include "o03_types.h"
typedef struct { u8 pad[0x20]; s32 f20; } O3Y;
extern O3Y *D_800E44A0;
s32 func_00422444(void) {
    D_800E44A0->f20 = 1;
    return 0;
}
