#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_801468F4;
extern u8 D_800D7BE8[];
extern u8 D_800D7BE4[];
s32 func_00443AD4(O06A *a) { if (D_801468F4) a->unk14 = D_800D7BE8; else a->unk14 = D_800D7BE4; return 0; }
