#include "o06_types.h"
typedef struct { u8 pad[0x120]; u32 unk120; } O06B;
typedef struct { u8 pad[0xC]; O06B *unkC; } O06A;
extern s32 D_801468F4;
void func_00443D44(O06A *a) { if (D_801468F4) a->unkC->unk120 |= 0x1000000; else a->unkC->unk120 &= ~0x1000000; }
