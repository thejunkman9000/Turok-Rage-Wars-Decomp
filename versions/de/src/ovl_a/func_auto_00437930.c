#include "o05_types.h"

typedef struct { void *f0; u8 pad[0xC]; s32 f10; } O05M84;
extern O05M84 *D_800E5784;
extern u8 D_80102B7E[];
void func_0029A73C(void);
s32 func_0029AA08(void);
void *memset(void *p, s32 c, u32 n);
void func_0041A4B0(void *w, s32 a);

s32 func_auto_00437930(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x3CB:
        D_800E5784->f10 = -1;
        break;
    case 0x3CA:
        D_800E5784->f10 = 7;
        memset(D_80102B7E, 0, 5);
        break;
    }
    func_0041A4B0(D_800E5784->f0, 2);
    return 0;
}
