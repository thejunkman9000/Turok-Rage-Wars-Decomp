#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; void *unk14; } O06A;
extern s32 D_801462CC;
extern s32 D_801462C8;
extern u8 D_800D7B58[];
extern u8 D_800D7B5C[];
s32 func_0043D678(O06A *a) {
    if (D_801462CC & 0x10) a->unk8 |= 0x1000000; else a->unk8 &= ~0x1000000;
    if (D_801462C8 & 0x10) a->unk14 = D_800D7B58; else a->unk14 = D_800D7B5C;
    return 0;
}
