#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; void *unk14; } O06A;
extern s32 func_002934DC(O06A *a);
extern u8 D_801462E5;
extern u8 D_801462E7;
extern u8 D_800D7610[];
extern u8 D_800D7614[];
s32 func_00444960(O06A *a) {
    if (func_002934DC(a) != 0 && D_801462E5 == 0) a->unk8 &= ~0x1000000; else a->unk8 |= 0x1000000;
    switch (D_801462E7) {
    case 0: a->unk14 = D_800D7610; break;
    case 1: a->unk14 = D_800D7614; break;
    }
    return 0;
}
