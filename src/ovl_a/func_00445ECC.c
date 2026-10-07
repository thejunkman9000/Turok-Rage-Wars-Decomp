#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_800E63B8;
extern u8 D_800D7DE8[];
extern s32 D_800D7DEC[];
extern u8 D_800E27F0[];
extern s32 func_00442158(O06A *a);
extern void func_00265904(s32 a, void *b, s32 c);
s32 func_00445ECC(O06A *a) {
    if (D_800E63B8 == 0) {
        a->unk14 = D_800D7DE8;
    } else {
        s32 s;
        a->unk14 = D_800D7DEC;
        s = D_800D7DEC[0];
        func_00265904(s - 2 + func_00442158(a), D_800E27F0, D_800E63B8);
    }
    return 0;
}
