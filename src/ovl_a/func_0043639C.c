#include "o05_types.h"

typedef struct { u8 pad[0x14]; s16 h14; s16 h16; } O05Cfg;
extern void *D_800E5558;
void *func_00252FFC(s32 n);
void func_002A3358(void);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_0040C4F4(void);

s32 func_0043639C(O05Cfg *cfg) {
    D_800E5558 = func_00252FFC(0x1C);
    func_002A3358();
    func_0043C3F0(D_800E5558, 0x67, 0, 0, 0);
    if (func_0040C4F4() == 1) {
        cfg->h14 = 0x62;
        cfg->h16 = 0x45;
    } else if (func_0040C4F4() == 2) {
        cfg->h14 = 0x69;
    }
    return 0;
}
