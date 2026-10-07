#include "o06_types.h"
typedef struct { u8 pad[0x78]; u8 unk78; u8 pad2[0x96 - 0x79]; } O06Row;
typedef struct { u8 pad[0x1D]; u8 unk1D; u8 unk1E; u8 pad2[0xD0 - 0x1F]; O06Row rows[8]; } O06Opt;
extern O06Opt D_801462C8[];
extern void func_00442934(s32 a, s32 b, void *c);
extern u8 D_00450AD4[];
s32 func_0043ED5C(s32 a, s32 b, s32 c) {
    s32 i;
    D_801462C8->unk1D = 1;
    D_801462C8->unk1E = 4;
    for (i = 7; i >= 0; i--) D_801462C8->rows[i].unk78 = 0;
    func_00442934(c, b, D_00450AD4);
    return 1;
}
