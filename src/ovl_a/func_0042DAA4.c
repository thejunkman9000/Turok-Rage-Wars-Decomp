#include "o04_types.h"
extern O04ModeS53C0 *D_800E53C0;
void func_0029A73C(void);
void func_0042C1F8(void);
s32 func_0042DAA4(s32 a, s32 b, s32 c, s32 d) {
    if (d != 1) {
        return 0;
    }
    func_0029A73C();
    if (D_800E53C0->unkE8 > 0) {
        D_800E53C0->unkE8 = D_800E53C0->unkE8 - 1;
        func_0042C1F8();
    }
    return 0;
}
