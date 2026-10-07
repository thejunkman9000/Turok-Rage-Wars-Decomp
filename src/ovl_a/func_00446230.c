#include "o06_types.h"
typedef struct { u8 pad[0x14]; void *unk14; } O06A;
extern s32 D_800D2AE0;
extern u8 D_800E6058[];
extern u8 D_800E6074[];
s32 func_00446230(O06A *a) { if (D_800D2AE0) a->unk14 = D_800E6058; else a->unk14 = D_800E6074; return 0; }
