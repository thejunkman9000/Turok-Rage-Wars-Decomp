#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; void *unk14; } O06A;
extern s32 D_801462CC;
extern s32 D_801462C8;
extern u8 D_800D7B60[];
extern u8 D_800D7B64[];
s32 func_0043D700(O06A *a) {
    if (D_801462CC & 0x20) a->unk8 |= 0x1000000; else a->unk8 &= ~0x1000000;
    if (D_801462C8 & 0x20) a->unk14 = D_800D7B60; else a->unk14 = D_800D7B64;
    return 0;
}
