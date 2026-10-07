#include "o04_types.h"
extern O04ModeS4690 *D_800E4690;
void func_0029A73C(void);
void func_0025DF54(s32 a);
s32 func_004289D8(s32 a, s32 b, u32 c, s32 d) {
    if ((c >> 16) == 3 && d == 0) {
        func_0029A73C();
        D_800E4690->unk988 = 8;
        D_800E4690->unkA50->unk10 = 0x5A;
        func_0025DF54(0xE7C);
    }
    return 0;
}
