#include "o04_types.h"
extern O04ModeS4600 *D_800E4600;
void func_0029A73C(void);
void func_0041A4B0(s32 a, s32 b);
s32 func_004244B4(s32 a, s32 b, u32 c, s32 d) {
    if ((c >> 16) == 3 && d == 10) {
        func_0029A73C();
        D_800E4600->unk18 = 0x1C;
        func_0041A4B0(D_800E4600->unk0, 2);
    }
    return 0;
}
