#include "o05_types.h"

typedef struct { void *f0; u8 pad[0xC]; s32 f10; } O05M80;
extern O05M80 *D_800E5780;
extern u8 D_80102B7E[];
extern u8 D_80102B0F;
extern u8 D_80146418;
void func_0029A73C(void);
s32 func_0029AA08(void);
s32 func_00265670(void *p, s32 a);
void func_0041A4B0(void *w, s32 a);

s32 func_auto_004375B0(void) {
    func_0029A73C();
    switch (func_0029AA08()) {
    case 0x13A:
        D_800E5780->f10 = -1;
        break;
    case 0x139:
        if (func_00265670(D_80102B7E, 0) == 0) {
            D_800E5780->f10 = 7;
        } else {
            D_800E5780->f10 = 0x1E;
        }
        break;
    case 0x138:
        D_80146418 = D_80102B0F;
        D_800E5780->f10 = 10;
        break;
    }
    func_0041A4B0(D_800E5780->f0, 2);
    return 0;
}
