#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern u32 D_801462D8;
extern s32 func_0025471C(void);
extern void func_0025470C(s32 a);
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_800D7650[];
extern s32 D_800D7654[];
extern u8 D_800E2788[];
s32 func_00444F0C(O06A *a) {
    u32 h = D_801462D8 >> 4;
    func_0025470C(func_0025471C() + 2);
    if (h == 0) {
        a->unk14 = D_800D7650;
    } else {
        s32 s;
        a->unk14 = D_800D7654;
        s = D_800D7654[0];
        func_00265904(s - 4 + func_00442158(a), D_800E2788, h);
    }
    return 0;
}
