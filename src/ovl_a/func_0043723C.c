#include "o05_types.h"

typedef struct { u8 pad[0x14]; s32 f14; } O05M94;
extern O05M94 *D_800E5694;
void func_0029A73C(void);
s32 func_0029AA08(void);
void func_00436BC8(s32 i);
s32 func_0029A9A0(s32 a);
void func_0042EB68(s32 a);
void func_0029A8A8(void);

s32 func_0043723C(void) {
    func_0029A73C();
    if (func_0029AA08() == 0x1C8) {
        func_00436BC8(D_800E5694->f14);
        func_0042EB68(func_0029A9A0(0) == 22 ? -1 : 11);
        func_0029A8A8();
    }
    return 0;
}
