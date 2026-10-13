#include "o05_types.h"

typedef struct { void *f0; u8 pad[0x1C]; s32 f20; u8 pad24[4]; s32 f28; } O05M90;
extern O05M90 *D_800E5690;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_00436988(s32 i);
void func_0041A4B0(void *w, s32 a);

s32 func_auto_00436BF4(void) {
    O05M90 *p;
    func_0029A73C();
    if (func_0029AA08() == 0x5E) {
        func_00436988(D_800E5690->f28);
        p = D_800E5690;
        p->f20 = -1;
        func_0041A4B0(p->f0, 2);
    }
    return 0;
}
