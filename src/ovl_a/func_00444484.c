#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; void *unk14; } O06A;
extern s32 D_80146878;
extern u32 D_801462D0;
extern u8 D_800D75D4[];
extern u8 D_800D75D8[];
extern u8 D_800D75DC[];
s32 func_00444484(O06A *a) {
    if (D_80146878 == 8) a->unk8 |= 0x1000000; else a->unk8 &= ~0x1000000;
    switch (D_801462D0) {
    case 8: a->unk14 = D_800D75D4; break;
    case 0x10: a->unk14 = D_800D75D8; break;
    case 0x20: a->unk14 = D_800D75DC; break;
    }
    return 0;
}
