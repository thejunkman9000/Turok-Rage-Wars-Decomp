#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern u16 D_801462DC;
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
extern u8 D_800D7618[];
extern u8 D_800D761C[];
extern s32 D_800D7620[];
extern u8 D_800E2780[];
s32 func_004449FC(O06A *a) {
    u32 h = D_801462DC >> 4;
    if (h == 0) {
        a->unk14 = D_800D7618;
    } else if (h == 0x10) {
        a->unk14 = D_800D761C;
    } else {
        s32 s;
        a->unk14 = D_800D7620;
        s = D_800D7620[0];
        func_00265904(s - 2 + func_00442158(a), D_800E2780, h);
    }
    return 0;
}
