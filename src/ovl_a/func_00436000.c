#include "o05_types.h"

typedef struct { u8 pad[0x1C]; s32 f1C; } O05W20;
typedef struct { u8 pad[0x14]; s16 h14; s16 h16; } O05Cfg;
extern O05W20 *D_800E5554;
void *func_00252FFC(s32 n);
void func_002A3358(void);
void func_0043C3F0(void *p, s32 a, s32 b, s32 c, s32 d);
s32 func_0040C4F4(void);

s32 func_00436000(O05Cfg *cfg) {
    D_800E5554 = func_00252FFC(0x20);
    func_002A3358();
    D_800E5554->f1C = -1;
    func_0043C3F0(D_800E5554, 0x67, 0, 0, 0);
    if (func_0040C4F4() == 1) {
        cfg->h14 = 0x62;
        cfg->h16 = 0x45;
    } else if (func_0040C4F4() == 2) {
        cfg->h14 = 0x69;
    }
    return 0;
}
