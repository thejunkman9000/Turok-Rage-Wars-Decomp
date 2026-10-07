#include "o06_types.h"
typedef struct { u8 pad[8]; u32 unk8; u8 pad2[8]; s32 unk14; } O06A;
extern s32 func_00265370(O06A *a);
extern s32 func_0040C43C();
s32 func_00446198(O06A *a) {
    if (func_00265370(a) != 0x400000) a->unk8 |= 0x800000; else a->unk8 &= ~0x800000;
    a->unk14 = func_0040C43C();
    return 0;
}
