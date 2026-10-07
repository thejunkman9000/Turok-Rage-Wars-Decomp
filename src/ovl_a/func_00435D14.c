#include "o05_types.h"

typedef struct { u8 pad[0x14]; s16 h14; s16 h16; } O05Cfg;
extern s32 *D_800E5550;
extern u8 D_801462D5;
extern s32 D_80146894;
void *func_00252FFC(s32 n);
void func_0025E234(s32 a);
void func_002648E8(void);
s32 func_0040C4F4(void);
void func_002A3358(void);
s32 func_0042B108();
s32 func_0040ECB0(O05Cfg *p, s32 a);
void func_0040E9D0(s32 a, s32 b);

s32 func_00435D14(O05Cfg *cfg) {
    D_800E5550 = func_00252FFC(0x14);
    *D_800E5550 = 0;
    func_0025E234(-1);
    func_002648E8();
    if (func_0040C4F4() == 1) {
        cfg->h14 = 0x62;
        cfg->h16 = 0x45;
    } else if (func_0040C4F4() == 2) {
        cfg->h14 = 0x69;
    }
    func_002A3358();
    if (D_801462D5 != 0 || func_0042B108() == 0) {
        func_0040E9D0(func_0040ECB0(cfg, 0x3E), 1);
    }
    D_80146894 = 1;
    return 0;
}
